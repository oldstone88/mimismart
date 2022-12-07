/*
{
  desc:"Штора - item",
  tag:"item",
  name:"Шторы",
  selectArea:true,
  vars:[
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы",descWidth:300,width:300},
  ]
}
*/

u8 i=0;

V-ID/V-ADDR
{
	if(([BLINDS0.0]&7)==0) {setStatus(BLINDS0, 1); i=1;}
	else
	if(([BLINDS0.0]&7)==1) {setStatus(BLINDS0, 0); i=0;}
	else
	if(([BLINDS0.0]&7)==2 || ([BLINDS0.0]&7)==3) setStatus(BLINDS0, 0);
	else
	if(([BLINDS0.0]&7)==4 || ([BLINDS0.0]&7)==5)
	{
		if(i==0) {setStatus(BLINDS0, 1); i=1;}
		else if(i==1) {setStatus(BLINDS0, 0); i=0;}
	}
}

