/*
{
  desc:"Объединение",
  tag:"item",
  name:"Объединение",
  selectArea:true,
  vars:[
        {name:"I00",type:"devices-list",required:false,filter:["script"],desc:"Скрипт"},
        {name:"I01",type:"devices-list",required:false,filter:["script"],desc:"Скрипт"},
        {name:"I02",type:"devices-list",required:false,filter:["script"],desc:"Скрипт"},
        {name:"I03",type:"devices-list",required:false,filter:["script"],desc:"Скрипт"},
  ]
}
*/

V-ID/V-ADDR{
  #ifdef I00 setStatus(I00, opt(0)&1); #endif
  #ifdef I01 setStatus(I01, opt(0)&1); #endif
  #ifdef I02 setStatus(I02, opt(0)&1); #endif
  #ifdef I03 setStatus(I03, opt(0)&1); #endif
}

V-ID/s:1{
  if(
  #ifdef I00 (([I00.0]&1)==0) #endif
  #ifdef I01 || (([I01.0]&1)==0) #endif
  #ifdef I02 || (([I02.0]&1)==0) #endif
  #ifdef I03 || (([I03.0]&1)==0) #endif){
    setStatus(V-ADDR, 0);
} else if(
  #ifdef I00 (([I00.0]&1)==1) #endif
  #ifdef I01 && (([I01.0]&1)==1) #endif
  #ifdef I02 && (([I02.0]&1)==1) #endif
  #ifdef I03 && (([I03.0]&1)==1) #endif){
  setStatus(V-ADDR, 1);
}
}