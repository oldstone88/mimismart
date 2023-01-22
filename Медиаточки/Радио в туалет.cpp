/*
{
	desc:"Радио",
	tag:"item",
	selectArea:true,
	
	vars:[
{name:"M0",type:"devices-list",required:true,width:900,filter:["speaker"],desc:"Медиаточка",descWidth:100},
{name:"L0",type:"devices-list",required:true,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет утро",descWidth:100},
{name:"L1",type:"devices-list",required:false,width:900,filter:["lamp","dimer-lamp", "light-scheme"],desc:"Свет вечер",descWidth:100},
{name:"T0", type:"number", defaultValue:1, min:1, max:30, required:true, desc:"Время до включения, сек"},
	]
}
*/

void PAUSE()
{
	setStatus(M0, {1, 50, 0, "http://nashe1.hostingradio.ru:80/jazz-256"});
}

V-ID/V-ADDR
{
	if((opt(0)&1)==1)
	{
		delayedCall(PAUSE, 5);
	}
	else
	{
		cancelDelayedCall(PAUSE);
		setStatus(M0, 0);
	}
}

V-ID/s:5
{
	if( (([L0.0]&1)==0) #ifdef L01 && (([L1.0]&1)==0) #endif )
	{
		setStatus(V-ADDR, 0);
	}


}