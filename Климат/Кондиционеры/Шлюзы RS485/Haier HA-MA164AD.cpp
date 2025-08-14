/*
{
  desc:"HA-MA164AD настройки RS br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 2", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 3", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 4", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 5", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
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

u8 write=0;
u8 NeedSend=0; // Флаги какой кондиционер требует отправки состояния
u8 NumSend=0; // Номер отправки команды

u8 numberCond=0; // Номер кондиционера
u8 setTemp=0; // Температура
u8 speed=0; // Скорость
u8 mode=0; // Режим

void startread(){
    write=0;
}

void settings(){
    u8 modbusregister=numberCond*4;
    u8 condstatus[15]={Address, 0x10, 0x00, modbusregister, 0x00, 0x03, 0x06, 0x00, setTemp, 0x00, mode, 0x00, speed, 0xCC, 0x16};
    setStatus(RS485, &condstatus);
}

void Send(){
    u8 breakpoint = 0;
    cancelDelayedCall(Send);
    if(NeedSend){
        for(u8 i=0; i<5 && (breakpoint==0); ++i){
            if((NeedSend>>i)&1){
                breakpoint=1;
                u8 cond[5]={0, 0, 0, 0, 0};
                if(!i){getStatus(COND00, cond);} else
                if(i==1){getStatus(COND01, cond);} else
                if(i==2){getStatus(COND02, cond);} else
                if(i==3){getStatus(COND03, cond);} else
                if(i==4){getStatus(COND04, cond);}
                u8 modbusregister = i; // Вычисляется адрес первого регистра для записи
                numberCond=i; // Для вычисления регистра для уставок
                u8 condstatus[8]={Address, 0x05, 0x00, modbusregister, 0x00, 0x00, 0xCC, 0x16};
                // ВКЛ-ВЫКЛ
                if(cond[0]%2==1) condstatus[4]=0xFF;
                // Температура
                setTemp=cond[1]+16;
                // Режимы
                if((cond[0]>>4)==0) mode=4;
                else if((cond[0]>>4)==1) mode=1;
                else if((cond[0]>>4)==2) mode=3;
                else if((cond[0]>>4)==3) mode=2;
                else if((cond[0]>>4)==4) mode=5;
                // Скорости
                if(cond[4]==0) speed=4;
                else speed=cond[4];
                write=1;
                setStatus(RS485, &condstatus); // Отправка состояния
                delayedCallMs(settings, 500);
                NeedSend -= 1<<i;
                if(NeedSend) {delayedCall(Send, 1);} else delayedCall(startread, 10); 
            }
        }
    }
}

u8 readcond=0; // Кондиционер который считываем

void readStatus(){
    u8 modbusregister = readcond*4; // Вычисляется адрес первого регистра для чтения
    u8 readmodbus[8]={Address, 0x03, 0x00, modbusregister, 0x00, 0x03, 0xCC, 0x16};
    setStatus(RS485, &readmodbus);
}

V-ID/COND00, COND01, COND02, COND03, COND04{
    if(senderId()!=exciterId()){
        cancelDelayedCall(readStatus);
        for(u8 i=0;i<5;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId()){
                    write=1;
                    NeedSend |= 1<<i;
                    cancelDelayedCall(Send);
                    delayedCall(Send,1);
            }
        }
    }
}

V-ID/s:1{
    if(write==0){
        ++readcond;
        if(readcond>4) readcond=0;
        u8 modbusregister = readcond; // Вычисляется адрес первого регистра для чтения
        u8 readcond[8]={Address, 0x01, 0x00, modbusregister, 0x00, 0x01, 0xCC, 0x16};
        //srvError("Считали кондиционер %d", modbusregister);
        setStatus(RS485, &readcond);
        delayedCallMs(readStatus, 500); // Чтение состояния
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
    u8 cond[5]={0, 0, 0, 0, 0};
    // Температура
    if(opt(4)>=16) cond[1]=opt(4)-16; // Проверка на пустое значение, чтоб не было глюков
    // Режимы
    if(opt(6)==1) cond[0]|=1<<4; // Холод
    else if(opt(6)==2) cond[0]|=3<<4; // Нагрев
    else if(opt(6)==3) cond[0]|=2<<4; // Осушение
    else if(opt(6)==4) cond[0]|=0<<4; // Вентиляция
    else if(opt(6)==5) cond[0]|=4<<4; // Авто
    // Скорости
    if(opt(8)==1) cond[4]=1; // Низкая
    else if(opt(8)==2) cond[4]=2; // Средняя
    else if(opt(8)==3) cond[4]=3; // Высокая
    else if(opt(8)==4) cond[4]=0; // Авто
    // Установка статуса
    if(readcond==0) { cond[0]|=([COND00.0]&1); setStatus(COND00, &cond);}
    else if(readcond==1) {cond[0]|=([COND01.0]&1); setStatus(COND01, &cond);}
    else if(readcond==2) {cond[0]|=([COND02.0]&1); setStatus(COND02, &cond);}
    else if(readcond==3) {cond[0]|=([COND03.0]&1); setStatus(COND03, &cond);}
    else if(readcond==4) {cond[0]|=([COND04.0]&1); setStatus(COND04, &cond);}
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    // Проверка ВКЛ-ВЫКЛ
    if(opt(0)==Address && opt(1)==1 && optl==6){
        u8 cond[5]={0, 0, 0, 0 ,0};
        if(!readcond) getStatus(COND00, cond);
        else if(readcond==1) getStatus(COND01, cond);
        else if(readcond==2) getStatus(COND02, cond);
        else if(readcond==3) getStatus(COND03, cond);
        else if(readcond==4) getStatus(COND04, cond);
        cond[0]=cond[0]|opt(3);
        setStatus(@ID[readcond]:@SID[readcond], &cond);
    }
    else if(opt(0)==Address && opt(1)==3 && optl==11) synccond(); // Чтение состояния
}
