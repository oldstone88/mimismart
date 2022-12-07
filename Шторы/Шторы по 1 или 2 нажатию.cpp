/*
{
  desc:"Шторы 1 нажатие - открыть 2 - закрыть",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы 1 нажатие",descWidth:300,width:300},
	{type:"comment",text:"Кнопки",width:200, style:"color:red;"},
	{name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	{name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
	
  ]
}
*/

u8 i=0;

void OPEN()
{
	i=0;
	if( ([BLINDS0.0]&7)!=1 ) setStatus(BLINDS0, 1); // Open
}

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2 #endif
{
	if(opt(0) == 0xFC)
	{
		++i;
		cancelDelayedCall(OPEN);
		if (i==1) delayedCall(OPEN, 1);
		else if (i==2) {if( ([BLINDS0.0]&7)!=0 ) setStatus(BLINDS0, 0); i=0;}
	}
}

