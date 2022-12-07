/*
{
	desc:"Клапан из RHX",
	tag:"import-script",
	selectArea:true,
	
	vars:[
	{name:"TIME",type:"number",required:true,defaultValue:25,min:1,max:75,desc:"Время открытия-закрытия клапана",descWidth:350},
	{name:"K00",type:"devices-list",required:false,width:600,filter:["valve"],desc:"Клапан 0",descWidth:100},
	{name:"L00",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Откр 0",descWidth:100},
	{name:"L01",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Закр 0",descWidth:100},
	]
}
*/

void OFF()
{
	if( ([L00.0]&1)==1 ) setStatus(L00, 0);
	if( ([L01.0]&1)==1 ) setStatus(L01, 0);
}

V-ID/K00
{
	cancelDelayedCall(OFF);
	if( (opt(0)&1)==0 ) {setStatus(L01, 0); setStatus(L00, 1); delayedCall(OFF, TIME);} else
	if( (opt(0)&1)==1 ) {setStatus(L00, 0); setStatus(L01, 1); delayedCall(OFF, TIME);}
}
