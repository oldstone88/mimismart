/*
{
  desc:"Термостат Techno KT-24 (Hysen HY607EC)",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
		{tag:"item", id:"%TARGET%", name:"Термостат1", "sub-id":"%SUBID99%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура1", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат2", "sub-id":"%SUBID95%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура2", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат3", "sub-id":"%SUBID91%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура3", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат4", "sub-id":"%SUBID87%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура4", "sub-id":"%SUBID85%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат5", "sub-id":"%SUBID83%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура5", "sub-id":"%SUBID81%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
	],
  vars:[
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"SENSOR01",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID99%"},
    {name:"SENSOR02",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"SENSOR03",type:"hidden",value:"%TARGET%:%SUBID89%"},
    {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID91%"},
    {name:"SENSOR04",type:"hidden",value:"%TARGET%:%SUBID85%"},
    {name:"COND04",type:"hidden",value:"%TARGET%:%SUBID87%"},
    {name:"SENSOR05",type:"hidden",value:"%TARGET%:%SUBID81%"},
    {name:"COND05",type:"hidden",value:"%TARGET%:%SUBID83%"},
    {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
    {name:"Address2",type:"number",min:"1",max:"127",required:false,defaultValue:"2",desc:"Адрес Modbus"},
    {name:"Address3",type:"number",min:"1",max:"127",required:false,defaultValue:"3",desc:"Адрес Modbus"},
    {name:"Address4",type:"number",min:"1",max:"127",required:false,defaultValue:"4",desc:"Адрес Modbus"},
    {name:"Address5",type:"number",min:"1",max:"127",required:false,defaultValue:"5",desc:"Адрес Modbus"},
 ]
}
*/


u8 write = 0;
u8 writehold[8] = {0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 count=0;


const u16 ID_CON [] = {
    ADDR2ID(COND01)
    #ifdef COND02, ADDR2ID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2ID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2ID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2ID(COND05) #else ,0 #endif
};
const u8 SID_CON [] = {
    ADDR2SID(COND01)
    #ifdef COND02, ADDR2SID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2SID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2SID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2SID(COND05) #else ,0 #endif
};

const u16 ID_SEN [] = {
    ADDR2ID(SENSOR01)
    #ifdef SENSOR02, ADDR2ID(SENSOR02) #else ,0 #endif
    #ifdef SENSOR03, ADDR2ID(SENSOR03) #else ,0 #endif
    #ifdef SENSOR04, ADDR2ID(SENSOR04) #else ,0 #endif
    #ifdef SENSOR05, ADDR2ID(SENSOR05) #else ,0 #endif
};
const u8 SID_SEN [] = {
    ADDR2SID(COND01)
    #ifdef SENSOR02, ADDR2SID(SENSOR02) #else ,0 #endif
    #ifdef SENSOR03, ADDR2SID(SENSOR03) #else ,0 #endif
    #ifdef SENSOR04, ADDR2SID(SENSOR04) #else ,0 #endif
    #ifdef SENSOR05, ADDR2SID(SENSOR05) #else ,0 #endif
};

const u8 Addr [] = {
    Address1
    #ifdef Address2, Address2 #else ,0#endif
    #ifdef Address3, Address3 #else ,0#endif
    #ifdef Address4, Address4 #else ,0#endif
    #ifdef Address5, Address5 #else ,0#endif
};



void setmode (u8 rezhim){
    if (rezhim==0) {rezhim=2; return rezhim;} //Обдув
    if (rezhim==1) {rezhim=0; return rezhim;} //Охлаждение
    if (rezhim==2) {rezhim=1; return rezhim;} //Обогрев
    if (rezhim==3) {rezhim=3; return rezhim;} //Авто
}

void backmode (u8 rezhim){
    if (rezhim==2) {rezhim=0; return rezhim;} //Обдув
    if (rezhim==0) {rezhim=1; return rezhim;} //Охлаждение
    if (rezhim==1) {rezhim=2; return rezhim;} //Обогрев
    if (rezhim==3) {rezhim=3; return rezhim;} //Авто
}



u16 NeedSend = 0;
u8 writeStage = 0;
u8 curIndex = 0;
u8 pollStage = 0;
u8 pollIndex = 0;

// Маркер чтения-записи
void stopwrite(){
    write=0;
}

// Отправка hold регистров
void slavesend(){
    setStatus(RS485, &writehold);
}

u8 findNextIndex(){
	for(u8 i=0; i<5; ++i){
		if(NeedSend & (1<<i)){
			return i;
		}
	}
	return 0xFF;
}

u8 state[5] = {0, 0, 0, 0, 0};
u8 pollState[5] = {0, 0, 0, 0, 0};
u8 pollStateRoomTemp[2] = {0, 0};

void getStateByIndex(u8 i){
	if (i == 0) getStatus(COND01, state);
	else if (i == 1) getStatus(COND02, state);
	else if (i == 2) getStatus(COND03, state);
	else if (i == 3) getStatus(COND04, state);
	else if (i == 4) getStatus(COND05, state);
}

void prepare_write_onoff(u8 i){
	getStateByIndex(i);
	
	writehold[0] = Addr[i];
	writehold[1] = 0x06;
	writehold[2] = 0x27;
	writehold[3] = 0x35;
	writehold[4] = 0x00;
	if(state[0] & 1)
	    writehold[5] = 0x01;
	else
	    writehold[5] = 0x00;
	
}

void prepare_write_mode(u8 i){
	getStateByIndex(i);
	
	writehold[0] = Addr[i];
	writehold[1] = 0x06;
	writehold[2] = 0x27;
	writehold[3] = 0x2F;
	writehold[4] = 0x00;
	writehold[5] = setmode(state[0]>>4);
	
}

void prepare_write_temp(u8 i){
	getStateByIndex(i);
	u16 newTemp = (state[1] + 16) * 10;
	
	writehold[0] = Addr[i];
	writehold[1] = 0x06;
	writehold[2] = 0x27;
	writehold[3] = 0x3D;
	writehold[4] = newTemp>>8;
	writehold[5] = newTemp;
	
}

void prepare_write_fan(u8 i){
	getStateByIndex(i);
	u8 fan_low = state[4] & 0x0F;
	u8 fan_high = state[4] >> 4;
	
	
	writehold[0] = Addr[i];
	writehold[1] = 0x06;
	writehold[2] = 0x27;
	writehold[3] = 0x34;
	writehold[4] = 0x00;
	writehold[5] = state[4];
	
}

void prepare_read_mode(u8 i){
	readhold[0] = Addr[i];
	readhold[1] = 0x03;
	readhold[2] = 0x27;
	readhold[3] = 0x2F;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void prepare_read_onoff(u8 i){
	readhold[0] = Addr[i];
	readhold[1] = 0x03;
	readhold[2] = 0x27;
	readhold[3] = 0x35;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void prepare_read_settemp(u8 i){
	readhold[0] = Addr[i];
	readhold[1] = 0x03;
	readhold[2] = 0x27;
	readhold[3] = 0x3D;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void prepare_read_fan(u8 i){
	readhold[0] = Addr[i];
	readhold[1] = 0x03;
	readhold[2] = 0x27;
	readhold[3] = 0x34;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void prepare_read_roomtemp(u8 i){
	readhold[0] = Addr[i];
	readhold[1] = 0x03;
	readhold[2] = 0x27;
	readhold[3] = 0x3C;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

//Функция передачи команд в термостат, последовательно отправляются команды по каждому из параметров виртуального кондиционера
void send(){
    cancelDelayedCall(send);
    
    if(!NeedSend){
    	write = 0;
    	writeStage = 0;
    	return;
    }
    
    write = 1;
    
    if (writeStage == 0){
    	curIndex = findNextIndex();
    	//srvError("curIndex %d", curIndex);
    	if (curIndex == 0xFF){
    		write = 0;
    		return;
    	}
    }
    
    //Включение / Выключение
    if (writeStage == 0){
    	prepare_write_onoff(curIndex);
    	setStatus(RS485, writehold);
    	
    	writeStage = 1;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Режим работы
    if (writeStage == 1){
    	prepare_write_mode(curIndex);
    	setStatus(RS485, writehold);
    	
    	writeStage = 2;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Температура
    if (writeStage == 2){
    	prepare_write_temp(curIndex);
    	setStatus(RS485, writehold);
    	
    	writeStage = 3;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Скорость обдува
    if (writeStage == 3){
    	prepare_write_fan(curIndex);
    	setStatus(RS485, writehold);
    	
    	writeStage = 4;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Завершение
    if(writeStage == 4){
    	NeedSend &= ~(1<<curIndex);
    	writeStage = 0;
    	
    	if (NeedSend){
    		delayedCall(send, 1);
    	}
    	else {
    		write = 0;
    	}
    	return;
    }
}

// Функция опроса состояний термостата
void poll(){

    // Если идёт запись — просто пропускаем тик
    if(write == 1){
        return;
    }

    // Режим
    if(pollStage == 0){
        prepare_read_mode(pollIndex);
        setStatus(RS485, readhold);
        pollStage = 1;
        return;
    }

    // Уставка
    if(pollStage == 1){
        prepare_read_settemp(pollIndex);
        setStatus(RS485, readhold);
        pollStage = 2;
        return;
    }

    // Скорость обдува
    if(pollStage == 2){
        prepare_read_fan(pollIndex);
        setStatus(RS485, readhold);
        pollStage = 3;
        return;
    }

    // Вкл/Выкл
    if(pollStage == 3){
        prepare_read_onoff(pollIndex);
        setStatus(RS485, readhold);
        pollStage = 4;
        return;
    }
    
    // Температура в комнате
    if(pollStage == 4){
        prepare_read_roomtemp(pollIndex);
        setStatus(RS485, readhold);
        pollStage = 5;
        return;
    }

    // Переход к следующему термостату
    if(pollStage == 5){
        pollStage = 0;
        if(pollIndex < 5) ++pollIndex;
        else pollIndex = 0;
        return;
    }
}


// Функция передачи состояния термостата в виртуальный кондиционер
void applyPollState(){
    if(pollIndex == 0){
    	setStatus(COND01, &pollState);
    	setStatus(SENSOR01, &pollStateRoomTemp);
    }
    else if(pollIndex == 1){
    	setStatus(COND02, &pollState);
    	setStatus(SENSOR02, &pollStateRoomTemp);
    }
    else if(pollIndex == 2){
    	setStatus(COND03, &pollState);
    	setStatus(SENSOR03, &pollStateRoomTemp);
    }
    else if(pollIndex == 3){
    	setStatus(COND04, &pollState);
    	setStatus(SENSOR04, &pollStateRoomTemp);
    }
    else if(pollIndex == 4){
    	setStatus(COND05, &pollState);
    	setStatus(SENSOR05, &pollStateRoomTemp);
    }
}

V-ID/COND01, COND02, COND03, COND04, COND05{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<5;++i){
          if(SID_CON[i]==senderSubId()){
            write=1;
            NeedSend|=1<<i;
            srvError("NeedSend %d", NeedSend);
            cancelDelayedCall(send);
            delayedCall(send, 1);
          }
        }
    }
}

//Опрашиваем все адреса i-го термостата
V-ID/s:5{
    poll(); // 0 ms
    
    delayedCallMs(poll, 300);
    delayedCallMs(poll, 600);
    delayedCallMs(poll, 900);
    delayedCallMs(poll, 1200);
    delayedCallMs(poll, 1500);
}


V-ID/RS485{
    if(write == 1) return;

    if(opt(1) == 0x03){
        //Формируем массив состояния термоста
        // Режим
        if(pollStage == 1){
            pollState[0] = backmode(opt(4)) << 4;
        }

        // Уставка температуры
        else if(pollStage == 2){
        	u16 settemp = (opt(3) << 8) | opt(4);
            pollState[1] = settemp/10 - 16;
        }

        // Обдув
        else if(pollStage == 3){
            pollState[4] = opt(4);
        }
        
        // Вкл/Выкл
        else if(pollStage == 4){
            pollState[0] |= opt(4) & 1;
        }
        
        // Температура
        else if(pollStage == 5){
        	u16 roomtemp = (opt(3) << 8) | opt(4);
        	pollStateRoomTemp[0] = roomtemp % 10; 
            pollStateRoomTemp[1] = roomtemp / 10;


            // Передаём состояние в виртуальный кондиционер
            applyPollState();

            // Переходим к следующему кондиционеру
            pollStage = 0;
            if(pollIndex < 4) ++pollIndex;
            else pollIndex = 0;
        }
}
}