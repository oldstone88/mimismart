/*
{
  desc:"Ballu BLC MB 20Y",
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

u8 write = 0;
u8 writehold[15]={0x02, 0x10, 0x00, 0x02, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 writecoil[8]={0x02, 0x05, 0x00, 0x01, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8]={0x02, 0x03, 0x00, 0x02, 0x00, 0x03, 0xCC, 0x16};
u8 readcoil[8]={0x02, 0x01, 0x00, 0x01, 0x00, 0x01, 0xCC, 0x16};
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

void setmode (u8 rezhim){
    if (rezhim==0) {rezhim=6; return rezhim;} //Обдув
    if (rezhim==1) {rezhim=1; return rezhim;} //Охлаждение
    if (rezhim==2) {rezhim=2; return rezhim;} //Сушка
    if (rezhim==3) {rezhim=4; return rezhim;} //Обогрев
    if (rezhim==4) {rezhim=0; return rezhim;} //Авто
}

void backmode (u8 rezhim){
    if (rezhim==6) {rezhim=0;} //Обдув
    else if (rezhim==1) {rezhim=1;} //Охлаждение
    else if (rezhim==2) {rezhim=2;} //Сушка
    else if (rezhim==4) {rezhim=3;} //Обогрев
    else if (rezhim==0) {rezhim=4;} //Авто
    return rezhim;
}

void speedToRS(u8 speed){
    if (speed==1) {speed=3; return speed;}
    if (speed==2) {speed=2; return speed;}
    if (speed==3) {speed=1; return speed;}
    if (speed==0) {speed=5; return speed;}
}

void rsToSpeed(u8 speed){
    if (speed==3) {speed=1; return speed;}
    if (speed==2) {speed=2; return speed;}
    if (speed==1) {speed=3; return speed;}
    if (speed==5) {speed=0; return speed;}
}

u16 NeedSend = 0;

// Отправка hold регистров
void slavesend(){
    setStatus(RS485, &writehold);
}

void stopwrite(){
    write=0;
}

void send(){
    cancelDelayedCall(send);
    u8 breakpoint=0;
    if(NeedSend){
        for(u8 i=0; (i<4) && (breakpoint==0); ++i){
            if( (NeedSend>>i)&1 ){
                u8 state[5];
                if(!i) {getStatus(Cond01, state);}
                else if(i==1) {getStatus(Cond02, state);}
                else if(i==2) {getStatus(Cond03, state);}
                else if(i==3) {getStatus(Cond04, state);}
                writecoil[0]=Addr[i]; // Адрес кондиционера
                if(state[0]%2==1) writecoil[4]=0xFF; // ВКЛ-ВЫКЛ
                else writecoil[4]=0x00;
                setStatus(RS485, writecoil);
                writehold[0]=Addr[i]; // Адрес кондиционера
                u16 temperature = (state[1]+16)*10; // Температура
                // srvError("Температура = %d", temperature);
                writehold[9]=temperature>>8;
                writehold[10]=temperature;
                // srvError("Регистр 9 = %x, регистр 10 = %x", writehold[9], writehold[10]);
                writehold[8]=setmode(state[0]>>4); // Режим
                writehold[12]=speedToRS(state[4]); // Скорость
                delayedCallMs(slavesend, 250);
                NeedSend -= 1<<i;
                if(NeedSend) delayedCall(send, 1);
                else {cancelDelayedCall(stopwrite); delayedCall(stopwrite, 5);}
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

// Проверка ВКЛ-ВЫКЛ
void onOffcheker(){
    if(write==0){
        readcoil[0]=Addr[count];
        setStatus(RS485, &readcoil);
        if(count!=4) ++count; else count=0;
    }
}

// Секция обратной связи
V-ID/s:5{
    if(write==0){
        readhold[0]=Addr[count];
        setStatus(RS485, &readhold);
        delayedCallMs(onOffcheker, 500);
    }
}

V-ID/RS485{
    //stat();
    if(optl==11 && opt(1)==0x03){
        u8 cond[5]={0, 0, 0, 0, 0};
        // Считываем состояние
        if(opt(0)==Addr[0]) getStatus(Cond01, cond);
        else if (opt(0)==Addr[1]) getStatus(Cond02, cond);
        else if (opt(0)==Addr[2]) getStatus(Cond03, cond);
        else if (opt(0)==Addr[3]) getStatus(Cond04, cond);
        // Обратная связь
        cond[0]=(cond[0]&1)|(backmode(opt(4))<<4); //Режим
        u16 temperature=((opt(5)<<8)|(opt(6)))/10-16;
        if(temperature<=16) cond[1]=temperature; // Температура + Проверка что не случилось переполнение
        cond[4]=rsToSpeed(opt(8)); // Скорость
        // Распределение уставки по блокам
        if(opt(0)==Addr[0]){setStatus(Cond01, &cond);}
        else if(opt(0)==Addr[1]){setStatus(Cond02, &cond);}
        else if(opt(0)==Addr[2]){setStatus(Cond03, &cond);}
        else if(opt(0)==Addr[3]){setStatus(Cond04, &cond);}
    }
    else if(optl==6 && opt(1)==0x01){
        u8 OnOff=opt(3); // Получаем состояние ВКЛ-ВЫКЛ
        u8 cond[5]={0, 0, 0, 0, 0};
        // Считываем состояние
        if(opt(0)==Addr[0]) getStatus(Cond01, &cond);
        else if(opt(0)==Addr[1]) getStatus(Cond02, &cond);
        else if(opt(0)==Addr[2]) getStatus(Cond03, &cond);
        else if(opt(0)==Addr[3]) getStatus(Cond04, &cond);
        if (OnOff){
            cond[0]=cond[0]|1;
        } else{
            cond[0]=cond[0]&0xFE;
        }
        // Записываем состояние
        if(opt(0)==Addr[0]) setStatus(Cond01, &cond);
        else if(opt(0)==Addr[1]) setStatus(Cond02, &cond);
        else if(opt(0)==Addr[2]) setStatus(Cond03, &cond);
        else if(opt(0)==Addr[3]) setStatus(Cond04, &cond);
    }
}