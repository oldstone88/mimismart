/*
{
  desc:"Контактор-геркон",
  tag:"import-script",
  selectArea:true,
  name:"Контактор-геркон",
  
  vars:[
    {name:"L00",type:"devices-list",required:true,filter:["lamp", "light-scheme"],desc:"Контактор",width:600},
    {name:"H00",type:"devices-list",required:true,filter:["door-sensor"],desc:"Геркон",width:600},
  ]
}
*/

V-ID/H00
{
    if((opt(0)&1)==1)
    {
        if(([L00.0]&1)==0) {setAutoState(L00, 0x00B4); setStatus(L00, 1);}
    }
}