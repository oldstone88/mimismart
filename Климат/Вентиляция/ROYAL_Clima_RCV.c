/*
{
  desc:"ROYAL Clima RCV br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E", "modes":"0x00"},
        {tag:"item", id:"%TARGET%", name:"NAME2", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E", "modes":"0x00"},
        {tag:"item", id:"%TARGET%", name:"NAME3", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E", "modes":"0x00"},
        {tag:"item", id:"%TARGET%", name:"NAME4", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E", "modes":"0x00"},
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
        {name:"Address1",type:"number",min:"0",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address2",type:"number",min:"0",max:"127",required:false,defaultValue:"2",desc:"Адрес Modbus"},
        {name:"Address3",type:"number",min:"0",max:"127",required:false,defaultValue:"3",desc:"Адрес Modbus"},
        {name:"Address4",type:"number",min:"0",max:"127",required:false,defaultValue:"4",desc:"Адрес Modbus"},

  ]
}
*/

u8 write = 0;
u8 state[5] = {0, 0, 0, 0, 0};
u8 writehold[8]={0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8]={0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0xCC, 0x16};
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

u8 NeedSend = 0; // Какой кондей
u8 NumSend = 0; // Что отправляем
u8 numRead = 0; // Что читаем
u8 breakpoint=0;

// Маркер чтения-записи
void stopwrite(){
    write=0;
}

void send(){
    cancelDelayedCall(send);
    breakpoint=0;
    if(NeedSend){
        if(NumSend == 0) NumSend = 3;
        for(u8 i=0; (i<4) && (breakpoint==0); ++i){
            if( (NeedSend>>i)&1 ){
                //srvError("Сейчас уставка кондиуионеру %d", i);
                breakpoint = 1;
                if(!i) getStatus(Cond01, state);
                else if(i==1) getStatus(Cond02, state);
                else if(i==2) getStatus(Cond03, state);
                else if(i==3) getStatus(Cond04, state);
                // Назначаем адрес шлюза
                writehold[0]=Addr[i];
                // Вкл - выкл
                if(NumSend == 3){
                    //srvError("Пробуем ВКЛ - ВЫКЛ");
                    writehold[3] = 0x00;
                    writehold[5] = state[0]&2;
                }
                // Температура
                else if(NumSend == 2){
                    //srvError("Пробуем температуру");
                    writehold[3] = 0x0A;
                    writehold[5] = state[1]+16;
                }
                // Скорость
                else if(NumSend == 1){
                    writehold[3] = 0x05;
                    writehold[5] = state[4]+1;
                }
                setStatus(RS485, &writehold);
                --NumSend;
                if(NumSend == 0) {
                    NeedSend -= 1<<i;
                }
                if(NeedSend) delayedCallMs(send, 250);
                else stopwrite();

            }
        }
    }
}

void readStatus(){
    if(numRead == 0) numRead = 3;
        // ВКЛ - ВЫКЛ
        readhold[0] = Addr[count];
        if(numRead == 3){
            //srvError("Считываем ВКЛ-ВЫКЛ");
            readhold[3] = 0x00;
        }
        else if(numRead == 2){
            readhold[3] = 0x0A;
        }
        else if(numRead == 1){
            readhold[3] = 0x05;
        }
        --numRead;
        setStatus(RS485, &readhold);
        if(numRead && write == 0) delayedCallMs(readStatus, 250);
}

V-ID/Cond01, Cond02, Cond03, Cond04{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<4;++i){
          if(SID[i]==senderSubId()){
            write=1;
            NeedSend |= (1<<i);
            NumSend=5;
            cancelDelayedCall(readStatus);
            cancelDelayedCall(send);
            delayedCall(send, 1);
          }
        }
    }
}

void stat(){
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

// Секция обратной связи
V-ID/s:5{
    if(write==0){
        count = count<3 ? ++count : 0;
        readStatus();
    }
}

u8 mode = 0;

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl == 8 && opt(1) == 0x03){
        if(count == 0) getStatus(Cond01, &state);
        else if(count == 1) getStatus(Cond02, &state);
        else if(count == 2) getStatus(Cond03, &state);
        else if(count == 3) getStatus(Cond04, &state);

        if(numRead == 2) {state[0] = opt(4);}
        else if(numRead == 1) {state[1] = opt(4)>=16 ? opt(4) - 16 : 0;}
        else if(numRead == 0) {state[4] = opt(4)>0 ? opt(4) - 1 : 0;}
        setStatus(@ID[count]:@SID[count], &state);
    }
}
