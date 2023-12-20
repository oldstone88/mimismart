/*
{
  desc:"Оазис_GTC",
  tag:"import-script",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"5", "t-delta":"34", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"5", "t-delta":"34", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    ],
  vars:
  [
    {name:"Address01",type:"number",required:false,min:1,max:250,defaultValue:1,desc:"Адрес установки 1",descWidth:340,width:100},
    {name:"Address02",type:"number",required:false,min:1,max:250,defaultValue:2,desc:"Адрес установки 2",descWidth:340,width:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
    {name:"K00",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"K01",type:"hidden",value:"%TARGET%:%SUBID03%"},
  ]
}
*/

u8 zapr=0; //Номер запроса
u8 write=0;
u8 kond[5];
u8 writeData[8]={0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16};
u8 needSend=0;
u8 numSend=0;

const u16 ID [] = {
    ADDR2ID(K00),
    ADDR2ID(K01)
};
const u8 SID [] = {
    ADDR2SID(K00),
    ADDR2SID(K01)
};

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
  if (j==2) {k=0x05; return(k);}
  if (j==3) {k=0x07; return(k);}
  if (j==0) {k=0x0A; return(k);}
}

//Скорость установки в скорость приложения(Обратная операция)
void usttoprog(u8 j)
{
  u8 k=0;
  if (j==0x02) {k=1; return(k);}
  if (j==0x05) {k=2; return(k);}
  if (j==0x07) {k=3; return(k);}
  if (j==0x0A) {k=0; return(k);}
  if (j==0x00) {k=0; return(k);}
}

void stopwrite(){
  write=0;
}

void setTemp(u8 vent){
  u16 temp=0;
  if(vent==0) {writeData[0]=Address01; temp=([K00.1]+5)*10;}
  else if(vent==1) {writeData[0]=Address02; temp=([K01.1]+5)*10;}
  writeData[3]=0x1F; writeData[4]=temp>>8; writeData[5]=temp;
  setStatus(RS485,&writeData);
}

void setObduv(u8 vent){
  if(vent==0) {writeData[0]=Address01; writeData[5]=progtoust([K00.4]);}
  else if(vent==1) {writeData[0]=Address02; writeData[5]=progtoust([K01.4]);}
  writeData[3]=0x20; writeData[4]=0;
  setStatus(RS485, &writeData);
}

void send(){
  u8 breakpoint=0;
  for(u8 i=0; (i<3) && (breakpoint==0); ++i){
    if((needSend>>i)&1==1){
      breakpoint=1;
      if(!numSend) numSend=2;
      if(!i) writeData[0]=Address01;
      else if(i==1) writeData[0]=Address02;
      if(numSend==2){setTemp(i); --numSend; delayedCallMs(send, 250);}
      else if(numSend==1){setObduv(i); --numSend;}
      if(!numSend){needSend-=1<<i;}
      if(needSend) delayedCallMs(send, 250);
      else delayedCallMs(stopwrite, 7);
    }
  }
}

V-ID/K00, K01{
   if(senderId()!=exciterId()){
    for(u8 i=0; i<3; ++i){
      if(SID[i]==senderSubId()){
        writeData[0]=i?Address01:Address02; // Определяем какой вентиляции посылаем статусы
        write=1;
        writeData[3]=0x02; // Вкл-Выкл
        writeData[4]=0x00;
        if(opt(0)%2==1){
          writeData[5]=0x01;
          writeSend|=1<<i;  // Ставим флаг что нужно отправлять еще температуру и скорость
          cancelDelayedCall(send);
          delayedCallMs(send, 250); // Запускаем функцию отправки
        }
        else if(opt(0)%2==0){
          writeData[5]=0x00;
        }
        setStatus(RS485, &writeData);
      }
    }
  }
}


// Секция обратной связи
V-ID/s:5
{
  if(write==0){
      if(zapr==0) {setStatus(RS485,{Address01, 0x04, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); zapr=1;} else //Вкл-Выкл
      if(zapr==1) {setStatus(RS485,{Address01, 0x04, 0x00, 0x19, 0x00, 0x01, 0xCC, 0x16}); zapr=2;} else //Скорость
      if(zapr==2) {setStatus(RS485,{Address01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xCC, 0x16}); zapr=3;} else //Температура
      if(zapr==3) {setStatus(RS485,{Address02, 0x04, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); zapr=4;} else //Вкл-Выкл
      if(zapr==4) {setStatus(RS485,{Address02, 0x04, 0x00, 0x19, 0x00, 0x01, 0xCC, 0x16}); zapr=5;} else //Скорость
      if(zapr==5) {setStatus(RS485,{Address02, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xCC, 0x16}); zapr=0;} //Температура
    }
}

V-ID/RS485
{
  //stat();
  //Обратная связь вкл-выкл
  if (zapr==1 && optl==7 && write==0){
    if( (opt(4)&1)!=[K00.0]%2 ){
      getStatus(K00, &kond); kond[0]=(opt(4)&1); setStatus(K00, &kond);
      //srvError("onOff=%d", opt(4)&1);
    }
  } else
  //Обратная связь скорость
  if (zapr==2 && optl==7 && write==0 && ([K00.0]&1)==1){
    if( usttoprog(opt(4))!=[K00.4] ){
      getStatus(K00, &kond); kond[4]=usttoprog(opt(4)); setStatus(K00, &kond);
      //srvError("Скорость=%d", kond[4]);
    }
  } else
  //Обратная связь температура
  if (zapr==3 && optl==7 && write==0 && ([K00.0]&1)==1){
    if( (opt(3)<<8|opt(4))!=(([K00.1]+5)*10) ){
      getStatus(K00, &kond); kond[1]=(((opt(3)<<8|opt(4))/10)-5); setStatus(K00, &kond);
      //srvError("Температура=%d", kond[1]+5);
    }
  } else
  if (zapr==4 && optl==7 && write==0){
    if( (opt(4)&1)!=[K01.0]%2 ){
      getStatus(K01, &kond); kond[0]=(opt(4)&1); setStatus(K01, &kond);
      //srvError("onOff=%d", opt(4)&1);
    }
  } else
  //Обратная связь скорость
  if (zapr==5 && optl==7 && write==0 && ([K01.0]&1)==1){
    if( usttoprog(opt(4))!=[K01.4] ){
      getStatus(K01, &kond); kond[4]=usttoprog(opt(4)); setStatus(K01, &kond);
      //srvError("Скорость=%d", kond[4]);
    }
  } else
  //Обратная связь температура
  if (zapr==0 && optl==7 && write==0 && ([K01.0]&1)==1){
    if( (opt(3)<<8|opt(4))!=(([K01.1]+5)*10) ){
      getStatus(K01, &kond); kond[1]=(((opt(3)<<8|opt(4))/10)-5); setStatus(K01, &kond);
      //srvError("Температура=%d", kond[1]+5);
    }
  }
}