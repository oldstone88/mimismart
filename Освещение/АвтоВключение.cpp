/*
{
  desc:"АвтоВключение",
  name:"АвтоВключение",
  tag:"item",
  selectArea:false,
  vars:[
	{name:"I00",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Включать 1"},
	{name:"I01",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Включать 2"},
	{name:"I02",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Включать 3"},
	]
}
*/

void autoOn(){
	if(([V-ADDR.0]&1)==1){
		#ifdef I00 setStatus(I00, 1); #endif
		#ifdef I01 setStatus(I01, 1); #endif
		#ifdef I02 setStatus(I02, 1); #endif
	}
}

void onInit(){
	setStatus(V-ADDR, 1);
	delayedCall(autoOn, 5);
}