/*
{
  desc:"Диммер MimiSmart",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"ID2",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {name:"ID3",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER09",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"DIMMER10",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"DIMMER11",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"DIMMER12",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
  ]
}
*/

u8 numberidset=0;

V-ID/ms:150{
    //Подсчет яркости
    if(numberidset==0){
    //Уставка диммеров
        u8 data[33]={ID1, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER01.0]&1, 0x00, [DIMMER01.1], 0x00, 0x01, //12
        0x00, [DIMMER02.0]&1, 0x00, [DIMMER02.1], 0x00, 0x01, //18
        0x00, [DIMMER03.0]&1, 0x00, [DIMMER03.1], 0x00, 0x01, //24
        0x00, [DIMMER04.0]&1, 0x00, [DIMMER04.1], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        ++numberidset;
        return;
    } else
    if(numberidset==1){
    //Уставка диммеров
        u8 data[33]={ID2, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER05.0]&1, 0x00, [DIMMER05.1], 0x00, 0x01, //12
        0x00, [DIMMER06.0]&1, 0x00, [DIMMER06.1], 0x00, 0x01, //18
        0x00, [DIMMER07.0]&1, 0x00, [DIMMER07.1], 0x00, 0x01, //24
        0x00, [DIMMER08.0]&1, 0x00, [DIMMER08.1], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        ++numberidset;
        return;
    } else
    if(numberidset==2){
    //Уставка диммеров
        u8 data[33]={ID3, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER09.0]&1, 0x00, [DIMMER09.1], 0x00, 0x01, //12
        0x00, [DIMMER10.0]&1, 0x00, [DIMMER10.1], 0x00, 0x01, //18
        0x00, [DIMMER11.0]&1, 0x00, [DIMMER11.1], 0x00, 0x01, //24
        0x00, [DIMMER12.0]&1, 0x00, [DIMMER12.1], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        numberidset=0;
        return;
    }
}

//Вывода в лог
void stat(){
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

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
}