/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  vars:[
  {name:"NEST", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"NEST"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];

void transform(u8 j){ //Преобразование температуры для сравнения
  if((j&0x80)==0x80){
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

V-ID/s:5
{
  if ([NEST.0]%2!=0){
    //Отопление
    if( ([NEST.1]+19)!=[VALVE.2] ) {u8 buff=([NEST.1]+19); setStatus(1000:102, {"VALVE\0t:"A, buff,0});}
    //Кондиционирование
        tempAuto = [NEST.1]*10;
        tempK=( [KOMHATA.1]*10 );
        tempK=tempK+([KOMHATA.0]*10)/250;
        i32 street=transform([YLITSA.1]);

    
        getStatus(COND, &k);
    
        if( (tempAuto+200 < tempK) && (street>=(tempAuto+190)) && i!=2 ) {i=2; k[0]=17; k[4]=0; k[1]=([NEST.1]); setStatus(COND, &k);} else 
        if( (tempAuto+180 > tempK) && (street<=(tempAuto+190)) && i!=1 ) {i=1; k[0]=49; k[4]=0; k[1]=([NEST.1]); setStatus(COND, &k);} else
        if( (i==2) && (tempK<tempAuto+190) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);} else
        if( (i==1) && (tempK>tempAuto+190) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);}
  }
}

void start()
{
  if( tempAuto+190 < tempK ) {i=2; k[0]=17; k[4]=0; k[1]=([NEST.1]); setStatus(COND, &k);} else 
  if( tempAuto+190 > tempK ) {i=1; k[0]=49; k[4]=0; k[1]=([NEST.1]); setStatus(COND, &k);} else
  {i=0; getStatus(COND, &k); k[0]=(k[0]&0xFE); setStatus(COND,&k);} 
}

V-ID/NEST
{
  if ([NEST.0]%2!=0)
  {
    i=0;
    start();
    setStatus(1000:102, "VALVE\0АВТО");
  } else
  if ([NEST.0]%2==0)
  {
    i=0;
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(1000:102,"VALVE\0as:-2");
    setStatus(COND, &k);
  }
}

