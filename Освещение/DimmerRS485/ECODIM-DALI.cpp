/*
{
  desc:"Диммер ECODIM br 19200 virtual:32-DDDDDDDD  virtual:40-DDDDDDDD  virtual:48-DDD",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"Address",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {name:"DIMMER09",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"DIMMER10",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"DIMMER11",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"DIMMER12",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
    {name:"DIMMER13",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 13",width:500},
    {name:"DIMMER14",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 14",width:500},
    {name:"DIMMER15",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 15",width:500},
    {name:"DIMMER16",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 16",width:500},
  ]
}
*/

u16 NeedSend = 0;

const u8 SID[]={
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

void sendtors(){
    cancelDelayedCall(sendtors);
    u8 breakpoint = 0;
    if(NeedSend){
        for(u8 i=0; (i<16) && (breakpoint==0); ++i){
            if((NeedSend>>i)&1){
                u8 data[8] = {Address, 0x06, 2000+i*5>>8, 2000+i*5, 0x00, 0x00, 0xCC, 0x16};
                breakpoint=1;
                if(!i) data[5] = ([DIMMER01.0]&1)?[DIMMER01.1]:0;
                else if(i==1) data[5] = ([DIMMER02.0]&1)?[DIMMER02.1]:0;
                else if(i==2) data[5] = ([DIMMER03.0]&1)?[DIMMER03.1]:0;
                else if(i==3) data[5] = ([DIMMER04.0]&1)?[DIMMER04.1]:0;
                else if(i==4) data[5] = ([DIMMER05.0]&1)?[DIMMER05.1]:0;
                else if(i==5) data[5] = ([DIMMER06.0]&1)?[DIMMER06.1]:0;
                else if(i==6) data[5] = ([DIMMER07.0]&1)?[DIMMER07.1]:0;
                else if(i==7) data[5] = ([DIMMER08.0]&1)?[DIMMER08.1]:0;
                else if(i==8) data[5] = ([DIMMER09.0]&1)?[DIMMER09.1]:0;
                else if(i==9) data[5] = ([DIMMER10.0]&1)?[DIMMER10.1]:0;
                else if(i==10) data[5] = ([DIMMER11.0]&1)?[DIMMER11.1]:0;
                else if(i==11) data[5] = ([DIMMER12.0]&1)?[DIMMER12.1]:0;
                else if(i==12) data[5] = ([DIMMER13.0]&1)?[DIMMER13.1]:0;
                else if(i==13) data[5] = ([DIMMER14.0]&1)?[DIMMER14.1]:0;
                else if(i==14) data[5] = ([DIMMER15.0]&1)?[DIMMER15.1]:0;
                else if(i==15) data[5] = ([DIMMER16.0]&1)?[DIMMER16.1]:0;
                // srvError("Адрес отправки = %x, %x. Яркость = %d", data[2], data[3], data[5]);
                setStatus(RS485, &data);
                NeedSend -= 1<<i;
                if(NeedSend) delayedCallMs(sendtors, 100);
            }
        }
    }
}

V-ID/DIMMER01, DIMMER02, DIMMER03, DIMMER04, DIMMER05, DIMMER06, DIMMER07, DIMMER08, DIMMER09, DIMMER10, DIMMER11, DIMMER12, DIMMER13, DIMMER14, DIMMER15, DIMMER16
{
    for(u8 i=0; i<16; ++i){
        if(SID[i] && (SID[i]==senderSubId())){
            cancelDelayedCall(sendtors);
            NeedSend |= 1<<i;
            delayedCallMs(sendtors, 100);
        }
    }
}

//Вывода в лог
void stat()
{
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

V-ID/RS485
{
    //stat();
}