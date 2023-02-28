/*
{
  desc:"Штора 50",
  tag:"item",
  name:"Штора 50",
  selectArea:true,
  vars:[
  {name:"TIME",type:"number",required:true,min:100, max:30000},
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы",descWidth:300,width:500},
  ]
}
*/

void STOP()
{
  setStatus(BLINDS0, 1);
}

V-ID/V-ADDR
{
	if( ([BLINDS0.0]&7)==0 ) {setStatus(BLINDS0, 1); delayedCallMs(STOP, TIME);}
  else if( ([BLINDS0.0]&7)==1 ) {setStatus(BLINDS0, 0); delayedCallMs(STOP, TIME);}
}
