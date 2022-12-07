/*
{
  desc:"Я ушел",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"L00",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L01",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L02",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L03",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L04",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L05",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L06",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L07",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L08",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"L09",type:"devices-list",required:false,filter:["lamp", "dimer-lamp"],desc:"Свет"},
    {name:"K00",type:"devices-list",required:false,filter:["conditioner"],desc:"Климат"},
    {name:"K01",type:"devices-list",required:false,filter:["conditioner"],desc:"Кондиционер"},
    {name:"V00",type:"devices-list",required:false,filter:["valve-heating"],desc:"Радиатор"},
    {name:"V01",type:"devices-list",required:false,filter:["valve-heating"],desc:"ТП 0"},
    {name:"V01",type:"devices-list",required:false,filter:["valve-heating"],desc:"ТП 1"},
  ]
}
*/

u8 k[5];

void OFF()
{setStatus(V-ADDR, 0);}

V-ID/V-ADDR
{
  if( (opt(0)&1)==1 )
  {
    #ifdef L00 setStatus(L00, 0); #endif
    #ifdef L01 setStatus(L01, 0); #endif
    #ifdef L02 setStatus(L02, 0); #endif
    #ifdef L03 setStatus(L03, 0); #endif
    #ifdef L04 setStatus(L04, 0); #endif
    #ifdef L05 setStatus(L05, 0); #endif
    #ifdef L06 setStatus(L06, 0); #endif
    #ifdef L07 setStatus(L07, 0); #endif
    #ifdef L08 setStatus(L08, 0); #endif
    #ifdef L09 setStatus(L09, 0); #endif
    getStatus(K00, &k);
    if(k[0]%2==1) {k[0]=k[0]&0xFE; setStatus(K00, &k);}
    else {getStatus(K01, &k); if(k[0]%2==1) {k[0]=k[0]&0xFE; setStatus(K01, &k);} setStatus(1000:102, "V00\0Эко");}
    #ifdef V01 setStatus(1000:102, "V01\0Эко"); #endif
    #ifdef V02 setStatus(1000:102, "V02\0Эко"); #endif
    delayedCall(OFF, 1);
  }
}