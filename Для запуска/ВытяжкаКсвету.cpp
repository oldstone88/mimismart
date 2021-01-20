/*
{
	desc:"Вытяжка-свет",
	tag:"import-script",
	selectArea:true,
	
	vars:[
{name:"V0",type:"devices-list",required:true,width:900,filter:["lamp"],desc:"Вытяжка",descWidth:100},
{name:"L0",type:"devices-list",required:true,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет ванной",descWidth:100},
{name:"T0", type:"number", defaultValue:1, min:1, max:30, required:true, desc:"Время до включения, мин"},
{name:"T1", type:"number", defaultValue:10, min:1, max:30, required:true, desc:"Время до выключенияб мин"},
	]
}
*/

u8 i=0;
u16 k=0;

void START()
{
	i=1;
	setStatus(V0, 1);
}

void STOP()
{
	setStatus(V0, 0);
}

V-ID/L0
{
	if((opt(0)&1)==1)
	{
		cancelDelayedCall(STOP);
		delayedCallM(START, T0);
	} else if ((opt(0)&1)==0)
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
