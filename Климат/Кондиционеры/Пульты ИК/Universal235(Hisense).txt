/*
{
	desc:"Скрипт к пульту Hisense",
	tag:"import-script",
	target:"IRT",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "vane-hor":"0x00", "vane-ver":"0x41"},
	],
	vars:[
		{name:"IRT", type:"devices-list", required:true, filter:["ir-transmitter"], desc:"ИК-передатчик"},
		{name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер"},
		{name:"Cond",type:"hidden",value:"%TARGET%:%SUBID%"}
	]
}
*/

// time 14:10-14:20
// temp - 27 f0        18 = 0, temp++
// modes - 27 0f
// 1 - auto
// 2 - cool
// 3 - dry
// 4 - fan
// 0 - heat
// fans - 26 0f
// 0 - autofan
// 1 - fan3
// 2 - fan2
// 3 - fan1
// vane - 26 = 0x80, 46 = 0x40
// off - 26 0f + 4

// 67  & 72 swing=07 onoff=01, 67=72

// cool:
// 	mas[51] = temps[opt(1)]<<4 | (modes[opt(0)>>4]+fans[opt(4)]+2)
// dry:
// 	fan only 1
// 	temp only 25
// 	mas[51] = 0x45
// fan:
// 	fan only 1-3
// 	temp only 25
// 	mas[51] = 
// 				if fan=1 then 0x43
// 				if fan=2 then 0x40
// 				if fan=3 then 0x41
// heat:
// 	mas[51] = temps[opt(1)]<<4 | modes[opt(0)>>4] + 
// 													if fan=1 then 7
// 													if fan=2 then 4
// 													if fan=3 then 5
// 													if fan=0 then 6
const u8 temps [] = {3,2,1,0,7,6,5,4,11,10,9,8,15};
const u8 fans  [] = {0,3,2,1};
const u8 modes [] = {4,2,3,0,1};

u8 OldState [] = {0,0,0};



void Send(){
	cancelDelayedCall(Send);
	u8 mas [] = {[Cond.0],[Cond.1],[Cond.2],[Cond.3],[Cond.4]};
	mas[3] = mas[3] ? 0 : 1;
	setStatus(Cond,mas);
}

V-ID/Cond{
	if((opt(0)&1)!=OldState[2]){
		u8 off [] = {0x19640800020036060103FF00006E9D62141472033014B61183060473000000011B870101140000034014C711000000004C001A21000106870101140000033814D71100010000000001};
		setStatus(IRT,off);
		delayedCallMs(Send,200);
	}
	else{
		u8 mas [] = {0x19640800020031060103FF00006E9D62146271033014AE118306000000000001B8860101140000034014AB11000000006C001A000001C8860101140000033814C51100000000000000};
		//fan
		if((opt(0)>>4)==0) {					  
			u8 temp [] = {0x19640800020035060103FF00006E9D62140B72033014B811830600000000000129870101140000034014C311000000002C001A000001FC860101140000033814D61100020000000002};
			memcpy(mas,temp,73);
			mas[26] = opt(4)==0 ? fans[2] : fans[opt(4)];
			mas[27] = 0x74;
			if(opt(4)==2 | opt(4)==0)  	mas[51]=0x40;
			else if(opt(4)==1) 			mas[51]=0x41;
			else if(opt(4)==3) 			mas[51]=0x43;
	    	//vane
	    	if(opt(3)>>4){
				mas[26]+=0x80;
				mas[46]=0x40;
				mas[51]+=0x40;
			}
		}
		//cool
		if((opt(0)>>4)==1){
			u8 temp [] = {0x19640800020033060103FF00006E9D6214C971033014BB118306000000000001C4860101140000034014BB11000000002C001A000001CF860101140000033814D01100020000000002};
			memcpy(mas,temp,73);
	    	mas[26] = fans[opt(4)];
	    	mas[27] = (opt(1)<<4) | (modes[opt(0)>>4]);
	   //  	//on off
	   //  	if((opt(0)&1)!=OldState[2]){
				// //не учитываем жалюзи
	   //  		mas[26] += 4;
				// mas[51] = (temps[opt(1)]<<4) | fans[opt(4)];
	   //  	}
	    	//vane
	    	if(opt(3)>>4){
				mas[51] = ((15-opt(1))<<4) | (modes[opt(0)>>4]+fans[opt(4)]+2);
				mas[46] = 0x40;
				mas[26] |= 0x80;
	    	}
	    	else mas[51] = temps[opt(1)]<<4 | (modes[opt(0)>>4]+fans[opt(4)]+2);
		}
		//dry
		if((opt(0)>>4)==2){
			u8 temp [] = {0x1964080002003E060103FF00006E9D62141373033014CF118306,0x00,0x03,0x00000001C0870101140000034014DB11000500002C001A,0x30,0x0001DC870101140000033814E91100060000000006};
			memcpy(mas,temp,73);
			mas[51] = temps[opt(1)]<<4;
			mas[26] = fans[opt(4)];
			mas[27] = (opt(1)<<4) | (modes[opt(0)>>4]);
			mas[51] += modes[opt(0)>>4] + mas[26] -3;
			//vane
	    	if(opt(3)>>4){
				mas[26]+=0x80;
				mas[46]=0x40;
				mas[51]+=0x40;
			}
		}
		//heat
		if((opt(0)>>4)==3){
			u8 temp [] = {0x19640800020036060103FF00006E9D62142072033014C611830600000000000121870101140000034014C011000000002C001A0000010B870101140000033814D81100020000000002};
			memcpy(mas,temp,73);
			mas[26] = fans[opt(4)];
	    	mas[27] = (opt(1)<<4) | (modes[opt(0)>>4]);
	    	//vane
	    	if(opt(3)>>4){
				mas[51] = ((15-opt(1))<<4) | modes[opt(0)>>4];
				mas[46] = 0x40;
				mas[26] |= 0x80;
	    	}
	    	else mas[51] = (temps[opt(1)]<<4) | modes[opt(0)>>4];
	    	
	    		 if (opt(4)==1) mas[51] += 5;
			else if (opt(4)==2) mas[51] += 4;
			else if (opt(4)==3) mas[51] += 7;
			else if (opt(4)==0) mas[51] += 6;
	    	
		}
		
		if((opt(0)>>4)!=OldState[1])		mas[67] = mas[72] = 6;
		else if((opt(0)&1)!=OldState[2])	mas[67] = mas[72] = 1;
		else if (opt(3)>>4) 				mas[67] = mas[72] = 7;
		else 								mas[67] = mas[72] = 2;
		
		setStatus(IRT,mas);

		u8 str [150] = "";
		for(u8 i=0;i<73;++i)
			sprintf(str + strlen(str),"%02x", mas[i]);
		srvMessage("%s", str);
	}	
	OldState[0] = opt(1);
	OldState[1] = opt(0)>>4;
	OldState[2] = opt(0)&1;
}

void onInit(){
	OldState[0] = [Cond.1];
	OldState[1] = [Cond.0]>>4;
	OldState[2] = [Cond.0]&1;
}








