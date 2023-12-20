/*
{
	desc:"Фрамуга по CO2",
	tag:"item",
	selectArea:true,
	vars:[
		{type:"comment",text:"Не будь дураком! Не ставь уровень открытия меньше уровня закрытия!!!",width:888, style:"color:red;"},
		{name:"TRASHLVL",type:"number",required:false,min:300,max:2000,defaultValue:1000,desc:"Уровень PPM открытия",descWidth:340,width:100},
		{name:"GOODLVL",type:"number",required:false,min:300,max:2000,defaultValue:1000,desc:"Уровень PPM закрытия",descWidth:340,width:100},
		{name:"FRAMYGA",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Фрамуга",descWidth:100},
		{name:"SENSOR",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
		]
}
*/

void onInit(){
	setStatus(V-ADDR, 1);
}

V-ID/s:1{
	u16 CO2LVL =(([SENSOR.0]*100/255)+([SENSOR.1]*100));
	if(CO2LVL>=(TRASHLVL)){
		if(([FRAMYGA.0]&7)==0) setStatus(FRAMYGA, 1);
	} else if(CO2LVL<=GOODLVL){
		if(([FRAMYGA.0]&7)==1) setStatus(FRAMYGA, 0);
	}
}