/*
{
desc:"Отопление",
tag:"import-script",
selectArea:true,

vars:[
{type:"comment",text:"Включить отопление",width:600, "style":"color:red; font-weight:bold"},
{name:"BUTTONON",type:"devices-list",required:true,filter:["switch"],desc:"ВКЛ",descWidth:300,width:600},
{type:"comment",text:"Выключить отопление",width:600, "style":"color:red; font-weight:bold"},
{name:"BUTTONOFF",type:"devices-list",required:true,filter:["switch"],desc:"ВЫКЛ",descWidth:300,width:600},
{name:"V00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
]
}
*/

V-ID/BUTTONON
{
   if(opt(0)==0xFF)
   {
      setStatus(1000:102,"V00\0as:-4");
      setStatus(V00, 1);
   }
}

V-ID/BUTTONOFF
{
   if(opt(0)==0xFF)
   {
      setStatus(1000:102,"V00\0as:-4");
      setStatus(V00, 0);
   }
}