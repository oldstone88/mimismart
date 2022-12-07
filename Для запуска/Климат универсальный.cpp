/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"13", "t-min":"17", "vane-hor":"0x00", "vane-ver":"0x00", "modes":"0x00", "funs":"0x01"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE00", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"VALVE01", type:"devices-list", required:false, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];

//Приводим температуру в нужный вид (x10)
void taketemp()
{
  tempAuto = [AUTO.1]*10+160;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
}

//Если датчик виртуальный!, Если реальный можно закоментить.

void transform(u8 j) //Преобразование температуры для сравнения
{
  if((j&0x80)==0x80)
  {
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

V-ID/s:60
{
  if ([AUTO.0]%2!=0)
  {
    //Отопление
    if( ([AUTO.1]+17)!=[VALVE00.2] ) {u8 buff=([AUTO.1]+17); setStatus(1000:102, {"VALVE00\0t:"A, buff,0});}
    #ifdef VALVE01 if( ([AUTO.1]+17)!=[VALVE01.2] ) {u8 buff=([AUTO.1]+17); setStatus(1000:102, {"VALVE01\0t:"A, buff,0});} #endif
    //Кондиционирование
    i8 n = -7;
    getStatus(COND, &k);
    srvError( "Предел=%d, На улице=%d", n, transform([YLITSA.1]) );
    if( transform([YLITSA.1])>n )
    {
      taketemp();
      if( (tempAuto+10 < tempK) && i!=2) {i=2; k[0]=1; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else //Охлаждение
      if( (tempAuto-10 > tempK) && i!=1) {i=1; k[0]=1; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else //Нагрев
      if( (i==2) && (tempK<tempAuto-5) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);} else
      if( (i==1) && (tempK>tempAuto+5) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);}
    } else {if( ([AUTO.0]%2)!=0) k[0]=k[0]&0xFE; setStatus(COND, &k);}
  }
}

void start()
{
  taketemp();
  getStatus(COND, &k);
  i8 n=-7;
  if( transform([YLITSA.1])>n )
    {
        if( tempAuto < tempK ) {i=2; k[0]=1; k[1]=([AUTO.1]); setStatus(COND, &k);} else //включаем на холод
        if( tempAuto > tempK ) {i=1; k[0]=1; k[1]=([AUTO.1]); setStatus(COND, &k);} else //включаем на отопление
        {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);}
    } else {if( ([AUTO.0]%2)!=0) k[0]=k[0]&0xFE; setStatus(COND, &k);}
}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    i=0;
    cancelDelayedCall(start);
    delayedCall(start, 3);
    setStatus(1000:102, "VALVE00\0Авто");
    #ifdef VALVE01 setStatus(1000:102, "VALVE01\0Авто"); #endif
  } else
  if ([AUTO.0]%2==0)
  {
    i=0;
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(1000:102,"VALVE00\0as:-4");
    #ifdef VALVE01 setStatus(1000:102, "VALVE01\0as:-4"); #endif
    setStatus(COND, &k);
  }
}