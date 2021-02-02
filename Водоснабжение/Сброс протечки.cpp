/*
{
  desc:"Сброс протечки",
  tag:"item",
  selectArea:true,
  vars:[
{type:"comment",text:"Датчики протечки",width:200, style:"color:red;"},
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
{type:"comment",text:"Клапана",width:200, style:"color:red;"},
{name:"V01",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 1"},
{name:"V02",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 2"},
{name:"V03",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 3"},
{name:"V04",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 4"},
{name:"V05",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 5"},
{name:"V06",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 6"},
{name:"V07",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 7"},
{name:"V08",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 8"},
{name:"V09",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 9"},
{name:"V10",type:"devices-list",required:false, filter:["valve", "lamp"],desc:"Устройство 10"},
  ]                       
}
*/


void OTKL()
{
    setStatus(V-ADDR,0);
}

V-ID/V-ADDR
{
  if (opt(0)==1)
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
  #ifdef V01 setStatus(V01, 1); #endif
  #ifdef V02 setStatus(V02, 1); #endif
  #ifdef V03 setStatus(V03, 1); #endif
  #ifdef V04 setStatus(V04, 1); #endif
  #ifdef V05 setStatus(V05, 1); #endif
  #ifdef V06 setStatus(V06, 1); #endif
  #ifdef V07 setStatus(V07, 1); #endif
  #ifdef V08 setStatus(V08, 1); #endif
  #ifdef V09 setStatus(V09, 1); #endif
  #ifdef V10 setStatus(V10, 1); #endif
  setStatus(2047:32,{4,"Сброс протечки!!! Клапана открыты!"});
  delayedCall(OTKL, 1);
  }
      
}
