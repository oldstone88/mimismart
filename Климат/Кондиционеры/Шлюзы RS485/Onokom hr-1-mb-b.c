/*
{
  desc:"Onokom hr-1-mb-b",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"16", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 2", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"16", "t-delta":"16", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 3", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"16", "t-delta":"16", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 4", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"16", "t-delta":"16", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 5", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"16", "t-delta":"16", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"MBS00",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"MBS01",type:"number",min:"1",max:"127",required:true,defaultValue:"2",desc:"Адрес Modbus"},
        {name:"MBS02",type:"number",min:"1",max:"127",required:true,defaultValue:"3",desc:"Адрес Modbus"},
        {name:"MBS03",type:"number",min:"1",max:"127",required:true,defaultValue:"4",desc:"Адрес Modbus"},
        {name:"MBS04",type:"number",min:"1",max:"127",required:true,defaultValue:"5",desc:"Адрес Modbus"},
        {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID07%"},
        {name:"COND04",type:"hidden",value:"%TARGET%:%SUBID09%"},
  ]
}
*/

const u8 MBSAD [] = {
    MBS00,
    MBS01,
    MBS02,
    MBS03,
    MBS04,
};


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

u8 cond [5] = {0, 0, 0, 0, 0};
u8 write = 0;
u8 NeedSend = 0; // Флаги какой кондиционер требует отправки состояния
u8 SendNext = 0; // Отправка параметров по 1
u8 readcond[8] = {0x01, 0x03, 0x00, 0x02, 0x00, 0x06, 0xCC, 0x16};
u8 writecond[8] = {0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u16 temperature = 0;

void startread(){
    write=0;
}

void Send(){
    u8 breakpoint = 0;
    cancelDelayedCall(Send);
    if(NeedSend){
        for(u8 i=0; i<5 && (breakpoint==0); ++i){
            if((NeedSend>>i)&1){
                breakpoint = 1;
                if(!i){getStatus(COND00, cond);} else
                if(i==1){getStatus(COND01, cond);} else
                if(i==2){getStatus(COND02, cond);} else
                if(i==3){getStatus(COND03, cond);} else
                if(i==4){getStatus(COND04, cond);}

                if(SendNext == 0) SendNext = 3;
                // ВКЛ-ВЫКЛ + Режим
                else if(SendNext == 3){
                    writecond[0] = MBSAD[i];
                    writecond[3] = 0x02;
                    writecond[4] = 0x00;
                    if((cond[0]%2)==0) writecond[5] = 0;
                    else if(cond[0]==1) writecond[5] = 5;
                    else if(cond[0]==17) writecond[5] = 2;
                    else if(cond[0]==49) writecond[5] = 1;
                    else if(cond[0]==65) writecond[5] = 3;
                }
                // Температура
                else if(SendNext == 2){
                    writecond[0] = MBSAD[i];
                    writecond[3] = 0x05;
                    writecond[4] = ((cond[1]+16)*100)>>8;
                    writecond[5] = (cond[1]+16)*100;
                }
                // Скорость
                else if(SendNext == 1){
                    writecond[0] = MBSAD[i];
                    writecond[3] = 0x07;
                    writecond[4] = 0x00;
                    writecond[5] = cond[4];
                }
                // Лопости

                write=1;
                if(SendNext < 4 && SendNext > 0){
                    setStatus(RS485, &writecond);
                    SendNext -= 1;
                }
                if(!SendNext) NeedSend -= 1<<i;

                if(NeedSend) delayedCallMs(Send, 500); else delayedCall(startread, 10); 
            }
        }
    }
}

V-ID/COND00, COND01, COND02, COND03, COND04{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<5;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId()){
                    write=1;
                    SendNext = 3;
                    NeedSend |= 1<<i;
                    cancelDelayedCall(Send);
                    delayedCall(Send,1);
            }
        }
    }
}

u8 count=0; // Кондиционер который считываем

V-ID/s:1{
    if(write==0){
        ++count;
        if(count>4) count=0;
        readcond[0]=MBSAD[count];
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
    // ВКЛ-ВЫКЛ и режимы
    if(opt(4)==0) cond[0]=0;
    else if(opt(4)==1) cond[0] = 49; // Нагрев
    else if(opt(4)==2) cond[0] = 17; // Охлаждение
    else if(opt(4)==3) cond[0] = 65; // Авто
    else if(opt(4)==4) cond[0] = 33; // Осушение
    else if(opt(4)==5) cond[0] = 1; // Вентиляция
    // Температура
    temperature = (opt(9)<<8|opt(10))/100;
    cond[1] = temperature>15?temperature-16:0;
    // Скорости
	cond[4] = opt(14);
    // Установка статуса
    if(count==0) setStatus(COND00, &cond);
    else if(count==1) setStatus(COND01, &cond);
    else if(count==2) setStatus(COND02, &cond);
    else if(count==3) setStatus(COND03, &cond);
    else if(count==4) setStatus(COND04, &cond);
}

V-ID/RS485{
    if(opt(1)==3 && optl==17) synccond(); // Чтение состояния
    #ifdef DEBUG stat(); #endif
}
