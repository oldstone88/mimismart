/*
{
  desc:"Охрана",
  tag:"item",
  
  name:"Охрана",
  selectArea:true,
  vars:[
        {type:"comment",text:"Выберите зоны охраны:"},
        {name:"L01",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 1"},
        {name:"L02",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 2"},
        {name:"L03",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 3"},
        {name:"L04",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 4"},
        {name:"L05",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 5"},
        {name:"L06",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 6"},
        {name:"L07",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Зона 7"},
        {type:"comment",text:"Постановка на охрану:"},
        {name:"SECURITY",type:"devices-list",required:false,filter:["lamp"], widht:500, desc:"Постановка"},
        {type:"comment",text:"Геркон-подтверждение:"},
        {name:"H00",type:"devices-list",required:false,filter:["door-sensor"], widht:500, desc:"Подтвержление охраны"},
        {type:"comment",text:"Время на постановку, секунд: "},
        {name:"TIME",type:"number",required:true,min:1,max:250,default:15},
  ]
}
*/

u8 ohrana=0;
u8 stopspam=0;

void onInit(){
  if( ([V-ADDR.0]&1)==1 && ([SECURITY.0]&1)==0){
    setStatus(2047:32, {8, "Была перезагрузка, проверьте охрану"});
  }
  if( ([V-ADDR.0]&1)==1 && ([SECURITY.0]&1)==1){
    ohrana=2;
  }
}

void offSpam(){
  stopspam=0;
}

//Проверка сработки охраны
V-ID/s:1{
  if( ([V-ADDR.0]&1)==1 && ([SECURITY.0]&1)==1 ){
    if( ([L01.0]&1)==1
      || ([L02.0]&1)==1
      || ([L03.0]&1)==1
      || ([L04.0]&1)==1
      || ([L05.0]&1)==1
      || ([L06.0]&1)==1
      || ([L07.0]&1)==1) { if(!stopspam) {setStatus(2047:32, {8, "Тревога!!! Обнаружено движение!!!"}); stopspam=1;} else {stopspam=1; delayedCall(offSpam, 60);} }
  }
  if( ([V-ADDR.0]&1)==1 && [H00.0]==1 && ohrana==2) {if(!stopspam) {setStatus(2047:32, {8, "КТО ТО СНЯЛ С АЛЬФЫ! ПРОВЕРЬТЕ!!!"}); stopspam=1;} else {stopspam=1; delayedCall(offSpam, 60);}}
}

//Проверка что контрольный геркон замкнулся!
void OnSecurity(){
  if([H00.0]==0){
    ohrana=2;
    setStatus(2047:32, {8, "На охране Альфа"});
    cancelDelayedCall(OnSecurity);
  }
}

//Проверка что контрольный геркон разомкнут!
void OffSecurity(){
  if([H00.0]==1){
    ohrana=0;
    setStatus(2047:32, {8, "Снято с охраны!"});
    cancelDelayedCall(OffSecurity);
  }
}

//Проверка что все зоны без движения и можно ставить на охрану
void CheckGoOut(){
  if( ([L01.0])==0
    && [L02.0]==0
    && [L03.0]==0
    && [L04.0]==0
    && [L05.0]==0
    && [L06.0]==0
    && [L07.0]==0) {setStatus(SECURITY, 1); setStatus(2047:32, {8, "Ставим на охрану..."}); delayedCallR(OnSecurity, 1);}
    else {setStatus(V-ADDR, 0); setStatus(2047:32, {8, "Есть движение в одной из зон. Охрана не установленна"});}
}

V-ID/V-ADDR{
  if( (opt(0)&1)==1 ){
    ohrana=1; //Антиспам
    delayedCall(CheckGoOut, TIME);
    u8 strForMass[55];
    sprintf(strForMass+1, "У Вас есть %d секунд на выход", TIME);
    strForMass[0]=8;
    setStatus(2047:32, &strForMass);
  } else {if(ohrana==2) {setStatus(2047:32, {8, "Снятие с охраны..."}); delayedCallR(OffSecurity, 1);} ohrana=0; setStatus(SECURITY, 0);}
}