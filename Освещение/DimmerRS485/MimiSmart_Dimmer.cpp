/*
{
  desc:"Диммер MimiSmart",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"MAX",type:"number",required:true,defaultValue:250,min:1,max:250,desc:"Максимальная",descWidth:350},
    {name:"MIN",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимальная",descWidth:350},
    {name:"START",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"Стартовая",descWidth:350},
    {name:"SETID",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"Установить ID",descWidth:350},
    {name:"FRONT",type:"number",required:true,defaultValue:0,min:0,max:1,desc:"1 - задний фронт, 0 - передний фронт",descWidth:350},
    {name:"DIMMER1",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1"},
    {name:"DIMMER2",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2"},
    {name:"DIMMER3",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3"},
    {name:"DIMMER4",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4"},
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"ID диммера",descWidth:350},
  ]
}
*/

u8 firstsetup[15]={ID1, 0x10, 0x00, 0x38, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 secondsetup[13]={ID1, 0x10, 0x00, 0x68, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 i1[13]={ID1, 0x10, 0x00, 0x28, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 i2[13]={ID1, 0x10, 0x00, 0x2B, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 i3[13]={ID1, 0x10, 0x00, 0x2E, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 i4[13]={ID1, 0x10, 0x00, 0x31, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

/*void CRC16(u8 *k)
{
    u16 reg=0XFFFF;
    u16 pol=0xA001;
    for(u8 j=0; j<11; ++j)
    {
        reg=reg^i1[j];
        for(u8 g=0; g<8; ++g)
        {
            if((reg&0x01)==1)
            {
                reg=reg>>1;
                reg=reg^pol;
            } else
            {
                reg=reg>>1;
            }
        }
    }
}
*/

V-ID/DIMMER1
{
    i1[8]=(opt(0)&1); i1[10]=opt(1);
    setStatus(RS485, &i1);
}

V-ID/DIMMER2
{
    i2[8]=(opt(0)&1); i2[10]=opt(1);
    setStatus(RS485, &i2);
}

V-ID/DIMMER3
{
    i3[8]=(opt(0)&1); i3[10]=opt(1);
    setStatus(RS485, &i3);
}

V-ID/DIMMER4
{
    i4[8]=(opt(0)&1); i4[10]=opt(1);
    setStatus(RS485, &i4);
}

u8 proverka=0;

void OFF()
{
    setStatus(V-ADDR, 0);
    proverka=0;
    srvError("Готово!");
}

void SETUP()
{
    setStatus(RS485, secondsetup);
}

V-ID/V-ADDR
{
    if(opt(0)%2==1)
    {
        cancelDelayedCall(proverka);
        if(proverka==0) {
        firstsetup[8]=MAX;
        firstsetup[10]=MIN;
        firstsetup[12]=START;
        secondsetup[7]=SETID>>8;
        secondsetup[8]=SETID;
        secondsetup[10]=FRONT;
        setStatus(RS485, &firstsetup);
        delayedCall(SETUP, 1);
        srvError("Ждите");}
        else {srvError("Андрей! НЕ СПЕШИ!!!");}
        proverka=1;
        delayedCall(OFF, 3);
    }
}

void stat()
{
u8 res[50]="";
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
    stat();
}