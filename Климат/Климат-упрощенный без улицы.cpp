/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  name:"Климат",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"16", "t-min":"16", "modes":"0x00", "funs":"0x01", "vane-hor":"0x00", "vane-ver":"0x00"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  ]
}
*/

u8 i=0; //Маркер 0-выкл 1-нагрев 2-охлаждение
i16 tempAuto = 0;
i16 tempK = 0;
u8 k[5];

void taketemp()
{
  tempAuto = [AUTO.1]*10;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;  
}

V-ID/s:5
{
  if ([AUTO.0]%2!=0)
  {
    //Отопление
    if( ([AUTO.1]+16)!=[VALVE.2] ) {u8 buff=([AUTO.1]+16); setStatus(1000:102, {"VALVE\0t:"A, buff,0});}
    //Кондиционирование
        getStatus(COND, &k);
        taketemp();
    
        if( (tempAuto+190 < tempK) && i!=2 ) {i=2; k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else 
        if( (tempAuto+120 > tempK) && i!=1 ) {i=1; k[0]=49; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else
        if( (i==2) && (tempK<tempAuto+160) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);} else
        if( (i==1) && (tempK>tempAuto+160) ) {i=0; k[0]=(k[0]&0xFE); setStatus(COND,&k);}
  }
}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    i=0;
    setStatus(1000:102, "VALVE\0АВТО");
  } else
  if ([AUTO.0]%2==0)
  {
    i=0;
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(1000:102,"VALVE\0as:-4");
    setStatus(COND, &k);
  }
}