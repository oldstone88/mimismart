/*
{
  desc:"Будильник-Штора",
  
  tag:"item",
  selectArea:true,
  vars:[
   	{name:"JAL00",type:"devices-list",required:false, filter:["jalousie"],desc:"Штора"},
{name:"TIME",type:"number",required:true,width:100,defaultValue:1,min:1,max:30,desc:"Время открытия"},

]
}
*/

void STOP()
{
  setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
  if ( (opt(0)&1)==1 )
  {
    if( ([JAL00.0]&7)==0 || ([JAL00.0]&7)==4 ) {setStatus(JAL00, 1);}
    delayedCall(STOP, TIME);
  } else
  if( (opt(0)&1)==0 )
  {
    if( ([JAL00.0]&7)==3 ) setStatus(JAL00, 1);
  }
}
