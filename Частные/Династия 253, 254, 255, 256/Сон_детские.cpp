/*
{
  desc:"Сон детские",
  tag:"item",
  selectArea:true,
  name:"Сон",
  vars:[
  {name:"L00", type:"devices-list", required:true, filter:["lamp", "dimer-lamp"], desc:"Свет 1", width:555},
  {name:"L01", type:"devices-list", required:true, filter:["lamp", "dimer-lamp"], desc:"Свет 2", width:555},
  {name:"L02", type:"devices-list", required:true, filter:["lamp", "dimer-lamp"], desc:"Свет 3", width:555},
  {name:"L03", type:"devices-list", required:true, filter:["lamp", "dimer-lamp"], desc:"Свет 4", width:555},
  {name:"L04", type:"devices-list", required:true, filter:["lamp", "dimer-lamp"], desc:"Свет 5", width:555},
  {name:"J00", type:"devices-list", required:true, filter:["jalousie"], desc:"Штора", width:555},
  {name:"J01", type:"devices-list", required:true, filter:["jalousie"], desc:"Тюль", width:555},
  ]
}
*/

void OFF(){
  setStatus(V-ADDR, 0);
}

V-ID/V-ADDR{
  if((opt(0)&1)==1){
    #ifdef L00 setStatus(L00, 0); #endif
    #ifdef L01 setStatus(L01, 0); #endif
    #ifdef L02 setStatus(L02, 0); #endif
    #ifdef L03 setStatus(L03, 0); #endif
    #ifdef L04 setStatus(L04, 0); #endif
    #ifdef J00 if(([J00.0]&7)!=0) setStatus(J00, 0); #endif
    #ifdef J01 if(([J01.0]&7)!=0) setStatus(J01, 0); #endif
    delayedCall(OFF, 1);
  }
}