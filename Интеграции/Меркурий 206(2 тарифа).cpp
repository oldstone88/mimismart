/*
{
  desc:"Mercury 206RN (настройки RS485: 9600, stop 1, no parity)",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME01", "sub-id":"%SUBID01%", type:"virtual", "sub-type":"long-text", length:"0"},
    {tag:"item", id:"%TARGET%", name:"NAME02", "sub-id":"%SUBID02%", type:"virtual", "sub-type":"long-text", length:"0"},
    {tag:"item", id:"%TARGET%", name:"NAME03", "sub-id":"%SUBID03%", type:"virtual", "sub-type":"long-text", length:"0"},
    {tag:"item", id:"%TARGET%", name:"NAME04", "sub-id":"%SUBID04%", type:"virtual", "sub-type":"long-text", length:"0"}
  ],
  vars:[
   	{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
	[
		{name:"CNTID01",type:"string",required:true,requiredItem:1,min:6,max:12,filter:"0123456789",desc:"Серийный номер счетчика 1",defaultValue:"12120873",descAlign:"top"},
		{name:"NAME01",type:"string",required:true,min:1,max:30,desc:"Имя счетчика",defaultValue:"Счетчик электроэнергии",descAlign:"top"}
	],
	[
		{name:"CNTID02",type:"string",required:false,requiredItem:2,min:6,max:12,filter:"0123456789",desc:"Серийный номер счетчика 2",descAlign:"top"},
		{name:"NAME02",type:"string",required:false,min:1,max:30,desc:"Имя счетчика",descAlign:"top"}
	],
	[
		{name:"CNTID03",type:"string",required:false,requiredItem:3,min:6,max:12,filter:"0123456789",desc:"Серийный номер счетчика 3",descAlign:"top"},
		{name:"NAME03",type:"string",required:false,min:1,max:30,desc:"Имя счетчика",descAlign:"top"}
	],
	[
		{name:"CNTID04",type:"string",required:false,requiredItem:4,min:6,max:12,filter:"0123456789",desc:"Серийный номер счетчика 4",descAlign:"top"},
		{name:"NAME04",type:"string",required:false,min:1,max:30,desc:"Имя счетчика",descAlign:"top"}
	],
    {name:"CNTSID01",type:"hidden",value:"%SUBID01%"},
    {name:"CNTSID02",type:"hidden",value:"%SUBID02%"},
    {name:"CNTSID03",type:"hidden",value:"%SUBID03%"},
    {name:"CNTSID04",type:"hidden",value:"%SUBID04%"},
    {name:"name",type:"hidden",value:"скрипт счетчика меркурий"}
  ]                       
}
*/
u32 cntids[] = {CNTID01
#ifdef CNTID02
,CNTID02
#endif
#ifdef CNTID03
,CNTID03
#endif
#ifdef CNTID04
,CNTID04
#endif
};

u8 vrt[]={CNTSID01
#ifdef CNTSID02
,CNTSID02
#endif
#ifdef CNTSID03
,CNTSID03
#endif
#ifdef CNTSID04
,CNTSID04
#endif
};
u32 res[20];
u8 fnlist[] = {0x63,0x81,0x27};
u8 cur = 0;
u8 fn = 0;
u8 active[5]={1,1,1,1,1};
u8 textpok[100];
u8 text[200];
u8 texttemp[2];
u16 itog=0;


V-ID/s:10 {
    for (u8 i=0;i<(sizeof(cntids)/4);++i) {
        if (!active[i]) {
		setStatus(:@vrt[i], "No answer");
        } else active[i] = 0; 
    }
}

V-ID/ms:500 {
	u8 data[7];
	u32 ad;
	u8 idx;
               
	if (fn>=sizeof(fnlist)) {
		fn = 0;
		idx = cur*5;
		sprintf(text, &textpok);
		sprintf(text+strlen(text), "ИТОГО: %d кВт.ч\10", itog);
		sprintf(text+strlen(text), "Напряжение: %d.%d В\10", res[idx]/10, res[idx]%10);
		sprintf(text+strlen(text), "Мощность: %d Вт\10", res[idx+2]);
		sprintf(text+strlen(text), "Частота: %d.%02d Гц", res[idx+3]/100, res[idx+3]%100);
		if (active[cur]) setStatus(:@vrt[cur], text);
		++cur;
		if (cur>=(sizeof(cntids)/4)) cur=0;
	}


	ad = cntids[cur];
	data[0] = ad>>24;
	data[1] = ad>>16;
	data[2] = ad>>8;
	data[3] = ad;

	data[4] = fnlist[fn];
	data[5] = 0xCC;
	data[6] = 0x16;
	setStatus(RS485, data);
	++fn;
}

u16 getint(u8 h, u8 l) {
 	return (h>>4)*1000 + (h&0x0f)*100 + (l>>4)*10 + (l&0x0f); 
}

void transform(u8 k1, u8 k2, u8 k3)
{
	sprintf(texttemp, "%x", k1);
	u16 g1=atol(texttemp);
	for(u8 i=0; i<3; ++i){texttemp[i]="";}
	sprintf(texttemp, "%x", k2);
	u16 g2=atol(texttemp);
	for(u8 i=0; i<3; ++i){texttemp[i]="";}
	sprintf(texttemp, "%x", k3);
	u16 g3=atol(texttemp);
	for(u8 i=0; i<3; ++i){texttemp[i]="";}
	return (g1*10000)+(g2*100)+g3;
}

V-ID/RS485 {
	u32 ad;
	u32 vl;
	u8 f;
	u8 idx;

	ad = opt(0)<<24 | opt(1)<<16 | opt(2)<<8 | opt(3);
	idx = 0xFF;
	for (u8 i=0;i<(sizeof(cntids)/4);++i) {
		if (ad==cntids[i]) {
		    idx = i*5;
		    active[i] = 1;
		}
	}
	if (idx == 0xFF) return;
	f = opt(4);
	if (f==fnlist[0]) {
		res[idx] = getint(opt(5), opt(6));
		res[idx+1] = getint(opt(7), opt(8));
		res[idx+2] = getint(opt(10), opt(11));
	} else if (f==fnlist[1]) {
		res[idx+3] = getint(opt(5), opt(6));
	} else if (f==fnlist[2]) {
		sprintf(textpok, "Тариф 1: %x%02x%02x,%x\10", opt(5), opt(6), opt(7), opt(8));
		sprintf(textpok+strlen(textpok), "Тариф 2: %x%02x%02x,%x\10", opt(9), opt(10), opt(11), opt(12));
		itog=transform(opt(5), opt(6), opt(7))+transform(opt(9), opt(10), opt(11));
	}
}


