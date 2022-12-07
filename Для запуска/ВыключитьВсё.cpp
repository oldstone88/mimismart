/*
{
    desc:"Выкл. весь cвет",
    tag:"item",
    name:"Выкл. весь свет",
    selectArea:true,
    vars:[

    {type:"comment",text:"Нужен ли возврат скрипта в состояние ВЫКЛ? 1 - ДА, 0 - НЕТ",width:200, style:"color:red;"},
    {name:"DELTA",type:"number",required:true,min:0,max:1,defaultValue:1,descWidth:150,desc:"Внесите значение 1 или 0"},
    {name:"TIME01",type:"number",required:true,min:1,max:100,defaultValue:3,descWidth:150,desc:"Время отскока в секундах, задайте любое значение если не нужно"},
    {type:"comment",text:"Автоматизации",width:200, style:"color:red;"},
    {name:"AUTO",type:"devices-list",required:false,filter:["script"],width:888,desc:"Автоматизации"},
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
   
   
    ]
}
*/

void OFF()
{
    setStatus(V-ADDR,0);
}

void ON()
{
    setStatus(AUTO, 1);
}

V-ID/V-ADDR
{
    if ([V-ADDR.0]==1)
    {
        setStatus(AUTO, 0);
        cancelDelayedCall(ON);
        delayedCall(ON, 300);
        #ifdef U00 setStatus(U00, 0); #endif
        #ifdef U01 setStatus(U01, 0); #endif
        #ifdef U02 setStatus(U02, 0); #endif
        #ifdef U03 setStatus(U03, 0); #endif
        #ifdef U04 setStatus(U04, 0); #endif
        #ifdef U05 setStatus(U05, 0); #endif
        #ifdef U06 setStatus(U06, 0); #endif
        #ifdef U07 setStatus(U07, 0); #endif
        #ifdef U08 setStatus(U08, 0); #endif
        #ifdef U09 setStatus(U09, 0); #endif
        #ifdef U10 setStatus(U10, 0); #endif
        #ifdef U11 setStatus(U11, 0); #endif
        #ifdef U12 setStatus(U12, 0); #endif
        #ifdef U13 setStatus(U13, 0); #endif
        #ifdef U14 setStatus(U14, 0); #endif
        #ifdef U15 setStatus(U15, 0); #endif
        #ifdef U16 setStatus(U16, 0); #endif
        #ifdef U17 setStatus(U17, 0); #endif
        #ifdef U18 setStatus(U18, 0); #endif
        #ifdef U19 setStatus(U19, 0); #endif
        #ifdef U20 setStatus(U20, 0); #endif
        #ifdef U21 setStatus(U21, 0); #endif
        #ifdef U22 setStatus(U22, 0); #endif
        #ifdef U23 setStatus(U23, 0); #endif
        #ifdef U24 setStatus(U24, 0); #endif
        #ifdef U25 setStatus(U25, 0); #endif
        #ifdef U26 setStatus(U26, 0); #endif
        #ifdef U27 setStatus(U27, 0); #endif
        #ifdef U28 setStatus(U28, 0); #endif
        #ifdef U29 setStatus(U29, 0); #endif
        #ifdef U30 setStatus(U30, 0); #endif
        #ifdef U31 setStatus(U31, 0); #endif
        #ifdef U32 setStatus(U32, 0); #endif
        #ifdef U33 setStatus(U33, 0); #endif
        #ifdef U34 setStatus(U34, 0); #endif
        #ifdef U35 setStatus(U35, 0); #endif
        #ifdef U36 setStatus(U36, 0); #endif
        #ifdef U37 setStatus(U37, 0); #endif
        #ifdef U38 setStatus(U38, 0); #endif
        #ifdef U39 setStatus(U39, 0); #endif
        #ifdef U40 setStatus(U40, 0); #endif
        #ifdef U41 setStatus(U41, 0); #endif
        #ifdef U42 setStatus(U42, 0); #endif
        #ifdef U43 setStatus(U43, 0); #endif
        #ifdef U44 setStatus(U44, 0); #endif
        #ifdef U45 setStatus(U45, 0); #endif
        #ifdef U46 setStatus(U46, 0); #endif
        #ifdef U47 setStatus(U47, 0); #endif
        #ifdef U48 setStatus(U48, 0); #endif
        #ifdef U49 setStatus(U49, 0); #endif
        #ifdef U50 setStatus(U50, 0); #endif
        #ifdef U51 setStatus(U51, 0); #endif
        #ifdef U52 setStatus(U52, 0); #endif
        #ifdef U53 setStatus(U53, 0); #endif
        #ifdef U54 setStatus(U54, 0); #endif
        #ifdef U55 setStatus(U55, 0); #endif
        #ifdef U56 setStatus(U56, 0); #endif
        #ifdef U57 setStatus(U57, 0); #endif
        #ifdef U58 setStatus(U58, 0); #endif
        #ifdef U59 setStatus(U59, 0); #endif
        #ifdef U60 setStatus(U60, 0); #endif
        #ifdef U61 setStatus(U61, 0); #endif
        #ifdef U62 setStatus(U62, 0); #endif
        #ifdef U63 setStatus(U63, 0); #endif
        #ifdef U64 setStatus(U64, 0); #endif
        #ifdef U65 setStatus(U65, 0); #endif
        #ifdef U66 setStatus(U66, 0); #endif
        #ifdef U67 setStatus(U67, 0); #endif
        #ifdef U68 setStatus(U68, 0); #endif
        #ifdef U69 setStatus(U69, 0); #endif

        if (DELTA==1) delayedCall(OFF, TIME01);
    } 

}


