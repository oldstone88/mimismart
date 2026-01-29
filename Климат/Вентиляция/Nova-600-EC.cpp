/*
{
  desc:"Nova-600-EC",
  tag:"import-script",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    ],
  vars:
  [
    {name:"VENT00",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write = 0; // Маркер чтения-записи
u8 writehold[8] = {0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readdiscrete[8] = {0x01, 0x02, 0x00, 0x1F, 0x00, 0x01, 0xCC, 0x16};
u8 onoff = 0; // маркер состояния установки
u8 curOnoff = 0; //буфер маркера состояния установки
u8 writeStage = 0; // Этап записи
u8 pollStage = 0; // Этап опроса
u8 state[5] = {0, 0, 0, 0, 0};
u8 pollState[5] = {0, 0, 0, 0, 0};



void prepare_write_onoff(){
	getStatus(VENT00, state);
	
	writehold[0] = 0x01;
	writehold[1] = 0x06;
	writehold[2] = 0x00;
	writehold[3] = 0x00;
	writehold[4] = 0x00;
	if(state[0] & 1){
	    writehold[5] = 0x01;
	    onoff = 1;
	}
	else{
	    writehold[5] = 0x00;
	    onoff = 0;
	}
}

void prepare_write_temp(){
	getStatus(VENT00, state);
	u16 newTemp = state[1] + 16;
	
	writehold[0] = 0x01;
	writehold[1] = 0x06;
	writehold[2] = 0x00;
	writehold[3] = 0x01;
	writehold[4] = newTemp>>8;
	writehold[5] = newTemp;
}

void prepare_write_fan(){
	getStatus(VENT00, state);
	
	writehold[0] = 0x01;
	writehold[1] = 0x06;
	writehold[2] = 0x00;
	writehold[3] = 0x00;
	writehold[4] = 0x00;
	writehold[5] = state[4] + 1;
}


void prepare_read_temp(){
	readhold[0] = 0x01;
	readhold[1] = 0x03;
	readhold[2] = 0x00;
	readhold[3] = 0x01;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void prepare_read_fan(){
	readhold[0] = 0x01;
	readhold[1] = 0x03;
	readhold[2] = 0x00;
	readhold[3] = 0x00;
	readhold[4] = 0x00;
	readhold[5] = 0x01;
}

void send(){
    cancelDelayedCall(send);
    write = 1;
    
    
    //Включение / Выключение
    if (writeStage == 0){
    	prepare_write_onoff();
    	if (curOnoff != onoff){
    	    setStatus(RS485, writehold);
    	    curOnoff = onoff;
    	}
    	
    	writeStage = 1;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Температура
    if (writeStage == 1 && onoff == 1){
    	prepare_write_temp();
    	setStatus(RS485, writehold);
    	
    	writeStage = 2;
    	delayedCallMs(send, 200);
    	return;
    }
    else if (writeStage == 1 && onoff == 0)
    {
    	writeStage = 0;
    }
    
    //Скорость обдува
    if (writeStage == 2 && onoff == 1){
    	prepare_write_fan();
    	setStatus(RS485, writehold);
    	
    	writeStage = 3;
    	delayedCallMs(send, 200);
    	return;
    }
    
    //Завершение
    if(writeStage == 3){
    	writeStage = 0;
    	write = 0;
    	return;
    }
}


V-ID/VENT00{
    if(senderId()!=exciterId()){
    	write=1;
        cancelDelayedCall(send);
        delayedCall(send, 1);
    }
}


// Функция опроса состояний термостата
void poll(){
	
	// Если идёт запись — просто пропускаем тик
    if(write == 1){
        return;
    }
    
    // Если установка выключена не опрашиваем её, если у установки есть другие каналы управления, то убрать
    if(onoff == 0){
    	return;
    }
    
    if(pollStage == 0){
    	prepare_read_fan();
    	setStatus(RS485, readhold);
    	pollStage = 1;
    	return;
    }
    
    if(pollStage == 1){
    	prepare_read_temp();
    	setStatus(RS485, readhold);
    	pollStage = 2;
    	return;
    }
    
    if(pollStage == 2){
    	setStatus(RS485, readdiscrete);
    	pollStage = 0;
        return;
    }
}


// Функция аварийного отключения виртуального кондея
void alarm(){
	getStatus(VENT00, state);
    state[0] = 0x00;
    setStatus(VENT00, state);
    onoff = 0;
    srvError("Авария вентустановки");
    setStatus(2047:32, {7, "Авария вентустановки"});
}


// Функция передачи состояния установки в виртуальный кондиционер
void applyPollState(){
	setStatus(VENT00, &pollState);
}


V-ID/s:4{
	poll();
	delayedCall(poll, 1);
	delayedCall(poll, 2);
}


V-ID/RS485{
    if(write == 1) return;
    
    if (opt(1) == 0x02 && optl < 7 && opt(3) == 0x01){
    	alarm(); //отключаем виртуальный кондей, если пришла ошибка аварии установки
    }
    
    if(opt(1) == 0x03){
        //Формируем массив состояния установки
        
        // Скорость обдува и вкл/выкл
        if (pollStage == 1) {
        u8 fan = opt(4);

        if (fan != 0) {
            pollState[4] = fan - 1;
            pollState[0] = 0x01;
            onoff = 1;
        } else {
            pollState[4] = 0;
            pollState[0] = 0x00;
            onoff = 0;
            applyPollState();
        }
    }	

        // Уставка температуры
        else if(pollStage == 2){
        	u16 settemp = (opt(3) << 8) | opt(4);
            pollState[1] = settemp - 16;
            
            applyPollState();
            
        }
    }
}
