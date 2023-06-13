/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  name:"Климат",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "vane-hor":"0x00", "vane-ver":"0x00", "modes":"0x00", "funs":"0x01"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE00", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"VALVE01", type:"devices-list", required:false, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  ]
}
*/

u8 k[5];

V-ID/s:30{
  if ([AUTO.0]%2!=0){
    //Отопление
    if( ([AUTO.1]+18)!=[VALVE00.2] ) {u8 buff=([AUTO.1]+18); setStatus(1000:102, {"VALVE00\0t:"A, buff,0});}
    #ifdef VALVE01 if( ([AUTO.1]+18)!=[VALVE01.2] ) {u8 buff=([AUTO.1]+18); setStatus(1000:102, {"VALVE01\0t:"A, buff,0});} #endif
    //Кондиционирование
    getStatus(COND, &k);
    u8 Month = month(); // Смотрим какой сейчас месяц
    if( Month>2  && Month<10) //C Апреля по Октябрь можно включать кондиционер
    {
      i16 tempAuto=([COND.1]+18)*10; //Температура уставки
      i16 tempRoom=([KOMHATA.1]*10)+(([KOMHATA.0]*10)/250); //Температура в комнате

      if( (tempAuto+10 < tempRoom) ) {k[0]=1; k[4]=[AUTO.4]; k[1]=0; setStatus(COND, &k);} //Охлаждение
      else if(tempAuto-5 > tempRoom ) {k[0]=k[0]&0xFE; setStatus(COND, &k);} //Достаточно охладили
    }
    else {if( ([AUTO.0]%2)!=0) k[0]=k[0]&0xFE; setStatus(COND, &k);}
  }
}

V-ID/AUTO{
  if ([AUTO.0]%2!=0){
    setStatus(1000:102, "VALVE00\0Авто");
    #ifdef VALVE01 setStatus(1000:102, "VALVE01\0Авто"); #endif
  } else
  if ([AUTO.0]%2==0){
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(1000:102,"VALVE00\0as:-4");
    #ifdef VALVE01 setStatus(1000:102, "VALVE01\0as:-4"); #endif
    setStatus(COND, &k);
  }
}