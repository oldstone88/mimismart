/*
{
	desc:"Экран кинотеатра",
	tag:"item",
	name:"Экран",
	selectArea:true,
	vars:[
		{name:"SCREEN", type:"devices-list", required:false, filter:["script"], width:700, desc:"Экран"},
		{name:"JVCOn", type:"devices-list", required:false, filter:["script"], width:700, desc:"Проектор ВКЛ"},
		{name:"JVCOff", type:"devices-list", required:false, filter:["script"], width:700, desc:"Проектор ВЫКЛ"},
		{name:"DIMMER", type:"devices-list", required:false, filter:["dimer-lamp"], width:700, desc:"Диммер"},
		{name:"L00", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 1"},
		{name:"L01", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 2"},
		{name:"L02", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 3"},
		{name:"L03", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 4"},
		{name:"L04", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 5"},
		{name:"L05", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 6"},
		{name:"L06", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 7"},
		{name:"L07", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 8"},
		{name:"L08", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 9"},
		{name:"L09", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 10"},
		{name:"L10", type:"devices-list", required:false, filter:["lamp"], width:700, desc:"Лампа 11"},
		{name:"B00", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 1"},
		{name:"B01", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 2"},
		{name:"B02", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 3"},
		{name:"B03", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 4"},
		{name:"B04", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 5"},
		{name:"B05", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 6"},
		{name:"B06", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 7"},
		{name:"B07", type:"devices-list", required:false, filter:["virtual"], width:700, desc:"Шторы 8"},
	]
}
*/

void closeShades(){
	u8 breakpoint=0;
	#ifdef B00 if( (([B00.0]&7)==1 || ([B00.0]&7)==4) && breakpoint==0) { setStatus(B00, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B01 if( (([B01.0]&7)==1 || ([B01.0]&7)==4) && breakpoint==0) { setStatus(B01, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B02 if( (([B02.0]&7)==1 || ([B02.0]&7)==4) && breakpoint==0) { setStatus(B02, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B03 if( (([B03.0]&7)==1 || ([B03.0]&7)==4) && breakpoint==0) { setStatus(B03, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B04 if( (([B04.0]&7)==1 || ([B04.0]&7)==4) && breakpoint==0) { setStatus(B04, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B05 if( (([B05.0]&7)==1 || ([B05.0]&7)==4) && breakpoint==0) { setStatus(B05, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B06 if( (([B06.0]&7)==1 || ([B06.0]&7)==4) && breakpoint==0) { setStatus(B06, 0); delayedCall(closeShades, 1); breakpoint=1;} #endif
	#ifdef B07 if( (([B07.0]&7)==1 || ([B07.0]&7)==4) && breakpoint==0) { setStatus(B07, 0);} #endif
}

void zatuhanie(){
	if( ([DIMMER.0]&1)==1 ){
		u8 bright=[DIMMER.1];
		if( (bright-5)>5 && [V-ADDR.0]){
			bright-=5;
			setStatus(DIMMER, {1, bright, 1});
			delayedCallMs(zatuhanie, 200);
		}
		else setStatus(DIMMER, 0); 
	}
}

V-ID/V-ADDR{
	if( (opt(0)&1)==1 ){
		setStatus(SCREEN, 1);
		setStatus(JVCOn, 1);
		closeShades();
		#ifdef DIMMER zatuhanie(); #endif
		#ifdef L00 setStatus(L00, 0); #endif
		#ifdef L01 setStatus(L01, 0); #endif
		#ifdef L02 setStatus(L02, 0); #endif
		#ifdef L03 setStatus(L03, 0); #endif
		#ifdef L04 setStatus(L04, 0); #endif
		#ifdef L05 setStatus(L05, 0); #endif
		#ifdef L06 setStatus(L06, 0); #endif
		#ifdef L07 setStatus(L07, 0); #endif
		#ifdef L08 setStatus(L08, 0); #endif
		#ifdef L09 setStatus(L09, 0); #endif
		#ifdef L10 setStatus(L10, 0); #endif
	}
	else if( (opt(0)&1)==0 ){
		setStatus(SCREEN, 0);
		setStatus(JVCOff, 1);
		setStatus(DIMMER, {1, 100, 1});
	}
}