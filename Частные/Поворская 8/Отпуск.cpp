/*
{
desc:"Отпуск",
tag:"item",
selectArea:true,

vars:[
{name:"ECO0",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"ECO1",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"ECO2",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"ECO3",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"ECO4",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"ECO5",type:"devices-list",required:false,width:800,filter:["script"],desc:"ЭКО",descWidth:100},
{name:"E00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"ТП 0",descWidth:100},
{name:"E01",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"ТП 1",descWidth:100},
{name:"E02",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"ТП 2",descWidth:100},
{name:"E03",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"ТП 3",descWidth:100},
]
}
*/

u8 kond[5];

void OFFOTP()
{
    #ifdef E00 setStatus(1000:102,"E00\0as:-1"); #endif
    #ifdef E01 setStatus(1000:102,"E01\0as:-1"); #endif
    #ifdef E02 setStatus(1000:102,"E02\0as:-1"); #endif
    #ifdef E03 setStatus(1000:102,"E03\0as:-1"); #endif
    #ifdef ECO0 setStatus(ECO0, 1); #endif
    #ifdef ECO1 setStatus(ECO1, 1); #endif
    #ifdef ECO2 setStatus(ECO2, 1); #endif
    #ifdef ECO3 setStatus(ECO3, 1); #endif
    #ifdef ECO4 setStatus(ECO4, 1); #endif
    #ifdef ECO5 setStatus(ECO5, 1); #endif
}

void ONOTP()
{
    #ifdef E00 setStatus(1000:102,"E00\0as:-2"); #endif
    #ifdef E01 setStatus(1000:102,"E01\0as:-2"); #endif
    #ifdef E02 setStatus(1000:102,"E02\0as:-2"); #endif
    #ifdef E03 setStatus(1000:102,"E03\0as:-2"); #endif
    #ifdef ECO0 setStatus(ECO0, 0); #endif
    #ifdef ECO1 setStatus(ECO1, 0); #endif
    #ifdef ECO2 setStatus(ECO2, 0); #endif
    #ifdef ECO3 setStatus(ECO3, 0); #endif
    #ifdef ECO4 setStatus(ECO4, 0); #endif
    #ifdef ECO5 setStatus(ECO5, 0); #endif
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        getStatus(K00, &kond); kond[0]=kond[0]&0xFE; setStatus(K00, &kond);
        getStatus(H00, &kond); kond[0]=kond[0]&0xFE; setStatus(H00, &kond);
        cancelDelayedCall(OFFOTP);
        cancelDelayedCall(ONOTP);
        delayedCall(OFFOTP, 5);
    } else
    if( (opt(0)&1)==0 && (senderId()!=exciterId()) )
    {
        cancelDelayedCall(OFFOTP);
        cancelDelayedCall(ONOTP);
        delayedCall(ONOTP, 5);
    }
}

V-ID/s:5
{
    if( ([V-ADDR.0]&1)==1 && (([ECO0.0]&1)==0 ||  ([ECO1.0]&1)==0 || ([ECO2.0]&1)==0 || ([ECO3.0]&1)==0 || ([ECO4.0]&1)==0 || ([ECO5.0]&1)==0) ) {setStatus(V-ADDR, 0);}
}