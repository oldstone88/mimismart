/*
{
  desc:"Gree U-Match Inverter",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 1"},
        {name:"Cond01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
  ]
}
*/

u8 write = 0;
u8 writehold[8]={Address1, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8]={Address1, 0x03, 0x00, 0x02, 0x00, 0x13, 0xCC, 0x16};
u8 numSend=0;

//------------------------------------------

void backmode (u8 rezhim){
    if (rezhim==4) {rezhim=0; return rezhim;} //Обдув
    if (rezhim==1) {rezhim=1; return rezhim;} //Охлаждение
    if (rezhim==3) {rezhim=2; return rezhim;} //Сушка
    if (rezhim==2) {rezhim=3; return rezhim;} //Обогрев
    if (rezhim==5) {rezhim=4; return rezhim;} //Авто
}

void stopWrite(){
    write=0;
}

void send(){
    cancelDelayedCall(send);
    u8 breakpoint=0;
    if(NeedSend){
        if(numSend==0) numSend=4;
        // Вкл-Выкл
        else if(numSend==4){
            writehold[3]=0x02;
            if(([Cond01.0]&1)==1){writehold[5]=0xAA;}
            else writehold[5]=0x55;
        }
        // Режим
        else if(numSend==3){
            writehold[3]=0x11;
            if(([Cond01.0]>>4)==0){writehold[5]=0x64;} // Вентиляция
            else if(([Cond01.0]>>4)==1){writehold[5]=0x01;} // Холод
            else if(([Cond01.0]>>4)==2){writehold[5]=0x0B;} // Осушение
            else if(([Cond01.0]>>4)==3){writehold[5]=0x0A;} // Нагрев
            else if(([Cond01.0]>>4)==4){writehold[5]=0x65;} // Авто
        }
        // Скорость
        else if(numSend==2){
            writehold[3]=0x13;
            writehold[5]=[Cond01.4];
        }
        // Температура
        else if(numSend==1){
            writehold[3]=0x14;
            writehold[5]=[Cond01.1]+16;
        }
        setStatus(RS485, &writehold);
        --numSend;
        if(!numSend) {NeedSend=0; delayedCall(stopWrite, 5);} else delayedCallMs(send, 250);
    }
}

V-ID/Cond01{
    if(senderId()!=exciterId()){
        cancelDelayedCall(stopWrite);
        cancelDelayedCall(send);
        delayedCall(send, 1);
        NeedSend=1;
        numSend=4;
        write=1;
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
        setStatus(RS485, &readhold)
    }
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl==11 && opt(1)==0x03){
    }
}