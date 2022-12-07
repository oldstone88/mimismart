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
  {name:"H0", type:"devices-list", required:false, filter:["valve-heating"], desc:"Отопление 2", descWidth:370},
  {name:"HF0", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF1", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF2", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF3", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF4", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF5", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"HF6", type:"devices-list", required:false, filter:["valve-heating"], desc:"Тёплый пол", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"POLL", type:"devices-list", required:false, filter:["temperature-sensor"], desc:"Датчик температуры ТП", descWidth:370},
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

void offtp()
{
  #ifdef HF0 if( ([HF0.0]&1)==1 ) setStatus(HF0, 0); #endif
  #ifdef HF1 if( ([HF1.0]&1)==1 ) setStatus(HF1, 0); #endif
  #ifdef HF2 if( ([HF2.0]&1)==1 ) setStatus(HF2, 0); #endif
  #ifdef HF3 if( ([HF3.0]&1)==1 ) setStatus(HF3, 0); #endif
  #ifdef HF4 if( ([HF4.0]&1)==1 ) setStatus(HF4, 0); #endif
  #ifdef HF5 if( ([HF5.0]&1)==1 ) setStatus(HF5, 0); #endif
  #ifdef HF6 if( ([HF6.0]&1)==1 ) setStatus(HF6, 0); #endif
}

void ontp()
{
  #ifdef HF0 if([HF0.0]!=1 && [POLL.1]<=22) setStatus(HF0, 1); else if([POLL.1]>23 && [HF0.0]!=0) setStatus(HF0, 1); #endif
  #ifdef HF1 if([HF1.0]!=1 && [POLL.1]<=22) setStatus(HF1, 1); else if([POLL.1]>23 && [HF1.0]!=0) setStatus(HF1, 1); #endif
  #ifdef HF2 if([HF2.0]!=1 && [POLL.1]<=22) setStatus(HF2, 1); else if([POLL.1]>23 && [HF2.0]!=0) setStatus(HF2, 1); #endif
  #ifdef HF3 if([HF3.0]!=1 && [POLL.1]<=22) setStatus(HF3, 1); else if([POLL.1]>23 && [HF3.0]!=0) setStatus(HF3, 1); #endif
  #ifdef HF4 if([HF4.0]!=1 && [POLL.1]<=22) setStatus(HF4, 1); else if([POLL.1]>23 && [HF4.0]!=0) setStatus(HF4, 1); #endif
  #ifdef HF5 if([HF5.0]!=1 && [POLL.1]<=22) setStatus(HF5, 1); else if([POLL.1]>23 && [HF5.0]!=0) setStatus(HF5, 1); #endif
  #ifdef HF6 if([HF6.0]!=1 && [POLL.1]<=22) setStatus(HF6, 1); else if([POLL.1]>23 && [HF6.0]!=0) setStatus(HF6, 1); #endif
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
          #ifdef HEATING if( ([HEATING.0]&1)==1 ) setStatus(HEATING, 0); #endif
          #ifdef H0 if( ([H0.0]&1)==1 ) setStatus(H0, 0); #endif
          offtp();
        } else 
        if(tempAuto+150 > tempK) //нагрев
        {
          i=1;
          if( transform([YLITSA.1])<tempB ) //Температура ниже 0
            {
              if([COND.0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
              #ifdef HEATING if([HEATING.0]!=1) setStatus(HEATING, 1); #endif
              #ifdef H0 if( ([H0.0]&1)!=1 ) setStatus(H0, 1); #endif
              ontp();
            } else // Температура выше 0
            {
              if( [COND.0]%2==0 ) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);}
              #ifdef HEATING if([HEATING.0]!=0) setStatus(HEATING, 0); #endif
              #ifdef H0 if([H0.0]!=0) setStatus(H0, 0); #endif
              ontp();
            }
        } else
        if( (i==2) && (tempK<tempAuto+160) ) {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); #ifdef HEATING setStatus(HEATING, 0); #ifdef H0 setStatus(H0, 0); #endif offtp();} else
        if( (i==1) && (tempK>tempAuto+160) ) {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); #ifdef HEATING setStatus(HEATING, 0); #ifdef H0 setStatus(H0, 0); #endif offtp();}
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
    #ifdef HEATING if( ([HEATING.0]&1)==1 ) setStatus(HEATING, 0); #endif
    #ifdef H0 if( ([H0.0]&1)==1 ) setStatus(H0, 0); #endif
    offtp();
  }
    else
  if(tempAuto>tempK) //Нагрев
  {
    i=1;
    if( transform([YLITSA.1])<tempB) //На улице меньше 0
      {
        if([COND.0]%2!=0) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
        #ifdef HEATING if([HEATING.0]!=1) setStatus(HEATING, 1); #endif
        #ifdef H0 if( ([H0.0]&1)!=1 ) setStatus(H0, 1); #endif
        ontp();
      } else //на улице больше 0
      {
        if( [COND.0]%2==0 ) {k[0]=k[0]|0x01; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} 
        #ifdef HEATING if([HEATING.0]!=0) setStatus(HEATING, 0); #endif
        #ifdef H0 if( ([H0.0]&1)!=0 ) setStatus(H0, 0); #endif
        ontp();
      }
  }
    else
    {i=0; k[0]=k[0]&0xFE; setStatus(COND, &k); #ifdef HEATING setStatus(HEATING, 0); #endif #ifdef H0 setStatus(H0, 0); #endif offtp();}
}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    i=0;
    if([AUTO.1]!=7){setStatus(LETO, 0); setStatus(ZIMA, 0);}
    #ifdef HEATING setStatus(1000:102,"HEATING\0as:-4"); #endif
    #ifdef H0 setStatus(1000:102,"H0\0as:-4"); #endif
    #ifdef HF0 setStatus(1000:102,"HF0\0as:-4"); #endif
    #ifdef HF1 setStatus(1000:102,"HF1\0as:-4"); #endif
    #ifdef HF2 setStatus(1000:102,"HF2\0as:-4"); #endif
    #ifdef HF3 setStatus(1000:102,"HF3\0as:-4"); #endif
    #ifdef HF4 setStatus(1000:102,"HF4\0as:-4"); #endif
    #ifdef HF5 setStatus(1000:102,"HF5\0as:-4"); #endif
    #ifdef HF6 setStatus(1000:102,"HF6\0as:-4"); #endif
    start();
  } else
  if ([AUTO.0]%2==0)
  {
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
    #ifdef HEATING setStatus(1000:102,"HEATING\0as:-2"); #endif
    #ifdef H0 setStatus(1000:102,"H0\0as:-2"); #endif
    #ifdef HF0 setStatus(1000:102,"HF0\0as:-2"); #endif
    #ifdef HF1 setStatus(1000:102,"HF1\0as:-2"); #endif
    #ifdef HF2 setStatus(1000:102,"HF2\0as:-2"); #endif
    #ifdef HF3 setStatus(1000:102,"HF3\0as:-2"); #endif
    #ifdef HF4 setStatus(1000:102,"HF4\0as:-2"); #endif
    #ifdef HF5 setStatus(1000:102,"HF5\0as:-2"); #endif
    #ifdef HF6 setStatus(1000:102,"HF6\0as:-2"); #endif
  }
}

