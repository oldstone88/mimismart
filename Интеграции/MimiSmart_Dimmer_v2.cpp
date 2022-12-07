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
    {name:"LOW1",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 1",descWidth:350},
    {name:"DIMMER1",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1"},
    {name:"LOW2",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 2",descWidth:350},
    {name:"DIMMER2",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2"},
    {name:"LOW3",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 3",descWidth:350},
    {name:"DIMMER3",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3"},
    {name:"LOW4",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 4",descWidth:350},
    {name:"DIMMER4",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4"},
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"REBOOT",type:"devices-list",required:true,filter:["script"],desc:"Сохранить"},
  ]
}
*/

u8 write=0; //0 - читаем датчики, 1 - пишем диммеры, 2 - пишем настройки
u8 firstsetup[13]={ID1, 0x10, 0x00, 0x38, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 secondsetup[13]={ID1, 0x10, 0x00, 0x68, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00,  0xCC, 0x16};
u8 reb[8]={ID1, 0x06, 0x00, 0x6A, 0x2C, 0x68, 0xCC, 0x16};

//Секция перезагрузки
void REBOFF()
{
    setStatus(REBOOT, 0);
}

V-ID/REBOOT
{
    if(opt(0)==1)
    {
        setStatus(RS485, &reb);
        delayedCall(REBOFF, 1);
        srvError("REBOOT");
    }
}

//Секция установки параметров диммера
u8 proverka=0;

void OFF()
{
    setStatus(V-ADDR, 0);
    proverka=0;
    write=0;
    srvError("Готово!");
}

void SETUP()
{
    setStatus(RS485, &secondsetup);
}

V-ID/V-ADDR
{
    if(opt(0)==1)
    {
        write=2;
        cancelDelayedCall(proverka);
        if(proverka==0) {
        firstsetup[8]=MIN;
        firstsetup[10]=MAX;
        setStatus(RS485, &firstsetup);
        secondsetup[7]=SETID>>8;
        secondsetup[8]=SETID;
        secondsetup[10]=FRONT;
        delayedCall(SETUP, 1);
        srvError("Ждите");}
        else {srvError("Андрей! НЕ СПЕШИ!!!");}
        proverka=1;
        delayedCall(OFF, 3);
    }
}

V-ID/ms:150
{
    //Подсчет яркости
    u8 bright[4];
    bright[0]=([DIMMER1.1]*((25000-LOW1*100)/250)+LOW1*100)/100;
    bright[1]=([DIMMER2.1]*((25000-LOW2*100)/250)+LOW2*100)/100;
    bright[2]=([DIMMER3.1]*((25000-LOW3*100)/250)+LOW3*100)/100;
    bright[3]=([DIMMER4.1]*((25000-LOW4*100)/250)+LOW4*100)/100;
    //Уставка диммеров
        u8 data[33]={ID1, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER1.0]&1, 0x00, bright[0], 0x00, 0x01, //12
        0x00, [DIMMER2.0]&1, 0x00, bright[1], 0x00, 0x01, //18
        0x00, [DIMMER3.0]&1, 0x00, bright[2], 0x00, 0x01, //24
        0x00, [DIMMER4.0]&1, 0x00, bright[3], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
}

//Вывода в лог
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
}