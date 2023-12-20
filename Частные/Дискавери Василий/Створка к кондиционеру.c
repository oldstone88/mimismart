/*
{
	desc:"АвтоСтворки",
	tag:"import-script",
	selectArea:true,
	vars:[
		{type:"comment",text:"Не будь дураком! Не ставь уровень открытия меньше уровня закрытия!!!",width:888, style:"color:red;"},
		{name:"COND",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
		{name:"TIME",type:"number",required:false,min:0,max:1200,defaultValue:300,desc:"Время до закрытия",descWidth:340,width:100},
		{name:"IMPULS",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Открыть шкаф",descWidth:100},
		]
}
*/

void OFF(){
	setStatus(IMPULS, 0);
}

void ON(){
	setStatus(IMPULS, 1);
	delayedCall(OFF, 1);
}

V-ID/COND{
	if( ([COND.0]%2)==1 ){
		setStatus(IMPULS, 1);
		delayedCall(OFF, 1);
	} else if(([COND.0]%2)==0){
		delayedCall(ON, TIME);
	}
}
