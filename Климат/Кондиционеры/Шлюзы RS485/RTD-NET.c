/*
{
  desc:"Скрипт управления платой RTD-NET Daikin по RS485 (добавляет 5 кондиционеров, ненужные потом удалить вручную) (настройки RS485: 9600, stop 1, no parity)",
  tag:"import-script",
  target:"RS485",
  selectArea:"true",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер1", sub-id:"%SUBID01%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x00",vane-ver:"0", modes:"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер2", sub-id:"%SUBID02%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x00",vane-ver:"0", modes:"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер3", sub-id:"%SUBID03%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x00",vane-ver:"0", modes:"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер4", sub-id:"%SUBID04%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x00",vane-ver:"0", modes:"0x1F"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер5", sub-id:"%SUBID05%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x00",vane-ver:"0", modes:"0x1F"},
  ],
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:63,desc:"ID1 пульта (для протокола Modbus)",descWidth:350},
    {name:"ID2",type:"number",required:false,min:1,max:63,desc:"ID2 пульта (для протокола Modbus)",descWidth:350},
    {name:"ID3",type:"number",required:false,min:1,max:63,desc:"ID3 пульта (для протокола Modbus)",descWidth:350},
    {name:"ID4",type:"number",required:false,min:1,max:63,desc:"ID4 пульта (для протокола Modbus)",descWidth:350},
    {name:"ID5",type:"number",required:false,min:1,max:63,desc:"ID5 пульта (для протокола Modbus)",descWidth:350},
    {name:"COND1",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"COND2",type:"hidden",value:"%TARGET%:%SUBID02%"},
    {name:"COND3",type:"hidden",value:"%TARGET%:%SUBID03%"},
    {name:"COND4",type:"hidden",value:"%TARGET%:%SUBID04%"},
    {name:"COND5",type:"hidden",value:"%TARGET%:%SUBID05%"},
  ]
}
*/

u8 writeHolding[19]={0x00, 0x10, 0x00, 0x01, 0x00, 0x05, 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xCC, 0x16};
u8 NeedSend=0;
u8 write=0;
u8 count=0;
u8 answer=0;

const u16 ID [] = {
    ADDR2ID(COND1)
    #ifdef COND2, ADDR2ID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2ID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2ID(COND4) #else ,0 #endif
    #ifdef COND5, ADDR2ID(COND5) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND1)
    #ifdef COND2, ADDR2SID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2SID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2SID(COND4) #else ,0 #endif
    #ifdef COND4, ADDR2SID(COND5) #else ,0 #endif
};

const u8 Addr [] = {
    ID1
    #ifdef ID2, ID2 #else ,0#endif
    #ifdef ID3, ID3 #else ,0#endif
    #ifdef ID4, ID4 #else ,0#endif
    #ifdef ID5, ID5 #else ,0#endif
};

void stopwrite(){
    write=0;
}

void send(){
    cancelDelayedCall(send);
    u8 breakpoint=0;
    if(NeedSend){
        for(u8 i=0; (i<5) && (breakpoint==0); ++i){
            if( (NeedSend>>i)&1 ){
                breakpoint=1;
                u8 state[5];
                if(!i) {getStatus(COND1, state);}
                else if(i==1) {getStatus(COND2, state);}
                else if(i==2) {getStatus(COND3, state);}
                else if(i==3) {getStatus(COND4, state);}
                else if(i==4) {getStatus(COND5, state);}
                writeHolding[0]=Addr[i]; // Установка адрес
                writeHolding[8]=state[1]+16; // Температура
                writeHolding[10]=state[4]+1; // Скорость
                // Режим
                if((state[0]>>4)==0) writeHolding[12]=0x02;
                else if((state[0]>>4)==1) writeHolding[12]=0x03;
                else if((state[0]>>4)==2) writeHolding[12]=0x04;
                else if((state[0]>>4)==3) writeHolding[12]=0x01;
                else if((state[0]>>4)==4) writeHolding[12]=0x00;
                writeHolding[16]=state[0]%2; // ВКЛ-ВЫКЛ
                setStatus(RS485, &writeHolding);
                NeedSend -= 1<<i;
                if(NeedSend) delayedCall(send, 1);
                else {cancelDelayedCall(stopwrite); delayedCall(stopwrite, 5);}
            }
        }
    }
}

V-ID/COND1#ifdef COND2, COND2#endif#ifdef COND3, COND3#endif#ifdef COND4, COND4#endif#ifdef COND5, COND5#endif{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<5;++i){
          if(SID[i]==senderSubId()){
            write=1;
            NeedSend|=1<<i;
            cancelDelayedCall(send);
            delayedCall(send, 1);
          }
        }
    }
}

V-ID/s:3{
    if(!write){
        ++count;
        if(count>4) count=0;
        u8 readHolding[8]={Addr[count], 0x03, 0x00, 0x01, 0x00, 0x05, 0xCC, 0x16};
        setStatus(RS485, &readHolding);
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

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl==15 && opt(1)==0x03){
        u8 state[5]={0, 0, 0, 0, 0};
        // ВКЛ-ВЫКЛ
        state[0]=opt(12);
        // Режим
        u8 mode=0;
        if(opt(8)==0) mode=4;
        else if(opt(8)==1) mode=3;
        else if(opt(8)==2) mode=0;
        else if(opt(8)==3) mode=1;
        else if(opt(8)==4) mode=2;
        state[0]=(state[0]|(mode<<4));
        // Температура
        if(opt(4)>16) state[1]=opt(4)-16;
        // Скорость
        state[4]=opt(6)?opt(6)-1:0;
        setStatus(@ID[count]:@SID[count], &state);
    }
}