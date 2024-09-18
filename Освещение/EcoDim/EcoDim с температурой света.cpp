/*
{
  desc:"Диммер ECODIM br 19200 virtual:32-DDDDDDDD  virtual:40-DDDDDDDD  virtual:48-DDD",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"Address",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"TEMPERATURE01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"TEMPERATURE02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"TEMPERATURE03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"TEMPERATURE04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 4",width:500},
    {name:"DIMMER05",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"TEMPERATURE05",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"TEMPERATURE06",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"TEMPERATURE07",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {name:"TEMPERATURE08",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 8",width:500},
    {name:"DIMMER09",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"TEMPERATURE09",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 9",width:500},
    {name:"DIMMER10",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"TEMPERATURE10",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 10",width:500},
    {name:"DIMMER11",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"TEMPERATURE11",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 11",width:500},
    {name:"DIMMER12",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
    {name:"TEMPERATURE12",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 12",width:500},
    {name:"DIMMER13",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 13",width:500},
    {name:"TEMPERATURE13",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 13",width:500},
    {name:"DIMMER14",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 14",width:500},
    {name:"TEMPERATURE14",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 14",width:500},
    {name:"DIMMER15",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 15",width:500},
    {name:"TEMPERATURE15",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 15",width:500},
    {name:"DIMMER16",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 16",width:500},
    {name:"TEMPERATURE16",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Цвет 16",width:500},
  ]
}
*/

u16 NeedSendD = 0;
u16 NumSend = 0;

const u8 SIDD[]={
    ADDR2SID(DIMMER01)
    #ifdef DIMMER02, ADDR2SID(DIMMER02) #else ,0 #endif
    #ifdef DIMMER03, ADDR2SID(DIMMER03) #else ,0 #endif
    #ifdef DIMMER04, ADDR2SID(DIMMER04) #else ,0 #endif
    #ifdef DIMMER05, ADDR2SID(DIMMER05) #else ,0 #endif
    #ifdef DIMMER06, ADDR2SID(DIMMER06) #else ,0 #endif
    #ifdef DIMMER07, ADDR2SID(DIMMER07) #else ,0 #endif
    #ifdef DIMMER08, ADDR2SID(DIMMER08) #else ,0 #endif
    #ifdef DIMMER09, ADDR2SID(DIMMER09) #else ,0 #endif
    #ifdef DIMMER10, ADDR2SID(DIMMER10) #else ,0 #endif
    #ifdef DIMMER11, ADDR2SID(DIMMER11) #else ,0 #endif
    #ifdef DIMMER12, ADDR2SID(DIMMER12) #else ,0 #endif
    #ifdef DIMMER13, ADDR2SID(DIMMER13) #else ,0 #endif
    #ifdef DIMMER14, ADDR2SID(DIMMER14) #else ,0 #endif
    #ifdef DIMMER15, ADDR2SID(DIMMER15) #else ,0 #endif
    #ifdef DIMMER16, ADDR2SID(DIMMER16) #else ,0 #endif
};

const u8 SIDT[]={
    ADDR2SID(TEMPERATURE01)
    #ifdef TEMPERATURE02, ADDR2SID(TEMPERATURE02) #else ,0 #endif
    #ifdef TEMPERATURE03, ADDR2SID(TEMPERATURE03) #else ,0 #endif
    #ifdef TEMPERATURE04, ADDR2SID(TEMPERATURE04) #else ,0 #endif
    #ifdef TEMPERATURE05, ADDR2SID(TEMPERATURE05) #else ,0 #endif
    #ifdef TEMPERATURE06, ADDR2SID(TEMPERATURE06) #else ,0 #endif
    #ifdef TEMPERATURE07, ADDR2SID(TEMPERATURE07) #else ,0 #endif
    #ifdef TEMPERATURE08, ADDR2SID(TEMPERATURE08) #else ,0 #endif
    #ifdef TEMPERATURE09, ADDR2SID(TEMPERATURE09) #else ,0 #endif
    #ifdef TEMPERATURE10, ADDR2SID(TEMPERATURE10) #else ,0 #endif
    #ifdef TEMPERATURE11, ADDR2SID(TEMPERATURE11) #else ,0 #endif
    #ifdef TEMPERATURE12, ADDR2SID(TEMPERATURE12) #else ,0 #endif
    #ifdef TEMPERATURE13, ADDR2SID(TEMPERATURE13) #else ,0 #endif
    #ifdef TEMPERATURE14, ADDR2SID(TEMPERATURE14) #else ,0 #endif
    #ifdef TEMPERATURE15, ADDR2SID(TEMPERATURE15) #else ,0 #endif
    #ifdef TEMPERATURE16, ADDR2SID(TEMPERATURE16) #else ,0 #endif
};

void sendtors(){
    cancelDelayedCall(sendtors);
    u8 breakpoint = 0;
    if(NeedSendD){
        for(u8 i=0; (i<16) && (breakpoint==0); ++i){
            if((NeedSendD>>i)&1){
                if(NumSend==0) NumSend=2;
                else if(NumSend==2){
                    u8 data[8] = {Address, 0x06, 2000+i*5>>8, 2000+i*5, 0x00, 0x00, 0xCC, 0x16};
                    breakpoint=1;
                    if(!i) data[5] = ([DIMMER01.0]&1)?[DIMMER01.1]:0;
                    #ifdef DIMMER02 else if(i==1) data[5] = ([DIMMER02.0]&1)?[DIMMER02.1]:0; #endif
                    #ifdef DIMMER03 else if(i==2) data[5] = ([DIMMER03.0]&1)?[DIMMER03.1]:0; #endif
                    #ifdef DIMMER04 else if(i==3) data[5] = ([DIMMER04.0]&1)?[DIMMER04.1]:0; #endif
                    #ifdef DIMMER05 else if(i==4) data[5] = ([DIMMER05.0]&1)?[DIMMER05.1]:0; #endif
                    #ifdef DIMMER06 else if(i==5) data[5] = ([DIMMER06.0]&1)?[DIMMER06.1]:0; #endif
                    #ifdef DIMMER07 else if(i==6) data[5] = ([DIMMER07.0]&1)?[DIMMER07.1]:0; #endif
                    #ifdef DIMMER08 else if(i==7) data[5] = ([DIMMER08.0]&1)?[DIMMER08.1]:0; #endif
                    #ifdef DIMMER09 else if(i==8) data[5] = ([DIMMER09.0]&1)?[DIMMER09.1]:0; #endif
                    #ifdef DIMMER10 else if(i==9) data[5] = ([DIMMER10.0]&1)?[DIMMER10.1]:0; #endif
                    #ifdef DIMMER11 else if(i==10) data[5] = ([DIMMER11.0]&1)?[DIMMER11.1]:0; #endif
                    #ifdef DIMMER12 else if(i==11) data[5] = ([DIMMER12.0]&1)?[DIMMER12.1]:0; #endif
                    #ifdef DIMMER13 else if(i==12) data[5] = ([DIMMER13.0]&1)?[DIMMER13.1]:0; #endif
                    #ifdef DIMMER14 else if(i==13) data[5] = ([DIMMER14.0]&1)?[DIMMER14.1]:0; #endif
                    #ifdef DIMMER15 else if(i==14) data[5] = ([DIMMER15.0]&1)?[DIMMER15.1]:0; #endif
                    #ifdef DIMMER16 else if(i==15) data[5] = ([DIMMER16.0]&1)?[DIMMER16.1]:0; #endif
                    // srvError("Адрес отправки = %x, %x. Яркость = %d", data[2], data[3], data[5]);
                    setStatus(RS485, &data);
                    --NumSend;
                } else if(NumSend==1){
                    u8 data[8] = {Address, 0x06, 2620+i*5>>8, 2620+i*5, 0x00, 0x00, 0xCC, 0x16};
                    breakpoint=1;
                    if(!i) {data[4] = 36*[TEMPERATURE01.1]>>8; data[5] = 36*[TEMPERATURE01.1];}
                    #ifdef TEMPERATURE02 else if(i==1) {data[4] = 36*[TEMPERATURE02.1]>>8; data[5] = 36*[TEMPERATURE02.1];} #endif
                    #ifdef TEMPERATURE03 else if(i==2) {data[4] = 36*[TEMPERATURE03.1]>>8; data[5] = 36*[TEMPERATURE03.1];} #endif
                    #ifdef TEMPERATURE04 else if(i==3) {data[4] = 36*[TEMPERATURE04.1]>>8; data[5] = 36*[TEMPERATURE04.1];} #endif
                    #ifdef TEMPERATURE05 else if(i==4) {data[4] = 36*[TEMPERATURE05.1]>>8; data[5] = 36*[TEMPERATURE05.1];} #endif
                    #ifdef TEMPERATURE06 else if(i==5) {data[4] = 36*[TEMPERATURE06.1]>>8; data[5] = 36*[TEMPERATURE06.1];} #endif
                    #ifdef TEMPERATURE07 else if(i==6) {data[4] = 36*[TEMPERATURE07.1]>>8; data[5] = 36*[TEMPERATURE07.1];} #endif
                    #ifdef TEMPERATURE08 else if(i==7) {data[4] = 36*[TEMPERATURE08.1]>>8; data[5] = 36*[TEMPERATURE08.1];} #endif
                    #ifdef TEMPERATURE09 else if(i==8) {data[4] = 36*[TEMPERATURE09.1]>>8; data[5] = 36*[TEMPERATURE09.1];} #endif
                    #ifdef TEMPERATURE10 else if(i==9) {data[4] = 36*[TEMPERATURE10.1]>>8; data[5] = 36*[TEMPERATURE10.1];} #endif
                    #ifdef TEMPERATURE11 else if(i==10) {data[4] = 36*[TEMPERATURE11.1]>>8; data[5] = 36*[TEMPERATURE11.1];} #endif
                    #ifdef TEMPERATURE12 else if(i==11) {data[4] = 36*[TEMPERATURE12.1]>>8; data[5] = 36*[TEMPERATURE12.1];} #endif
                    #ifdef TEMPERATURE13 else if(i==12) {data[4] = 36*[TEMPERATURE13.1]>>8; data[5] = 36*[TEMPERATURE13.1];} #endif
                    #ifdef TEMPERATURE14 else if(i==13) {data[4] = 36*[TEMPERATURE14.1]>>8; data[5] = 36*[TEMPERATURE14.1];} #endif
                    #ifdef TEMPERATURE15 else if(i==14) {data[4] = 36*[TEMPERATURE15.1]>>8; data[5] = 36*[TEMPERATURE15.1];} #endif
                    #ifdef TEMPERATURE16 else if(i==15) {data[4] = 36*[TEMPERATURE16.1]>>8; data[5] = 36*[TEMPERATURE16.1];} #endif
                    // srvError("Адрес отправки = %x, %x. Яркость = %d", data[2], data[3], data[5]);
                    setStatus(RS485, &data);
                    --NumSend;
                }
                if(!NumSend) NeedSendD -= 1<<i;
                if(NeedSendD) delayedCallMs(sendtors, 100);
            }
        }
    }
}

V-ID/DIMMER01#ifdef DIMMER02, DIMMER02#endif#ifdef DIMMER03, DIMMER03#endif#ifdef DIMMER04, DIMMER04#endif#ifdef DIMMER05, DIMMER05#endif#ifdef DIMMER06, DIMMER06#endif#ifdef DIMMER07, DIMMER07#endif#ifdef DIMMER08, DIMMER08#endif#ifdef DIMMER09, DIMMER09#endif#ifdef DIMMER10, DIMMER10#endif#ifdef DIMMER11, DIMMER11#endif#ifdef DIMMER12, DIMMER12#endif#ifdef DIMMER13, DIMMER13#endif#ifdef DIMMER14, DIMMER14#endif#ifdef DIMMER15, DIMMER15#endif#ifdef DIMMER16, DIMMER16#endif
{
    for(u8 i=0; i<16; ++i){
        if(SID[i] && (SIDD[i]==senderSubId())){
            cancelDelayedCall(sendtors);
            NeedSendD |= 1<<i;
            delayedCallMs(sendtors, 100);
        }
    }
}

V-ID/TEMPERATURE01#ifdef TEMPERATURE02, TEMPERATURE02#endif#ifdef TEMPERATURE03, TEMPERATURE03#endif#ifdef TEMPERATURE04, TEMPERATURE04#endif#ifdef TEMPERATURE05, TEMPERATURE05#endif#ifdef TEMPERATURE06, TEMPERATURE06#endif#ifdef TEMPERATURE07, TEMPERATURE07#endif#ifdef TEMPERATURE08, TEMPERATURE08#endif#ifdef TEMPERATURE09, TEMPERATURE09#endif#ifdef TEMPERATURE10, TEMPERATURE10#endif#ifdef TEMPERATURE11, TEMPERATURE11#endif#ifdef TEMPERATURE12, TEMPERATURE12#endif#ifdef TEMPERATURE13, TEMPERATURE13#endif#ifdef TEMPERATURE14, TEMPERATURE14#endif#ifdef TEMPERATURE15, TEMPERATURE15#endif#ifdef TEMPERATURE16, TEMPERATURE16#endif
{
    for(u8 i=0; i<16; ++i){
        if(SID[i] && (SIDT[i]==senderSubId())){
            cancelDelayedCall(sendtors);
            NeedSendT |= 1<<i;
            delayedCallMs(sendtors, 100);
        }
    }
}

//Вывода в лог
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

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
}