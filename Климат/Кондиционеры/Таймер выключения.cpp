/*
{
desc:"Таймер",
tag:"item",
selectArea:true,

vars:[
{name:"TIME", type:"number", defaultValue:3600, required:true, desc:"Таймер в сек"},
{name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K02",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K03",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K04",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K05",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K06",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"K07",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
]
}
*/

u8 kond[5];

void OFF()
{
    setStatus(V-ADDR, 0);
}

#ifdef K00
void K0OFF()
    {getStatus(K00, &kond); kond[0]=(kond[0]&0xFE); setStatus(K00, &kond);}
#endif

#ifdef K01
void K1OFF()
    {getStatus(K01, &kond); kond[0]=(kond[0]&0xFE); setStatus(K01, &kond);}
#endif

#ifdef K02
void K2OFF()
    {getStatus(K02, &kond); kond[0]=(kond[0]&0xFE); setStatus(K02, &kond);}
#endif

#ifdef K03
void K3OFF()
    {getStatus(K03, &kond); kond[0]=(kond[0]&0xFE); setStatus(K03, &kond);}
#endif

#ifdef K04
void K4OFF()
    {getStatus(K04, &kond); kond[0]=(kond[0]&0xFE); setStatus(K04, &kond);}
#endif

    #ifdef K05
void K5OFF()
    {getStatus(K05, &kond); kond[0]=(kond[0]&0xFE); setStatus(K05, &kond);}
#endif

#ifdef K06
void K6OFF()
    {getStatus(K06, &kond); kond[0]=(kond[0]&0xFE); setStatus(K06, &kond);}
#endif

#ifdef K07
void K7OFF()
    {getStatus(K07, &kond); kond[0]=(kond[0]&0xFE); setStatus(K07, &kond);}
#endif

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        delayedCall(OFF, (TIME+10));
        #ifdef K00 delayedCall(K0OFF, TIME); #endif
        #ifdef K01 delayedCall(K1OFF, (TIME+1)); #endif
        #ifdef K02 delayedCall(K2OFF, (TIME+2)); #endif
        #ifdef K03 delayedCall(K3OFF, (TIME+3)); #endif
        #ifdef K04 delayedCall(K4OFF, (TIME+4)); #endif
        #ifdef K05 delayedCall(K5OFF, (TIME+5)); #endif
        #ifdef K06 delayedCall(K6OFF, (TIME+6)); #endif
        #ifdef K07 delayedCall(K7OFF, (TIME+7)); #endif
    } else
    if ((opt(0)&1)==0)
    {
        cancelDelayedCall(OFF);
        #ifdef K00 cancelDelayedCall(K0OFF); #endif
        #ifdef K01 cancelDelayedCall(K1OFF); #endif
        #ifdef K02 cancelDelayedCall(K2OFF); #endif
        #ifdef K03 cancelDelayedCall(K3OFF); #endif
        #ifdef K04 cancelDelayedCall(K4OFF); #endif
        #ifdef K05 cancelDelayedCall(K5OFF); #endif
        #ifdef K06 cancelDelayedCall(K6OFF); #endif
        #ifdef K07 cancelDelayedCall(K7OFF); #endif
    }
}
