/*
{
	desc:"Скрипт к пульту LG",
	tag:"import-script",
	target:"IRT",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "vane-hor":"0x00", "vane-ver":"0x41", "t-delta":"12", "t-min":"18"},
	],
	vars:[
		{name:"IRT", type:"devices-list", required:true, filter:["ir-transmitter"], desc:"ИК-передатчик"},
		{name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер"},
		{name:"Cond",type:"hidden",value:"%TARGET%:%SUBID%"}
	]
}
*/

const u8 fans [] = {10,0,4,2};
const u8 arr [] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
const u8 modes [] = {5,1,9,3,13};
u8 OldState = 0;
u8 key=0;

void onInit(){
	OldState = [Cond.0]&1;
}

u8 CRC(u8 mode,u8 fan,u8 temp){
	u8 index;
	
	//---------Auto------
	if (mode == 4){
			 if (fan == 0) index = 2;
		else if (fan == 1) index = 13;
		else if (fan == 2) index = 15;
		else if (fan == 3) index = 1;
		return arr[index];
	}
	//-------------------
	else if (mode == 0) index = 13; //Fan
	else if (mode == 1) index = 11; //Cool
	else if (mode == 2) index = 12; //Dry 
	else if (mode == 3) index = 15; //Heat
		 if (fan  == 0)	index += 5;
	else if (fan  == 2)	index += 2;
	else if (fan  == 3)	index += 4;

	index += temp;
	if(OldState!=([Cond.0]&1)) index -= 8;
	for (;index>15;) index -= 16;

	return arr[index];
}

void Reset(){
	key=1;
	u8 mas [] = {0,0,0,0,0};
	mas[0] = [Cond.0];
	mas[1] = [Cond.1];
	mas[4] = [Cond.4];
	setStatus(Cond,mas);
}

V-ID/Cond{
	if(!key){
		u8 mas [] = {0x19640200020095060103FF000044976814C35D031C1474101103A008};
		u8 mode	= opt(0) >> 4;
		u8 temp	= opt(1) & 15;
		u8 fan 	= opt(4) & 3;
		u8 vane =  opt(3) >> 4;

		if(vane){
			cancelDelayedCall(Reset);
			delayedCallMs(Reset,500);
			mas[25] = 8;
			mas[26] = 0;
			mas[27] = 8;
		}
		else if(opt(0)&1){
			mas[25] = modes[mode]<<4;
			mas[26] = (fans[fan] << 4) | ( mode==4 ? 4 : (arr[temp+3]&0x0F) );
			mas[27] = CRC(mode,fan,temp);
			if(OldState!=(opt(0)&1))mas[25] -= 0x10;
		}
		if(OldState!=(opt(0)&1)) OldState = opt(0)&1;

		setStatus(IRT,mas);
	}
	else key=0;
}
