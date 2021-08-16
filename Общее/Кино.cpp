/*
{
desc:"Кино",
tag:"item",
selectArea:true,

vars:[
{name:"IRT",type:"devices-list",required:false,width:800,filter:["ir-transmitter"],desc:"ИК",descWidth:100},
{name:"L00",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L03",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L04",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L05",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L06",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"L07",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"B00",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B01",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B02",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B03",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B04",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B05",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B06",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"B07",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
]
}
*/

void zatuhanie()
{
    u8 i=[L00.1];
    i=i-1;
    if(i==0 || i<0) i=0;
    if([L00.0]==1) setStatus(L00, {1, i, 0});
    if (i==0) {cancelDelayedCall(zatuhanie); setStatus(L00, 0);}
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        #ifdef IRT u8 n[]={};setStatus(IRT, &on); #endif
        #ifdef L00 delayedCall(zatuhanie, 1); #endif
        #ifdef L01 setStatus(L01, 0); #endif
        #ifdef L02 setStatus(L02, 0); #endif
        #ifdef L03 setStatus(L03, 0); #endif
        #ifdef L04 setStatus(L04, 0); #endif
        #ifdef L05 setStatus(L05, 0); #endif
        #ifdef L06 setStatus(L06, 0); #endif
        #ifdef L07 setStatus(L07, 0); #endif
        #ifdef B00 if(([B00.0]&7)==1 || ([B00.0]&7)==4) setStatus(B00, 0); #endif
        #ifdef B01 if(([B01.0]&7)==1 || ([B01.0]&7)==4) setStatus(B01, 0); #endif
        #ifdef B02 if(([B02.0]&7)==1 || ([B02.0]&7)==4) setStatus(B02, 0); #endif
        #ifdef B03 if(([B03.0]&7)==1 || ([B03.0]&7)==4) setStatus(B03, 0); #endif
        #ifdef B04 if(([B04.0]&7)==1 || ([B04.0]&7)==4) setStatus(B04, 0); #endif
        #ifdef B05 if(([B05.0]&7)==1 || ([B05.0]&7)==4) setStatus(B05, 0); #endif
        #ifdef B06 if(([B06.0]&7)==1 || ([B06.0]&7)==4) setStatus(B06, 0); #endif
        #ifdef B07 if(([B07.0]&7)==1 || ([B07.0]&7)==4) setStatus(B07, 0); #endif
        #ifdef L00 setAutoState(L00, 0xfffe); #endif
        #ifdef L01 setAutoState(L01, 0xfffe); #endif
        #ifdef L02 setAutoState(L02, 0xfffe); #endif
        #ifdef L03 setAutoState(L03, 0xfffe); #endif
        #ifdef L04 setAutoState(L04, 0xfffe); #endif
        #ifdef L05 setAutoState(L05, 0xfffe); #endif
        #ifdef L06 setAutoState(L06, 0xfffe); #endif
        #ifdef L07 setAutoState(L07, 0xfffe); #endif
        #ifdef B00 setAutoState(B00, 0xfffe); #endif
        #ifdef B01 setAutoState(B01, 0xfffe); #endif
        #ifdef B02 setAutoState(B02, 0xfffe); #endif
        #ifdef B03 setAutoState(B03, 0xfffe); #endif
        #ifdef B04 setAutoState(B04, 0xfffe); #endif
        #ifdef B05 setAutoState(B05, 0xfffe); #endif
        #ifdef B06 setAutoState(B06, 0xfffe); #endif
        #ifdef B07 setAutoState(B07, 0xfffe); #endif
    } else
    if((opt(0)&1)==0)
    {
        #ifdef L01 setStatus(L01, 1); #endif
        #ifdef L02 setStatus(L02, 1); #endif
        #ifdef L03 setStatus(L03, 1); #endif
        #ifdef L04 setStatus(L04, 1); #endif
        #ifdef L05 setStatus(L05, 1); #endif
        #ifdef L06 setStatus(L06, 1); #endif
        #ifdef L07 setStatus(L07, 1); #endif
        #ifdef L00 setAutoState(L00, 0x003C); #endif
        #ifdef L01 setAutoState(L01, 0x003C); #endif
        #ifdef L02 setAutoState(L02, 0x003C); #endif
        #ifdef L03 setAutoState(L03, 0x003C); #endif
        #ifdef L04 setAutoState(L04, 0x003C); #endif
        #ifdef L05 setAutoState(L05, 0x003C); #endif
        #ifdef L06 setAutoState(L06, 0x003C); #endif
        #ifdef L07 setAutoState(L07, 0x003C); #endif
        #ifdef B00 setAutoState(B00, 0x003C); #endif
        #ifdef B01 setAutoState(B01, 0x003C); #endif
        #ifdef B02 setAutoState(B02, 0x003C); #endif
        #ifdef B03 setAutoState(B03, 0x003C); #endif
        #ifdef B04 setAutoState(B04, 0x003C); #endif
        #ifdef B05 setAutoState(B05, 0x003C); #endif
        #ifdef B06 setAutoState(B06, 0x003C); #endif
        #ifdef B07 setAutoState(B07, 0x003C); #endif
    }
}
