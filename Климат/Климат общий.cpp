/*
{
  desc:"Климат",
  tag:"import-script",
  selectArea:true,
  name:"Климат",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Климат", "sub-id":"%SUBID01%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00", "modes":"0x00", "funs":"0x01"},
    {tag:"item", id:"%TARGET%", name:"Охл-Нагр", "sub-id":"%SUBID02%", type:"virtual", "sub-type":"sensor", length:"2"},
  ],
  vars:[
  {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID01%"},
  {name:"MODES",type:"hidden",value:"%TARGET%:%SUBID02%"},
  {name:"TMIN",type:"number",required:true,defaultValue:16,min:15,max:19,desc:"Минимальная температура кондиционера",descWidth:250},
  {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:250, width:600, desc:"Кондиционер"},
  {name:"VALVE", type:"devices-list", required:true, filter:["valve-heating"], desc:"Отопление", descWidth:250, width:600},
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:250, width:600},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:250, width:600},
  ]
}
*/

u8 gist = 5; // Гистерезис x10
i8 porog = -5; // Порог работы кондиционеры
i16 streetTemp = 0; // Температура на улице
u8 prevMode = 0; // 0 - неопределен, 1 - охлаждение, 2 - отопление
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

V-ID/s:5{
  // Обновление температур
  streetTemp = transform([YLITSA.1]);
  tempAuto = ([AUTO.1]+TMIN)*10;
  tempK = ([KOMHATA.1]*10);
  tempK = tempK+([KOMHATA.0]*10)/250;

  if ([AUTO.0]%2!=0){
    // Кондиционирование
    if(streetTemp > porog){
        getStatus(COND, &k);
        if( ((tempAuto+gist < tempK) && (prevMode==0 || prevMode==1)) || ((tempAuto+(gist*3) < tempK) && prevMode==2) ){
          k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k); prevMode=1; setStatus(MODES, {0, prevMode});
        } else if(tempAuto-gist > tempK){
          k[0]=(k[0]&0xFE); setStatus(COND,&k);
        }
    // Температура на улице ниже порога
    } else if( ([COND.0]%2)!=0 ){
      k[0]=(k[0]&0xFE); setStatus(COND,&k);
    }
    // Отопление
    if( ((tempAuto-gist > tempK) && (prevMode==0 || prevMode==2)) || ((tempAuto-(gist*3) > tempK) && prevMode==1) ){
      setStatus(VALVE, 1); prevMode=2; setStatus(MODES, {0, prevMode});
    } else if( tempAuto+gist < tempK ){
      setStatus(VALVE, 0);
    }
  }
}

// При уставке гистерезис не учитываем
void start(){
  if( (tempAuto < tempK) && (streetTemp > porog) ){
    k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k); prevMode=1; setStatus(MODES, {0, prevMode});
  } else {
    getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND,&k);
  }
}

V-ID/AUTO{
  if ([AUTO.0]%2!=0){
    start();
    prevMode=0; // Предыдущий режим работы
    setStatus(MODES, {0, prevMode});
    setStatus(1000:102,"VALVE\0as:-4");
  } else
  if ([AUTO.0]%2==0){
    setStatus(1000:102,"VALVE\0as:-2");
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
  }
}
