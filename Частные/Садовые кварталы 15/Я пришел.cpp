/*
{
  desc:"Я пришел",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"I00",type:"devices-list",required:false,filter:["script"],desc:"Отпуск"},
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
    {name:"K00",type:"devices-list",required:false,filter:["conditioner"],desc:"Весь климат"},
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
    #ifdef I00 setStatus(I00, 0); #endif
    #ifdef L00 setStatus(L00, 1); #endif
    #ifdef L01 setStatus(L01, 1); #endif
    #ifdef L02 setStatus(L02, 1); #endif
    #ifdef L03 setStatus(L03, 1); #endif
    #ifdef L04 setStatus(L04, 1); #endif
    #ifdef L05 setStatus(L05, 1); #endif
    #ifdef L06 setStatus(L06, 1); #endif
    #ifdef L07 setStatus(L07, 1); #endif
    #ifdef L08 setStatus(L08, 1); #endif
    #ifdef L09 setStatus(L09, 1); #endif
    getStatus(K00, &k);
    k[0]=1; k[1]=6; setStatus(K00, &k);
    setStatus(1000:100, "Авто");
    delayedCall(OFF, 1);
  }
}