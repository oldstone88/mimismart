/*
{
	desc:"Кино",
	tag:"item",
	selectArea:true,
	vars:[
		{name:"LIFT",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Лифт",descWidth:100},
		{name:"SCREEN",type:"devices-list",required:false,width:800,filter:["jalousie", "virtual"],desc:"Экран",descWidth:100},
		{name:"D00",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"D01",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L03",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L04",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"B00",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Штора",descWidth:100},
		]
}
*/

void razgoranie(){
	u8 bright=[D01.1];
	setStatus(D01, {1, bright+5, 1});
	if(bright<125) delayedCallMs(razgoranie, 250);
}

void zatuhanie(){
	u8 bright0=[D00.1];
	u8 bright1=[D01.1];
	if(bright0-5>0) setStatus(D00, {0xFE, bright0-5, 1});
	if(bright1-5>0) setStatus(D01, {0xFE, bright1-5, 1});
	if(([D00.1]<=5) && ([D01.1]<=5)){ setStatus(D00, {0, 0, 0}); setStatus(D01, {0, 0, 0});}
	else delayedCallMs(zatuhanie,250);
}

V-ID/V-ADDR{
	if((opt(0)&1)==1){
		zatuhanie();
		setStatus(LIFT, 1);
		setStatus(SCREEN, 1);
		setStatus(L00, 0);
		setStatus(L01, 0);
		setStatus(L02, 0);
		setStatus(L03, 0);
		setStatus(L04, 0);
		setStatus(B00, 0);
	} else if((opt(0)&1)==0){
		setStatus(LIFT, 0);
		setStatus(SCREEN, 0);
		razgoranie();
	}
}