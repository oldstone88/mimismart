/*
{
  desc:"Контактор-геркон",
  tag:"import-script",
  selectArea:true,
  name:"Контактор-геркон",
  
  vars:[
    {name:"TIME",type:"number",required:true,defaultValue:7,min:1,max:100,desc:"Время задержки при открытии",descWidth:350},
    {name:"L00",type:"devices-list",required:true,filter:["conditioner"],desc:"Кондиционер",width:600},
    {name:"H00",type:"devices-list",required:true,filter:["door-sensor"],desc:"Геркон",width:600},
  ]
}
*/

u8 i=0;
u8 last=0;

V-ID/s:5
{
  if( ([H00.0]==1) && (([L00.0]%2)==1) ){
    if( i*5>TIME ){
      u8 state[5];
      last=1;
      getStatus(L00, &state); state[0]=state[0]&0xFE;
      setStatus(L00, &state);
     } else ++i;
  } else if([H00.0]==0 && last==1){
      u8 state[5];
      i=0;
      last=0;
      getStatus(L00, &state); state[0]=state[0]|0x01;
      setStatus(L00, &state);
  }
   else i=0;
  }
}