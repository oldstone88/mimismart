/*
{
	desc:"АвтоУборка",
	tag:"item",
	selectArea:true,
	name:"АвтоУборка",
	vars:[
{name:"K1",type:"devices-list",required:false,width:700,filter:["script"],desc:"Уборка 1",descWidth:100},
{name:"K2",type:"devices-list",required:false,width:700,filter:["script"],desc:"Уборка 2",descWidth:100},
{name:"K3",type:"devices-list",required:false,width:700,filter:["script"],desc:"Уборка 3",descWidth:100},
	]
}
*/

void onInit(){
	setStatus(V-ADDR, 1);
}

V-ID/s:11{
	u8 res = timeInRange(9:00-17:00);
	if( (([V-ADDR.0]&1)==1) && (res!=0) ){
		#ifdef K1 if(([K1.0]&1)==0) setStatus(K1, 1); #endif
		#ifdef K2 if(([K2.0]&1)==0) setStatus(K2, 1); #endif
		#ifdef K3 if(([K3.0]&1)==0) setStatus(K3, 1); #endif
	}
}