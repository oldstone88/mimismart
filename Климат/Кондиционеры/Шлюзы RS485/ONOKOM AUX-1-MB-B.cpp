/*
{
  desc:"ONOKOM AUX-2MB-B br 9600 stop 2.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME2", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME3", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME4", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"}
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 1"},
        {name:"NAME2",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 2"},
        {name:"NAME3",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 3"},
        {name:"NAME4",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 4"},
        {name:"Cond01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Cond02",type:"hidden",value:"%TARGET%:%SUBID02%"},
        {name:"Cond03",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"Cond04",type:"hidden",value:"%TARGET%:%SUBID04%"},
        {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address2",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address3",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address4",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},

  ]
}
*/

#define DEBUG 1

u8 NeedSend = 0;
u8 onMass = 0;
u8 write = 0;
u8 prevState[5];
u8 writehold[15]={0x00, 0x10, 0x00, 0x05, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8]={0x00, 0x03, 0x00, 0x02, 0x00, 0x06, 0xCC, 0x16};
u8 readHoldCorr[8]={0x00, 0x03, 0x00, 0x14, 0x00, 0x01, 0xCC, 0x16};
u8 writeHoldMode[8]={0x00, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16};
u8 count=0;


const u16 ID [] = {
    ADDR2ID(Cond01)
    #ifdef Cond02, ADDR2ID(Cond02) #else ,0 #endif
    #ifdef Cond03, ADDR2ID(Cond03) #else ,0 #endif
    #ifdef Cond04, ADDR2ID(Cond04) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(Cond01)
    #ifdef Cond02, ADDR2SID(Cond02) #else ,0 #endif
    #ifdef Cond03, ADDR2SID(Cond03) #else ,0 #endif
    #ifdef Cond04, ADDR2SID(Cond04) #else ,0 #endif
};

const u8 Addr [] = {
    Address1
    #ifdef Address2, Address2 #else ,0#endif
    #ifdef Address3, Address3 #else ,0#endif
    #ifdef Address4, Address4 #else ,0#endif
};


//------------------------------------------

// Контрольная сумма
void CRC16modbus(u8 size){
  u16 reg=0XFFFF;
  u16 pol=0xA001;
  // size-2 потому что 2 байта как раз контрольная сумма
  for(u8 j=0; j<(size-2); ++j){
    if(onMass==1) reg=reg^writehold[j];
    else if (onMass==2) reg=reg^readhold[j];
    else if (onMass==3) reg=reg^readHoldCorr[j];
    else if (onMass==4) reg=reg^writeHoldMode[j];
    for(u8 g=0; g<8; ++g){
      if((reg&0x01)==1){
        reg=reg>>1;
        reg=reg^pol;
      } else{
        reg=reg>>1;
      }
    }
  }
    return reg;
}

void setmode (u8 rezhim){
    if ((rezhim%2)==0) {rezhim=0x00; return rezhim;} // Выключен
    if (rezhim==1) {rezhim=0x05; return rezhim;} // Обдув
    if (rezhim==17) {rezhim=0x02; return rezhim;} // Охлаждение
    if (rezhim==33) {rezhim=0x04; return rezhim;} // Сушка
    if (rezhim==49) {rezhim=0x01; return rezhim;} // Нагрев
    if (rezhim==65) {rezhim=0x03; return rezhim;} // Авто
}

void backmode (u8 rezhim){
    if (rezhim==0x00) {rezhim=0; return rezhim;} // Выключен
    if (rezhim==0x01) {rezhim=49; return rezhim;} // Нагрев
    if (rezhim==0x02) {rezhim=17; return rezhim;} // Охлаждение
    if (rezhim==0x03) {rezhim=65; return rezhim;} // Авто
    if (rezhim==0x04) {rezhim=33; return rezhim;} // Сушка
    if (rezhim==0x05) {rezhim=1; return rezhim;} // Вентиляция
}

// Маркер чтения-записи
void stopwrite(){
    write=0;
}

void sendStateOnokom(){
    setStatus(RS485, &writehold);
}

void send(){
    cancelDelayedCall(send);
    u8 breakpoint=0;
    u16 crc16;
    if(NeedSend){
        for(u8 i=0;(i<4) && (breakpoint==0);++i){
            if( (NeedSend>>i)&1 ){
                breakpoint=1;
                u8 state[5];
                if(!i) getStatus(Cond01, state);
                else if(i==1) getStatus(Cond02, state);
                else if(i==2) getStatus(Cond03, state);
                else if(i==3) getStatus(Cond04, state);
                // Назначаем адрес шлюза
                writehold[0]=Addr[i];
                writeHoldMode[0]=Addr[i];
                // Режим и ВКЛ-ВЫКЛ
                if (prevState[0]!=state[0]) {
                writeHoldMode[5]=setmode(state[0]);
                onMass = 4;
                crc16 = CRC16modbus(sizeof(writeHoldMode));
                writeHoldMode[6]=crc16;
                writeHoldMode[7]=crc16>>8;
                setStatus(RS485, &writeHoldMode);
                memcpy(prevState, state, 5);
                }
                // Температура
                writehold[7]=((state[1]+16)*100)>>8;
                writehold[8]=((state[1]+16)*100);
                // Скорость
                writehold[12]=state[4];
                // CRC16_ModBus
                onMass = 1;
                crc16 = CRC16modbus(sizeof(writehold));
                writehold[13]=crc16;
                writehold[14]=crc16>>8;
                // Send state via rs
                delayedCallMs(sendStateOnokom, 360);

                NeedSend -= 1<<i;
                if(NeedSend) delayedCall(send, 1);
                else stopwrite();
            }
        }
    }
}

V-ID/Cond01, Cond02, Cond03, Cond04{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<4;++i){
          if(SID[i]==senderSubId()){
            write=1;
            NeedSend|=1<<i;
            cancelDelayedCall(send);
            delayedCall(send, 1);
          }
        }
    }
}

void checkCorr(u8 addr) {
    onMass = 3;
    readHoldCorr[0]=addr;
    // CRC16
    u16 crc16 = CRC16modbus(sizeof(readHoldCorr));
    readHoldCorr[6]=crc16;
    readHoldCorr[7]=crc16>>8;
    setStatus(RS485, &readHoldCorr);
}

void stat(){
    u8 res[100]="";
    u8 *st = opt;
    if (optl == 7 && st[1] == 3) {
        srvMessage("%cКоррекция = %d", 1, st[4]);
    } else {
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
    }
}

// Секция обратной связи
V-ID/s:3 {
    if(write==0){
        if(count==0){readhold[0]=Address1;}
        else if(count==1){readhold[0]=Address2;}
        else if(count==2){readhold[0]=Address3;}
        else if(count==3){readhold[0]=Address4;}

        // CRC16_ModBus
        onMass = 2;
        u16 crc16 = CRC16modbus(sizeof(readhold));
        readhold[6]=crc16;
        readhold[7]=crc16>>8;

        // Send state via rs
        setStatus(RS485, &readhold);
        count = count>3 ? ++count : 0;
    }
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl==17 && opt(1)==0x03){
        u8 cond[5]={0, 0, 0, 0, 0};
        // Режим и вкл-выкл
        cond[0]=backmode(opt(4));
        u16 temperature = (opt(9)<<8);
        temperature = ((temperature|opt(10))/100) - 16;
        if(temperature<=16) cond[1]=temperature; // Температура + Проверка что не случилось переполнение
        // Скорость
        cond[4]=opt(14);
        // Распределение уставки по блокам
        setStatus(@ID[count]:@SID[count], &cond);
        #ifdef DEBUG checkCorr(count); #endif
    }
}
