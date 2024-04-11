/*
{
  desc:"DALI",
  tag:"import-script",
  target:"ModBusTCP",
  name:"DaliToTCP",
  selectArea:true,
  vars:[
        {type:"comment",text:"Введите адрес шлюза EcoDim GW2"},
        {name:"IP",type:"string",required:true,filter:".1234567890",defaultValue:"192.168.1.99",min:7,max:15,desc:"IP",width:300},
        {type:"comment",text:"Выберите диммеры:"},
        {type:"comment",text:"Введите порог Диммера 1"},
        {name:"MIN00",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Значение",width:300},
        {name:"D00",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1"},
        {type:"comment",text:"Введите порог Диммера 2"},
        {name:"MIN01",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Значение",width:300},
        {name:"D01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 2"},
        {type:"comment",text:"Введите порог Диммера 3"},
        {name:"MIN02",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Значение",width:300},
        {name:"D02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 3"},
        {type:"comment",text:"Введите порог Диммера 4"},
        {name:"MIN03",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Значение",width:300},
        {name:"D03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 4"},
        {type:"comment",text:"Введите порог Диммера 5"},
        {name:"MIN04",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Значение",width:300},
        {name:"D04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 5"},
  ]
}
*/

u8 sdata[50];
u8 cvalue;

const u8 SID[]={
    #ifdef D00 ADDR2SID(D00) #else, 0 #endif
    #ifdef D01, ADDR2SID(D01) #else, 0 #endif
    #ifdef D02, ADDR2SID(D02) #else, 0 #endif
    #ifdef D03, ADDR2SID(D03) #else, 0 #endif
    #ifdef D04, ADDR2SID(D04) #else, 0 #endif
    #ifdef D05, ADDR2SID(D05) #else, 0 #endif
    #ifdef D06, ADDR2SID(D06) #else, 0 #endif
    #ifdef D07, ADDR2SID(D07) #else, 0 #endif
    #ifdef D08, ADDR2SID(D08) #else, 0 #endif
    #ifdef D09, ADDR2SID(D09) #else, 0 #endif
};

u8 search(u8* k, u8 n, u8 key)
{
  for (u8 i = 0; i < n; ++i)
  {
    if (k[i] == key)
    return i;
  }
}

V-ID/D00#ifdef D01, D01#endif#ifdef D02, D02#endif#ifdef D03, D03#endif#ifdef D04, D04#endif
{
	if([D00.0]&1){
		cvalue =  MIN00 + ((opt(1) * 10 / 25) * (250 - MIN00) / 100);
		sprintf(sdata, {"IP|%d|%d"}, search(SID, 10, senderSubId()), cvalue);
		setStatus(1000:82, &sdata);
	} else {
		sprintf(sdata, {"IP|%d|0"}, search(SID, 10, senderSubId()));
		setStatus(1000:82, &sdata);
	}
}
