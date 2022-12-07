/*
{
	desc:"Вентиляция Турков-Zenit",
	tag:"import-script",
	target:"RS485",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"34", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
	],
	vars:[
		{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
		{name:"V00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},

        
	]
}
*/

u8 cond [5];
u8 read[8]={0x01, 0x03, 0x00, 0x01, 0x00, 0x04, 0xCC, 0x16};
u8 send[17]={0x01, 0x10, 0x00, 0x01, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 write=0;

V-ID/V00
{
    if(senderId()!=exciterId())
        {
            send[10]=opt(1)+16; send[12]=opt(4); if(send[12]==0) send[12]=4; //Уставка температуры и скорости вентилятора
            if(opt(0)==1) //Уставка ВКЛ-ВЫКЛ
            {
                send[8]=0x01; send[14]=0x00;
            } else
            if(opt(0)==17)
            {
                send[8]=0x01; send[14]=0x01;
            } else
            if(opt(0)%2==0)
            {
                send[8]=0x00;
            }
            write=1;
            setStatus(RS485, &send);
        }
}

//Опрос вентиляции
V-ID/s:5
{
    !write?setStatus(RS485, &read):(write=0);
}

void stat()
{
    u8 res[100]="";
    u8 *st = opt;
    u8 i = 0;
    sprintf(res,"%d ",optl);
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), " %x", st[i]);
    }
    sprintf(res+strlen(res), "\10");
    srvError(&res);
}

V-ID/RS485
{
    //stat();
    if(optl==13 && opt(1)==0x03) //Пришел ответ на запрос
    {
        cond[0]=opt(10); cond[0]=(cond[0]<<4)+opt(4); cond[1]=opt(6)-16; cond[4]=opt(8); if(cond[4]==4) cond[4]=0; else cond[4];
        setStatus(V00, &cond);
    }
}