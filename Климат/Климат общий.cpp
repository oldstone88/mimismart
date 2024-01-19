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
  {name:"KOMHATA", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры в комнате", descWidth:370},
  {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
  ]
}
*/

u8 gist = 10; // Гистерезис x10;
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
  if ([AUTO.0]%2!=0){
    //Отопление
    if( ([AUTO.1]+TMIN) != [VALVE.2] ) {u8 buff=([AUTO.1]+TMIN); setStatus(1000:102, {"VALVE\0t:"A, buff,0});}
    //Кондиционирование
    i16 streetTemp = transform([YLITSA.1]);
    i8 porog = -5; // Порог работы кондиционеры
    if( [YLITSA] > porog ){
        tempAuto = ([AUTO.1]+TMIN)*10;
        tempK = ([KOMHATA.1]*10);
        tempK = tempK+([KOMHATA.0]*10)/250;
    
        getStatus(COND, &k);
    
        if(tempAuto+gist < tempK) {k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else 
        if(tempAuto+gist > tempK) {k[0]=(k[0]&0xFE); setStatus(COND,&k);}
    } else if( ([COND.0]%2)!=0 ) {k[0]=(k[0]&0xFE); setStatus(COND,&k);} // Температура на улице ниже порога
  }
}

// При уставке гистерезис не учитываем
void start(){
  if( tempAuto < tempK ) {k[0]=17; k[4]=0; k[1]=([AUTO.1]); setStatus(COND, &k);} else 
  {getStatus(COND, &k); k[0]=k[0]&0xFE; setStatus(COND,&k);} 
}

V-ID/AUTO{
  if ([AUTO.0]%2!=0){
    start();
    setStatus(1000:102, "VALVE\0Авто");
  } else
  if ([AUTO.0]%2==0){
    setStatus(1000:102,"VALVE\0as:-2");
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
  }
}

