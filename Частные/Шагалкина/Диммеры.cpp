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

u8 updown = 0;
u8 OldState [2] ={0,0};
u8 State [2] = {0,0};

void ON()
{
	if (updown==0) if( ([D00.0]&1)==0 ) {setStatus(D00, {1, 0xFE, 0});} else {setStatus(D00, {1, 150, 0});}
}

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2, #endif #ifdef  BUTTONUP3 BUTTONUP3 #endif
{
	State[0]=opt(0);
	State[1]=opt(1);
	updown=1; // маркер повышения яркости
	if (opt(0)==0xFC)
	{
		delayedCallMs(ON, 500);
	}
	if(opt(0)==0xFF) updown=0;

}

void OFF()
{
	if (updown==0) if( ([D00.0]&1)==1 ) {setStatus(D00, {0, 0xFE, 0});} else if( ([D00.0]&1)==0 ) {setStatus(D00, {1, 10, 0});}
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2, #endif #ifdef BUTTONDOWN3 BUTTONDOWN3, #endif
{
	State[0]=opt(0);
	State[1]=opt(1);
	updown=2; // Маркер понижения яркости
	if (opt(0)==0xFC)
	{
		delayedCallMs(OFF, 500);
	}
	if(opt(0)==0xFF) updown=0;
}

u8 temp =0;

V-ID/ms:150
{
	u8 breakpoint=0;
	if(State[0]==0xfd && updown==1 && ([D00.0]&1)==1)
	{
		for(u8 i=0;i<2;++i)
		{
			if(OldState[i]!=State[i] || (OldState[1]==0xff && State[1]==0xff))
			{
				OldState[i]=State[i];
				if(!breakpoint)
				{
					i16 bright = [D00.1];
					if (bright<250) {bright=bright+3; if(bright>250) bright=250; setStatus(D00,{1,bright,0});}
					breakpoint=1;
				}
			}
		}
	}
	else
		if(State[0]==0xfd && updown==2 && ([D00.0]&1)==1)
	{
		for(u8 i=0;i<2;++i)
		{
			if(OldState[i]!=State[i] || (OldState[1]==0xff && State[1]==0xff))
			{
				OldState[i]=State[i];
				if(!breakpoint)
				{
					i16 bright = [D00.1];
					if (bright!=0) {bright=bright-3; if(bright<10) bright=10; setStatus(D00,{1,bright,0});}
					breakpoint=1;
				}
			}
		}
	}
}

