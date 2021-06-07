/*
{
  desc:"Пожарная тревога",
  tag:"import-script",
  selectArea:true,
  vars:[
{name:"P00",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"Лестница 2й этаж"},
{name:"P01",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"Птички"},
{name:"P02",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"Детская 1"},
{name:"P03",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"Детская 2"},
{name:"P04",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"СУ 3-й этаж"},
{name:"P05",type:"devices-list",required:false, width:600, filter:["door-sensor"],desc:"Гостиная"},
  ]                       
}
*/


#ifdef P00
void DANGER00()
{
  setStatus(2047:32, {8, "Дым Лестница 2-й этаж!!!"});
}

V-ID/P00
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым Лестница 2-й этаж!!!"}); delayedCall(DANGER00, 720);} else {cancelDelayedCall(DANGER00);}
}
#endif

#ifdef P01
void DANGER01()
{
  setStatus(2047:32, {8, "Дым Птички!!!"});
}

V-ID/P01
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым Птички!!!!"}); delayedCall(DANGER01, 720);} else {cancelDelayedCall(DANGER01);}
}
#endif

#ifdef P02
void DANGER02()
{
  setStatus(2047:32, {8, "Дым Детская 1!!!"});
}

V-ID/P02
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым Детская 1!!!"}); delayedCall(DANGER02, 720);} else {cancelDelayedCall(DANGER02);}
}
#endif

#ifdef P03
void DANGER03()
{
  setStatus(2047:32, {8, "Дым Детская 2!!!"});
}

V-ID/P03
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым Детская 2!!!"}); delayedCall(DANGER03, 720);} else {cancelDelayedCall(DANGER03);}
}
#endif

#ifdef P04
void DANGER04()
{
  setStatus(2047:32, {8, "Дым СУ 3-й этаж!!!"});
}

V-ID/P04
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым СУ 3-й этаж!!!"}); delayedCall(DANGER04, 720);} else {cancelDelayedCall(DANGER04);}
}
#endif

#ifdef P05
void DANGER05()
{
  setStatus(2047:32, {8, "Дым Гостиная!!!"});
}

V-ID/P05
{
  if(opt(0)==1) {setStatus(2047:32, {8, "Дым Гостиная!!!"}); delayedCall(DANGER05, 720);} else {cancelDelayedCall(DANGER05);}
}
#endif
