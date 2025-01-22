/*
{
  desc:"Защита диммера",
  tag:"item",
  selectArea:true,
  name:"Установить",
  
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    
    {type:"comment", style:"color:red", text:"Настройки первого канала:"},
    {name:"PROTECT01",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки второго канала:"},
    {name:"PROTECT02",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки третьего канала:"},
    {name:"PROTECT03",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки четвертого канала:"},
    {name:"PROTECT04",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
  ]
}
*/

// Настройка
V-ID/V-ADDR{
    u16 j1 = PROTECT01;
    u16 j2 = PROTECT02;
    u16 j3 = PROTECT03;
    u16 j4 = PROTECT04;
    u8 writeSetup[17]={
        ID1, 0x10, 0x00, 0x45, 0x00, 0x04, 0x08,//общие данные
        j1>>8, j1, j2>>8, j2, j3>>8, j3, j4>>8, j4, //Защита по току
        0xCC, 0x16 //CRC
    };
    setStatus(RS485, &writeSetup);
}

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
    //stat();
}
