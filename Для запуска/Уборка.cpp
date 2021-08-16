/*
{
  desc:"Уборка",
  tag:"item",
  selectArea:true,
  vars:[
  {name:"TIME", type:"number", required:true, defaultValue:10800, min:1800, max:21600, desc:"Задержка, мин", descWidth:370},
{type:"comment",text:"Выберите элементы, которые нужно",width:600, "style":"color:red; font-weight:bold"},

{name:"ITEM101",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 1"},
{name:"ITEM102",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 2"},
{name:"ITEM103",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 3"},
{name:"ITEM104",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 4"},
{name:"ITEM105",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 5"},
{name:"ITEM106",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 6"},
{name:"ITEM107",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 7"},
{name:"ITEM108",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 8"},
{name:"ITEM109",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 9"},
{name:"ITEM110",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 10"},
{name:"ITEM111",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 11"},
{name:"ITEM112",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 12"},
{name:"ITEM113",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 13"},
{name:"ITEM114",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 14"},
{name:"ITEM114",type:"devices-list",required:false, filter:["leak-sensor"],desc:"Устройство 15"},
{name:"K00",type:"devices-list",required:false, filter:["valve"],desc:"Клапан"},
{name:"K01",type:"devices-list",required:false, filter:["valve"],desc:"Клапан"},
{name:"K02",type:"devices-list",required:false, filter:["valve"],desc:"Клапан"},
{name:"K03",type:"devices-list",required:false, filter:["valve"],desc:"Клапан"},

  ]                       
}
*/


void OTKL()
{
    setStatus(V-ADDR,0);
}

V-ID/V-ADDR
{
  if ( (opt(0)&1)==1 )
  {

  setStatus(ITEM101,{TIME & 0xFF, TIME >> 8});
  #ifdef K00 if(([K00.0]&1)==1) setStatus(K00, 0); #endif
  #ifdef K01 if(([K00.0]&1)==1) setStatus(K01, 0); #endif
  #ifdef K02 if(([K00.0]&1)==1) setStatus(K02, 0); #endif
  #ifdef K03 if(([K00.0]&1)==1) setStatus(K03, 0); #endif
  #ifdef ITEM102 setStatus(ITEM102,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM103 setStatus(ITEM103,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM104 setStatus(ITEM104,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM105 setStatus(ITEM105,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM106 setStatus(ITEM106,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM107 setStatus(ITEM107,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM108 setStatus(ITEM108,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM109 setStatus(ITEM109,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM110 setStatus(ITEM110,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM111 setStatus(ITEM111,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM112 setStatus(ITEM112,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM113 setStatus(ITEM113,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM114 setStatus(ITEM114,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef ITEM115 setStatus(ITEM115,{TIME & 0xFF, TIME >> 8}); #endif
  setStatus(2047:32,{4,"Уборка активирована"});
  delayedCall(OTKL,TIME);
  }

  else

  {
  
  #ifdef ITEM101 setStatus(ITEM101, 0); #endif
  #ifdef ITEM102 setStatus(ITEM102, 0); #endif
  #ifdef ITEM103 setStatus(ITEM103, 0); #endif
  #ifdef ITEM104 setStatus(ITEM104, 0); #endif
  #ifdef ITEM105 setStatus(ITEM105, 0); #endif
  #ifdef ITEM106 setStatus(ITEM106, 0); #endif
  #ifdef ITEM107 setStatus(ITEM107, 0); #endif
  #ifdef ITEM108 setStatus(ITEM108, 0); #endif
  #ifdef ITEM109 setStatus(ITEM109, 0); #endif
  #ifdef ITEM110 setStatus(ITEM110, 0); #endif
  #ifdef ITEM111 setStatus(ITEM111, 0); #endif
  #ifdef ITEM112 setStatus(ITEM112, 0); #endif
  #ifdef ITEM113 setStatus(ITEM113, 0); #endif
  #ifdef ITEM114 setStatus(ITEM114, 0); #endif
  #ifdef ITEM115 setStatus(ITEM115, 0); #endif
  
  setStatus(2047:32,{4,"Уборка выключена!"});
  cancelDelayedCall(OTKL);
  }
      
}
