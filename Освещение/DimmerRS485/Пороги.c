/*
{
  desc:"Пороги диммера",
  tag:"item",
  selectArea:true,
  name:"Уставка порогов",
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",Width:350},
    {type:"comment",text:"Минимумы",width:200, style:"color:red;"},
    {name:"MIN01",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"Минимульный 1",Width:350},
    {name:"MIN02",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"Минимульный 2",Width:350},
    {name:"MIN03",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"Минимульный 3",Width:350},
    {name:"MIN04",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"Минимульный 4",Width:350},
    {type:"comment",text:"Максимумы",width:200, style:"color:red;"},
    {name:"MAX01",type:"number",required:true,defaultValue:250,min:0,max:255,desc:"Максимальный 1",Width:350},
    {name:"MAX02",type:"number",required:true,defaultValue:250,min:0,max:255,desc:"Максимальный 2",Width:350},
    {name:"MAX03",type:"number",required:true,defaultValue:250,min:0,max:255,desc:"Максимальный 3",Width:350},
    {name:"MAX04",type:"number",required:true,defaultValue:250,min:0,max:255,desc:"Максимальный 4",Width:350},
    ]
}
*/

V-ID/V-ADDR
{
    srvError("Смена яркости");
    u8 writeSetup[41]={ID, 0x10, 0x00, 0x35, 0x00, 0x10, 0x20 //начало
    ,0x00, MIN01, 0x00, MAX01, 0x00, 0x64, 0x00, 0x0A
    ,0x00, MIN02, 0x00, MAX02, 0x00, 0x64, 0x00, 0x0A
    ,0x00, MIN03, 0x00, MAX03, 0x00, 0x64, 0x00, 0x0A
    ,0x00, MIN04, 0x00, MAX04, 0x00, 0x64, 0x00, 0x0A //Канал 1
    ,0xCC, 0x16};//Сумма
    setStatus(RS485, &writeSetup);
}