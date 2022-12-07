/*
{
	desc:"Вытяжка-свет",
	tag:"item",
	selectArea:true,
	
	vars:[
{name:"V0",type:"devices-list",required:true,width:900,filter:["lamp"],desc:"Вытяжка",descWidth:100},
{name:"L0",type:"devices-list",required:true,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"L1",type:"devices-list",required:false,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"L2",type:"devices-list",required:false,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"L3",type:"devices-list",required:false,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"L4",type:"devices-list",required:false,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"T0", type:"number", defaultValue:1, min:1, max:30, required:true, desc:"Время до включения, мин"},
{name:"T1", type:"number", defaultValue:10, min:1, max:30, required:true, desc:"Время до выключения мин"},
	]
}
*/

u8 i=0;
u16 k=0;

void onInit()
{
	setStatus(V-ADDR, 1);
}

void START()
{
	i=1;
	setStatus(V0, 1);
}

void STOP()
{
	setStatus(V0, 0);
}

V-ID/L0, #ifdef L1 L1, #endif #ifdef L2 L2, #endif #ifdef L3 L3, #endif#ifdef L4 L4 #endif
{
	if((opt(0)&1)==1 && ([V-ADDR.0]&1)==1)
	{
		cancelDelayedCall(STOP);
		delayedCallM(START, T0);
	} else if (
				( ([L0.0]&1)==0
				#ifdef L1 && ([L1.0]&1)==0 #endif
				#ifdef L2 && ([L2.0]&1)==0 #endif
				#ifdef L3 && ([L3.0]&1)==0 #endif
				#ifdef L4 && ([L4.0]&1)==0 #endif)
				&& ([V-ADDR.0]&1)==1
			)
	{
		cancelDelayedCall(START);
		if(([V0.0]&1)==1 && i==1) delayedCallM(STOP, T1);
	}
}

V-ID/m:1
{
	if ([V0.0]==1) ++k; else k=0;
	if (k>60 && [L0.0]==0) {setStatus(V0, 0); k=0;}
}
