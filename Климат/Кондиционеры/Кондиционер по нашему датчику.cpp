/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
  ],
  vars:[
  {name:"G00", type:"number", defaultValue:10, required:true, desc:"Гистерезис x 10"},
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  ]
}
*/

i32 tempAuto = 0;
i32 tempK = 0;
i8 k[5];


V-ID/s:5
{
  if([AUTO.0]%2!=0)
    {
        tempAuto = [AUTO.1]*10;
        tempK=( [KOMHATA.1]*10 );
        tempK=tempK+([KOMHATA.0]*10)/250;
        //srvError("Значение=%d",tempK);
    
        getStatus(AUTO, &k);
    
        if(tempAuto+160+G00 <= tempK) {k[1]=k[1]-2; if(k[1]<0) k[1]=0; setStatus(COND, &k);} else
        if(tempAuto+160-G00 <= tempK) {k[0]=k[0]&0xFE; setStatus(COND, &k);}
    }
}

V-ID/AUTO
{
  if ([AUTO.0]%2==0)
  {
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
  }
}

