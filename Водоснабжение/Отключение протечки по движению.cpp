/*
{
  desc:"Отключение протечки по движению",
  tag:"item",
  name:"Отключение протечки",
  selectArea:true,
  vars:[
	{name:"LEAK00",type:"devices-list",required:true,filter:["leak-sensor"],desc:"Датчик протечки 0",descWidth:300,width:500},
  {name:"LEAK01",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки 1",descWidth:300,width:500},
  {name:"LEAK02",type:"devices-list",required:false,filter:["leak-sensor"],desc:"Датчик протечки 2",descWidth:300,width:500},
  ]
}
*/

V-ID/V-ADDR
{
	if( (opt(0)&1)==1 )
  {
    setStatus(LEAK00, {0xC2, 0x01});
    #ifdef LEAK01 setStatus(LEAK01, {0xC2, 0x01}); #endif
    #ifdef LEAK02 setStatus(LEAK02, {0xC2, 0x01}); #endif
  }
  else if((opt(0)&1)==0)
  {
    setStatus(LEAK00, 0);
    #ifdef LEAK01 setStatus(LEAK01, 0); #endif
    #ifdef LEAK02 setStatus(LEAK02, 0); #endif
  }
}
