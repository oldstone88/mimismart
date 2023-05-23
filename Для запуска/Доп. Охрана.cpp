/*
{
    desc:"Доп. Охрана",
    tag:"item",
    selectArea:true,
    name:"Охрана-2",
    vars:[
        {name:"SECURITY",type:"devices-list",required:false,width:600,filter:["script"],desc:"Охрана",descWidth:100},
        {name:"L00",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L01",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L02",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L03",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L04",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L05",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L07",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L08",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
    ]
}
*/

u8 antispam=0;

void onInit(){
    setStatus(V-ADDR, 1);
}

void stopSpam(){
    antispam=0;
}

V-ID/{
    if([~SECURITY.0]==1){setStatus(V-ADDR, 1);}
}

V-ID/{
    if([~SECURITY.0]==0){setStatus(V-ADDR, 0);}
}

V-ID/s:5
{
    if ([V-ADDR.0]&1==1 && antispam==0)
    {
        #ifdef L00 if( ([L00.0]&1)==1 ) {setStatus(2047:32, {8, "T00"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L01 if( ([L01.0]&1)==1 ) {setStatus(2047:32, {8, "T01"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L02 if( ([L02.0]&1)==1 ) {setStatus(2047:32, {8, "T02"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L03 if( ([L03.0]&1)==1 ) {setStatus(2047:32, {8, "T03"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L04 if( ([L04.0]&1)==1 ) {setStatus(2047:32, {8, "T04"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L05 if( ([L05.0]&1)==1 ) {setStatus(2047:32, {8, "T05"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L06 if( ([L06.0]&1)==1 ) {setStatus(2047:32, {8, "T06"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L07 if( ([L07.0]&1)==1 ) {setStatus(2047:32, {8, "T07"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
        #ifdef L08 if( ([L08.0]&1)==1 ) {setStatus(2047:32, {8, "T08"}); antispam=1; cancelDelayedCall(stopSpam); delayedCall(stopSpam, 300);} #endif
    }
}