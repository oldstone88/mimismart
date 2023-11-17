/*
{
  desc:"Смена фронта",
  tag:"item",
  selectArea:true,
  name:"Уставка порогов",
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",Width:350},
    {type:"comment",text:"Какой фронт ставим? 0 - задний, 1 - передний",width:200, style:"color:red;"},
    {name:"FRONT",type:"number",required:true,defaultValue:1,min:0,max:1,desc:"Фронт",Width:350},
    ]
}
*/

V-ID/V-ADDR
{
    srvError("Смена фронта");
    u8 writeSetup[41]={ID, 0x10, 0x00, 0x69, 0x00, 0x02, 0x04 // Начало
    ,0x00, FRONT, 0x00, FRONT // Установка вронтов
    ,0xCC, 0x16};//Сумма
    setStatus(RS485, &writeSetup);
    if(FRONT==0){
      srvError("Вы установили задний фронт");
    }
    else{
      srvError("Вы установили передний фронт");
    }
    
}
