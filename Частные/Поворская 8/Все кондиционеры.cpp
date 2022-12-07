/*
{
desc:"Все кондеи RS",
tag:"import-script",
selectArea:true,
addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "vane-hor":"0x00", "vane-ver":"0x00", "funs":"0x01", "modes":"0x00"},
    ],
vars:[
{name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
{name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO0",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO1",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K02",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO2",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K03",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO3",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K04",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO4",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K05",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO5",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K06",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO6",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
{name:"K07",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"ECO7",type:"devices-list",required:false,width:800,filter:["script"],desc:"Эко",descWidth:100},
]
}
*/

u8 kond[5];

#ifdef K01
void K1OFF()
    {setStatus(K01, &kond);}
#endif

#ifdef K02
void K2OFF()
    {setStatus(K02, &kond);}
#endif

#ifdef K03
void K3OFF()
    {setStatus(K03, &kond);}
#endif

#ifdef K04
void K4OFF()
    {setStatus(K04, &kond);}
#endif

    #ifdef K05
void K5OFF()
    {setStatus(K05, &kond);}
#endif

#ifdef K06
void K6OFF()
    {setStatus(K06, &kond);}
#endif

#ifdef K07
void K7OFF()
    {setStatus(K07, &kond);}
#endif

void send()
{
    getStatus(AUTO, &kond);
    #ifdef K00 if( ([ECO0.0]&1)==0 ) setStatus(K00, &kond); #endif
    #ifdef K01 if( ([ECO1.0]&1)==0 ) delayedCall(K1OFF, 1); #endif
    #ifdef K02 if( ([ECO2.0]&1)==0 ) delayedCall(K2OFF, 2); #endif
    #ifdef K03 if( ([ECO3.0]&1)==0 ) delayedCall(K3OFF, 3); #endif
    #ifdef K04 if( ([ECO4.0]&1)==0 ) delayedCall(K4OFF, 4); #endif
    #ifdef K05 if( ([ECO5.0]&1)==0 ) delayedCall(K5OFF, 5); #endif
    #ifdef K06 if( ([ECO6.0]&1)==0 ) delayedCall(K6OFF, 6); #endif
    #ifdef K07 if( ([ECO7.0]&1)==0 ) delayedCall(K7OFF, 7); #endif
}

V-ID/AUTO
{
    cancelDelayedCall(send);
    #ifdef K01 cancelDelayedCall(K1OFF); #endif
    #ifdef K02 cancelDelayedCall(K2OFF); #endif
    #ifdef K03 cancelDelayedCall(K3OFF); #endif
    #ifdef K04 cancelDelayedCall(K4OFF); #endif
    #ifdef K05 cancelDelayedCall(K5OFF); #endif
    #ifdef K06 cancelDelayedCall(K6OFF); #endif
    #ifdef K07 cancelDelayedCall(K7OFF); #endif
    delayedCall(send, 3);
}
