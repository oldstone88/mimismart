/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "vane-hor":"0x00", "vane-ver":"0x00", "funs":"0x01", "modes":"0x00"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"EL00", type:"devices-list", required:false, filter:["valve-heating"], desc:"Электро", descWidth:370},
  {name:"EL01", type:"devices-list", required:false, filter:["valve-heating"], desc:"Электро", descWidth:370},
  {name:"EL02", type:"devices-list", required:false, filter:["valve-heating"], desc:"Электро", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"STREET", type:"devices-list", required:true, filter:["virtual"], desc:"Датчик температуры улицы", descWidth:370},
  {name:"GIST", type:"number", defaultValue:10, required:true, desc:"Гистерезис нужно умножить на 10"},
  {name:"TIME", type:"number", defaultValue:10, required:true, desc:"Время до включенияэлектро конвекторов"},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];
u16 timer=0;
i8 buff=0;

void transform(u8 j) //Преобразование температуры для сравнения
{
  if((j&0x80)==0x80)
  {
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

void taketemp()
{
  tempAuto = [AUTO.1]*10;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
}

void OFFEL()
{
  timer=0;
  #ifdef EL00 if( ([EL00.0]&1)==1 ) setStatus(EL00, 0); #endif
  #ifdef EL01 if( ([EL01.0]&1)==1 ) setStatus(EL01, 0); #endif
  #ifdef EL02 if( ([EL02.0]&1)==1 ) setStatus(EL02, 0); #endif
}

void OFFALL()
{
  i=0;
  k[0]=k[0]&0xFE; setStatus(COND, &k);
  OFFEL();
}

void NAGREV()
{
  i=1;
  buff=-7; //Температура для сравнения
  if( transform([STREET.1])>=buff )// на улице больше -7 греем кондеем
  {
    if(k[0]!=49 || k[1]!=[AUTO.1] || k[4]!=4) {k[0]=49; k[1]=[AUTO.1]; k[4]=3; setStatus(COND, &k);}
    #ifdef EL00 if( ([EL00.0]&1)==0 && timer>=(TIME*12)) setStatus(EL00, 1); #endif
    #ifdef EL01 if( ([EL01.0]&1)==0 && timer>=(TIME*12)) setStatus(EL01, 1); #endif
    #ifdef EL02 if( ([EL02.0]&1)==0 && timer>=(TIME*12)) setStatus(EL02, 1); #endif
  } else // На улице меньше -7
  {
   if(k[0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
    #ifdef EL00 if( ([EL00.0]&1)==0) setStatus(EL00, 1); #endif
    #ifdef EL01 if( ([EL01.0]&1)==0) setStatus(EL01, 1); #endif
    #ifdef EL02 if( ([EL02.0]&1)==0) setStatus(EL02, 1); #endif
  }
}

void HOLOD()
{
  i=2;
  buff=19;
  if( transform([STREET.1])>buff ) //на улице больше 19
  {
    if(k[0]!=17 || k[1]!=[AUTO.1] || k[4]!=0) {k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);}
  } else // на улице меньше 19
  {
    if(k[0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
  }
  OFFEL();
}

V-ID/s:5
{
  if([AUTO.0]%2!=0)
    {
      taketemp(); //Считываем температуру Х10
      getStatus(COND, &k);

      //Секция водяного отопления
      buff=19;
      if( transform([STREET.1])<=buff ) {if([VALVE.0]==0) setStatus(VALVE, 1);} else // Если на улице меньше или 19, то всегда включаем водяное отопление
      if( transform([STREET.1])>buff) // Если на улице больше 19
      {
        if(tempK>=tempAuto+180) {if([VALVE.0]==1) setStatus(VALVE, 0);} else// Комната нагрета, то выключаем водяное отопление
        if(tempK<tempAuto+180-GIST) {if([VALVE.0]==0) setStatus(VALVE, 1);} // Комната холодная, то включаем водяное отопление
      }
      //Секция неводяного отопления
      if(tempAuto+180+GIST < tempK) //Охлаждение
        {
          HOLOD();
        } else 
      if(tempAuto+180-GIST > tempK) //Нагрев
        {
          if(timer<=TIME*12)++timer;
          NAGREV();
        } else
      if( (i==2) ) //было охлаждение
        {
          if(tempK<tempAuto+180) {OFFALL();} else //Достаточно охладили
          HOLOD(); //Еще нужно охлождать
        } else
      if( (i==1) ) //был нагрев
        {
          if(tempK>tempAuto+180) { OFFALL();} else //Нагрели до нужной, выключаем электро и кондей
          NAGREV();
        } else
        if(i==0) {OFFALL();} //температура в нужном диапозоне. Выключаем всё или проверяем что выключенно.
    }
}

void START()
{
  taketemp(); //Считываем температуру Х10
  getStatus(COND, &k);
  if(tempAuto+180 < tempK) //Задали температуру ниже комнатной
    {
      HOLOD();
    } else
  if(tempAuto+180 > tempK) //Задали температуру выше комнатной
    {
      NAGREV();
    } else i=0; //Попали точно в цель!

}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    if ([VALVE.5]!=255) setStatus(1000:102,"VALVE\0as:-4");
    #ifdef EL00 if([EL00.5]!=255) setStatus(1000:102,"EL00\0as:-4"); #endif
    #ifdef EL01 if([EL01.5]!=255) setStatus(1000:102,"EL01\0as:-4"); #endif
    #ifdef EL02 if([EL02.5]!=255) setStatus(1000:102,"EL02\0as:-4"); #endif
    START();
  } else
  if ([AUTO.0]%2==0)
  {
    getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k);
    setStatus(1000:102,"VALVE\0as:-1");
    #ifdef EL00 setStatus(1000:102,"EL00\0as:-1"); #endif
    #ifdef EL01 setStatus(1000:102,"EL01\0as:-1"); #endif
    #ifdef EL02 setStatus(1000:102,"EL02\0as:-1"); #endif
  }
}

