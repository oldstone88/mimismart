/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
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
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];


V-ID/s:5
{
  if([AUTO.0]%2!=0)
    {
        tempAuto = [AUTO.1]*10;
        tempK=( [KOMHATA.1]*10 );
        tempK=tempK+([KOMHATA.0]*10)/250;
        srvError("Значение=%d",tempK);
    
        getStatus(COND, &k);
    
        if(tempAuto+170 < tempK) {i=2; k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k); if( ([VALVE.0]&1)==1 )setStatus(VALVE, 0);} else 
        if(tempAuto+150 > tempK) {i=1; setStatus(VALVE, 1); if ( [COND.0]%2!=0) setStatus(COND, 0); } else
        if( (i==2) && (tempK<tempAuto+160) ) {i=0; setStatus(COND, 0); setStatus(VALVE, 0); srvError("Выкл конд");} else
        if( (i==1) && (tempK>tempAuto+160) ) {i=0; setStatus(COND, 0); setStatus(VALVE, 0); srvError("Нагрев выкл");}
    }
}

V-ID/AUTO
{
  if ([AUTO.0]%2!=0)
  {
    setStatus(1000:102,"VALVE\0as:-4");
  } else
  if ([AUTO.0]%2==0)
  {
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(1000:102,"VALVE\0as:-2");
    setStatus(COND, &k);
  }
}

