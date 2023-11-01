/*
{
  desc:"Отопление и 1 скорость",
  tag:"item",
  selectArea:true,
  vars:[
{type:"comment",text:"На какой дельте включать вентилятор",width:600, "style":"color:red; font-weight:bold"},
{name:"DELTA", type:"number", defaultValue:1, required:true, desc:"Дельта", min:0},
{name:"V00",type:"devices-list",required:true, filter:["valve-heating"],descWidth:150, desc:"Батарея"},
{name:"D00",type:"devices-list",required:true, filter:["lamp"],desc:"Вентилятор"},
{name:"T00",type:"devices-list",required:true, filter:["temperature-sensor"],descWidth:150, desc:"Датчик темпиратуры"},
  ]                       
}
*/

V-ID/s:5
{
  if( (([V-ADDR.0]&1)==1) && (([V00.0]&1)==1) && ([V00.5]!=255) && ([V00.5]!=254) ){ // Проверяем что включен "Авто-режим", что отопление находится не в ручном режиме и не в режиме всегда выключен
  if( ([V00.2]-DELTA) >= [T00.1] ) {setStatus(D00, 1);} // Если заданная температура выше на DELTA чем температура на датчике - включаем вентилятор
  else if( [V00.2] >= ([T00.1]) ) { setStatus(D00, 0); } // Когда температура на датчике , выключается вентилятор 
  }
  else if (([V-ADDR.0]&1)==1 [V00.5]!=255){ setStatus(D00, 0); } // Если включен авторежим, но остальные условия не соблюдены - выключаем вентилятор

}