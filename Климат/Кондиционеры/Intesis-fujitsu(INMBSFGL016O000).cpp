/*
{
  desc:"INMBSFGL016O000",
  tag:"import-script",
  selectArea:true,
  name:"Шлюз Intesis",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер1", sub-id:"%SUBID01%", type:"conditioner",funs:"0x0F",modes:"0x06",t-min:"18",t-delta:"12",vane-hor:"0x00",vane-ver:"0x00"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер2", sub-id:"%SUBID02%", type:"conditioner",funs:"0x0F",modes:"0x06",t-min:"18",t-delta:"12",vane-hor:"0x00",vane-ver:"0x00"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер3", sub-id:"%SUBID03%", type:"conditioner",funs:"0x0F",modes:"0x06",t-min:"18",t-delta:"12",vane-hor:"0x00",vane-ver:"0x00"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер4", sub-id:"%SUBID04%", type:"conditioner",funs:"0x0F",modes:"0x06",t-min:"18",t-delta:"12",vane-hor:"0x00",vane-ver:"0x00"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер5", sub-id:"%SUBID05%", type:"conditioner",funs:"0x0F",modes:"0x06",t-min:"18",t-delta:"12",vane-hor:"0x00",vane-ver:"0x00"},
  ],
  vars:
  [
    {name:"ID00",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
    {name:"RS485",type:"devices-list",required:false,width:600,filter:["com-port"],desc:"RS",descWidth:100},
    {name:"COND1",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"COND2",type:"hidden",value:"%TARGET%:%SUBID02%"},
    {name:"COND3",type:"hidden",value:"%TARGET%:%SUBID03%"},
    {name:"COND4",type:"hidden",value:"%TARGET%:%SUBID04%"},
    {name:"COND5",type:"hidden",value:"%TARGET%:%SUBID05%"},
  ]
}
*/

void stat()
{
u8 res[50]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

u8 NeedSend=0; //Маркер какой кондиционер должен отправить свой статус
u8 NumSend=0; //Номер операции отправки
u8 counter=0; //Счетчик чтения
u8 read[8]={ID00, 0x03, 0x00, 0x00, 0x00, 0x07, 0xCC, 0x16};
u8 write[8]={ID00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

const u16 ID [] = {
    ADDR2ID(COND1)
    #ifdef COND2, ADDR2ID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2ID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2ID(COND4) #else ,0 #endif
    #ifdef COND5, ADDR2ID(COND5) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND1)
    #ifdef COND2, ADDR2SID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2SID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2SID(COND4) #else ,0 #endif
    #ifdef COND5, ADDR2SID(COND5) #else ,0 #endif
};

void sendToIntesis(){
  u8 breakpoint=0;
  cancelDelayedCall(sendToIntesis);
  for(u8 i=0; (i<5) && (breakpoint==0); ++i){
    if((NeedSend>>i)&1){
      breakpoint=1;
      u8 cond[5]={0, 0, 0, 0, 0};
      if(i==0) {getStatus(COND1, &cond);}
      else if(i==1) {getStatus(COND2, &cond);}
      else if(i==2) {getStatus(COND3, &cond);}
      else if(i==3) {getStatus(COND4, &cond);}
      else if(i==4) {getStatus(COND5, &cond);}
      if(!NumSend) NumSend=7;
      else if(NumSend==6){
        //Вкл-Выкл
        write[2]=(200+100*i)>>8;
        write[3]=200+100*i;
        write[4]=0x00;
        write[5]=cond[0];
      } else if(NumSend==5){
        //Режимы
        write[2]=(200+100*i+1)>>8;
        write[3]=200+100*i+1;
        write[4]=0x00;
        if(cond[0]>>4==0) write[5]=4;
        else if(cond[0]>>4==1) write[5]=2;
        else if(cond[0]>>4==2) write[5]=1;
      } else if(NumSend==4){
        //Скорости (У канальных блоков регистр 3, у настенного - 2)!!! ТУТ ОЧЕНЬ ВНИМАТЕЛЬНО!!!
        if(i==1) {write[2]=(200+100*i+2)>>8; write[3]=(200+100*i+2);}
        else {write[2]=(200+100*i+3)>>8; write[3]=200+100*i+3;}
        u8 set=0;
        if(cond[4]==0) set=0;
        else if(cond[4]==1) set=2;
        else if(cond[4]==2) set=3;
        else if(cond[4]==3) set=4;
        write[4]=0x00;
        write[5]=set;
      } else if(NumSend==3){
        //Лопости верх-низ
        write[2]=(200+100*i+4)>>8;
        write[3]=200+100*i+4;
      } else if(NumSend==2){
        //Лопости право-лево
        write[2]=(200+100*i+5)>>8;
        write[3]=200+100*i+5;
      } else if(NumSend==1){
        //Температура
        write[2]=(200+100*i+6)>>8;
        write[3]=200+100*i+6;
        write[4]=((cond[1]+18)*10)>>8;
        write[5]=(cond[1]+18)*10;
      }
      if(NumSend!=7) setStatus(RS485, &write);
      --NumSend;
      breakpoint=1;
      if(!NumSend) NeedSend-=1<<i;
      if(NeedSend) delayedCallMs(sendToIntesis, 150);
    }
  }  
}

V-ID/COND1, COND2, COND3, COND4, COND5
{
  if(senderId()!=exciterId())
  {
    for(u8 i=0;i<5;++i)
    {
      if(ID[i] && SID[i] && SID[i]==senderSubId())
      {
        NeedSend|=1<<i; //Помечаем что нужна отправка
        cancelDelayedCall(sendToIntesis);
        NumSend=7;
        delayedCall(sendToIntesis, 1);
      }
    }
  }
}

//Обратная связь
void chtenie(u8 OnOff, u8 tempHi, u8 tempLow, u8 speed, u8 mode){
  u8 tocond[5]={0, 0, 0, 0, 0};
  //Вкл-Выкл
  tocond[0]=OnOff;
  //Температура
  u16 temperatura=tempHi<<8|tempLow;
  tocond[1]=temperatura/10-18;
  //Скорость
  if(speed==2) tocond[4]=1;
  else if(speed==3) tocond[4]=2;
  else if(speed==4) tocond[4]=3;
  else tocond[4]=0;
  //Режимы
  if(mode==1) tocond[0]|=2<<4; //Нагрев
  else if(mode==2) tocond[0]|=1<<4; //Сушка
  else if(mode==4 && OnOff) tocond[0]=1; //Холод
  //srvError("mode = %d, tocond[0] = %d", mode, cond[0]);
  setStatus(@ID[counter]:@SID[counter], &tocond);

  if(counter<7) ++counter; else counter=0;
}

//Чтение состояний
V-ID/s:1{
  if(!NeedSend){
    if(counter==0) {read[2]=(200+(100*counter))>>8; read[3]=200+(100*counter); setStatus(RS485, &read);}
    else if(counter==1) {read[2]=(200+(100*counter))>>8; read[3]=200+(100*counter); setStatus(RS485, &read);}
    else if(counter==2) {read[2]=(200+(100*counter))>>8; read[3]=200+(100*counter); setStatus(RS485, &read);}
    else if(counter==3) {read[2]=(200+(100*counter))>>8; read[3]=200+(100*counter); setStatus(RS485, &read);}
    else if(counter==4) {read[2]=(200+(100*counter))>>8; read[3]=200+(100*counter); setStatus(RS485, &read);}
  }
}

V-ID/RS485{
  //stat();
  if(optl==19 && opt(0)==1) chtenie(opt(4), opt(15), opt(16), opt(8), opt(6));
}