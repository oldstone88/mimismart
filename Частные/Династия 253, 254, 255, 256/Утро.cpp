/*
{
  desc:"Утро",
  tag:"item",
  selectArea:true,
  name:"Утро",
  vars:[
  {name:"MEDIA", type:"devices-list", required:false, filter:["script"], desc:"Музыка", width:555},
  {name:"L00", type:"devices-list", required:false, filter:["lamp", "dimer-lamp"], desc:"Свет 1", width:555},
  {name:"L01", type:"devices-list", required:false, filter:["lamp", "dimer-lamp"], desc:"Свет 2", width:555},
  {name:"L02", type:"devices-list", required:false, filter:["lamp", "dimer-lamp"], desc:"Свет 3", width:555},
  {name:"L03", type:"devices-list", required:false, filter:["lamp", "dimer-lamp"], desc:"Свет 4", width:555},
  {name:"L04", type:"devices-list", required:false, filter:["lamp", "dimer-lamp"], desc:"Свет 5", width:555},
  {name:"J00", type:"devices-list", required:false, filter:["jalousie"], desc:"Шторы", width:555},
  {name:"J01", type:"devices-list", required:false, filter:["jalousie"], desc:"Шторы", width:555},
  {name:"J02", type:"devices-list", required:false, filter:["jalousie"], desc:"Шторы", width:555},

  ]
}
*/

void OFF(){
  setStatus(V-ADDR, 0);
}

V-ID/V-ADDR{
  if((opt(0)&1)==1){
    #ifdef MEDIA setStatus(MEDIA, 1); #endif
    #ifdef L00 setStatus(L00, 1); #endif
    #ifdef L01 setStatus(L01, 1); #endif
    #ifdef L02 setStatus(L02, 1); #endif
    #ifdef L03 setStatus(L03, 1); #endif
    #ifdef L04 setStatus(L04, 1); #endif
    #ifdef J00 setAutoState(J00, 0x0258); if(([J00.0]&7)!=1) setStatus(J00, 1); #endif
    #ifdef J01 setAutoState(J01, 0x0258); if(([J01.0]&7)!=1) setStatus(J01, 1); #endif
    #ifdef J02 setAutoState(J02, 0x0258); if(([J02.0]&7)!=1) setStatus(J02, 1); #endif
    delayedCall(OFF, 1);
  }
}