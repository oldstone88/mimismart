/*
{
  desc:"Климат комнаты",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00", "modes":"0x00", "funs":"0x01"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"HEATING", type:"devices-list", required:false, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"HF", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"POLL", type:"devices-list", required:false, filter:["temperature-sensor"], desc:"Датчик температуры ТП", descWidth:370},
  {name:"DELTA",type:"number",min:"15",max:"50",required:true,defaultValue:"23",desc:"Лимит нагревания пола"},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  {name:"LETO", type:"devices-list", required:true, filter:["script"], desc:"Лето", descWidth:370},
  {name:"ZIMA", type:"devices-list", required:true, filter:["script"], desc:"Зима", descWidth:370},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];
u8 nagrtp=0;

void transform(u8 j) //Преобразование температуры для сравнения
{
  if((j&0x80)==0x80)
  {
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

void taketemp() //Приведение температуры к 1 виду
{
  tempAuto = [AUTO.1]*10;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
  getStatus(COND, &k);
}

void otoplenie(u8 k0, u8 k1) //k0 - то что нужно сделать с отоплением, k1 - то, что нужно сделать с тёплым полом
{
  #ifdef HEATING
  if( ([HEATING.0]&1)==(~k0)&0x01 ) setStatus(HEATING, k0);
  #endif

  #ifdef HF
  if (k1==1)
  {
    if( ([HF.0]&1)==0 && [POLL.1]<=(DELTA-1) ) setStatus(HF, 1); else
    if( ([HF.0]&1)==1 && [POLL.1]>(DELTA+1) ) setStatus(HF, 0);
  } else
  if(k1==0)
  {
    if( ([HF.0]&1)==1) setStatus(HF, 0);
  }
  #endif
}

V-ID/s:5
{
  if([AUTO.0]%2!=0)
    {
      i8 tempB= 0;
      taketemp();
        //srvError("Задано=%d, На датчике=%d",tempAuto, tempK);
        if(tempAuto+170 < tempK) //Охлаждение
        {
          i=2;
          if(transform([YLITSA.1])>=tempB) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else {k[0]=k[0]&0xFE; k[4]=0; setStatus(COND, &k);}
          otoplenie(0, 0);
        } else 
        if(tempAuto+150 > tempK) //нагрев
        {
          i=1;
          if( transform([YLITSA.1])<tempB ) //Температура ниже 0
            {
              otoplenie(1, 1);
              if([COND.0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
            } else // Температура выше 0
            {
              if( [COND.0]%2==0 ) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);}
              otoplenie(0, 1);
            }
        } else
        if( (i==2) && (tempK<tempAuto+160) ) {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); otoplenie(0, 0);} else
        if( (i==1) && (tempK>tempAuto+160) ) {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); otoplenie(0, 0);}
    }
}

void start()
{
  i8 tempB=0;
  taketemp();
  if(tempAuto<tempK) //Охлаждение
  {
    i=2;
    if(transform([YLITSA.1])>=tempB) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else {k[0]=k[0]&0xFE; k[4]=0; setStatus(COND, &k);}
    otoplenie(0, 0);
  }
    else
  if(tempAuto>tempK) //Нагрев
  {
    i=1;
    if( transform([YLITSA.1])<tempB) //На улице меньше 0
      {
        otoplenie(1, 1);
        if([COND.0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
      } else //на улице больше 0
      {
        if( [COND.0]%2==0 ) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} 
        otoplenie(0, 1);
      }
  }
    else
    {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); otoplenie(0, 0);}
}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    i=0;
    if([AUTO.1]!=7){setStatus(LETO, 0); setStatus(ZIMA, 0);}
    #ifdef HEATING setStatus(1000:102,"HEATING\0as:-4"); #endif
    #ifdef HF setStatus(1000:102,"HF\0as:-4"); #endif
    start();
  } else
  if ([AUTO.0]%2==0)
  {
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
    #ifdef HEATING setStatus(1000:102,"HEATING\0as:-2"); #endif
    #ifdef HF setStatus(1000:102,"HF\0as:-2"); #endif
  }
}


