/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  name:"Климат",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"13", "t-min":"17", "vane-hor":"0x00", "vane-ver":"0x00"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
  {name:"TMIN",type:"number",required:true,defaultValue:16,min:15,max:19,desc:"Минимальная температура кондиционера",descWidth:350},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
  {name:"VALVE", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:370},
  {name:"HFWATER", type:"devices-list", required:true, filter:["valve-heating"], desc:"ТП Водяной", descWidth:370},
  {name:"HFELECTRO", type:"devices-list", required:true, filter:["valve-heating"], desc:"ТП Электрический", descWidth:370},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  ]
}
*/

u8 gist = 10; // Гистерезис x10;
i32 tempAuto = 0;
i32 tempK = 0;
u8 k[5];
u16 timerWater = 0; // Таймер включения водяного пола
u16 timerElectro = 0; // Таймер включения электрического пола
u16 timerConditioner = 0; // Таймер кондиционера


void transform(u8 j){ //Преобразование температуры для сравнения
  if((j&0x80)==0x80){
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

V-ID/s:5{
  if ([AUTO.0]%2!=0){

    tempAuto = ([AUTO.1]+TMIN)*10; // Уставка
    tempK = ([KOMHATA.1]*10);
    tempK = tempK+([KOMHATA.0]*10)/250; // В комнате

    // Отопление
    if( ([AUTO.1]+TMIN) != [VALVE.2] ) {u8 buff=([AUTO.1]+TMIN); setStatus(1000:102, {"VALVE\0t:"A, buff,0});}
    
    if(tempAuto - 20 > tempK){
      // Таймер запуска водяного пола
      if(timerWater>=360){
        if([HFWATER.2] != 32){setStatus(1000:102, "HFWATER\0Авто"); u8 buff=32; setStatus(1000:102, {"HFWATER\0t:"A, 32, 0});}
      } else ++timerWater;
      // Таймер запуска электрического пола
      if(timerElectro>=720){
        if([HFELECTRO.2] != 32){setStatus(1000:102, "HFELECTRO\0Авто"); u8 buff=32; setStatus(1000:102, {"HFELECTRO\0t:"A, 32, 0});}
      } else ++timerElectro;
    } else{
      timerWater = 0;
      timerElectro = 0;
      if(([HFWATER.0] != 0) || ([HFWATER.5] != 254)){setStatus(1000:102,"HFWATER\0as:-1");}
      if(([HFELECTRO.0] != 0) || ([HFELECTRO.5] != 254)){setStatus(1000:102,"HFELECTRO\0as:-1");}
    }
    // Кондиционирование
    i16 streetTemp = transform([YLITSA.1]);
    i8 porog = -5; // Порог работы кондиционеры
    if( [YLITSA] > porog ){
        getStatus(COND, &k);
        if(tempAuto+gist < tempK) {
          if(timerConditioner >= 1440){
            k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);
          } else
          ++timerConditioner;
        } else{
          timerConditioner = 0;
          if(tempAuto-gist > tempK) {k[0]=(k[0]&0xFE); setStatus(COND,&k);}
        }
    } else if( ([COND.0]%2)!=0 ) {k[0]=(k[0]&0xFE); setStatus(COND,&k);}
  }
}

/*
// При уставке гистерезис не учитываем
void start(){
  if( tempAuto < tempK ) {k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else 
  {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND,&k);} 
}
*/

V-ID/AUTO{
  if ([AUTO.0]%2!=0){
    //start();
    setStatus(1000:102, "VALVE\0Авто");
  } else
  if ([AUTO.0]%2==0){
    setStatus(1000:102,"VALVE\0as:-2");
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
  }
}

