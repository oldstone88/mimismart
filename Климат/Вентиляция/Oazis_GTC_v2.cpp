/*
{
  desc:"Оазис_GTC",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Установка",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
    {name:"O00",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 1",descWidth:100},
    {name:"O01",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 2",descWidth:100},
    {name:"O02",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 3",descWidth:100},
    {name:"O03",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 4",descWidth:100},
    {name:"O04",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 5",descWidth:100},
  ]
}
*/

u8 zapr=0; //Номер запроса
u8 write=0;
u8 kond[5];
u8 i[8]={0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16};

void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

//Скорость в приложении в скорость установки(Если более 3х скоростей, иначе равны)
void progtoust(u8 j)
{
  u8 k=0;
  if (j==1) {k=0x02; return(k);}
  if (j==2) {k=0x04; return(k);}
  if (j==3) {k=0x07; return(k);}
  if (j==0) {k=0x0A; return(k);}
}

//Скорость установки в скорость приложения(Обратная операция)
void usttoprog(u8 j)
{
  u8 k=0;
  if (j==0x02) {k=1; return(k);}
  if (j==0x04) {k=2; return(k);}
  if (j==0x07) {k=3; return(k);}
  if (j==0x0A) {k=0; return(k);}
  if (j==0x00) {k=0; return(k);}
}

void setTemp(){
  u16 temp=([K00.1]+5)*10; i[3]=0x1F; i[4]=temp>>8; i[5]=temp;
  setStatus(RS485,&i);
}

void setObduv(){
  i[3]=0x20; i[4]=0; i[5]=progtoust([K00.4]);
  setStatus(RS485,&i);
  write=0;
}

V-ID/K00
{
   if(senderId()!=exciterId()){
    //Секция ВКЛ-ВЫКЛ
    if(opt(0)%2==0) {write=1; setStatus(RS485,{0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16});}
    else if(opt(0)%2!=0){
      write=1;
      setStatus(RS485,{0x01, 0x06, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16});
      cancelDelayedCall(setTemp);
      cancelDelayedCall(setObduv);
      delayedCallMs(setTemp,350);
      delayedCallMs(setObduv,700);
    }
  }
}

V-ID/s:5
{
  if(write==0)
    {
      if(zapr==0) {setStatus(RS485,{0x01, 0x04, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); zapr=1;} else //Вкл-Выкл
      if(zapr==1) {setStatus(RS485,{0x01, 0x04, 0x00, 0x19, 0x00, 0x01, 0xCC, 0x16}); zapr=2;} else //Скорость
      if(zapr==2) {setStatus(RS485,{0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xCC, 0x16}); zapr=0;} //Температура
    }
}

V-ID/RS485
{
  stat();
  //Обратная связь вкл-выкл
  if (zapr==1 && optl==7 && write==0){
    if( (opt(4)&1)!=[K00.0]%2 ){
      getStatus(K00, &kond); kond[0]=(opt(4)&1); setStatus(K00, &kond);
      srvError("onOff=%d", opt(4)&1);
    }
  } else
  //Обратная связь скорость
  if (zapr==2 && optl==7 && write==0 && ([K00.0]&1)==1){
    if( usttoprog(opt(4))!=[K00.4] ){
      getStatus(K00, &kond); kond[4]=usttoprog(opt(4)); setStatus(K00, &kond);
      srvError("Скорость=%d", kond[4]);
    }
  } else
  //Обратная связь температура
  if (zapr==0 && optl==7 && write==0 && ([K00.0]&1)==1){
    if( (opt(3)<<8|opt(4))!=(([K00.1]+5)*10) ){
      getStatus(K00, &kond); kond[1]=(((opt(3)<<8|opt(4))/10)-5); setStatus(K00, &kond);
      srvError("Температура=%d", kond[1]+5);
    }
  }
}