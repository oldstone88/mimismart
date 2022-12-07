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
  {name:"VALVE", type:"devices-list", required:true, filter:["conditioner"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"STREET", type:"devices-list", required:true, filter:["virtual"], desc:"Датчик температуры улицы", descWidth:370},
  {name:"GIST", type:"number", defaultValue:10, required:true, desc:"Гистерезис нужно умножить на 10"},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i32 tempAuto = 0;
i32 tempK = 0;
u8 statecond[5];
u8 statevalv[5];
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
  tempAuto = ([AUTO.1]*10)+160;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
}

void OFFALL()
{
  i=0;
  k[0]=k[0]&0xFE; setStatus(COND, &k);
  k[0]=k[0]&0xFE; setStatus(VALVE, &k);
}

void BATAREYA()
{
  i=1;
  buff=10; //Температура для сравнения
  if( transform([STREET.1])<buff )// на улице меньше 10
  {
    
  } else // На улице больше 10
  {
   statevalv[0]=statevalv[0]|0x01; statevalv[1]=[AUTO.1]; setStatus(VALVE, &statevalv);
  }
}

void KONDER()
{
  i=2;
  buff=-15;
  if( transform([STREET.1])>buff ) //на улице больше -15
  {
    if(statecond[0]!=17 || statecond[1]!=[AUTO.1] || statecond[4]!=0) {statecond[0]=17; statecond[4]=0; statecond[1]=([AUTO.1]); setStatus(COND, &statecond);}
  } else // на улице меньше -15
  {
    if(statecond[0]%2!=0) {statecond[0]=statecond[0]&0xFE; setStatus(COND, &k);}
  }
}

V-ID/s:5
{
  if([AUTO.0]%2!=0)
    {
      taketemp(); //Считываем температуру Х10
      getStatus(COND, &statecond);
      getStatus(VALVE, &statevalv);

      buff=10;
      
      if( transform([STREET.1])>buff) // Если на улице больше 10, сценарий холод
      {
        HOLOD();
      } else
      if( transform([STREET.1])<=buff) // Если на улице меньше 10 или 10, сценарий обогрев
      {
        if(tempAuto=<tempK){OFFALL();} else
        if(tempAuto>tempK+15) {BATAREYA(); if([COND.0]%2)!=0 {statecond[0]=statecond[0]&0xFE; setStatus(COND, &statecond);}} else
        
      }
    }
}

void START()
{
  taketemp(); //Считываем температуру Х10
  getStatus(COND, &k);
  if(tempAuto < tempK) //Задали температуру ниже комнатной
    {
      HOLOD();
    } else
  if(tempAuto > tempK) //Задали температуру выше комнатной
    {
      NAGREV();
    } else i=0; //Попали точно в цель!

}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    START();
  } else
  if ([AUTO.0]%2==0)
  {

  }
}

