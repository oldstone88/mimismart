/*
{
    desc-ru:"Выключить, включить - по Активации скрипта",
    tag:"item",
    selectArea:true,
    vars:[

    {type:"comment",text:"Нужен ли возврат скрипта в состояние ВЫКЛ? 1 - ДА, 0 - НЕТ",width:200, style:"color:red;"},
    {name:"DELTA",type:"number",required:true,min:0,max:1,defaultValue:1,descWidth:150,desc:"Внесите значение 1 или 0"},
    {name:"TIME01",type:"number",required:true,min:1,max:100,defaultValue:3,descWidth:150,desc:"Время отскока в секундах, задайте любое значение если не нужно"},

    {type:"comment",text:"Укажите ИК передатчик, команду внесите внутри скрипта:",width:200, style:"color:red;"},
    {name:"IRT",type:"devices-list",required:false,filter:["ir-transmitter"],desc:"ИК-передатчик"},

    {type:"comment",text:"Устройства для включения автоматизации",width:200, style:"color:red;"},
    {name:"TIME00",type:"string",required:false,min:1,max:10,desc:"Время выключения автоматизации в 16ти ричной системе",width:300},
    
    {type:"comment",text:"Группы света, RGB, Световая схема",width:200, style:"color:red;"},
    {name:"U00",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U01",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U02",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U03",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U04",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U05",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U06",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U07",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U08",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U09",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {type:"comment",text:"Шторы",width:200, style:"color:red;"},
    {name:"U10",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U11",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U12",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U13",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U14",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U15",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U16",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U17",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U18",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {name:"U19",type:"devices-list",required:false,filter:["jalousie","virtual"],width:888,desc:"Шторы"},
    {type:"comment",text:"Кондей",width:200, style:"color:red;"},
    {name:"U20",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U21",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U22",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U23",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U24",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U25",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U26",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U27",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U28",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {name:"U29",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Устройство"},
    {type:"comment",text:"Скрипты",width:200, style:"color:red;"},
    {name:"U30",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {name:"U31",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {name:"U32",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {name:"U33",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {name:"U34",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {name:"U35",type:"devices-list",required:false,filter:["script"],width:888,desc:"Скрипты"},
    {type:"comment",text:"Точки-Клапаны",width:200, style:"color:red;"},
    {name:"U36",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U37",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U38",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U39",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U40",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U41",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U42",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U43",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U44",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U45",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U46",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U47",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U48",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {name:"U49",type:"devices-list",required:false,filter:["speaker","valve"],width:888,desc:"Устройство"},
    {type:"comment",text:"То, что надо включить",width:200, style:"color:red;"},
    {name:"L00",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L01",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L02",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L03",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L04",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L05",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L06",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L07",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L08",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L09",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L10",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L11",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L12",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L13",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L14",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L15",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L16",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L17",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L18",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L19",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L20",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L21",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L22",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L23",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L24",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L25",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L26",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L27",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L28",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    {name:"L29",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","jalousie","conditioner","speaker","light-scheme","virtual","valve-heating","valve"],width:888,desc:"Устройство"},
    ]
}
*/

#ifdef IRT
u8 comand[]=0x;
#endif

void OFF()
{
    setStatus(V-ADDR,0);
}

V-ID/V-ADDR
{
    if ([V-ADDR.0]==1)
    {
       #ifdef IRT setStatus(IRT, &comand); #endif        

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
        #ifdef U10 if(([U10.0]&7)==1 ) setStatus(U10, 0); #endif
        #ifdef U11 if(([U10.0]&7)==1 ) setStatus(U11, 0); #endif
        #ifdef U12 if(([U10.0]&7)==1 ) setStatus(U12, 0); #endif
        #ifdef U13 if(([U10.0]&7)==1 ) setStatus(U13, 0); #endif
        #ifdef U14 if(([U10.0]&7)==1 ) setStatus(U14, 0); #endif
        #ifdef U15 if(([U10.0]&7)==1 ) setStatus(U15, 0); #endif
        #ifdef U16 if(([U10.0]&7)==1 ) setStatus(U16, 0); #endif
        #ifdef U17 if(([U10.0]&7)==1 ) setStatus(U17, 0); #endif
        #ifdef U18 if(([U10.0]&7)==1 ) setStatus(U18, 0); #endif
        #ifdef U19 if(([U10.0]&7)==1 ) setStatus(U19, 0); #endif
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

        #ifdef L00 setStatus(L00, 1); #endif
        #ifdef L01 setStatus(L01, 1); #endif
        #ifdef L02 setStatus(L02, 1); #endif
        #ifdef L03 setStatus(L03, 1); #endif
        #ifdef L04 setStatus(L04, 1); #endif
        #ifdef L05 setStatus(L05, 1); #endif
        #ifdef L06 setStatus(L06, 1); #endif
        #ifdef L07 setStatus(L07, 1); #endif
        #ifdef L08 setStatus(L08, 1); #endif
        #ifdef L09 setStatus(L09, 1); #endif
        #ifdef L10 setStatus(L10, 1); #endif
        #ifdef L11 setStatus(L11, 1); #endif
        #ifdef L12 setStatus(L12, 1); #endif
        #ifdef L13 setStatus(L13, 1); #endif
        #ifdef L14 setStatus(L14, 1); #endif
        #ifdef L15 setStatus(L15, 1); #endif
        #ifdef L16 setStatus(L16, 1); #endif
        #ifdef L17 setStatus(L17, 1); #endif
        #ifdef L18 setStatus(L18, 1); #endif
        #ifdef L19 setStatus(L19, 1); #endif
        #ifdef L20 setStatus(L20, 1); #endif
        #ifdef L21 setStatus(L21, 1); #endif
        #ifdef L22 setStatus(L22, 1); #endif
        #ifdef L23 setStatus(L23, 1); #endif
        #ifdef L24 setStatus(L24, 1); #endif
        #ifdef L25 setStatus(L25, 1); #endif
        #ifdef L26 setStatus(L26, 1); #endif
        #ifdef L27 setStatus(L27, 1); #endif
        #ifdef L28 setStatus(L28, 1); #endif
        #ifdef L29 setStatus(L29, 1); #endif

        #ifdef U00 setAutoState(U00, TIME00); #endif
        #ifdef U01 setAutoState(U01, TIME00); #endif
        #ifdef U02 setAutoState(U02, TIME00); #endif
        #ifdef U03 setAutoState(U03, TIME00); #endif
        #ifdef U04 setAutoState(U04, TIME00); #endif
        #ifdef U05 setAutoState(U05, TIME00); #endif
        #ifdef U06 setAutoState(U06, TIME00); #endif
        #ifdef U07 setAutoState(U07, TIME00); #endif
        #ifdef U08 setAutoState(U08, TIME00); #endif
        #ifdef U09 setAutoState(U09, TIME00); #endif
        #ifdef U10 setAutoState(U10, TIME00); #endif
        #ifdef U11 setAutoState(U11, TIME00); #endif
        #ifdef U12 setAutoState(U12, TIME00); #endif
        #ifdef U13 setAutoState(U13, TIME00); #endif
        #ifdef U14 setAutoState(U14, TIME00); #endif
        #ifdef U15 setAutoState(U15, TIME00); #endif
        #ifdef U16 setAutoState(U16, TIME00); #endif
        #ifdef U17 setAutoState(U17, TIME00); #endif
        #ifdef U18 setAutoState(U18, TIME00); #endif
        #ifdef U19 setAutoState(U19, TIME00); #endif
        #ifdef U20 setAutoState(U20, TIME00); #endif
        #ifdef U21 setAutoState(U21, TIME00); #endif
        #ifdef U22 setAutoState(U22, TIME00); #endif
        #ifdef U23 setAutoState(U23, TIME00); #endif
        #ifdef U24 setAutoState(U24, TIME00); #endif
        #ifdef U25 setAutoState(U25, TIME00); #endif
        #ifdef U26 setAutoState(U26, TIME00); #endif
        #ifdef U27 setAutoState(U27, TIME00); #endif
        #ifdef U28 setAutoState(U28, TIME00); #endif
        #ifdef U29 setAutoState(U29, TIME00); #endif
        #ifdef U30 setAutoState(U30, TIME00); #endif
        #ifdef U31 setAutoState(U31, TIME00); #endif
        #ifdef U32 setAutoState(U32, TIME00); #endif
        #ifdef U33 setAutoState(U33, TIME00); #endif
        #ifdef U34 setAutoState(U34, TIME00); #endif
        #ifdef U35 setAutoState(U35, TIME00); #endif
        #ifdef U36 setAutoState(U36, TIME00); #endif
        #ifdef U37 setAutoState(U37, TIME00); #endif
        #ifdef U38 setAutoState(U38, TIME00); #endif
        #ifdef U39 setAutoState(U39, TIME00); #endif
        #ifdef U40 setAutoState(U40, TIME00); #endif
        #ifdef U41 setAutoState(U41, TIME00); #endif
        #ifdef U42 setAutoState(U42, TIME00); #endif
        #ifdef U43 setAutoState(U43, TIME00); #endif
        #ifdef U44 setAutoState(U44, TIME00); #endif
        #ifdef U45 setAutoState(U45, TIME00); #endif
        #ifdef U46 setAutoState(U46, TIME00); #endif
        #ifdef U47 setAutoState(U47, TIME00); #endif
        #ifdef U48 setAutoState(U48, TIME00); #endif
        #ifdef U49 setAutoState(U49, TIME00); #endif

        if (DELTA==1) delayedCall(OFF, TIME01);
    } 
    else
    {

    }
}

