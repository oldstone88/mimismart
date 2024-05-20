/*
{
    desc:"Яркость диммеров по умолчанию",
    tag:"import-script",
    name:"Яркость диммеров по умолчанию",
    selectArea:true,
    vars:[
        {type:"comment",text:"Элементы должны идти строго по порядку!!!",width:200, style:"color:red;"},
        {type:"comment",text:"Уровень яркости по умолчанию:",width:200, style:"color:red;"},
        {name:"DEFBRIGHT",type:"number",required:true,defaultValue:163,min:0,max:250,desc:"Яркость",descWidth:350},
        {type:"comment",text:"Группы света, RGB, скрипты - выключить, закрыть",width:200, style:"color:red;"},
        {name:"U00",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U01",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U02",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U03",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U04",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U05",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U06",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U07",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U08",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U09",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U10",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U11",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U12",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U13",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U14",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U15",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U16",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U17",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U18",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U19",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U20",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U21",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U22",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U23",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U24",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U25",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U26",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U27",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U28",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
        {name:"U29",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
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
    #ifdef U16, ADDR2ID(U16) #else, 0 #endif
    #ifdef U17, ADDR2ID(U17) #else, 0 #endif
    #ifdef U18, ADDR2ID(U18) #else, 0 #endif
    #ifdef U19, ADDR2ID(U19) #else, 0 #endif
    #ifdef U20, ADDR2ID(U20) #else, 0 #endif
    #ifdef U21, ADDR2ID(U21) #else, 0 #endif
    #ifdef U22, ADDR2ID(U22) #else, 0 #endif
    #ifdef U23, ADDR2ID(U23) #else, 0 #endif
    #ifdef U24, ADDR2ID(U24) #else, 0 #endif
    #ifdef U25, ADDR2ID(U25) #else, 0 #endif
    #ifdef U26, ADDR2ID(U26) #else, 0 #endif
    #ifdef U27, ADDR2ID(U27) #else, 0 #endif
    #ifdef U28, ADDR2ID(U28) #else, 0 #endif
    #ifdef U29, ADDR2ID(U29) #else, 0 #endif
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
    #ifdef U16, ADDR2SID(U16) #else, 0 #endif
    #ifdef U17, ADDR2SID(U17) #else, 0 #endif
    #ifdef U18, ADDR2SID(U18) #else, 0 #endif
    #ifdef U19, ADDR2SID(U19) #else, 0 #endif
    #ifdef U20, ADDR2SID(U20) #else, 0 #endif
    #ifdef U21, ADDR2SID(U21) #else, 0 #endif
    #ifdef U22, ADDR2SID(U22) #else, 0 #endif
    #ifdef U23, ADDR2SID(U23) #else, 0 #endif
    #ifdef U24, ADDR2SID(U24) #else, 0 #endif
    #ifdef U25, ADDR2SID(U25) #else, 0 #endif
    #ifdef U26, ADDR2SID(U26) #else, 0 #endif
    #ifdef U27, ADDR2SID(U27) #else, 0 #endif
    #ifdef U28, ADDR2SID(U28) #else, 0 #endif
    #ifdef U29, ADDR2SID(U29) #else, 0 #endif
};
u8 count=0;

void defaultStat(){
    if(ID[count]){
        setStatus(@ID[count]:@SID[count], {0xFE, DEFBRIGHT, 0});
        ++count;
        delayedCallMs(defaultStat, 150);
    }
}

void onInit(){
    delayedCall(defaultStat, 1);
}