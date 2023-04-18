/*
{
  desc:"Уборка",
  tag:"item",
  name:"Уборка",
  selectArea:true,
  vars:[
    {name:"TIME", type:"number", required:true, defaultValue:10800, min:1800, max:21600, desc:"Задержка, мин", descWidth:370},
    {name:"GERKON",type:"devices-list",required:false, filter:["script"],desc:"Уборка-геркон"},
    {type:"comment",text:"Выберите элементы, которые нужно",width:600, "style":"color:red; font-weight:bold"},
    {name:"LEAK00",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 1"},
    {name:"LEAK01",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 2"},
    {name:"LEAK02",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 3"},
    {name:"LEAK03",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 4"},
    {name:"LEAK04",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 5"},
    {name:"LEAK05",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 6"},
    {name:"LEAK06",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 7"},
    {name:"LEAK07",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 8"},
    {name:"LEAK08",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 9"},
    {name:"LEAK09",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 10"},
    {name:"LEAK10",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 11"},
    {name:"LEAK11",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 12"},
    {name:"LEAK12",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 13"},
    {name:"LEAK13",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 14"},
    {name:"LEAK14",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 15"},
    {name:"LEAK15",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 16"},
    {name:"LEAK16",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 17"},
    {name:"LEAK17",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 18"},
    {name:"LEAK18",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 19"},
    {name:"LEAK19",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 20"},
    {name:"LEAK20",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 21"},
    {name:"LEAK21",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 22"},
    {name:"LEAK22",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 23"},
    {name:"LEAK23",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 24"},
    {name:"LEAK24",type:"devices-list",required:false, filter:["leak-sensor"],width:888,desc:"Протечка 25"},
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
    #ifdef GERKON setStatus(GERKON, 0); #endif //Скрипт уборки через геркон
}

V-ID/V-ADDR{
  if ( (opt(0)&1)==1 )
  {
  #ifdef GERKON setStatus(GERKON, 1); #endif //Скрипт уборки через геркон
  #ifdef K00 if(([K00.0]&1)==1) setStatus(K00, 0); #endif
  #ifdef K01 if(([K00.0]&1)==1) setStatus(K01, 0); #endif
  #ifdef K02 if(([K00.0]&1)==1) setStatus(K02, 0); #endif
  #ifdef K03 if(([K00.0]&1)==1) setStatus(K03, 0); #endif
  setStatus(LEAK00,{TIME & 0xFF, TIME >> 8});
  #ifdef LEAK01 setStatus(LEAK01,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK02 setStatus(LEAK02,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK03 setStatus(LEAK03,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK04 setStatus(LEAK04,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK05 setStatus(LEAK05,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK06 setStatus(LEAK06,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK07 setStatus(LEAK07,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK08 setStatus(LEAK08,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK09 setStatus(LEAK09,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK10 setStatus(LEAK10,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK11 setStatus(LEAK11,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK12 setStatus(LEAK12,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK13 setStatus(LEAK13,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK14 setStatus(LEAK14,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK15 setStatus(LEAK15,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK16 setStatus(LEAK16,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK17 setStatus(LEAK17,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK18 setStatus(LEAK18,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK19 setStatus(LEAK19,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK20 setStatus(LEAK20,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK21 setStatus(LEAK21,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK22 setStatus(LEAK22,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK23 setStatus(LEAK23,{TIME & 0xFF, TIME >> 8}); #endif
  #ifdef LEAK24 setStatus(LEAK24,{TIME & 0xFF, TIME >> 8}); #endif
  setStatus(2047:32,{4,"Уборка активирована"});
  delayedCall(OTKL,TIME);
  }

  else

  {
  
  #ifdef LEAK00 setStatus(LEAK00, 0); #endif
  #ifdef LEAK01 setStatus(LEAK01, 0); #endif
  #ifdef LEAK02 setStatus(LEAK02, 0); #endif
  #ifdef LEAK03 setStatus(LEAK03, 0); #endif
  #ifdef LEAK04 setStatus(LEAK04, 0); #endif
  #ifdef LEAK05 setStatus(LEAK05, 0); #endif
  #ifdef LEAK06 setStatus(LEAK06, 0); #endif
  #ifdef LEAK07 setStatus(LEAK07, 0); #endif
  #ifdef LEAK08 setStatus(LEAK08, 0); #endif
  #ifdef LEAK09 setStatus(LEAK09, 0); #endif
  #ifdef LEAK10 setStatus(LEAK10, 0); #endif
  #ifdef LEAK11 setStatus(LEAK11, 0); #endif
  #ifdef LEAK12 setStatus(LEAK12, 0); #endif
  #ifdef LEAK13 setStatus(LEAK13, 0); #endif
  #ifdef LEAK14 setStatus(LEAK14, 0); #endif
  #ifdef LEAK15 setStatus(LEAK15, 0); #endif
  #ifdef LEAK16 setStatus(LEAK16, 0); #endif
  #ifdef LEAK17 setStatus(LEAK17, 0); #endif
  #ifdef LEAK18 setStatus(LEAK18, 0); #endif
  #ifdef LEAK19 setStatus(LEAK19, 0); #endif
  #ifdef LEAK20 setStatus(LEAK20, 0); #endif
  #ifdef LEAK21 setStatus(LEAK21, 0); #endif
  #ifdef LEAK22 setStatus(LEAK22, 0); #endif
  #ifdef LEAK23 setStatus(LEAK23, 0); #endif
  #ifdef LEAK24 setStatus(LEAK24, 0); #endif
  
  setStatus(2047:32,{4,"Уборка выключена!"});
  cancelDelayedCall(OTKL);
  }
      
}
