/*
{
  desc:"Спорт",
  tag:"item",
  selectArea:true,
  name:"Спорт",
  vars:[
  {name:"MEDIA", type:"devices-list", required:false, filter:["script"], desc:"Музыка", width:555},
  {name:"COND", type:"devices-list", required:false, filter:["conditioner], desc:"Кондиционер", width:555},
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
    #ifdef COND
    u8 Month = month();
    if(Month>5 && Month<8){
      u8 condState[5]={0, 0, 0, 0, 0};
      condState[0]=1; condState[1]=6;
      setStatus(COND, &condState);
    }
    #endif
    #ifdef J00 if(([J00.0]&7)!=1) setStatus(J00, 1); #endif
    #ifdef J01 if(([J01.0]&7)!=1) setStatus(J01, 1); #endif
    #ifdef J02 if(([J02.0]&7)!=1) setStatus(J02, 1); #endif
    delayedCall(OFF, 1);
  }
}