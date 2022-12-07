/*
{
  desc:"Будильник",
  tag:"item",
  selectArea:true,
  vars:[
  {name:"TIME00",type:"string",required:false,min:1,max:10,desc:"Время выключения автоматизации в 16ти ричной системе",width:300},
  {type:"comment",text:"Диммера:",width:200, style:"color:red;"},
  {name:"DIM00",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 0",descWidth:500,width:500},
  {name:"DIM01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 1",descWidth:500,width:500},
  {name:"DIM02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 2",descWidth:500,width:500},
  {name:"DIM03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 3",descWidth:500,width:500},
  {name:"DIM04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 4",descWidth:500,width:500},
  {name:"DIM05",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 5",descWidth:500,width:500},
  {name:"DIM06",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 6",descWidth:500,width:500},
  {name:"DIM07",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 7",descWidth:500,width:500},
  {name:"DIM08",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 8",descWidth:500,width:500},
  {name:"DIM09",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 9",descWidth:500,width:500},
  {name:"DIM10",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 10",descWidth:500,width:500},
  {name:"DIM11",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 11",descWidth:500,width:500},
  {name:"DIM12",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 12",descWidth:500,width:500},
  {name:"DIM13",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 13",descWidth:500,width:500},
  {name:"DIM14",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 14",descWidth:500,width:500},
  {name:"DIM15",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 15",descWidth:500,width:500},
  ]
}
*/

u8 bright=0;

void OFFAUTO()
{
  #ifdef DIM00 setAutoState(DIM00, TIME00); #endif
  #ifdef DIM01 setAutoState(DIM01, TIME00); #endif
  #ifdef DIM02 setAutoState(DIM02, TIME00); #endif
  #ifdef DIM03 setAutoState(DIM03, TIME00); #endif
  #ifdef DIM04 setAutoState(DIM04, TIME00); #endif
  #ifdef DIM05 setAutoState(DIM05, TIME00); #endif
  #ifdef DIM06 setAutoState(DIM06, TIME00); #endif
  #ifdef DIM07 setAutoState(DIM07, TIME00); #endif
  #ifdef DIM08 setAutoState(DIM08, TIME00); #endif
  #ifdef DIM09 setAutoState(DIM09, TIME00); #endif
  #ifdef DIM10 setAutoState(DIM10, TIME00); #endif
  #ifdef DIM11 setAutoState(DIM11, TIME00); #endif
  #ifdef DIM12 setAutoState(DIM12, TIME00); #endif
  #ifdef DIM13 setAutoState(DIM13, TIME00); #endif
  #ifdef DIM14 setAutoState(DIM14, TIME00); #endif
  #ifdef DIM15 setAutoState(DIM15, TIME00); #endif
}

void ONAUTO()
{
  #ifdef DIM00 setAutoState(DIM00, 0); #endif
  #ifdef DIM01 setAutoState(DIM01, 0); #endif
  #ifdef DIM02 setAutoState(DIM02, 0); #endif
  #ifdef DIM03 setAutoState(DIM03, 0); #endif
  #ifdef DIM04 setAutoState(DIM04, 0); #endif
  #ifdef DIM05 setAutoState(DIM05, 0); #endif
  #ifdef DIM06 setAutoState(DIM06, 0); #endif
  #ifdef DIM07 setAutoState(DIM07, 0); #endif
  #ifdef DIM08 setAutoState(DIM08, 0); #endif
  #ifdef DIM09 setAutoState(DIM09, 0); #endif
  #ifdef DIM10 setAutoState(DIM10, 0); #endif
  #ifdef DIM11 setAutoState(DIM11, 0); #endif
  #ifdef DIM12 setAutoState(DIM12, 0); #endif
  #ifdef DIM13 setAutoState(DIM13, 0); #endif
  #ifdef DIM14 setAutoState(DIM14, 0); #endif
  #ifdef DIM15 setAutoState(DIM15, 0); #endif
}

void RAZGORANIE()
{
  bright+=5;
  #ifdef DIM00 if( ([DIM00.0]&1)==1 && [DIM00.1]==bright-5 ) {setStatus(DIM00, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM01 if( ([DIM01.0]&1)==1 && [DIM01.1]==bright-5 ) {setStatus(DIM01, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM02 if( ([DIM02.0]&1)==1 && [DIM02.1]==bright-5 ) {setStatus(DIM02, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM03 if( ([DIM03.0]&1)==1 && [DIM03.1]==bright-5 ) {setStatus(DIM03, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM04 if( ([DIM04.0]&1)==1 && [DIM04.1]==bright-5 ) {setStatus(DIM04, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM05 if( ([DIM05.0]&1)==1 && [DIM05.1]==bright-5 ) {setStatus(DIM05, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM06 if( ([DIM06.0]&1)==1 && [DIM06.1]==bright-5 ) {setStatus(DIM06, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM07 if( ([DIM07.0]&1)==1 && [DIM07.1]==bright-5 ) {setStatus(DIM07, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM08 if( ([DIM08.0]&1)==1 && [DIM08.1]==bright-5 ) {setStatus(DIM08, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM09 if( ([DIM09.0]&1)==1 && [DIM09.1]==bright-5 ) {setStatus(DIM09, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM10 if( ([DIM10.0]&1)==1 && [DIM10.1]==bright-5 ) {setStatus(DIM10, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM11 if( ([DIM11.0]&1)==1 && [DIM11.1]==bright-5 ) {setStatus(DIM11, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM12 if( ([DIM12.0]&1)==1 && [DIM12.1]==bright-5 ) {setStatus(DIM12, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM13 if( ([DIM13.0]&1)==1 && [DIM13.1]==bright-5 ) {setStatus(DIM13, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM14 if( ([DIM14.0]&1)==1 && [DIM14.1]==bright-5 ) {setStatus(DIM14, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  #ifdef DIM15 if( ([DIM15.0]&1)==1 && [DIM15.1]==bright-5 ) {setStatus(DIM15, {1, bright, 1});} else {setStatus(V-ADDR, 0);} #endif
  
  if(bright>=250) setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
  if((opt(0)&1)==1)
  {
    //Обнуляем яркость
    //Выключаем автоматизации
    OFFAUTO();
    //Обнуляем яркость
    bright=0;
      #ifdef DIM00 if( ([DIM00.0]&1)==0 ) {setStatus(DIM00, {1, 0, 1});} #endif
      #ifdef DIM01 if( ([DIM01.0]&1)==0 ) {setStatus(DIM01, {1, 0, 1});} #endif
      #ifdef DIM02 if( ([DIM02.0]&1)==0 ) {setStatus(DIM02, {1, 0, 1});} #endif
      #ifdef DIM03 if( ([DIM03.0]&1)==0 ) {setStatus(DIM03, {1, 0, 1});} #endif
      #ifdef DIM04 if( ([DIM04.0]&1)==0 ) {setStatus(DIM04, {1, 0, 1});} #endif
      #ifdef DIM05 if( ([DIM05.0]&1)==0 ) {setStatus(DIM05, {1, 0, 1});} #endif
      #ifdef DIM06 if( ([DIM06.0]&1)==0 ) {setStatus(DIM06, {1, 0, 1});} #endif
      #ifdef DIM07 if( ([DIM07.0]&1)==0 ) {setStatus(DIM07, {1, 0, 1});} #endif
      #ifdef DIM08 if( ([DIM08.0]&1)==0 ) {setStatus(DIM08, {1, 0, 1});} #endif
      #ifdef DIM09 if( ([DIM09.0]&1)==0 ) {setStatus(DIM09, {1, 0, 1});} #endif
      #ifdef DIM10 if( ([DIM10.0]&1)==0 ) {setStatus(DIM10, {1, 0, 1});} #endif
      #ifdef DIM11 if( ([DIM11.0]&1)==0 ) {setStatus(DIM11, {1, 0, 1});} #endif
      #ifdef DIM12 if( ([DIM12.0]&1)==0 ) {setStatus(DIM12, {1, 0, 1});} #endif
      #ifdef DIM13 if( ([DIM13.0]&1)==0 ) {setStatus(DIM13, {1, 0, 1});} #endif
      #ifdef DIM14 if( ([DIM14.0]&1)==0 ) {setStatus(DIM14, {1, 0, 1});} #endif
      #ifdef DIM15 if( ([DIM15.0]&1)==0 ) {setStatus(DIM15, {1, 0, 1});} #endif
    delayedCallR(RAZGORANIE, 6);
  }
  else if( (opt(0)&1)==0 )
  {
    cancelDelayedCall(RAZGORANIE);
    ONAUTO();
  }
}