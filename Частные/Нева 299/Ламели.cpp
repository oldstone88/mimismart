/*
{
	desc:"Ламелии",
	tag:"item",
	selectArea:true,
	
	vars:[
	{name:"UP",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Открыть",descWidth:100},
	{name:"J0",type:"devices-list",required:true,width:1000,filter:["jalousie"],desc:"Жалюзи",descWidth:100},
	{name:"J1",type:"devices-list",required:false,width:1000,filter:["jalousie"],desc:"Жалюзи",descWidth:100},
	{type:"comment",text:"Время прокрутки ламели"},
    {name:"TIME",type:"number",required:true,min:150, max:5000, defaultValue:1500},
	]
}
*/

void OFF1()
{
	setStatus(J0, 1);
	#ifdef J1 setStatus(J1, 1); #endif
}

void OFF0()
{
	setStatus(J0, 0);
	#ifdef J1 setStatus(J1, 0); #endif
}

V-ID/V-ADDR
{
	setStatus(J0, 0); #ifdef J1 setStatus(J1, 0); #endif delayedCallMs(OFF1, TIME);
}

V-ID/UP
{
	setStatus(J0, 1); #ifdef J1 setStatus(J1, 1); #endif delayedCallMs(OFF1, TIME);
}