/*
{
  desc:"Протечка RHX без клапана",
  tag:"item",
  selectArea:true,
  name:"Вода",

  vars:[
        {name:"OPEN",type:"devices-list",required:false,width:200,filter:["lamp"],desc:"Открыть"},
        {name:"CLOSE",type:"devices-list",required:false,width:200,filter:["lamp"],desc:"Закрыть"},
        {type:"comment",style:"color:green; font-weight:bold;", text:"Время закрытия клапана:"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"LEAK01",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 1"},
        {name:"LEAK02",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 2"},
        {name:"LEAK03",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 3"},
        {name:"LEAK04",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 4"},
        {name:"LEAK05",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 5"},
        {name:"LEAK06",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 6"},
        {name:"LEAK07",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 7"},
        {name:"LEAK08",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 8"},
        {name:"LEAK09",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 9"},
        {name:"LEAK10",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 10"},
        {name:"LEAK11",type:"devices-list",required:false,width:200,filter:["leak-sensor"],desc:"Датчик протечки 11"},
  ]
}
*/

V-ID/LEAK01#ifdef LEAK02, LEAK02#endif#ifdef LEAK03, LEAK03#endif#ifdef LEAK04, LEAK04#endif#ifdef LEAK05, LEAK05#endif#ifdef LEAK06, LEAK06#endif#ifdef LEAK07, LEAK07#endif#ifdef LEAK08, LEAK08#endif#ifdef LEAK09, LEAK09#endif#ifdef LEAK10, LEAK10#endif#ifdef LEAK11, LEAK11#endif
{
  if(opt(0)==1)
  {
    setStatus(V-ADDR, 0);
  }
}

void onInit()
{
  setStatus(V-ADDR, 1);
}

void OFF()
{
  setStatus(OPEN, 0);
  setStatus(CLOSE, 0);
}

V-ID/V-ADDR
{
  if((opt(0)&1)==0)
  {
    cancelDelayedCall(OFF);
    setStatus(OPEN, 0);
    setStatus(CLOSE, 1);
    delayedCall(OFF, TIME);
  }
  else if((opt(0)&1)==1)
  {
    if(
      ![LEAK01.0]
      #ifdef LEAK02 && ![LEAK02.0] #endif
      #ifdef LEAK03 && ![LEAK03.0] #endif
      #ifdef LEAK04 && ![LEAK04.0] #endif
      #ifdef LEAK05 && ![LEAK05.0] #endif
      #ifdef LEAK06 && ![LEAK06.0] #endif
      #ifdef LEAK07 && ![LEAK07.0] #endif
      #ifdef LEAK08 && ![LEAK08.0] #endif
      #ifdef LEAK09 && ![LEAK09.0] #endif
      #ifdef LEAK10 && ![LEAK10.0] #endif
      #ifdef LEAK11 && ![LEAK11.0] #endif)
    {
        cancelDelayedCall(OFF);
        setStatus(OPEN, 1);
        setStatus(CLOSE, 0);
        delayedCall(OFF, TIME);
    }
    else
    {
        setStatus(2047:32, {8, "Один из датчиков мокрый!"});
        setStatus(V-ADDR, 0);
    }
  }
}