/*
{
  desc:"MD-CCM18A/N(A) br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 2", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 3", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 4", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 5", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID07%"},
        {name:"COND04",type:"hidden",value:"%TARGET%:%SUBID09%"},
  ]
}
*/

const u16 ID [] = {
    ADDR2ID(COND00)
    #ifdef COND01, ADDR2ID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2ID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2ID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2ID(COND04) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND00)
    #ifdef COND01, ADDR2SID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2SID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2SID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2SID(COND04) #else ,0 #endif
};

u8 cond[5] = {0, 0, 0, 0, 0};
u8 write = 0;
u8 breakpoint = 0;
u8 NeedSend = 0; // Флаги какой кондиционер требует отправки состояния
u16 modbusregister = 0;
u8 condstatus[15] = {Address, 0x10, 0, 0x01, 0, 0x03, 0x06, 0, 0, 0, 0, 0, 0, 0xCC, 0x16};

void startread(){
    write=0;
}

void Send(){
    breakpoint = 0;
    cancelDelayedCall(Send);
    if(NeedSend){
        for(u8 i = 0; (i < 5) && (breakpoint == 0 ); ++i){
            if((NeedSend >> i)&1){
                breakpoint = 1;
                if(!i){getStatus(COND00, cond);}
                else if(i == 1){getStatus(COND01, cond);}
                else if(i == 2){getStatus(COND02, cond);}
                else if(i == 3){getStatus(COND03, cond);}
                else if(i == 4){getStatus(COND04, cond);}
                modbusregister = (32 * i) + 1; // Вычисляется адрес первого регистра для записи
                condstatus[2] = modbusregister>>8;
                condstatus[3] = modbusregister;
                // Режим
                if((cond[0]>>4) == 0 ) condstatus[8] = 1; // Обдув
                else if((cond[0]>>4) == 1) condstatus[8] = (1<<3); // Охлаждение
                else if((cond[0]>>4) == 2) condstatus[8] = (1<<1); // Осушение
                else if((cond[0]>>4) == 3) condstatus[8] = (1<<2); // Обогрев
                else if((cond[0]>>4) == 4) condstatus[8] = (1<<4); // Авто
                // ВКЛ-ВЫКЛ
                condstatus[8] |= ((cond[0]%2)<<7);
                // srvError("Регистр режима и ВКЛ-ВЫКЛ = %x", condstatus[8]);
                // Скорость
                if(cond[4] == 0) condstatus[10] = (1<<7); // Авто
                else if(cond[4] == 1) condstatus[10] = (1<<2); // Низкая 
                else if(cond[4] == 2) condstatus[10] = (1<<1); // Средняя
                else if(cond[4] == 3) condstatus[10] = 1; // Высокая
                // srvError("Регистр скорости = %x", condstatus[10]);
                // Лопости
                // Ничего не делаем 
                // Температура
                condstatus[12] = cond[1]+17;
                // srvError("Регистр температуры = %x", condstatus[12]);
                setStatus(RS485, &condstatus); // Отправка состояния
                NeedSend -= 1<<i;
                if(NeedSend) {delayedCall(Send, 1);} else delayedCall(startread, 10); 
            }
        }
    }
}

V-ID/COND00, COND01, COND02, COND03, COND04{
    if(senderId()!=exciterId()){
        for(u8 i=0; i<5; ++i){
            if(SID[i] && SID[i]==senderSubId()){
                    write=1;
                    NeedSend |= 1<<i;
                    cancelDelayedCall(Send);
                    delayedCall(Send,1);
            }
        }
    }
}

u8 readCount = 0; // Кондиционер который считываем
u8 readcond[8] = {Address, 0x03, 0, 0, 0x00, 0x03, 0xCC, 0x16};

V-ID/s:1{
    if(write == 0){
        ++readCount;
        if(readCount>4) readCount=0;
        modbusregister = (readcond * 32) + 1; // Вычисляется адрес первого регистра для чтения
        readcond[2] = modbusregister>>8;
        readcond[3] = modbusregister;
        setStatus(RS485, &readcond);
    }
}


//вывод в лог ответов RS
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

// Обратная связь
void synccond(){
    // ВКЛ-ВЫКЛ
    cond[0] = (opt(4)&128);
    // Режимы
    if((opt(4)&16) == 16) cond[0] |= (4<<4); // Авто
    else if((opt(4)&8) == 8) cond[0] |= (1<<4); // Охлаждение
    else if((opt(4)&2) == 2) cond[0] |= (2<<4); // Осушение
    else if((opt(4)&1) == 1) cond[0] |= (0<<4); // Вентиляция
    else if((opt(4)&4) == 4) cond[0] |= (3<<4); // Нагрев
    // Скорости
    if(opt(6) == 4) cond[4]=0; // Низкая
    else if(opt(6) == 2) cond[4]=1; // Средняя
    else if(opt(6) == 1) cond[4]=2; // Высокая
    else if(opt(6) == 128) cond[4]=0; // Авто
    // Температура
    if(opt(8) >= 17) cond[1]=opt(8) - 17; // Проверка на пустое значение, чтоб не было глюков
    // Установка статуса
    if(readCount == 0) setStatus(COND00, &cond);
    else if(readCount == 1) setStatus(COND01, &cond);
    else if(readCount == 2) setStatus(COND02, &cond);
    else if(readCount == 3) setStatus(COND03, &cond);
    else if(readCount == 4) setStatus(COND04, &cond);
}

V-ID/RS485{
    if(opt(0)==Address && opt(1)==3 && optl==11) synccond(); // Чтение состояния
    #ifdef DEBUG stat(); #endif
}
