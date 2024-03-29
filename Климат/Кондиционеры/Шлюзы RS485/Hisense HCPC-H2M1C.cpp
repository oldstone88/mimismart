/*
{
  desc:"HCPC-H2M1C настройки RS br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"19", "t-delta":"11", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 2", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"19", "t-delta":"11", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 3", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"19", "t-delta":"11", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 4", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"19", "t-delta":"11", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID07%"},
  ]
}
*/

const u16 ID [] = {
    ADDR2ID(COND00)
    #ifdef COND01, ADDR2ID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2ID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2ID(COND03) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND00)
    #ifdef COND01, ADDR2SID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2SID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2SID(COND03) #else ,0 #endif
};

u8 cond [5];
u8 count=0;
u8 write=0;
u8 NeedSend=0; // Флаги какой кондиционер требует отправки состояния

void startread(){
    write=0;
}

void Send(){
    u8 breakpoint = 0;
    cancelDelayedCall(Send);
    if(NeedSend){
        for(u8 i=0; i<4 && (breakpoint==0); ++i){
            if((NeedSend>>i)&1){
                breakpoint=1;
                if(!i){getStatus(COND00, cond);} else
                if(i==1){getStatus(COND01, cond);} else
                if(i==2){getStatus(COND02, cond);} else
                if(i==3){getStatus(COND03, cond);}
                u16 modbusregister = 40000 + 78 + 91*i; // Вычисляется адрес первого регистра для записи
                u8 condstatus[]={Address, 0x10, modbusregister>>8, modbusregister, 0x00, 0x05, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
                // ВКЛ-ВЫКЛ
                condstatus[8] = cond[0]%2;
                // Режим
                if(cond[0]>>4==0) condstatus[10]=8; // Обдув
                else if(cond[0]>>4==1) condstatus[10]=2; // Охлаждение
                else if(cond[0]>>4==2) condstatus[10]=4; // Осушение
                else if(cond[0]>>4==3) condstatus[10]=16; // Обогрев
                //else if((cond[0]>>7)%2==1) condstatus[10]=1; // Авто
                // Скорость
                //if(cond[4]==0) condstatus[12]=1; // Авто
                //else 
                if(cond[4]==0) condstatus[12]=8; // Низкая 
                else if(cond[4]==1) condstatus[12]=4; // Средняя
                else if(cond[4]==2) condstatus[12]=2; // Высокая
                // Лопости
                // Ничего не делаем 
                // Температура
                condstatus[16] = cond[1]+19;
                write=1;
                setStatus(RS485, &condstatus); // Отправка состояния
                NeedSend -= 1<<i;
                if(NeedSend) {delayedCall(Send, 1);} else delayedCall(startread, 10); 
            }
        }
    }
}

V-ID/COND00, COND01, COND02, COND03{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<4;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId()){
                    write=1;
                    count=0;
                    NeedSend |= 1<<i;
                    cancelDelayedCall(Send);
                    delayedCall(Send,1);
            }
        }
    }
}

u8 readcond=0; // Кондиционер который считываем

V-ID/s:1{
    if(write==0){
        ++readcond;
        if(readcond>3) readcond=0;
        u16 modbusregister = 40000 + 2 + readcond*91; // Вычисляется адрес первого регистра для чтения
        u8 readcond[]={Address, 0x03, modbusregister>>8, modbusregister, 0x00, 0x07, 0xCC, 0x16};
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
    cond[0]=opt(4)%2;
    // Режимы
    //if(opt(6)==1) cond[0]=0; // Авто
    if(opt(6)==2) cond[0]|=1<<4; // Охлаждение
    else if(opt(6)==4) cond[0]|=2<<4; // Осушение
    else if(opt(6)==8) cond[0]|=0<<4; // Вентиляция
    else if(opt(6)==16) cond[0]|=3<<4; // Нагрев
    // Скорости
    if(opt(8)==8) cond[4]=0; // Низкая
    else if(opt(8)==4) cond[4]=1; // Средняя
    else if(opt(8)==2) cond[4]=2; // Высокая
    //else if(opt(8)==1) cond[4]=0; // Авто
    // Температура
    if(opt(16)>=19) cond[1]=opt(16)-19; // Проверка на пустое значение, чтоб не было глюков
    // Установка статуса
    if(readcond==0) setStatus(COND00, &cond);
    else if(readcond==1) setStatus(COND01, &cond);
    else if(readcond==2) setStatus(COND02, &cond);
    else if(readcond==3) setStatus(COND03, &cond);
}

V-ID/RS485
{
    if(opt(0)==Address && opt(1)==3 && optl==19) synccond(); // Чтение состояния
    //stat();
}