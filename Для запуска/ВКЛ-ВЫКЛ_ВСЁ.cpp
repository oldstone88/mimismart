/*
{
    desc:"Выкл. весь cвет",
    tag:"item",
    name:"Выкл. весь свет",
    selectArea:true,
    vars:[
    {type:"comment",text:"Автоматизации",width:200, style:"color:red;"},
    {name:"AUTO",type:"devices-list",required:false,filter:["script"],width:888,desc:"Автоматизации"},
    {type:"comment",text:"Выберите что делать:",width:200, style:"color:red;"},
    {name:"WHATDO",type:"number",required:true,defaultValue:0,min:0,max:1,desc:"0-Выключить, 1-Включить",descWidth:350},
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
    {name:"U16",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U17",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U18",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U19",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U20",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U21",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U22",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U23",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U24",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U25",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U26",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U27",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U28",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U29",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U30",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U31",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U32",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U33",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U34",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U35",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U36",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U37",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U38",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U39",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U40",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U41",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U42",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U43",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U44",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U45",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U46",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U47",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U48",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U49",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U50",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U51",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U52",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U53",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U54",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U55",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U56",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U57",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U58",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U59",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U60",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U61",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U62",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U63",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U64",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U65",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U66",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U67",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U68",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U69",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U70",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U71",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U72",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U73",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U74",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U75",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U76",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U77",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U78",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U79",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U80",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U81",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U82",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U83",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U84",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U85",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U86",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U87",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U88",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U89",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U90",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U91",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U92",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U93",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U94",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U95",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U96",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U97",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U98",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U99",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
   
   
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
    #ifdef U30, ADDR2ID(U30) #else, 0 #endif
    #ifdef U31, ADDR2ID(U31) #else, 0 #endif
    #ifdef U32, ADDR2ID(U32) #else, 0 #endif
    #ifdef U33, ADDR2ID(U33) #else, 0 #endif
    #ifdef U34, ADDR2ID(U34) #else, 0 #endif
    #ifdef U35, ADDR2ID(U35) #else, 0 #endif
    #ifdef U36, ADDR2ID(U36) #else, 0 #endif
    #ifdef U37, ADDR2ID(U37) #else, 0 #endif
    #ifdef U38, ADDR2ID(U38) #else, 0 #endif
    #ifdef U39, ADDR2ID(U39) #else, 0 #endif
    #ifdef U40, ADDR2ID(U40) #else, 0 #endif
    #ifdef U41, ADDR2ID(U41) #else, 0 #endif
    #ifdef U42, ADDR2ID(U42) #else, 0 #endif
    #ifdef U43, ADDR2ID(U43) #else, 0 #endif
    #ifdef U44, ADDR2ID(U44) #else, 0 #endif
    #ifdef U45, ADDR2ID(U45) #else, 0 #endif
    #ifdef U46, ADDR2ID(U46) #else, 0 #endif
    #ifdef U47, ADDR2ID(U47) #else, 0 #endif
    #ifdef U48, ADDR2ID(U48) #else, 0 #endif
    #ifdef U49, ADDR2ID(U49) #else, 0 #endif
    #ifdef U50, ADDR2ID(U50) #else, 0 #endif
    #ifdef U51, ADDR2ID(U51) #else, 0 #endif
    #ifdef U52, ADDR2ID(U52) #else, 0 #endif
    #ifdef U53, ADDR2ID(U53) #else, 0 #endif
    #ifdef U54, ADDR2ID(U54) #else, 0 #endif
    #ifdef U55, ADDR2ID(U55) #else, 0 #endif
    #ifdef U56, ADDR2ID(U56) #else, 0 #endif
    #ifdef U57, ADDR2ID(U57) #else, 0 #endif
    #ifdef U58, ADDR2ID(U58) #else, 0 #endif
    #ifdef U59, ADDR2ID(U59) #else, 0 #endif
    #ifdef U60, ADDR2ID(U60) #else, 0 #endif
    #ifdef U61, ADDR2ID(U61) #else, 0 #endif
    #ifdef U62, ADDR2ID(U62) #else, 0 #endif
    #ifdef U63, ADDR2ID(U63) #else, 0 #endif
    #ifdef U64, ADDR2ID(U64) #else, 0 #endif
    #ifdef U65, ADDR2ID(U65) #else, 0 #endif
    #ifdef U66, ADDR2ID(U66) #else, 0 #endif
    #ifdef U67, ADDR2ID(U67) #else, 0 #endif
    #ifdef U68, ADDR2ID(U68) #else, 0 #endif
    #ifdef U69, ADDR2ID(U69) #else, 0 #endif
    #ifdef U70, ADDR2ID(U70) #else, 0 #endif
    #ifdef U71, ADDR2ID(U71) #else, 0 #endif
    #ifdef U72, ADDR2ID(U72) #else, 0 #endif
    #ifdef U73, ADDR2ID(U73) #else, 0 #endif
    #ifdef U74, ADDR2ID(U74) #else, 0 #endif
    #ifdef U75, ADDR2ID(U75) #else, 0 #endif
    #ifdef U76, ADDR2ID(U76) #else, 0 #endif
    #ifdef U77, ADDR2ID(U77) #else, 0 #endif
    #ifdef U78, ADDR2ID(U78) #else, 0 #endif
    #ifdef U79, ADDR2ID(U79) #else, 0 #endif
    #ifdef U80, ADDR2ID(U80) #else, 0 #endif
    #ifdef U81, ADDR2ID(U81) #else, 0 #endif
    #ifdef U82, ADDR2ID(U82) #else, 0 #endif
    #ifdef U83, ADDR2ID(U83) #else, 0 #endif
    #ifdef U84, ADDR2ID(U84) #else, 0 #endif
    #ifdef U85, ADDR2ID(U85) #else, 0 #endif
    #ifdef U86, ADDR2ID(U86) #else, 0 #endif
    #ifdef U87, ADDR2ID(U87) #else, 0 #endif
    #ifdef U88, ADDR2ID(U88) #else, 0 #endif
    #ifdef U89, ADDR2ID(U89) #else, 0 #endif
    #ifdef U90, ADDR2ID(U90) #else, 0 #endif
    #ifdef U91, ADDR2ID(U91) #else, 0 #endif
    #ifdef U92, ADDR2ID(U92) #else, 0 #endif
    #ifdef U93, ADDR2ID(U93) #else, 0 #endif
    #ifdef U94, ADDR2ID(U94) #else, 0 #endif
    #ifdef U95, ADDR2ID(U95) #else, 0 #endif
    #ifdef U96, ADDR2ID(U96) #else, 0 #endif
    #ifdef U97, ADDR2ID(U97) #else, 0 #endif
    #ifdef U98, ADDR2ID(U98) #else, 0 #endif
    #ifdef U99, ADDR2ID(U99) #else, 0 #endif
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
    #ifdef U30, ADDR2SID(U30) #else, 0 #endif
    #ifdef U31, ADDR2SID(U31) #else, 0 #endif
    #ifdef U32, ADDR2SID(U32) #else, 0 #endif
    #ifdef U33, ADDR2SID(U33) #else, 0 #endif
    #ifdef U34, ADDR2SID(U34) #else, 0 #endif
    #ifdef U35, ADDR2SID(U35) #else, 0 #endif
    #ifdef U36, ADDR2SID(U36) #else, 0 #endif
    #ifdef U37, ADDR2SID(U37) #else, 0 #endif
    #ifdef U38, ADDR2SID(U38) #else, 0 #endif
    #ifdef U39, ADDR2SID(U39) #else, 0 #endif
    #ifdef U40, ADDR2SID(U40) #else, 0 #endif
    #ifdef U41, ADDR2SID(U41) #else, 0 #endif
    #ifdef U42, ADDR2SID(U42) #else, 0 #endif
    #ifdef U43, ADDR2SID(U43) #else, 0 #endif
    #ifdef U44, ADDR2SID(U44) #else, 0 #endif
    #ifdef U45, ADDR2SID(U45) #else, 0 #endif
    #ifdef U46, ADDR2SID(U46) #else, 0 #endif
    #ifdef U47, ADDR2SID(U47) #else, 0 #endif
    #ifdef U48, ADDR2SID(U48) #else, 0 #endif
    #ifdef U49, ADDR2SID(U49) #else, 0 #endif
    #ifdef U50, ADDR2SID(U50) #else, 0 #endif
    #ifdef U51, ADDR2SID(U51) #else, 0 #endif
    #ifdef U52, ADDR2SID(U52) #else, 0 #endif
    #ifdef U53, ADDR2SID(U53) #else, 0 #endif
    #ifdef U54, ADDR2SID(U54) #else, 0 #endif
    #ifdef U55, ADDR2SID(U55) #else, 0 #endif
    #ifdef U56, ADDR2SID(U56) #else, 0 #endif
    #ifdef U57, ADDR2SID(U57) #else, 0 #endif
    #ifdef U58, ADDR2SID(U58) #else, 0 #endif
    #ifdef U59, ADDR2SID(U59) #else, 0 #endif
    #ifdef U60, ADDR2SID(U60) #else, 0 #endif
    #ifdef U61, ADDR2SID(U61) #else, 0 #endif
    #ifdef U62, ADDR2SID(U62) #else, 0 #endif
    #ifdef U63, ADDR2SID(U63) #else, 0 #endif
    #ifdef U64, ADDR2SID(U64) #else, 0 #endif
    #ifdef U65, ADDR2SID(U65) #else, 0 #endif
    #ifdef U66, ADDR2SID(U66) #else, 0 #endif
    #ifdef U67, ADDR2SID(U67) #else, 0 #endif
    #ifdef U68, ADDR2SID(U68) #else, 0 #endif
    #ifdef U69, ADDR2SID(U69) #else, 0 #endif
    #ifdef U70, ADDR2SID(U70) #else, 0 #endif
    #ifdef U71, ADDR2SID(U71) #else, 0 #endif
    #ifdef U72, ADDR2SID(U72) #else, 0 #endif
    #ifdef U73, ADDR2SID(U73) #else, 0 #endif
    #ifdef U74, ADDR2SID(U74) #else, 0 #endif
    #ifdef U75, ADDR2SID(U75) #else, 0 #endif
    #ifdef U76, ADDR2SID(U76) #else, 0 #endif
    #ifdef U77, ADDR2SID(U77) #else, 0 #endif
    #ifdef U78, ADDR2SID(U78) #else, 0 #endif
    #ifdef U79, ADDR2SID(U79) #else, 0 #endif
    #ifdef U80, ADDR2SID(U80) #else, 0 #endif
    #ifdef U81, ADDR2SID(U81) #else, 0 #endif
    #ifdef U82, ADDR2SID(U82) #else, 0 #endif
    #ifdef U83, ADDR2SID(U83) #else, 0 #endif
    #ifdef U84, ADDR2SID(U84) #else, 0 #endif
    #ifdef U85, ADDR2SID(U85) #else, 0 #endif
    #ifdef U86, ADDR2SID(U86) #else, 0 #endif
    #ifdef U87, ADDR2SID(U87) #else, 0 #endif
    #ifdef U88, ADDR2SID(U88) #else, 0 #endif
    #ifdef U89, ADDR2SID(U89) #else, 0 #endif
    #ifdef U90, ADDR2SID(U90) #else, 0 #endif
    #ifdef U91, ADDR2SID(U91) #else, 0 #endif
    #ifdef U92, ADDR2SID(U92) #else, 0 #endif
    #ifdef U93, ADDR2SID(U93) #else, 0 #endif
    #ifdef U94, ADDR2SID(U94) #else, 0 #endif
    #ifdef U95, ADDR2SID(U95) #else, 0 #endif
    #ifdef U96, ADDR2SID(U96) #else, 0 #endif
    #ifdef U97, ADDR2SID(U97) #else, 0 #endif
    #ifdef U98, ADDR2SID(U98) #else, 0 #endif
    #ifdef U99, ADDR2SID(U99) #else, 0 #endif
};
u8 count=0;

#ifdef AUTO
void ON(){
    setStatus(AUTO, 1);
}
#endif

void OFF(){
    if(ID[count]){
        setStatus(@ID:@SID, WHATDO);
        ++count;
        delayedCallMs(OFF, 250);
    } else {setStatus(V-ADDR, 0);}
}

V-ID/V-ADDR
{
    if (([V-ADDR.0]&1)==1)
    {
        #ifdef AUTO setStatus(AUTO, 0);
        cancelDelayedCall(ON);
        delayedCall(ON, 300); #endif
        count=0;
        cancelDelayedCall(OFF);
        OFF();
    }
}


