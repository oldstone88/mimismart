/*
{
  desc:"Скрипт для управления шторами(гардинами, жалюзями) с кнопок",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы 1 нажатие",descWidth:300,width:300},
	{name:"BLINDS1",type:"devices-list",required:false,filter:["virtual","jalousie"],desc:"Шторы 1 нажатие",descWidth:300,width:300},
	{name:"BLINDS2",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы 2 нажатия",descWidth:300,width:300},
	{name:"BLINDS3",type:"devices-list",required:false,filter:["virtual","jalousie"],desc:"Шторы 2 нажатия",descWidth:300,width:300},
	{type:"comment",text:"Кнопки открытия",width:200, style:"color:red;"},
	{name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{type:"comment",text:"Кнопки закрытия",width:200, style:"color:red;"},
	{name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	
  ]
}
*/

u8 i=0;

void OPEN()
{
	i=0;
	setStatus(BLINDS0, 1); // Open
	#ifdef BLIENDS1 setStatus(BLINDS1, 1); #endif
}

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2 #endif
{
	if(opt(0) == 0xFC)
	{
		++i;
		cancelDelayedCall(OPEN);
		if (i==1) delayedCall(OPEN, 1);
		else if (i==2) {setStatus(BLINDS2, 1); 	#ifdef BLIENDS3 setStatus(BLINDS3, 1); #endif i=0;}
	}
}


void CLOSE()
{
	i=0;
	setStatus(BLINDS0, 0);
	#ifdef BLIENDS1 setStatus(BLINDS1, 0); #endif // Close
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2 #endif
{
	if(opt(0) == 0xFC)
	{
		++i;
		cancelDelayedCall(CLOSE);
		if (i==1) delayedCall(CLOSE, 1);
		else if (i==2) {setStatus(BLINDS2, 0); #ifdef BLIENDS3 setStatus(BLINDS3, 0); #endif i=0;}
	}
}
