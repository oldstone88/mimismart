/*
{
  desc:"Диммирование по кнопкам",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"D00",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммируемая группа",width:800},
	{type:"comment",text:"Кнопки ВКЛ, ярче",width:600, "style":"color:red; font-weight:bold"},
	{name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Ярче",descWidth:300,width:600},
	{name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Ярче",descWidth:300,width:600},
	{name:"BUTTONUP3",type:"devices-list",required:false,filter:["switch"],desc:"Ярче",descWidth:300,width:600},
	{type:"comment",text:"Кнопки ВЫКЛ, тусклее",width:600, "style":"color:red; font-weight:bold"},
	{name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Тусклее",descWidth:300,width:300},
	{name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["switch"],desc:"Тусклее",descWidth:300,width:300},
	{name:"BUTTONDOWN3",type:"devices-list",required:false,filter:["switch"],desc:"Тусклее",descWidth:300,width:300},
  ]
}
*/

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2, #endif #ifdef  BUTTONUP3 BUTTONUP3 #endif
{
	if (opt(0)==)
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2, #endif #ifdef BUTTONDOWN3 BUTTONDOWN3, #endif
{

}
