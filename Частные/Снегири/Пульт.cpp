/*
{
	desc:"Скрипт к пульту Hisense",
	tag:"import-script",
	target:"IRT",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"Вверх", "sub-id":"%SUBID01%", type:"script"},
		{tag:"item", id:"%TARGET%", name:"Вниз", "sub-id":"%SUBID02%", type:"script"},
	],
	vars:[
		{name:"IRT", type:"devices-list", required:true, filter:["ir-transmitter"], desc:"ИК-передатчик"},
		{name:"UP",type:"hidden",value:"%TARGET%:%SUBID01%"},
		{name:"DOWN",type:"hidden",value:"%TARGET%:%SUBID02%"},
	]
}
*/

void OFF(){
	setStatus(V-ADDR, 0);
	setStatus(UP, 0);
	setStatus(DOWN, 0);
}

V-ID/V-ADDR{
	if((opt(0)&1)==1){
		u8 comand[4]={0xD0,0x81,0xDD,0x2E};
		setStatus(IRT, &comand);
		delayedCall(OFF, 1);
	}
}

V-ID/UP{
	if((opt(0)&1)==1){
	u8 comand[4]={0xD2,0x01,0xEE,0xC1};
	setStatus(IRT, &comand);
	delayedCall(OFF, 1);
	}
}

V-ID/DOWN{
	if((opt(0)&1)==1){
	u8 comand[4]={0xD1,0x01,0xCC,0x9E};
	setStatus(IRT, &comand);
	delayedCall(OFF, 1);
	}
}