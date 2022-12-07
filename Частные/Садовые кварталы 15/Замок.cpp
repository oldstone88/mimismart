/*
{
  desc:"Замок",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"LAMP",type:"devices-list",required:true,filter:["lamp"],desc:"Замок"},
  ]
}
*/

u8 i=0;

V-ID/s:1
{
  if(([LAMP.0]&1)==1) {++i;} else if(i!=0)i=0;
  if(i>3) setStatus(LAMP, 0);
}