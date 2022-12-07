/*
{
  desc:"Пожарная сигнализация",
  tag:"item",
  selectArea:true,

  vars:[
  {name:"FIRE", type:"devices-list", required:true, filter:["door-sensor"], descWidth:370, desc:"Датчик сигнализации"},
  {name:"ITEM00", type:"devices-list", required:false, filter:["script"], desc:"Вентиляция-гост", descWidth:370},
  {name:"ITEM01", type:"devices-list", required:false, filter:["script"], desc:"Вентиляция-спальня", descWidth:370},
  {name:"VENT00", type:"devices-list", required:false, filter:["virtual"], desc:"Вентиляция", descWidth:370},
  {name:"VENT01", type:"devices-list", required:false, filter:["virtual"], desc:"Вентиляция", descWidth:370},
  {name:"VENT02", type:"devices-list", required:false, filter:["virtual"], desc:"Вентиляция", descWidth:370},
  {name:"SHADE00", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 0", descWidth:370},
  {name:"SHADE01", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 1", descWidth:370},
  {name:"SHADE02", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 2", descWidth:370},
  {name:"SHADE03", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 3", descWidth:370},
  {name:"SHADE04", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 4", descWidth:370},
  {name:"SHADE05", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 5", descWidth:370},
  {name:"SHADE06", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 6", descWidth:370},
  {name:"SHADE07", type:"devices-list", required:false, filter:["jalousie"], desc:"Штора 7", descWidth:370},
  ]
}
*/

u8 i=0;

void onInit()
{
  setStatus(V-ADDR, 1);
}

V-ID/s:5
{
  if(([V-ADDR.0]&1)==1)
    {
      
        if([FIRE.0]==1)
        {
          if(i==0){setStatus(2047:32, {8, "ПОЖАР!!!"}); i=1;}
          #ifdef ITEM00 if(([ITEM00.0]&7)==1 || ([ITEM00.0]&7)==4 || ([ITEM00.0]&7)==3) setStatus(ITEM00, 0); #endif
          #ifdef ITEM01 if(([ITEM01.0]&7)==1 || ([ITEM01.0]&7)==4 || ([ITEM01.0]&7)==3) setStatus(ITEM01, 0); #endif
          #ifdef VENT00 if(([VENT00.0]&7)==1 || ([VENT00.0]&7)==4 || ([VENT00.0]&7)==3) setStatus(VENT00, 0); #endif
          #ifdef VENT01 if(([VENT01.0]&7)==1 || ([VENT01.0]&7)==4 || ([VENT01.0]&7)==3) setStatus(VENT01, 0); #endif
          #ifdef VENT02 if(([VENT02.0]&7)==1 || ([VENT02.0]&7)==4 || ([VENT02.0]&7)==3) setStatus(VENT02, 0); #endif
          #ifdef SHADE00 if(([SHADE00.0]&7)==0 || ([SHADE00.0]&7)==4 || ([SHADE00.0]&7)==2 || ([SHADE00.0]&7)==5) setStatus(SHADE00, 1); #endif
          #ifdef SHADE01 if(([SHADE01.0]&7)==0 || ([SHADE01.0]&7)==4 || ([SHADE01.0]&7)==2 || ([SHADE01.0]&7)==5) setStatus(SHADE01, 1); #endif
          #ifdef SHADE02 if(([SHADE02.0]&7)==0 || ([SHADE02.0]&7)==4 || ([SHADE02.0]&7)==2 || ([SHADE02.0]&7)==5) setStatus(SHADE02, 1); #endif
          #ifdef SHADE03 if(([SHADE03.0]&7)==0 || ([SHADE03.0]&7)==4 || ([SHADE03.0]&7)==2 || ([SHADE03.0]&7)==5) setStatus(SHADE03, 1); #endif
          #ifdef SHADE04 if(([SHADE04.0]&7)==0 || ([SHADE04.0]&7)==4 || ([SHADE04.0]&7)==2 || ([SHADE04.0]&7)==5) setStatus(SHADE04, 1); #endif
          #ifdef SHADE05 if(([SHADE05.0]&7)==0 || ([SHADE05.0]&7)==4 || ([SHADE05.0]&7)==2 || ([SHADE05.0]&7)==5) setStatus(SHADE05, 1); #endif
          #ifdef SHADE06 if(([SHADE06.0]&7)==0 || ([SHADE06.0]&7)==4 || ([SHADE06.0]&7)==2 || ([SHADE06.0]&7)==5) setStatus(SHADE06, 1); #endif
          #ifdef SHADE07 if(([SHADE07.0]&7)==0 || ([SHADE07.0]&7)==4 || ([SHADE07.0]&7)==2 || ([SHADE07.0]&7)==5) setStatus(SHADE07, 1); #endif
        } else if(i!=0) i=0;
    }
}