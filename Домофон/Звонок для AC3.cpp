/*
{
  desc:"Звонок на медиаточку",
  
  tag:"item",
  selectArea:true,
  vars:[
    {name:"POINT",type:"number",required:false,min:1,max:99,desc:"ID скрипта",descWidth:350},
]
}
*/

void OFF()
{
    setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1) {setStatus(1000:POINT, 1); delayedCall(OFF, 1);}
}