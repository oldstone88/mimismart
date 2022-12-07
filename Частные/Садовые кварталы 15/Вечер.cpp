/*
{
  desc:"Вечер",
  tag:"item",
  name:"Вечер",
  selectArea:true,
  vars:[
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

void OFF()
{setStatus(V-ADDR, 0);}

V-ID/V-ADDR
{
  if((opt(0)&1)==1)
  {
    //Выставляем яркость
      #ifdef DIM00 if(([DIM00.0]&1)==0 || [DIM00.1]>75 ) {setStatus(DIM00, {0xFE, 75, 1});} #endif
      #ifdef DIM01 if(([DIM01.0]&1)==0 || [DIM01.1]>75 ) {setStatus(DIM01, {0xFE, 75, 1});} #endif
      #ifdef DIM02 if(([DIM02.0]&1)==0 || [DIM02.1]>75 ) {setStatus(DIM02, {0xFE, 75, 1});} #endif
      #ifdef DIM03 if(([DIM03.0]&1)==0 || [DIM03.1]>75 ) {setStatus(DIM03, {0xFE, 75, 1});} #endif
      #ifdef DIM04 if(([DIM04.0]&1)==0 || [DIM04.1]>75 ) {setStatus(DIM04, {0xFE, 75, 1});} #endif
      #ifdef DIM05 if(([DIM05.0]&1)==0 || [DIM05.1]>75 ) {setStatus(DIM05, {0xFE, 75, 1});} #endif
      #ifdef DIM06 if(([DIM06.0]&1)==0 || [DIM06.1]>75 ) {setStatus(DIM06, {0xFE, 75, 1});} #endif
      #ifdef DIM07 if(([DIM07.0]&1)==0 || [DIM07.1]>75 ) {setStatus(DIM07, {0xFE, 75, 1});} #endif
      #ifdef DIM08 if(([DIM08.0]&1)==0 || [DIM08.1]>75 ) {setStatus(DIM08, {0xFE, 75, 1});} #endif
      #ifdef DIM09 if(([DIM09.0]&1)==0 || [DIM09.1]>75 ) {setStatus(DIM09, {0xFE, 75, 1});} #endif
      #ifdef DIM10 if(([DIM10.0]&1)==0 || [DIM10.1]>75 ) {setStatus(DIM10, {0xFE, 75, 1});} #endif
      #ifdef DIM11 if(([DIM11.0]&1)==0 || [DIM11.1]>75 ) {setStatus(DIM11, {0xFE, 75, 1});} #endif
      #ifdef DIM12 if(([DIM12.0]&1)==0 || [DIM12.1]>75 ) {setStatus(DIM12, {0xFE, 75, 1});} #endif
      #ifdef DIM13 if(([DIM13.0]&1)==0 || [DIM13.1]>75 ) {setStatus(DIM13, {0xFE, 75, 1});} #endif
      #ifdef DIM14 if(([DIM14.0]&1)==0 || [DIM14.1]>75 ) {setStatus(DIM14, {0xFE, 75, 1});} #endif
      #ifdef DIM15 if(([DIM15.0]&1)==0 || [DIM15.1]>75 ) {setStatus(DIM15, {0xFE, 75, 1});} #endif
    delayedCall(OFF, 1);
    }
}