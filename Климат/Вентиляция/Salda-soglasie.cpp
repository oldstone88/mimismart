/*
{
	desc:"Salda br 19200 EP stop 1.0",
	tag:"import-script",
	target:"RS485",
	selectArea:true,
    name:"Вентиляция",
    addItems:[
    {tag:"item", id:"%TARGET%", name:"Вентиляция", sub-id:"%SUBID01%", type:"conditioner",funs:"0x0E",t-min:"0",t-delta:"30",vane-hor:"0x00",vane-ver:"0x00",modes:"0x01"},
  ],
	vars:[
		{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"VENT",type:"hidden",value:"%TARGET%:%SUBID01%"},
	]
}
*/

u8 write[13]={0x01, 0x10, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

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

V-ID/VENT
{
    if(senderId()!=exciterId())
    {
        write[10]=opt(1);
        if((opt(0)%2)==1){ write[8]=opt(4)+1; }
        else if((opt(0)%2)==0){ write[8]=0; }
        setStatus(RS485, &write);
    }
}

V-ID/s:9
{
    u8 zadacha[5]={0x00, 0x00, 0x00, 0x00, 0x00};
    u8 read[8]={0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xCC, 0x16};
    setStatus(RS485, &read);
}

V-ID/RS485
{
    stat();
    if(opt(0)==0x01 && opt(1)==0x03)
    {
        u8 zadacha[5]={0x00, 0x00, 0x00, 0x00, 0x00};
        if(opt(4)==0) {zadacha[0]=0; zadacha[1]=opt(6);}
        else {zadacha[0]=1; zadacha[4]=opt(4)-1; zadacha[1]=opt(6);}
        setStatus(VENT, &zadacha);
    }
}