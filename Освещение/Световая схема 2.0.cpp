/*
{
    desc:"Сценарий",
    tag:"item",
    name:"Сценарий",
    selectArea:true,
    vars:[
    {type:"comment",text:"Группы света, RGB, скрипты - выключить, закрыть",width:200, style:"color:red;"},
    {name:"U00",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U01",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U02",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U03",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U04",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U05",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U06",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U07",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U08",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U09",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U10",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U11",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U12",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U13",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U14",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U15",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},   
    ]
}
*/
const u16 ID[]={
    #ifdef U00 ADDR2ID(U00) #else, 0 #endif
    #ifdef U01, ADDR2ID(U01) #else, 0 #endif
    #ifdef U02, ADDR2ID(U02) #else, 0 #endif
    #ifdef U03, ADDR2ID(U03) #else, 0 #endif
    #ifdef U04, ADDR2ID(U04) #else, 0 #endif
    #ifdef U05, ADDR2ID(U05) #else, 0 #endif
    #ifdef U06, ADDR2ID(U06) #else, 0 #endif
    #ifdef U07, ADDR2ID(U07) #else, 0 #endif
    #ifdef U08, ADDR2ID(U08) #else, 0 #endif
    #ifdef U09, ADDR2ID(U09) #else, 0 #endif
    #ifdef U10, ADDR2ID(U10) #else, 0 #endif
    #ifdef U11, ADDR2ID(U11) #else, 0 #endif
    #ifdef U12, ADDR2ID(U12) #else, 0 #endif
    #ifdef U13, ADDR2ID(U13) #else, 0 #endif
    #ifdef U14, ADDR2ID(U14) #else, 0 #endif
    #ifdef U15, ADDR2ID(U15) #else, 0 #endif
};
const u8 SID[]={
    #ifdef U00 ADDR2SID(U00) #else, 0 #endif
    #ifdef U01, ADDR2SID(U01) #else, 0 #endif
    #ifdef U02, ADDR2SID(U02) #else, 0 #endif
    #ifdef U03, ADDR2SID(U03) #else, 0 #endif
    #ifdef U04, ADDR2SID(U04) #else, 0 #endif
    #ifdef U05, ADDR2SID(U05) #else, 0 #endif
    #ifdef U06, ADDR2SID(U06) #else, 0 #endif
    #ifdef U07, ADDR2SID(U07) #else, 0 #endif
    #ifdef U08, ADDR2SID(U08) #else, 0 #endif
    #ifdef U09, ADDR2SID(U09) #else, 0 #endif
    #ifdef U10, ADDR2SID(U10) #else, 0 #endif
    #ifdef U11, ADDR2SID(U11) #else, 0 #endif
    #ifdef U12, ADDR2SID(U12) #else, 0 #endif
    #ifdef U13, ADDR2SID(U13) #else, 0 #endif
    #ifdef U14, ADDR2SID(U14) #else, 0 #endif
    #ifdef U15, ADDR2SID(U15) #else, 0 #endif
};
u8 count=0;
u8 onoff=0; // Флаг что делать
u8 marker=0; // Флаг работы

void action(){
    if(ID[count]){
        setStatus(@ID[count]:@SID[count], onoff);
        ++count;
        delayedCallMs(action, 150);
    }
    else {marker=0;}
}

V-ID/V-ADDR
{
    if (([V-ADDR.0]&1)==1){
        cancelDelayedCall(action);
        delayedCallMs(action, 150);
        count=0;
        onoff=1;
        marker=1;
        #ifdef U00 setAutoState(U00, 0xfffe); #endif
        #ifdef U01 setAutoState(U01, 0xfffe); #endif
        #ifdef U02 setAutoState(U02, 0xfffe); #endif
        #ifdef U03 setAutoState(U03, 0xfffe); #endif
        #ifdef U04 setAutoState(U04, 0xfffe); #endif
        #ifdef U05 setAutoState(U05, 0xfffe); #endif
        #ifdef U06 setAutoState(U06, 0xfffe); #endif
        #ifdef U07 setAutoState(U07, 0xfffe); #endif
        #ifdef U08 setAutoState(U08, 0xfffe); #endif
        #ifdef U09 setAutoState(U09, 0xfffe); #endif
        #ifdef U10 setAutoState(U10, 0xfffe); #endif
        #ifdef U11 setAutoState(U11, 0xfffe); #endif
        #ifdef U12 setAutoState(U12, 0xfffe); #endif
        #ifdef U13 setAutoState(U13, 0xfffe); #endif
        #ifdef U14 setAutoState(U14, 0xfffe); #endif
        #ifdef U15 setAutoState(U15, 0xfffe); #endif
    }
    else if(([V-ADDR.0]&1)==0){
        if(senderSubId()!=exciterSubId() ){
            cancelDelayedCall(action);
            delayedCallMs(action, 150);
            count=0;
            onoff=0;
            marker=1;
        }
        #ifdef U00 setAutoState(U00, 15); #endif
        #ifdef U01 setAutoState(U01, 15); #endif
        #ifdef U02 setAutoState(U02, 15); #endif
        #ifdef U03 setAutoState(U03, 15); #endif
        #ifdef U04 setAutoState(U04, 15); #endif
        #ifdef U05 setAutoState(U05, 15); #endif
        #ifdef U06 setAutoState(U06, 15); #endif
        #ifdef U07 setAutoState(U07, 15); #endif
        #ifdef U08 setAutoState(U08, 15); #endif
        #ifdef U09 setAutoState(U09, 15); #endif
        #ifdef U10 setAutoState(U10, 15); #endif
        #ifdef U11 setAutoState(U11, 15); #endif
        #ifdef U12 setAutoState(U12, 15); #endif
        #ifdef U13 setAutoState(U13, 15); #endif
        #ifdef U14 setAutoState(U14, 15); #endif
        #ifdef U15 setAutoState(U15, 15); #endif
    }
}


V-ID/s:1{
    if(
        (#ifdef U00 ([U00.0]&1)==0 #endif
        #ifdef U01 || ([U01.0]&1)==0 #endif
        #ifdef U02 || ([U02.0]&1)==0 #endif
        #ifdef U03 || ([U03.0]&1)==0 #endif
        #ifdef U04 || ([U04.0]&1)==0 #endif
        #ifdef U05 || ([U05.0]&1)==0 #endif
        #ifdef U06 || ([U06.0]&1)==0 #endif
        #ifdef U07 || ([U07.0]&1)==0 #endif
        #ifdef U08 || ([U08.0]&1)==0 #endif
        #ifdef U09 || ([U09.0]&1)==0 #endif
        #ifdef U10 || ([U10.0]&1)==0 #endif
        #ifdef U11 || ([U11.0]&1)==0 #endif
        #ifdef U12 || ([U12.0]&1)==0 #endif
        #ifdef U13 || ([U13.0]&1)==0 #endif
        #ifdef U14 || ([U14.0]&1)==0 #endif
        #ifdef U15 || ([U15.0]&1)==0 #endif)
        && marker==0
    ) setStatus(V-ADDR, 0);
}