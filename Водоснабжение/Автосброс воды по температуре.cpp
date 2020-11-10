/*
{
desc:"Спуск",
"name":"Spusk",
"name-ru":"Спуск",  
selectArea:true,
tag:"import-script",
vars:[

{name:"L00",type:"devices-list",required:true, filter:["lamp","dimer-lamp"],width:888,desc:"Свет"},
{name:"L01",type:"devices-list",required:true, filter:["lamp","valve-heating"],width:888,desc:"Клапан"},
{name:"T00",type:"devices-list",required:true, filter:["temperature-sensor"],width:888,desc:"Температура"},
{type:"comment",text:"С какой температуры скидываем?",width:200, style:"color:red;"},
{name:"DELTA",type:"number",required:true,min:20,max:100,defaultValue:30,descWidth:150,desc:"Значение температуры"},
{type:"comment",text:"Время спуска воды.",width:200, style:"color:red;"},
{name:"TIME",type:"number",required:true,min:10,max:120,defaultValue:30,descWidth:150,desc:"Время спуска в секундах"},
  ]                       
}
*/

void SBROS()
{
    setStatus(L01,0);
}

V-ID/L00
{
    if ([L00.0]==1 && [T00.1]<DELTA)
    {
        cancelDelayedCall(SBROS);
        setStatus(L01, 1);
        delayedCall(SBROS, TIME);
    }
}