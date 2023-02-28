/*
{
    desc:"Вентиляция ZenTeck br 9600 EP stop 1.0",
    tag:"import-script",
    target:"RS485",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"34", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    ],
    vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"V00",type:"hidden",value:"%TARGET%:%SUBID01%"},
    ]
}
*/

u8 cond [5];
u8 read[8]={0xF7, 0x03, 0x01, 0xF4, 0x00, 0x04, 0xCC, 0x16};
u8 send[17]={0xF7, 0x10, 0x01, 0xF4, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0xCC, 0x16};
u8 write=0;

V-ID/V00
{
    if(senderId()!=exciterId())
        {
            send[14]=opt(1)+10; //Уставка температуры и скорости вентилятора
            if(opt(0)==1) //Уставка ВКЛ-ВЫКЛ
            {
                send[10]=0x01; send[12]=0x01;
            } else
            if(opt(0)==17)
            {
                send[10]=0x02; send[12]=0x01;
            }else
            if(opt(0)%2==0)
            {
                send[10]=0x01; send[12]=0x00;
            }
            //Скорость
            if(opt(4)==1)
            {
                send[8]=0x02;
            } else
            if(opt(4)==2)
            {
                send[8]=0x04;
            } else
            if(opt(4)==3)
            {
                send[8]=0x07;
            } else
            if(opt(4)==0)
            {
                send[8]=0x05;
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

void transformspeed(u8 j)
{
    if(j==2) {j=1; return j;} else
    if(j==4) {j=2; return j;} else
    if(j==7) {j=3; return j;} else
    {j=0; return j;}
}

V-ID/RS485
{
    stat();
    if(optl==13 && opt(1)==0x03) //Пришел ответ на запрос
    {
        cond[0]=(opt(6)-1)<<4; cond[0]=cond[0]|opt(8); cond[1]=opt(10)-10; cond[4]=transformspeed(opt(4));
        setStatus(V00, &cond);
    }
}