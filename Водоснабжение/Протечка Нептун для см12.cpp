/*
{
desc:"Протечка",
tag:"import-script",
selectArea:true,

vars:[
{type:"comment",text:"Уборка:",width:200, style:"color:red;"},
{name:"I00",type:"devices-list",required:false,width:800,filter:["script"],desc:"Уборка",descWidth:100},
{type:"comment",text:"Кран к датчикам:",width:200, style:"color:red;"},
{name:"V00",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{name:"V01",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{name:"V02",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{type:"comment",text:"Датчики протечки:",width:200, style:"color:red;"},
{name:"H00",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H01",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H02",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H03",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H04",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H05",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T05",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H06",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H07",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H08",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H09",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T09",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H10",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T10",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H11",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T11",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H12",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T12",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H13",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T13",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H14",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T14",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H15",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T15",type:"string",required:false,desc:"Текст оповещения",width:300},
]
}
*/

V-ID/H00
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T00"});}
}

#ifdef H01
V-ID/H01
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T01"});}
}
#endif

#ifdef H02
V-ID/H02
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T02"});}
}
#endif

#ifdef H03
V-ID/H03
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T03"});}
}
#endif

#ifdef H04
V-ID/H04
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T04"});}
}
#endif

#ifdef H05
V-ID/H05
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T05"});}
}
#endif

#ifdef H06
V-ID/H06
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T06"});}
}
#endif

#ifdef H07
V-ID/H07
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T07"});}
}
#endif

#ifdef H08
V-ID/H08
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T08"});}
}
#endif

#ifdef H09
V-ID/H09
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T09"});}
}
#endif

#ifdef H10
V-ID/H10
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T10"});}
}
#endif

#ifdef H11
V-ID/H11
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T11"});}
}
#endif

#ifdef H12
V-ID/H12
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T12"});}
}
#endif

#ifdef H13
V-ID/H13
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T13"});}
}
#endif

#ifdef H14
V-ID/H14
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T14"});}
}
#endif

#ifdef H15
V-ID/H15
{
    if ( (opt(0)&1)==0 && ([I00.0]&1)==0 ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T15"});}
}
#endif

V-ID/V00, #ifdef V01 V01, #endif #ifdef V02 V02 #endif
{
    if ((opt(0)&1)==0 && (([H00.0]&1)==0)
        #ifdef H01 || (([H01.0]&1)==0) #endif
        #ifdef H02 || (([H02.0]&1)==0) #endif
        #ifdef H03 || (([H03.0]&1)==0) #endif
        #ifdef H04 || (([H04.0]&1)==0) #endif
        #ifdef H05 || (([H05.0]&1)==0) #endif
        #ifdef H06 || (([H06.0]&1)==0) #endif
        #ifdef H07 || (([H07.0]&1)==0) #endif
        #ifdef H08 || (([H08.0]&1)==0) #endif
        #ifdef H09 || (([H09.0]&1)==0) #endif
        #ifdef H10 || (([H10.0]&1)==0) #endif
        #ifdef H11 || (([H11.0]&1)==0) #endif
        #ifdef H12 || (([H12.0]&1)==0) #endif
        #ifdef H13 || (([H13.0]&1)==0) #endif
        #ifdef H14 || (([H14.0]&1)==0) #endif
        #ifdef H15 || (([H15.0]&1)==0) #endif
        ) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif}
}