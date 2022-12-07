/*
{
  desc:"Штора - 2 item",
  tag:"item",
  name:"Открыть",
  selectArea:true,
  addItems:[
		{tag:"item", id:"%TARGET%", name:"Закрыть", "sub-id":"%SUBID01%", "type":"script"},
	],
  vars:[
  {name:"CLOSE",type:"hidden",value:"%TARGET%:%SUBID01%"},
	{name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Шторы",descWidth:300,width:300},
  ]
}
*/

V-ID/V-ADDR
{
	if(([BLINDS0.0]&7)!=1) {setStatus(BLINDS0, 1);}
}

V-ID/CLOSE
{
	if(([BLINDS0.0]&7)!=0) {setStatus(BLINDS0, 0);}
}