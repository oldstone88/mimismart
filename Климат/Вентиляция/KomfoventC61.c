/*
{
  desc:"Komfovent C6.1 br 19200 EP stop 1.0",
  name:"Komfovent C6.1",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"5", "t-delta":"40", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x00", "modes":"0x08"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя бассейн",defaultValue:"Бассейн"},
        {name:"VENT",type:"hidden",value:"%TARGET%:%SUBID01%"},
  ]
}
*/

u8 block=0;
u8 write[21]={Address, 0x10, 0x00, 0x6A, 0x00, 0x06, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 numSend=0;

void stotWrite(){
    block=0;
}

void send(){
    if(numSend){
        if(numSend==3){
            u8 onOff[8]={Address, 0x06, 0x00, 0x01, 0x00, 0x01, 0xCC, 0x16};
            setStatus(RS485, &onOff);
        } else if(numSend==2){
            u8 mode[8]={Address, 0x06, 0x00, 0x05, 0x00, 0x02, 0xCC, 0x16};
            setStatus(RS485, &mode);
        } else if(numSend==1){
            // Приток
            u32 speed=60000*(1+[VENT.4]);
            write[7]=speed>>24;
            write[8]=speed>>16;
            write[9]=speed>>8;
            write[10]=speed;
            // Вытяжка
            speed=(speed*8)/10;
            write[11]=speed>>24;
            write[12]=speed>>16;
            write[13]=speed>>8;
            write[14]=speed;
            // Температура
            write[15]=(([VENT.1]+5)*10)>>8;
            write[16]=([VENT.1]+5)*10;
            // Обогрев или вентиляция
            write[18]=[VENT.0]>>4;
            setStatus(RS485, &write);
        }
        numSend-=1;
        if(numSend) delayedCallMs(send, 500);
        else delayedCallMs(stotWrite, 1000);
    }
}

V-ID/VENT{
    if(senderId()!=exciterId()){
        cancelDelayedCall(send);
        block=1;
        if(([VENT.0]%2)==1){
            numSend=3;
            delayedCallMs(send, 500);
        } else if(([VENT.0]%2)==0){
            u8 onOff[]={Address, 0x06, 0x00, 0x01, 0x00, 0x00, 0xCC, 0x16};
            setStatus(RS485, &onOff);
        }
    }
}

u8 count=0;

V-ID/s:5{
    if(!block){
        if(!count){
            // Чтение ВКЛ-ВЫКЛ
            u8 onOff[8]={Address, 0x03, 0x00, 0x01, 0x00, 0x01, 0xCC, 0x16};
            setStatus(RS485, &onOff);
            ++count;
        } else{
            // Чтение уставок
            u8 read[8]={Address, 0x03, 0x00, 0x6A, 0x00, 0x06, 0xCC, 0x16};
            setStatus(RS485, &read);
            --count;
        }
    }
}

// Функция вывода ответа
void stat(){
    u8 res[240]="";
    u8 *st = opt;
    u8 i = 0;
    sprintf(res,"%d ",optl);
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), " %x", st[i]);
    }
    sprintf(res+strlen(res), "\10");
    srvError(&res);
}

V-ID/RS485{
    #ifdef DEBUF stat(); #endif
    if(opt(1)==3 && optl==17){
        u8 state[5]={0, 0, 0, 0, 0};
        getStatus(VENT, state);
        // Температура
        state[1]=(((opt(11)<<8)|opt(12))/10)-5;
        // Нагрев
        state[0]|=opt(14)<<4;
        setStatus(VENT, state);
    } else if(opt(1)==3 && optl==7){
        u8 state[5] = {0, 0, 0, 0, 0};
        state[0]&=0xFE;
        state[0]|=opt(4);
        setStatus(VENT, &state);
    }
}