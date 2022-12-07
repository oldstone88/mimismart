/*
{
    desc-ru:"Кино",
    tag:"item",
    selectArea:true,
    vars:[

    {type:"comment",text:"Нужен ли возврат скрипта в состояние ВЫКЛ? 1 - ДА, 0 - НЕТ",width:200, style:"color:red;"},
    {name:"DELTA",type:"number",required:true,min:0,max:1,defaultValue:1,descWidth:150,desc:"Внесите значение 1 или 0"},
    {name:"TIME01",type:"number",required:true,min:1,max:100,defaultValue:3,descWidth:150,desc:"Время отскока в секундах, задайте любое значение если не нужно"},
    
    {type:"comment",text:"Группы света, RGB, Световая схема",width:200, style:"color:red;"},
    {name:"U00",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Диммер"},
    {name:"U01",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U02",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U03",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U04",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U05",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U06",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U07",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U08",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U09",type:"devices-list",required:false,filter:["lamp","dimer-lamp","rgb-lamp","light-scheme"],width:888,desc:"Свет"},
    {name:"U10",type:"devices-list",required:false,filter:["script"],width:888,desc:"Проектор"},
    {name:"U11",type:"devices-list",required:false,filter:["jalousie"],width:888,desc:"Экран"},
    {type:"comment",text:"Шторы",width:200, style:"color:red;"},
    {name:"B00",type:"devices-list",required:false,filter:["virtual", "jalousie"],width:888,desc:"Шторы"},
    {name:"B01",type:"devices-list",required:false,filter:["virtual", "jalousie"],width:888,desc:"Шторы"},
    {name:"B02",type:"devices-list",required:false,filter:["virtual", "jalousie"],width:888,desc:"Шторы"},
    {type:"comment",text:"Точки-Клапаны",width:200, style:"color:red;"},
    {name:"M00",type:"devices-list",required:false,filter:["speaker"],width:888,desc:"Мультирум"},
    ]
}
*/

void OFF()
{
    setStatus(V-ADDR,0);
}

V-ID/V-ADDR
{
    if (([V-ADDR.0]&1)==1)
    {
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
        #ifdef U10 setStatus(U10, 1); #endif
        #ifdef U11 setStatus(U11, 1); #endif
        #ifdef B00 setStatus(B00, 0); #endif
        #ifdef B01 setStatus(B01, 0); #endif
        #ifdef B02 setStatus(B02, 0); #endif
        #ifdef M00 setStatus(M00, 0); #endif
        if (DELTA==1) delayedCall(OFF, TIME01);
    } 
    else if(([V-ADDR.0])==0)
    {
        #ifdef U00 setStatus(U00, {1, 0, 1}); #endif
        #ifdef U10 setStatus(U10, 0); #endif
        #ifdef U11 setStatus(U11, 0); #endif
        #ifdef B00 setStatus(B00, 1); #endif
        #ifdef B01 setStatus(B01, 1); #endif
        #ifdef B02 setStatus(B02, 1); #endif
    }
}

