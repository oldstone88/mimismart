/*
{
	desc:"Скрипт к пульту Electrolux YACIFBI",
	tag:"import-script",
	target:"IRT",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x41"},
	],
	vars:[
		{name:"IRT", type:"devices-list", required:true, filter:["ir-transmitter"], desc:"ИК-передатчик"},
		{name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер"},
		{name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
	]
}
*/

u8 onoff = 0;
u8 OldTemp = 0;
const u8 modes [] = {11,9,10,12,8};
const u8 ModeCRC [] = {7,5,6,8};

// u8 key= 0;
// void Reset(){
// 	cancelDelayedCall(Reset);
// 	key=1;
// 	setStatus(COND,{[COND.0],[COND.1],[COND.2],0,[COND.4]});
// }
// off 19640B0002008D060103FF000056986719DF6A03231999120102205002000281420101190000032019BE12004000100003257B0103FF000056986719DA6A03231991120102207002000274420101190000032019B312000000D0
V-ID/COND{
	// if(!key){
		u8 mas [] = {0x19640500020087060103FF00005A0000182A00032318001200002050020002F84101011A0000032018001200200000};
		u8 mode = modes[opt(0)>>4];
		u8 temp = opt(1);
		u8 fan = opt(4);
		u8 vane = opt(3)>>4;
		mas[18] = 0x6C;
		if(onoff!=(opt(0)&1)){
			onoff=opt(0)&1;
			fan += 4;
			mas[43] = 1;
			if(!onoff) mode -=8;
			mas[18] = onoff ? 0x6B : 0x6C;
		}
		else if(vane){
			fan += 4;
			mas[43] = 1;
		}
		mas[14] = onoff ? 0x98 : 0x99;
		mas[15] = onoff ? 0x67 : 0x66;
		
		mas[24] = (fan<<4) | (mode&0x0F);
		mas[25] = temp;

		mas[46] = (mode==8 ? 0x0D:(ModeCRC[opt(0)>>4]+temp)) << 4;

		//u8 str [150] = "";
		//for(u8 i=0;i<47;++i){
		//	sprintf(str + strlen(str),"%02x", mas[i]);
		//}
		u8 t=opt(0)&1;
		//srvMessage("%d", t);
		if(t==0) setStatus(IRT, 0x19640B0002008D060103FF000056986719DF6A03231999120102205002000281420101190000032019BE12004000100003257B0103FF000056986719DA6A03231991120102207002000274420101190000032019B312000000D0);
		else setStatus(IRT,mas);
		// if(vane)delayedCallMs(Reset,250);
		OldTemp = temp;
	// }
	// else key=0;
}

void onInit(){
	onoff = [COND.0]&1;
	OldTemp = [COND.1];
}