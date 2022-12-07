/*
{
	desc:"Ламелии",
	tag:"item",
	selectArea:true,
	name:"Ламели",
	vars:[
	{name:"J0",type:"devices-list",required:true,width:1000,filter:["jalousie", "virtual"],desc:"Жалюзи",descWidth:100},
	{type:"comment",text:"Время прокрутки ламели"},
    {name:"TIME",type:"number",required:true,min:150, max:5000, defaultValue:1500},
	]
}
*/

u8 i=0;
u8 j=0;

void OFF()
{
	if(j==0)setStatus(J0, 0);
	j=0;
}

V-ID/V-ADDR
{
	if(([J0.0]&7)==1) {setStatus(J0, 0); i=0;}
	else
	if(([J0.0]&7)==0) {setStatus(J0, 1); i=1;}
	else
	if(([J0.0]&7)==4 || ([J0.0]&7)==5)
		{
			if(i==0){setStatus(J0, 1); i=1;}
			else if(i==1){setStatus(J0, 0); i=0;}
		}
	else {setStatus(J0, 0); j=1;}
	delayedCallMs(OFF, TIME);
}