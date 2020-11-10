/*
{
  desc:"Будильник",
  tag:"item",
  selectArea:true,
  vars:[
	{type:"comment",text:"Димера",width:200, style:"color:red;"},
	{type:"comment",text:"Устройства для включения автоматизации",width:200, style:"color:red;"},
  	{name:"TIME00",type:"string",required:false,min:1,max:10,desc:"Время выключения автоматизации в 16ти ричной системе",width:300},
	{name:"DIM00",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 0",descWidth:500,width:500},
	{name:"DIM01",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 1",descWidth:500,width:500},
	{name:"DIM02",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 2",descWidth:500,width:500},
	{name:"DIM03",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 3",descWidth:500,width:500},
	{name:"DIM04",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 4",descWidth:500,width:500},
	{name:"DIM05",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 5",descWidth:500,width:500},
	{name:"DIM06",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 6",descWidth:500,width:500},
	{name:"DIM07",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 7",descWidth:500,width:500},
	{name:"DIM08",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 8",descWidth:500,width:500},
	{name:"DIM09",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 9",descWidth:500,width:500},
	{name:"DIM10",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 10",descWidth:500,width:500},
	{name:"DIM11",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 11",descWidth:500,width:500},
	{name:"DIM12",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 12",descWidth:500,width:500},
	{name:"DIM13",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 13",descWidth:500,width:500},
	{name:"DIM14",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 14",descWidth:500,width:500},
	{name:"DIM15",type:"devices-list",required:false,filter:["virtual"],desc:"Диммер 15",descWidth:500,width:500},
  ]
}
*/

u8 i=0;
u8 k=0;
u8 chek[16];

void OFFAUTO()
{
	#ifdef DIM00 setAutoState(DIM00, TIME00); #endif
	#ifdef DIM01 setAutoState(DIM01, TIME00); #endif
	#ifdef DIM02 setAutoState(DIM02, TIME00); #endif
	#ifdef DIM03 setAutoState(DIM03, TIME00); #endif
	#ifdef DIM04 setAutoState(DIM04, TIME00); #endif
	#ifdef DIM05 setAutoState(DIM05, TIME00); #endif
	#ifdef DIM06 setAutoState(DIM06, TIME00); #endif
	#ifdef DIM07 setAutoState(DIM07, TIME00); #endif
	#ifdef DIM08 setAutoState(DIM08, TIME00); #endif
	#ifdef DIM09 setAutoState(DIM09, TIME00); #endif
	#ifdef DIM10 setAutoState(DIM10, TIME00); #endif
	#ifdef DIM11 setAutoState(DIM11, TIME00); #endif
	#ifdef DIM12 setAutoState(DIM12, TIME00); #endif
	#ifdef DIM13 setAutoState(DIM13, TIME00); #endif
	#ifdef DIM14 setAutoState(DIM14, TIME00); #endif
	#ifdef DIM15 setAutoState(DIM15, TIME00); #endif
}

void ONAUTO()
{
	#ifdef DIM00 setAutoState(DIM00, 0); #endif
	#ifdef DIM01 setAutoState(DIM01, 0); #endif
	#ifdef DIM02 setAutoState(DIM02, 0); #endif
	#ifdef DIM03 setAutoState(DIM03, 0); #endif
	#ifdef DIM04 setAutoState(DIM04, 0); #endif
	#ifdef DIM05 setAutoState(DIM05, 0); #endif
	#ifdef DIM06 setAutoState(DIM06, 0); #endif
	#ifdef DIM07 setAutoState(DIM07, 0); #endif
	#ifdef DIM08 setAutoState(DIM08, 0); #endif
	#ifdef DIM09 setAutoState(DIM09, 0); #endif
	#ifdef DIM10 setAutoState(DIM10, 0); #endif
	#ifdef DIM11 setAutoState(DIM11, 0); #endif
	#ifdef DIM12 setAutoState(DIM12, 0); #endif
	#ifdef DIM13 setAutoState(DIM13, 0); #endif
	#ifdef DIM14 setAutoState(DIM14, 0); #endif
	#ifdef DIM15 setAutoState(DIM15, 0); #endif
}

void CLEAR()
{
	u8 z;
	for(z=0; z==15; z=z+1)
	{
		chek[z]=0;
	}
}

void UP()
{
	if (k==0)
	{
		i=0;
		k=1;
		CLEAR();
		#ifdef DIM00 if ([DIM00.0]==0) {setStatus(DIM00, {1, 0, 5}); chek[0]=1;} #endif
		#ifdef DIM01 if ([DIM01.0]==0) {setStatus(DIM01, {1, 0, 5}); chek[1]=1;} #endif
		#ifdef DIM02 if ([DIM02.0]==0) {setStatus(DIM02, {1, 0, 5}); chek[2]=1;} #endif
		#ifdef DIM03 if ([DIM03.0]==0) {setStatus(DIM03, {1, 0, 5}); chek[3]=1;} #endif
		#ifdef DIM04 if ([DIM04.0]==0) {setStatus(DIM04, {1, 0, 5}); chek[4]=1;} #endif
		#ifdef DIM05 if ([DIM05.0]==0) {setStatus(DIM05, {1, 0, 5}); chek[5]=1;} #endif
		#ifdef DIM06 if ([DIM06.0]==0) {setStatus(DIM06, {1, 0, 5}); chek[6]=1;} #endif
		#ifdef DIM07 if ([DIM07.0]==0) {setStatus(DIM07, {1, 0, 5}); chek[7]=1;} #endif
		#ifdef DIM08 if ([DIM08.0]==0) {setStatus(DIM08, {1, 0, 5}); chek[8]=1;} #endif
		#ifdef DIM09 if ([DIM09.0]==0) {setStatus(DIM09, {1, 0, 5}); chek[9]=1;} #endif
		#ifdef DIM10 if ([DIM10.0]==0) {setStatus(DIM10, {1, 0, 5}); chek[10]=1;} #endif
		#ifdef DIM11 if ([DIM11.0]==0) {setStatus(DIM11, {1, 0, 5}); chek[11]=1;} #endif
		#ifdef DIM12 if ([DIM12.0]==0) {setStatus(DIM12, {1, 0, 5}); chek[12]=1;} #endif
		#ifdef DIM13 if ([DIM13.0]==0) {setStatus(DIM13, {1, 0, 5}); chek[13]=1;} #endif
		#ifdef DIM14 if ([DIM14.0]==0) {setStatus(DIM14, {1, 0, 5}); chek[14]=1;} #endif
		#ifdef DIM15 if ([DIM15.0]==0) {setStatus(DIM15, {1, 0, 5}); chek[15]=1;} #endif
	} else
	{
		i=i+5;
		if (i>=250) {cancelDelayedCall(UP); i=250; setStatus(V-ADDR, 0);}
		#ifdef DIM00 if (chek[0]==1) {setStatus(DIM00, {1, i, 5}); chek[0]=1;} #endif
		#ifdef DIM01 if (chek[1]==1) {setStatus(DIM01, {1, i, 5}); chek[1]=1;} #endif
		#ifdef DIM02 if (chek[2]==1) {setStatus(DIM02, {1, i, 5}); chek[2]=1;} #endif
		#ifdef DIM03 if (chek[3]==1) {setStatus(DIM03, {1, i, 5}); chek[3]=1;} #endif
		#ifdef DIM04 if (chek[4]==1) {setStatus(DIM04, {1, i, 5}); chek[4]=1;} #endif
		#ifdef DIM05 if (chek[5]==1) {setStatus(DIM05, {1, i, 5}); chek[5]=1;} #endif
		#ifdef DIM06 if (chek[6]==1) {setStatus(DIM06, {1, i, 5}); chek[6]=1;} #endif
		#ifdef DIM07 if (chek[7]==1) {setStatus(DIM07, {1, i, 5}); chek[7]=1;} #endif
		#ifdef DIM08 if (chek[8]==1) {setStatus(DIM08, {1, i, 5}); chek[8]=1;} #endif
		#ifdef DIM09 if (chek[9]==1) {setStatus(DIM09, {1, i, 5}); chek[9]=1;} #endif
		#ifdef DIM10 if (chek[10]==1) {setStatus(DIM10, {1, i, 5}); chek[10]=1;} #endif
		#ifdef DIM11 if (chek[11]==1) {setStatus(DIM11, {1, i, 5}); chek[11]=1;} #endif
		#ifdef DIM12 if (chek[12]==1) {setStatus(DIM12, {1, i, 5}); chek[12]=1;} #endif
		#ifdef DIM13 if (chek[13]==1) {setStatus(DIM13, {1, i, 5}); chek[13]=1;} #endif
		#ifdef DIM14 if (chek[14]==1) {setStatus(DIM14, {1, i, 5}); chek[14]=1;} #endif
		#ifdef DIM15 if (chek[15]==1) {setStatus(DIM15, {1, i, 5}); chek[15]=1;} #endif
	}


}

V-ID/V-ADDR
{
	if (opt(0)==1) {OFFAUTO(); delayedCallR(UP, 12); k=0;}
	else {cancelDelayedCall(UP); ONAUTO();}
}

//Удалить если диммер не виртуальный

#ifdef DIM00
u8 state [] = {0,0};
V-ID/DIM00{
    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM00,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM00,state);
    }
}
#endif

#ifdef DIM01
V-ID/DIM01{
	
    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM01,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM01,state);
    }
}
#endif

#ifdef DIM02

V-ID/DIM02{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM02,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM02,state);
    }
}
#endif

#ifdef DIM03

V-ID/DIM03{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM03,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM03,state);
    }
}
#endif

#ifdef DIM04

V-ID/DIM04{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM04,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM04,state);
    }
}
#endif

#ifdef DIM05

V-ID/DIM05{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM05,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM05,state);
    }
}
#endif

#ifdef DIM06

V-ID/DIM06{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM06,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM06,state);
    }
}
#endif

#ifdef DIM07

V-ID/DIM07{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM07,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM07,state);
    }
}
#endif

#ifdef DIM08

V-ID/DIM08{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM08,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM08,state);
    }
}
#endif

#ifdef DIM09

V-ID/DIM09{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM09,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM09,state);
    }
}
#endif

#ifdef DIM10

V-ID/DIM10{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM10,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM10,state);
    }
}
#endif

#ifdef DIM11

V-ID/DIM11{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM11,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM11,state);
    }
}
#endif

#ifdef DIM12

V-ID/DIM12{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM12,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM12,state);
    }
}
#endif

#ifdef DIM13

V-ID/DIM13{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM13,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM13,state);
    }
}
#endif

#ifdef DIM14

V-ID/DIM14{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM14,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM14,state);
    }
}
#endif

#ifdef DIM15

V-ID/DIM15{

    if (opt(0)==0xff){
        state[0] = state[0] ? 0:1;
        setStatus(DIM15,state);
    }
    else if (opt(0)==0xfe){
        state[1] = opt(1);
        setStatus(DIM15,state);
    }
}
#endif