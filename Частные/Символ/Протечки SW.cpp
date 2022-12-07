/*
{
desc:"Протечка",
tag:"item",
selectArea:true,

vars:[
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

void drebezg0()
{
    if([H00.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T00"});}
}
#ifdef H01
void drebezg1()
{
    if([H01.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T01"});}
}
#endif
#ifdef H02
void drebezg2()
{
    if([H02.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T02"});}
}
#endif
#ifdef H03
void drebezg3()
{
    if([H03.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T03"});}
}
#endif
#ifdef H04
void drebezg4()
{
    if([H04.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T04"});}
}
#endif
#ifdef H05
void drebezg5()
{
    if([H05.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T05"});}
}
#endif
#ifdef H06
void drebezg6()
{
    if([H06.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T06"});}
}
#endif
#ifdef H07
void drebezg7()
{
    if([H07.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T07"});}
}
#endif
#ifdef H08
void drebezg8()
{
    if([H08.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T08"});}
}
#endif
#ifdef H09
void drebezg9()
{
    if([H09.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T09"});}
}
#endif
#ifdef H10
void drebezg10()
{
    if([H10.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T10"});}
}
#endif
#ifdef H11
void drebezg11()
{
    if([H11.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T11"});}
}
#endif
#ifdef H12
void drebezg12()
{
    if([H12.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T12"});}
}
#endif
#ifdef H13
void drebezg13()
{
    if([H13.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T13"});}
}
#endif
#ifdef H14
void drebezg14()
{
    if([H14.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T14"});}
}
#endif
#ifdef H15
void drebezg15()
{
    if([H15.0]==0) {setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif setStatus(2047:32, {8, "T15"});}
}
#endif


V-ID/H00
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg0, 5);}
}

#ifdef H01
V-ID/H01
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg1, 5);}
}
#endif

#ifdef H02
V-ID/H02
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg2, 5);}
}
#endif

#ifdef H03
V-ID/H03
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg3, 5);}
}
#endif

#ifdef H04
V-ID/H04
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg4, 5);}
}
#endif

#ifdef H05
V-ID/H05
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg5, 5);}
}
#endif

#ifdef H06
V-ID/H06
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg6, 5);}
}
#endif

#ifdef H07
V-ID/H07
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg7, 5);}
}
#endif

#ifdef H08
V-ID/H08
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg8, 5);}
}
#endif

#ifdef H09
V-ID/H09
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg9, 5);}
}
#endif

#ifdef H10
V-ID/H10
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg10, 5);}
}
#endif

#ifdef H11
V-ID/H11
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg11, 5);}
}
#endif

#ifdef H15
V-ID/H15
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg12, 5);}
}
#endif

#ifdef H13
V-ID/H13
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg13, 5);}
}
#endif

#ifdef H14
V-ID/H14
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg14, 5);}
}
#endif

#ifdef H15
V-ID/H15
{
    if ( (opt(0)&1)==0 && ([V-ADDR.0]&1)==0 ) {delayedCall(drebezg15, 5);}
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

