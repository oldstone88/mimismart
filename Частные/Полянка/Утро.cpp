/*
{
	desc:"Утро",
	tag:"item",
	selectArea:true,
	name:"Утро",

	vars:[
		{name:"SHADES",type:"devices-list",required:false,width:600,filter:["virtual"],descAlign:"top",desc:"Все шторы",descWidth:100},
		{name:"L00",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Люстра Детская",descWidth:100},
		{name:"L01",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Мастер Бра Справа",descWidth:100},
		{name:"L02",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Мастер Бра Слева",descWidth:100},
		{name:"L03",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Кухня Бра",descWidth:100},
		{name:"I00",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 00",descWidth:100},
		{name:"I01",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 01",descWidth:100},
		{name:"I02",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 02",descWidth:100},
		{name:"I03",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 03",descWidth:100},
		{name:"I04",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 04",descWidth:100},
		{name:"I05",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 05",descWidth:100},
		{name:"I06",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 06",descWidth:100},
		{name:"I07",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 07",descWidth:100},
		{name:"I08",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 08",descWidth:100},
		{name:"I09",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 09",descWidth:100},
		{name:"I10",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 10",descWidth:100},
		{name:"I11",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 11",descWidth:100},
		{name:"I12",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 12",descWidth:100},
		{name:"I13",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 13",descWidth:100},
		{name:"I14",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 14",descWidth:100},
		{name:"I15",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 15",descWidth:100},
		{name:"I16",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 16",descWidth:100},
		{name:"I17",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 17",descWidth:100},
		{name:"I18",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 18",descWidth:100},
		{name:"I19",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],descAlign:"top",desc:"Выключить 19",descWidth:100},
	]
}
*/

void OFF()
{
	setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
	if((opt(0)&1)==1)
	{
		setStatus(SHADES, 1);
		#ifdef L00 setStatus(L00, 1); #endif
		#ifdef L01 setStatus(L01, 1); #endif
		#ifdef L02 setStatus(L02, 1); #endif
		#ifdef L03 setStatus(L03, 1); #endif
		#ifdef I00 setStatus(I00, 0); #endif
		#ifdef I01 setStatus(I01, 0); #endif
		#ifdef I02 setStatus(I02, 0); #endif
		#ifdef I03 setStatus(I03, 0); #endif
		#ifdef I04 setStatus(I04, 0); #endif
		#ifdef I05 setStatus(I05, 0); #endif
		#ifdef I06 setStatus(I06, 0); #endif
		#ifdef I07 setStatus(I07, 0); #endif
		#ifdef I08 setStatus(I08, 0); #endif
		#ifdef I09 setStatus(I09, 0); #endif
		#ifdef I10 setStatus(I10, 0); #endif
		#ifdef I11 setStatus(I11, 0); #endif
		#ifdef I12 setStatus(I12, 0); #endif
		#ifdef I13 setStatus(I13, 0); #endif
		#ifdef I14 setStatus(I14, 0); #endif
		#ifdef I15 setStatus(I15, 0); #endif
		#ifdef I16 setStatus(I16, 0); #endif
		#ifdef I17 setStatus(I17, 0); #endif
		#ifdef I18 setStatus(I18, 0); #endif
		#ifdef I19 setStatus(I19, 0); #endif
		delayedCall(OFF, 1);
	}
}