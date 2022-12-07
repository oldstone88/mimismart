/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"15", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00", "modes":"0x00", "funs":"0x01"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE00", type:"devices-list", required:false, filter:["conditioner"], desc:"Отопление", descWidth:370},
  {name:"VALVE01", type:"devices-list", required:false, filter:["conditioner"], desc:"Отопление", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  {type:"comment",style:"color:green; font-weight:bold;", text:"Режим холод:"},
  {name:"COOL1",type:"number",min:"1",max:"127",required:true,defaultValue:"15",desc:"Дельта*10 до Tу=Tк"},
  {name:"COOL2",type:"number",min:"1",max:"127",required:true,defaultValue:"20",desc:"Дельта*10 до Tу=Tк-1"},
  {name:"COOL3",type:"number",min:"1",max:"127",required:true,defaultValue:"30",desc:"Дельта*10 до Tу=Tк-2"},
  {type:"comment", style:"color:red; font-weight:bold;", text:"Если дельта больше будет Tу=Tк-3"},
  {type:"comment",style:"color:green; font-weight:bold;", text:"Режим нагрев:"},
  {name:"HEAT1",type:"number",min:"1",max:"127",required:true,defaultValue:"15",desc:"Дельта*10 до которой кондиционер выключен"},
  {name:"HEAT2",type:"number",min:"1",max:"127",required:true,defaultValue:"20",desc:"Дельта*10 до которой кондиционер включен"},
  {type:"comment", style:"color:red; font-weight:bold;", text:"Если дельта больше - кондиционер включен +2 градуса"},
  ]
}
*/

i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];
u8 work=0;

void transform(u8 j) //Преобразование температуры для сравнения
{
  if((j&0x80)==0x80)
  {
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

//Приводим температуру в нужный вид (x10)
void taketemp()
{
  tempAuto = [AUTO.1]*10+160;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
}

//Включение конвектора на заданную температуру
void ONVAL()
{
  #ifdef VALVE00 if( ([VALVE00.0]%2==0) || ([VALVE00.1]!=[AUTO.1]) ) {getStatus(VALVE00, &k); k[0]=1; k[1]=[AUTO.1]; setStatus(VALVE00, &k);} #endif
  #ifdef VALVE01 if( ([VALVE01.0]%2==0) || ([VALVE01.1]!=[AUTO.1]) ) {getStatus(VALVE01, &k); k[0]=1; k[1]=[AUTO.1]; setStatus(VALVE01, &k);} #endif
}
//Включаем кондиционер
void ONHOL(u8 j)
{
  getStatus(COND, &k); k[0]=17;  i8 buff=([AUTO.1]-j); if(buff<0)buff=0; k[1]=buff; setStatus(COND, &k);
  work=1;
}

void OFFOXL()
{
  work=0;
}

V-ID/s:10
{
  i8 error=-15;
  i8 street=10;
  i8 outdoor=transform([YLITSA.1]);
  
  if([AUTO.0]%2==1)
  {
    taketemp();
    //srvError("На улице=%d", outdoor);
    //На улице больше 10
    if(outdoor>street) //Сценарий охлождение
    {
      //Конвектор
      #ifdef VALVE00 if( ([VALVE00.0]%2)==1 ) {getStatus(VALVE00, &k); k[0]=k[0]&0xFE; setStatus(VALVE00, &k);} #endif
      #ifdef VALVE01 if( ([VALVE01.0]%2)==1 ) {getStatus(VALVE01, &k); k[0]=k[0]&0xFE; setStatus(VALVE01, &k);} #endif
      //Кондиционер
      if( tempAuto>=tempK ) //-гистерезис *10
      {
        if([COND.0]%2==1) {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k); cancelDelayedCall(OFFOXL); delayedCall(OFFOXL, 600);}
      }
      else if ( (tempAuto+COOL1>tempK) && (tempAuto<tempK) )
      {
        if( ([COND.0]!=17) || ([COND.1]!=[AUTO.1])) {ONHOL(0);}
      }
      else if ( (tempAuto+COOL2>tempK) && (tempAuto<tempK) )
      {
        if( ([COND.0]!=17) || ([COND.1]!=([AUTO.1]-1)) ) {ONHOL(1);}
      }
      else if ( (tempAuto+COOL3>tempK) && (tempAuto<tempK) )
      {
        if( ([COND.0]!=17) || ([COND.1]!=([AUTO.1]-2)) ) {ONHOL(2);}
      }
      else if(tempAuto<tempK)
      {
        if( ([COND.0]!=17) || ([COND.1]!=([AUTO.1]-3)) ) {ONHOL(3);}
      }
    }
    else //Сценарий нагрев
    {
      //Конвектор
      if(tempAuto<=tempK) //+ гистерезис градусы*10
      {
        if( ([COND.0]%2)==1 ) {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k); cancelDelayedCall(OFFOXL); delayedCall(OFFOXL, 600);}
        #ifdef VALVE00 if( ([VALVE00.0]%2)==1 ) {getStatus(VALVE00, &k); k[0]=k[0]&0xFE; setStatus(VALVE00, &k);} #endif
        #ifdef VALVE01 if( ([VALVE01.0]%2)==1 ) {getStatus(VALVE01, &k); k[0]=k[0]&0xFE; setStatus(VALVE01, &k);} #endif
      }
      else if( (tempAuto-HEAT1<tempK) && (tempAuto>tempK) )
      {
        if( ([COND.0]%2)==1) {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k);  cancelDelayedCall(OFFOXL); delayedCall(OFFOXL, 600);}
        ONVAL();
      }
      else if( (tempAuto-HEAT2<tempK) && (tempAuto>tempK) )
      {
        if( (([COND.0]%2!=49) || ([COND.1]!=[AUTO.1])) && (outdoor>error) && work==0)
          {
            getStatus(COND, &k); k[0]=49; k[1]=[AUTO.1]; setStatus(COND, &k); work=1;
          }
        ONVAL();
      }
      else if(tempAuto>tempK)
      {
        if( ( ([COND.0]%2!=49) || ([COND.1]!=([AUTO.1]+2)) ) && (outdoor>error) && work==0)
          {
            getStatus(COND, &k); k[0]=49; k[1]=[AUTO.1]+2; if(k[1]>15) k[1]=15; setStatus(COND, &k); work=1;
          }
        ONVAL();
      }
    }
  }
  if(([COND.0]%2==1) && (outdoor<=error)) {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k);}
}


//Выключение
V-ID/AUTO
{
  if(opt(0)%2==0)
  {
    if( ([COND.0]%2)==1 ) {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND, &k); work=0;}
    #ifdef VALVE00 if( ([VALVE00.0]%2)==1 ) {getStatus(VALVE00, &k); k[0]=k[0]&0xFE; setStatus(VALVE00, &k);} #endif
    #ifdef VALVE01 if( ([VALVE01.0]%2)==1 ) {getStatus(VALVE01, &k); k[0]=k[0]&0xFE; setStatus(VALVE01, &k);} #endif
  }
}