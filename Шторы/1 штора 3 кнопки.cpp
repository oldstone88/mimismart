/*
{
  desc:"Скрипт для управления шторами(гардинами, жалюзями) с кнопок",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Выберите шторы(гардины, жалюзи), которые нужно открывать/закрывать",descWidth:300,width:300},
	{name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONUP3",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONDOWN3",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
  ]
}
*/

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2, #endif #ifdef  BUTTONUP3 BUTTONUP3 #endif
{
	if(opt(0) == 0xFC)
	{
		setStatus(BLINDS0, 1); // Open

	}
	if(opt(0) == 0xFF && opt(1) >= 0x06)
	{
		setStatus(BLINDS0, 1); // Open
	}
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2, #endif #ifdef BUTTONDOWN3 BUTTONDOWN3, #endif
{
	if(opt(0) == 0xFC)
	{
			setStatus(BLINDS0, 0); // Open

	}
	if(opt(0) == 0xFF && opt(1) >= 0x06)
	{
		setStatus(BLINDS0, 0); // Open
	}
}
