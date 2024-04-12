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
        {name:"MIN00",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 1",width:300},
        {name:"D00",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1"},
        {name:"MIN01",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 2",width:300},
        {name:"D01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 2"},
        {name:"MIN02",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 3",width:300},
        {name:"D02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 3"},
        {name:"MIN03",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 4",width:300},
        {name:"D03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 4"},
        {name:"MIN04",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 5",width:300},
        {name:"D04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 5"},
        {name:"MIN05",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 6",width:300},
        {name:"D05",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 6"},
        {name:"MIN06",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 7",width:300},
        {name:"D06",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 7"},
        {name:"MIN07",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 8",width:300},
        {name:"D07",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 8"},
        {name:"MIN08",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 9",width:300},
        {name:"D08",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 9"},
        {name:"MIN09",type:"number",required:true,filter:"1234567890",defaultValue:"10",min:0,max:250,desc:"Введите порог Диммера 10",width:300},
        {name:"D09",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 10"},
  ]
}
*/

u8 sdata[50];
u8 cvalue;
u8 dimmer_id;

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
const u16 MINVAL[]={
    #ifdef D00 MIN00 #else, 0 #endif
    #ifdef D01, MIN01 #else, 0 #endif
    #ifdef D02, MIN02 #else, 0 #endif
    #ifdef D03, MIN03 #else, 0 #endif
    #ifdef D04, MIN04 #else, 0 #endif
    #ifdef D05, MIN05 #else, 0 #endif
    #ifdef D06, MIN06 #else, 0 #endif
    #ifdef D07, MIN07 #else, 0 #endif
    #ifdef D08, MIN08 #else, 0 #endif
    #ifdef D09, MIN09 #else, 0 #endif
};

u8 search(u8* k, u8 n, u8 key)
{
  for (u8 i = 0; i < n; ++i)
  {
    if (k[i] == key)
    return i;
  }
}

V-ID/D00#ifdef D01, D01#endif#ifdef D02, D02#endif#ifdef D03, D03#endif#ifdef D04, D04#endif#ifdef D05, D05#endif#ifdef D06, D06#endif#ifdef D07, D07#endif#ifdef D08, D08#endif#ifdef D09, D09#endif
{
	dimmer_id = search(SID, 10, senderSubId());
	if(opt(0)&1){
		cvalue =  MINVAL[dimmer_id] + ((opt(1) * 10 / 25) * (250 - MINVAL[dimmer_id]) / 100);
		sprintf(sdata, {"IP|%d|%d"}, dimmer_id, cvalue);
		setStatus(1000:82, &sdata);
	} else {
		sprintf(sdata, {"IP|%d|0"}, dimmer_id);
		setStatus(1000:82, &sdata);
	}
}
