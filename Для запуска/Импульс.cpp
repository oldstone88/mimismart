/*
{
  desc:"Импульс",
  tag:"import-script",
  selectArea:true,
  vars:[
  {name:"ZAMOK", type:"devices-list", required:true, filter:["lamp"], descWidth:370, desc:"Замок"},
  {name:"TIME", type:"number", defaultValue:10, required:true, desc:"Время замыкания"},
  ]
}
*/

u8 timer=0;

V-ID/s:1{
  ++timer;
  if(([ZAMOK.0]&1)==1 && timer>=TIME){
    setStatus(ZAMOK, 0);
  } else if( ([ZAMOK.0]&1)==0 ) timer=0;
}