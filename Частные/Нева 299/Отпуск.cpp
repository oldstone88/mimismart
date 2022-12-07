/*
{
  desc:"Отпуск",
  tag:"item",
  selectArea:true,
  name:"Отпуск",
  vars:
  [
    {name:"I00",type:"devices-list",required:false,width:600,filter:["script"],desc:"Выключить весь свет",descWidth:100},
    {name:"V00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V01",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V02",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V03",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V04",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V05",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"V06",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
  ]
}
*/

V-ID/V-ADDR
{
  if((opt(0)&1)==1)
  {
    setStatus(I00, 1);
    #ifdef V00 setStatus(1000:102,"V00\0as:-1"); #endif
    #ifdef V01 setStatus(1000:102,"V01\0as:-1"); #endif
    #ifdef V02 setStatus(1000:102,"V02\0as:-1"); #endif
    #ifdef V03 setStatus(1000:102,"V03\0as:-1"); #endif
    #ifdef V04 setStatus(1000:102,"V04\0as:-1"); #endif
    #ifdef V05 setStatus(1000:102,"V05\0as:-1"); #endif
    #ifdef V06 setStatus(1000:102,"V06\0as:-1"); #endif
  }
  else if((opt(0)&1)==0)
  {
    setStatus(1000:100, "Комфорт");
  }
}