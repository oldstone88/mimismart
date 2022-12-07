/*
{
  desc:"Свет к кнопкам",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"L00",type:"devices-list",required:true,filter:["lamp", "dimer-lamp", "light-scheme"],desc:"Свет",descWidth:300,width:300},
	{type:"comment",text:"Кнопки включить",width:600, "style":"color:red; font-weight:bold"},
	{name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Включить",descWidth:300,width:300},
	{name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Кнопка включить",descWidth:300,width:300},
	{name:"BUTTONUP3",type:"devices-list",required:false,filter:["switch"],desc:"Кнопка включить",descWidth:300,width:300},
	{type:"comment",text:"Кнопки закрыть",width:600, "style":"color:red; font-weight:bold"},
	{name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Кнопка выключить",descWidth:300,width:300},
	{name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["switch"],desc:"Кнопка выключить",descWidth:300,width:300},
	{name:"BUTTONDOWN3",type:"devices-list",required:false,filter:["switch"],desc:"Кнопка выключить",descWidth:300,width:300},
  ]
}
*/

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2, #endif #ifdef  BUTTONUP3 BUTTONUP3 #endif
{
	if(opt(0)==0xFC)
	{
		if(([L00.0]&1)==0) setStatus(L00, 1);
	}
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2, #endif #ifdef BUTTONDOWN3 BUTTONDOWN3, #endif
{
	if(opt(0)==0xFC)
	{
		if(([L00.0]&1)==1) setStatus(L00, 0);
	}
}
