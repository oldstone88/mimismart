/*
{
  desc:"Диммер MimiSmart",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"LOW01",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 1",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"LOW02",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 2",descWidth:350},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"LOW03",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 3",descWidth:350},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"LOW04",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 4",descWidth:350},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"ID2",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"LOW05",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 5",descWidth:350},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"LOW06",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 6",descWidth:350},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"LOW07",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 7",descWidth:350},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"LOW08",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 8",descWidth:350},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
  ]
}
*/

u8 numberidset=0;

V-ID/ms:150
{
    //Подсчет яркости
    u8 bright[4];
    if(numberidset==0)
    {
    bright[0]=([DIMMER01.1]*((25000-LOW01*100)/250)+LOW01*100)/100;
    bright[1]=([DIMMER02.1]*((25000-LOW02*100)/250)+LOW02*100)/100;
    bright[2]=([DIMMER03.1]*((25000-LOW03*100)/250)+LOW03*100)/100;
    bright[3]=([DIMMER04.1]*((25000-LOW04*100)/250)+LOW04*100)/100;
    //Уставка диммеров
        u8 data[33]={ID1, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER01.0]&1, 0x00, bright[0], 0x00, 0x01, //12
        0x00, [DIMMER02.0]&1, 0x00, bright[1], 0x00, 0x01, //18
        0x00, [DIMMER03.0]&1, 0x00, bright[2], 0x00, 0x01, //24
        0x00, [DIMMER04.0]&1, 0x00, bright[3], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        ++numberidset;
        return;
    } else
    if(numberidset==1)
    {
    bright[0]=([DIMMER05.1]*((25000-LOW05*100)/250)+LOW05*100)/100;
    bright[1]=([DIMMER06.1]*((25000-LOW06*100)/250)+LOW06*100)/100;
    bright[2]=([DIMMER07.1]*((25000-LOW07*100)/250)+LOW07*100)/100;
    bright[3]=([DIMMER08.1]*((25000-LOW08*100)/250)+LOW08*100)/100;
    //Уставка диммеров
        u8 data[33]={ID2, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER05.0]&1, 0x00, bright[0], 0x00, 0x01, //12
        0x00, [DIMMER06.0]&1, 0x00, bright[1], 0x00, 0x01, //18
        0x00, [DIMMER07.0]&1, 0x00, bright[2], 0x00, 0x01, //24
        0x00, [DIMMER08.0]&1, 0x00, bright[3], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        --numberidset;
        return;
    }
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