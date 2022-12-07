/*
{
desc:"Автокотлы",
tag:"item",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Котел Газ",descWidth:100},
{name:"K01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Котел Электро",descWidth:100},
{name:"V00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Котел Газ",descWidth:100},
{name:"V01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Котел Электро",descWidth:100},
{name:"BOILER",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Бойлер",descWidth:100},
]
}
*/

u8 i=0;
u8 on=0;
u8 old[4]={0, 0, 0, 0};
u8 cond[5];

start()
{
   setStatus(V-ADDR, 1);
   if( ([BOILER.0]&1)==0 && on==0) on=1; 
}

void onInit()
{
   delayedCall(start, 5);
}

V-ID/s:5
{
   if( ([BOILER.0]&1)==1 && on!=1 && ([V-ADDR.0]&1)==1 )
   {
      on=1;
      #ifdef K00 getStatus(K00, &cond);
      old[0]=cond[0]; old[1]=cond[1]; cond[0]=1; cond[1]=40;
      setStatus(K00, &cond); #endif
      #ifdef K01 getStatus(K01, &cond);
      old[2]=cond[0]; old[3]=cond[1]; cond[0]=1; cond[1]=80;
      setStatus(K01, &cond); #endif
      setStatus(1000:102,"V00\0as:-4"); setStatus(V00, 1);
      setStatus(1000:102,"V01\0as:-4"); setStatus(V01, 1);
   } else
   if( ([BOILER.0]&1)==0 && on!=0 && ([V-ADDR.0]&1)==1 )
   {
      on=0;
      #ifdef K00 getStatus(K00, &cond);
      if( old[0]!=0 && old[1]!=0 ) {cond[0]=old[0]; cond[1]=old[1];}
      setStatus(K00, &cond); #endif
      #ifdef K01 getStatus(K01, &cond);
      if( old[2]!=0 && old[3]!=0 ) {cond[0]=old[2]; cond[1]=old[3];}
      setStatus(K00, &cond); #endif
      setStatus(1000:102, "V00\0Газ");
      setStatus(1000:102, "V01\0Электро");
   }
}