/*
{
  desc:"Управление бассейном DOZBOX 2 br 57600 stop 1.0",
  name:"DOZBOX",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"0", "t-delta":"2", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x00", "modes":"0x00"},
        {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID99%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    	{tag:"item", id:"%TARGET%", name:"Cl", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", length:"2", dim:" "},
    	{tag:"item", id:"%TARGET%", name:"pH", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", length:"2", dim:" "},
    	{tag:"item", id:"%TARGET%", name:"Фильтрация", "sub-id":"%SUBID91%", type:"virtual", "sub-type":"sensor", length:"2", dim:" "},
    	{tag:"item", id:"%TARGET%", name:"Нагрев", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", length:"2", dim:" "},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Имя бассейн",defaultValue:"Бассейн"},
        {name:"Cond01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"TEMP",type:"hidden",value:"%TARGET%:%SUBID99%"},
        {name:"CHLORINE",type:"hidden",value:"%TARGET%:%SUBID97%"},
        {name:"ACID",type:"hidden",value:"%TARGET%:%SUBID95%"},
        {name:"FILTER",type:"hidden",value:"%TARGET%:%SUBID91%"},
        {name:"HEAT",type:"hidden",value:"%TARGET%:%SUBID89%"},
  ]
}
*/

u8 block=0;

void stopBlock(){
	block=0;
}

u8 write[8] = {0x1E, 0x06, 0x20, 0x20, 0x00, 0x00, 0xCC, 0x16};

void send(){
	setStatus(RS485, &write);
}

// Задача температуры бассейна
V-ID/Cond01{
	if(senderId()!=exciterId()){
		cancelDelayedCall(stopBlock);
		if((opt(0)%2) != 0) write[5] = opt(1);
		delayedCall(send, 1);
		delayedCall(stopBlock, 3);
	}
}

u8 count = 0;
u8 read[8]={0x1E, 0x03, 0x20, 0x00, 0x00, 0x01, 0xCC, 0x16};

// Чтение данных
V-ID/s:5{
	//srvError("Отправка");
    if(count == 0){
    	read[3] = 0x1B;
    	read[5] = 0x06;
    }
    else if(count == 1){
    	read[3] = 0x07;
    	read[5] = 0x01;
    }
    count = count == 1 ? 0 : 1;
    setStatus(RS485, &read);
}

// Вывод в лог
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

u16 temp = 0;
u8 buff[5] = {0, 0, 0 ,0 ,0};

V-ID/RS485{
	if(optl == 17 && opt(1) == 3){
		temp = 0;
		temp = (opt(3)<<8)|opt(4);
		setStatus(TEMP, {((temp%10)*25) ,(temp/10)});
		// Хлор
		temp = 0;
		temp = (opt(9)<<8)|opt(10);
		setStatus(CHLORINE, {0, temp});
		// pH
		temp = 0;
		temp = (opt(11)<<8)|opt(12);
		setStatus(ACID, {0, temp});
		buff[1] = opt(14);
		setStatus(Cond01, &buff);
	}
	if(optl == 7 && opt(1) == 3){
		temp = 0;
		temp = (opt(3)<<8)|opt(4);
		// Фильтрация
		setStatus(FILTER, {0, ((temp>>5)%2)});
		// Нагрев
		setStatus(HEAT, {0, ((temp>>6)%2)});
	}
    // stat();
}
