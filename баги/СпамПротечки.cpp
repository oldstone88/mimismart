/*
{
  desc:"Скрипт игнорирования протески 30 минут",
  tag:"import-script",
  selectArea:false,
  vars:[
 {name:"LEAK00",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK01",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK02",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK03",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK04",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK05",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK06",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK07",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK08",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
 {name:"LEAK09",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки"},
  ]
}
*/

u8 i=0;

const u16 ID [] = {
    ADDR2ID(LEAK00)
    #ifdef LEAK01, ADDR2ID(LEAK01) #else ,0 #endif
    #ifdef LEAK02, ADDR2ID(LEAK02) #else ,0 #endif
    #ifdef LEAK03, ADDR2ID(LEAK03) #else ,0 #endif
    #ifdef LEAK04, ADDR2ID(LEAK04) #else ,0 #endif
    #ifdef LEAK05, ADDR2ID(LEAK05) #else ,0 #endif
    #ifdef LEAK06, ADDR2ID(LEAK06) #else ,0 #endif
    #ifdef LEAK07, ADDR2ID(LEAK07) #else ,0 #endif
    #ifdef LEAK08, ADDR2ID(LEAK08) #else ,0 #endif
    #ifdef LEAK09, ADDR2ID(LEAK09) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(LEAK00)
    #ifdef LEAK01, ADDR2SID(LEAK01) #else ,0 #endif
    #ifdef LEAK02, ADDR2SID(LEAK02) #else ,0 #endif
    #ifdef LEAK03, ADDR2SID(LEAK03) #else ,0 #endif
    #ifdef LEAK04, ADDR2SID(LEAK04) #else ,0 #endif
    #ifdef LEAK05, ADDR2SID(LEAK05) #else ,0 #endif
    #ifdef LEAK06, ADDR2SID(LEAK06) #else ,0 #endif
    #ifdef LEAK07, ADDR2SID(LEAK07) #else ,0 #endif
    #ifdef LEAK08, ADDR2SID(LEAK08) #else ,0 #endif
    #ifdef LEAK09, ADDR2SID(LEAK09) #else ,0 #endif
};

//<import-script id="535" LEAK="535:8" path="scripts/script_wleak.txt"/>
void OFF()
{
  setStatus(@ID[i]:@SID[i], {0x08,0x07} );
}

V-ID/LEAK00{
  if(opt(0)==1){
    i=0; delayedCall(OFF, 1);
  } 
}

#ifdef LEAK01
V-ID/LEAK01{
  if(opt(0)==1){
   i=1; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK02
V-ID/LEAK02{
  if(opt(0)==1){
    i=2; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK03
V-ID/LEAK03{
  if(opt(0)==1){
    i=3; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK04
V-ID/LEAK04{
  if(opt(0)==1){
    i=4; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK05
V-ID/LEAK05{
  if(opt(0)==1){
    i=5; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK06
V-ID/LEAK06{
  if(opt(0)==1){
    i=6; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK07
V-ID/LEAK07{
  if(opt(0)==1){
    i=7; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK08
V-ID/LEAK08{
  if(opt(0)==1){
    i=8; delayedCall(OFF, 1);
  } 
}
#endif

#ifdef LEAK09
V-ID/LEAK09{
  if(opt(0)==1){
    i=9; delayedCall(OFF, 1);
  } 
}
#endif
