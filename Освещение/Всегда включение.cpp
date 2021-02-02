/*
{
    desc:"Всегда ВКЛ",
    tag:"import-script",
    selectArea:true,
    vars:[    
    {name:"U00",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U01",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U02",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U03",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U04",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U05",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U06",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    {name:"U07",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
    ]
}
*/

V-ID/s:10
{
        #ifdef U00 if(([U00.0]&1)==0) setStatus(U00, 1); #endif
        #ifdef U01 if(([U01.0]&1)==0) setStatus(U01, 1); #endif
        #ifdef U02 if(([U02.0]&1)==0) setStatus(U02, 1); #endif
        #ifdef U03 if(([U03.0]&1)==0) setStatus(U03, 1); #endif
        #ifdef U04 if(([U04.0]&1)==0) setStatus(U04, 1); #endif
        #ifdef U05 if(([U05.0]&1)==0) setStatus(U05, 1); #endif
        #ifdef U06 if(([U06.0]&1)==0) setStatus(U06, 1); #endif
        #ifdef U07 if(([U07.0]&1)==0) setStatus(U07, 1); #endif 
}
