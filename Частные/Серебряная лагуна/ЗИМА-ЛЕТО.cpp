/*
{
  desc:"ЗИМА-ЛЕТО",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"LETO",type:"devices-list",required:true,width:600,filter:["script"],desc:"Лето",descWidth:100},
    {name:"ZIMA",type:"devices-list",required:true,width:600,filter:["script"],desc:"Зима",descWidth:100},
    {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K01",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K02",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K03",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K04",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K05",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K06",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K07",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"K08",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат комнаты",descWidth:100},
    {name:"H00",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H01",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H02",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H03",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H04",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H05",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H06",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H07",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
    {name:"H08",type:"devices-list",required:false,width:600,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
  ]
}
*/

V-ID/s:60
{
  u8 temp=0;
  //if(([LETO.0]&1)==1 && temp<-1) {setStatus(ZIMA, 1);}
}

u8 i[5];

void cond1()
{
  setStatus(K01, &i);
}

void cond2()
{
  setStatus(K02, &i);
}

void cond3()
{
  setStatus(K03, &i);
}

void cond4()
{
  setStatus(K04, &i);
}

void cond5()
{
  setStatus(K05, &i);
}

void cond6()
{
  setStatus(K06, &i);
}

void cond7()
{
  setStatus(K07, &i);
}

void cond8()
{
  setStatus(K08, &i);
}

V-ID/LETO
{
  if((opt(0)&1)==1)
  {
    setStatus(ZIMA, 0);
    cancelDelayedCall(cond1);
    cancelDelayedCall(cond2);
    cancelDelayedCall(cond3);
    cancelDelayedCall(cond4);
    cancelDelayedCall(cond5);
    cancelDelayedCall(cond6);
    cancelDelayedCall(cond7);
    cancelDelayedCall(cond8);
    i[0]=1;
    i[1]=7;
    setStatus(1000:100, "always-off");
    #ifdef H00 setStatus(1000:102, "H00\0ts:25"); #endif
    #ifdef H01 setStatus(1000:102, "H01\0ts:25"); #endif
    #ifdef H02 setStatus(1000:102, "H02\0ts:25"); #endif
    #ifdef H03 setStatus(1000:102, "H03\0ts:25"); #endif
    #ifdef H04 setStatus(1000:102, "H04\0ts:25"); #endif
    #ifdef H05 setStatus(1000:102, "H05\0ts:25"); #endif
    #ifdef H06 setStatus(1000:102, "H06\0ts:25"); #endif
    #ifdef H07 setStatus(1000:102, "H07\0ts:25"); #endif
    #ifdef H07 setStatus(1000:102, "H08\0ts:25"); #endif
    setStatus(K00, &i);
    delayedCall(cond1, 1);
    delayedCall(cond2, 2);
    delayedCall(cond3, 3);
    delayedCall(cond4, 4);
    delayedCall(cond5, 5);
    delayedCall(cond6, 6);
    delayedCall(cond7, 7);
    delayedCall(cond8, 8);
  }
}

V-ID/ZIMA
{
    if((opt(0)&1)==1)
    {
      setStatus(LETO, 0);
      cancelDelayedCall(cond1);
      cancelDelayedCall(cond2);
      cancelDelayedCall(cond3);
      cancelDelayedCall(cond4);
      cancelDelayedCall(cond5);
      cancelDelayedCall(cond6);
      cancelDelayedCall(cond7);
      cancelDelayedCall(cond8);
      i[0]=1;
      i[1]=7;
      setStatus(1000:100, 0);
      #ifdef H00 setStatus(1000:102, "H00\0ts:30"); #endif
      #ifdef H01 setStatus(1000:102, "H01\0ts:30"); #endif
      #ifdef H02 setStatus(1000:102, "H02\0ts:30"); #endif
      #ifdef H03 setStatus(1000:102, "H03\0ts:30"); #endif
      #ifdef H04 setStatus(1000:102, "H04\0ts:30"); #endif
      #ifdef H05 setStatus(1000:102, "H05\0ts:30"); #endif
      #ifdef H06 setStatus(1000:102, "H06\0ts:30"); #endif
      #ifdef H07 setStatus(1000:102, "H07\0ts:30"); #endif
      #ifdef H07 setStatus(1000:102, "H08\0ts:30"); #endif
      setStatus(K00, &i);
      delayedCall(cond1, 1);
      delayedCall(cond2, 2);
      delayedCall(cond3, 3);
      delayedCall(cond4, 4);
      delayedCall(cond5, 5);
      delayedCall(cond6, 6);
      delayedCall(cond7, 7);
      delayedCall(cond8, 8);
    }
}