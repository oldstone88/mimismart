/*
{
	desc:"Клапан",
	tag:"import-script",
	selectArea:true,
	
	vars:[
{name:"K00",type:"devices-list",required:false,width:600,filter:["valve"],desc:"Клапан 0",descWidth:100},
{name:"L00",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Откр 0",descWidth:100},
{name:"L01",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Закр 0",descWidth:100},
{name:"K10",type:"devices-list",required:false,width:600,filter:["valve"],desc:"Клапан 1",descWidth:100},
{name:"L10",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Откр 1",descWidth:100},
{name:"L11",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Закр 1",descWidth:100},
	]
}
*/

void OFF()
{
	if( ([L00.0]&1)==1 ) setStatus(L00, 0);
	if( ([L01.0]&1)==1 ) setStatus(L01, 0);
	if( ([L10.0]&1)==1 ) setStatus(L10, 0);
	if( ([L11.0]&1)==1 ) setStatus(L11, 0);
}

V-ID/K00
{
	if( (opt(0)&1)==0 ) {setStatus(L00, 1); delayedCall(OFF, 1);} else
	if( (opt(0)&1)==1 ) {setStatus(L01, 1); delayedCall(OFF, 1);}
}

V-ID/K10
{
	if( (opt(0)&1)==0 ) {setStatus(L10, 1); delayedCall(OFF, 1);} else
	if( (opt(0)&1)==1 ) {setStatus(L11, 1); delayedCall(OFF, 1);}
}