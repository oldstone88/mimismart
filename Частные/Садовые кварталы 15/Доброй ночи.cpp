/*
{
  desc:"Доброй ночи",
  tag:"item",
  selectArea:true,
  name:"Доброй ночи",
  vars:[
{name:"D0",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 0"},
{name:"D1",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 1"},
{name:"D2",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 2"},
{name:"D3",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 3"},
{name:"D4",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 4"},
{name:"L0",type:"devices-list",required:false, filter:["lamp"],desc:"Свет 0"},
{name:"L1",type:"devices-list",required:false, filter:["lamp"],desc:"Свет 1"},
{name:"L2",type:"devices-list",required:false, filter:["lamp"],desc:"Свет 2"},
{name:"L3",type:"devices-list",required:false, filter:["lamp"],desc:"Свет 3"},
{name:"L4",type:"devices-list",required:false, filter:["lamp"],desc:"Свет 4"},
{name:"JAL00",type:"devices-list",required:false,filter:["virtual"],desc:"Штора 0",descWidth:500,width:500},
{name:"JAL01",type:"devices-list",required:false,filter:["virtual"],desc:"Штора 1",descWidth:500,width:500},
{name:"JAL02",type:"devices-list",required:false,filter:["virtual"],desc:"Штора 2",descWidth:500,width:500},
  ]                       
}
*/

u8 k=0;

void zatuhanie()
{
	u8 i=0;
	#ifdef D0 if(([D0.0]&1)==1) {i=[D0.0]; if(i>0) --i; setStatus(D0, {1, i, 0}); } #endif
	#ifdef D1 if(([D1.0]&1)==1) {i=[D1.0]; if(i>0) --i; setStatus(D1, {1, i, 0}); } #endif
	#ifdef D2 if(([D2.0]&1)==1) {i=[D2.0]; if(i>0) --i; setStatus(D2, {1, i, 0}); } #endif
	#ifdef D3 if(([D3.0]&1)==1) {i=[D3.0]; if(i>0) --i; setStatus(D3, {1, i, 0}); } #endif
	#ifdef D4 if(([D4.0]&1)==1) {i=[D4.0]; if(i>0) --i; setStatus(D4, {1, i, 0}); } #endif
	++k;
	if (k==250) {cancelDelayedCall(zatuhanie); k=0;
		#ifdef D0 setStatus(D0, 0); #endif
		#ifdef D1 setStatus(D1, 0); #endif
		#ifdef D2 setStatus(D2, 0); #endif
		#ifdef D3 setStatus(D3, 0); #endif
		#ifdef D4 setStatus(D4, 0); #endif
		#ifdef L0 setStatus(L0, 0); #endif
		#ifdef L1 setStatus(L1, 0); #endif
		#ifdef L2 setStatus(L2, 0); #endif
		#ifdef L3 setStatus(L3, 0); #endif
		#ifdef L4 setStatus(L4, 0); #endif}
}

V-ID/V-ADDR
{
	if( (opt(0)&1)==1 )
		{
			k=0;
			delayedCallMsR(zatuhanie, 120);
			#ifdef JAL00 if( ([JAL00.0]&7)!=0 ) {setStatus(JAL00, 0);} #endif
	    #ifdef JAL01 if( ([JAL01.0]&7)!=0 ) {setStatus(JAL01, 0);} #endif
	    #ifdef JAL02 if( ([JAL02.0]&7)!=0 ) {setStatus(JAL02, 0);} #endif
		}
		else
	if( (opt(0)&1)==0 )
	{
		cancelDelayedCall(zatuhanie);
	}
}