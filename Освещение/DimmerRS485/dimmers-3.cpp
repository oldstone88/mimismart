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
    {name:"ID3",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"LOW09",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 9",descWidth:350},
    {name:"DIMMER09",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"LOW10",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 10",descWidth:350},
    {name:"DIMMER10",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"LOW11",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 11",descWidth:350},
    {name:"DIMMER11",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"LOW12",type:"number",required:true,defaultValue:0,min:0,max:255,desc:"Минимум 12",descWidth:350},
    {name:"DIMMER12",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
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
    bright[0]=([DIMMER01.1]*((2500-LOW01*10)/250)+LOW01*10)/10;
    bright[1]=([DIMMER02.1]*((2500-LOW02*10)/250)+LOW02*10)/10;
    bright[2]=([DIMMER03.1]*((2500-LOW03*10)/250)+LOW03*10)/10;
    bright[3]=([DIMMER04.1]*((2500-LOW04*10)/250)+LOW04*10)/10;
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
    bright[0]=([DIMMER05.1]*((2500-LOW05*10)/250)+LOW05*10)/10;
    bright[1]=([DIMMER06.1]*((2500-LOW06*10)/250)+LOW06*10)/10;
    bright[2]=([DIMMER07.1]*((2500-LOW07*10)/250)+LOW07*10)/10;
    bright[3]=([DIMMER08.1]*((2500-LOW08*10)/250)+LOW08*10)/10;
    //Уставка диммеров
        u8 data[33]={ID2, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER05.0]&1, 0x00, bright[0], 0x00, 0x01, //12
        0x00, [DIMMER06.0]&1, 0x00, bright[1], 0x00, 0x01, //18
        0x00, [DIMMER07.0]&1, 0x00, bright[2], 0x00, 0x01, //24
        0x00, [DIMMER08.0]&1, 0x00, bright[3], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        ++numberidset;
        return;
    } else
    if(numberidset==2)
    {
    bright[0]=([DIMMER09.1]*((2500-LOW09*10)/250)+LOW09*10)/10;
    bright[1]=([DIMMER10.1]*((2500-LOW10*10)/250)+LOW10*10)/10;
    bright[2]=([DIMMER11.1]*((2500-LOW11*10)/250)+LOW11*10)/10;
    bright[3]=([DIMMER12.1]*((2500-LOW12*10)/250)+LOW12*10)/10;
    //Уставка диммеров
        u8 data[33]={ID3, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER09.0]&1, 0x00, bright[0], 0x00, 0x01, //12
        0x00, [DIMMER10.0]&1, 0x00, bright[1], 0x00, 0x01, //18
        0x00, [DIMMER11.0]&1, 0x00, bright[2], 0x00, 0x01, //24
        0x00, [DIMMER12.0]&1, 0x00, bright[3], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        numberidset=0;
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