/*
{
	desc:"Камин",
	tag:"import-script",
	selectArea:true,
	
	vars:[
{name:"D0",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
{name:"ON",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"ON",descWidth:100},
{name:"OFF",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"OFF",descWidth:100},
{name:"C1",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Скорость 1",descWidth:100},
{name:"C2",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Скорость 2",descWidth:100},
{name:"C3",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Скорость 3",descWidth:100},
{name:"G1",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон 30",descWidth:100},
{name:"G2",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон 50",descWidth:100},
{name:"G3",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон 100",descWidth:100},
{name:"G4",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон ON/OFF",descWidth:100},
{name:"G5",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Топливо",descWidth:100},



	]
}
*/

u8 write=0;
u8 vkl=0;
u8 speed=0;

void impuls()
{
	if( ([ON.0]&1)==1 ) {setStatus(ON, 0);}
	if( ([OFF.0]&1)==1 ) {setStatus(OFF, 0);}
	if( ([C1.0]&1)==1 ) {setStatus(C1, 0);}
	if( ([C2.0]&1)==1 ) {setStatus(C2, 0);}
	if( ([C3.0]&1)==1 ) {setStatus(C3, 0);}
}

V-ID/D0
{
	if( (opt(0)&1)==1 && write==0)
	{
		if( vkl==1 ) {setStatus(ON, 1); vkl=0;}
		if( [D0.1]<=75 && speed!=1) {setStatus(C3, 0); setStatus(C2, 0); setStatus(C1, 1); speed=1;} else
		if( [D0.1]<=175 && [D0.1]>75 && speed!=2) {setStatus(C1, 0); setStatus(C3, 0); setStatus(C2, 1); speed=2;} else
		if( [D0.1]>175 && speed!=3) {setStatus(C1, 0); setStatus(C2, 0); setStatus(C3, 1); speed=3;}
		delayedCallMs(impuls, 500);
	} else
	if( (opt(0)&1)==0  && write==0)
	{
		if( vkl==0 ) {setStatus(OFF, 1); vkl=1;}
		delayedCallMs(impuls, 500);
	}
}


V-ID/s:10
{
	//0-ВКЛ 1-ВЫКЛ
	if([G4.0]==0 && vkl==1) {vkl=0; write=1; setStatus(D0, {1, 0xFE, 0});} else
	if([G4.0]==1 && vkl==0) {vkl=1; write=1; setStatus(D0, {0, 0xFE, 0});} else
	if([G1.0]==0 && speed!=1) {speed=1; write=1; setStatus(D0, {0xFE, 75, 0});} else
	if([G2.0]==0 && speed!=2) {speed=2; write=1; setStatus(D0, {0xFE, 125, 0});} else
	if([G3.0]==0 && speed!=3) {speed=3; write=1; setStatus(D0, {0xFE, 250, 0});} else
	if([G5.0]==0) {write=1; setStatus(D0, {0, 0xFE, 0}); setStatus(OFF, 1); delayedCallMs(impuls, 500);  setStatus(2047:32, {4, "В камине нет топлива"});} else
	write=0;
}
