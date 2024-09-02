/*
{
  desc:"Термостат MC6",
  name:"Термостат MC6",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"Термостат 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 2", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 3", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 4", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 5", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 6", "sub-id":"%SUBID06%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"Термостат 7", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"5", "t-delta":"30", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address1",type:"number",min:"1",max:"250",required:true,defaultValue:"1",desc:"Адрес Modbus 1"},
        {name:"Address2",type:"number",min:"1",max:"250",required:true,defaultValue:"2",desc:"Адрес Modbus 2"},
        {name:"Address3",type:"number",min:"1",max:"250",required:true,defaultValue:"3",desc:"Адрес Modbus 3"},
        {name:"Address4",type:"number",min:"1",max:"250",required:true,defaultValue:"4",desc:"Адрес Modbus 4"},
        {name:"Address5",type:"number",min:"1",max:"250",required:true,defaultValue:"5",desc:"Адрес Modbus 5"},
        {name:"Address6",type:"number",min:"1",max:"250",required:true,defaultValue:"6",desc:"Адрес Modbus 6"},
        {name:"Address7",type:"number",min:"1",max:"250",required:true,defaultValue:"7",desc:"Адрес Modbus 7"},
        {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID02%"},
        {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"COND04",type:"hidden",value:"%TARGET%:%SUBID04%"},
        {name:"COND05",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"COND06",type:"hidden",value:"%TARGET%:%SUBID06%"},
        {name:"COND07",type:"hidden",value:"%TARGET%:%SUBID07%"},
  ]
}
*/

u8 block=0;
u8 write[17]={0x00, 0x10, 0x00, 61, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 needSend=0;

u8 MODBUS[]={Address1, Address2, Address3, Address4, Address5, Address6, Address7};
u16 ID[]={ADDR2ID(COND01), ADDR2ID(COND02), ADDR2ID(COND03), ADDR2ID(COND04), ADDR2ID(COND05), ADDR2ID(COND06), ADDR2ID(COND07)};
u8 SID[]={ADDR2SID(COND01), ADDR2SID(COND02), ADDR2SID(COND03), ADDR2SID(COND04), ADDR2SID(COND05), ADDR2SID(COND06), ADDR2SID(COND07)};

void antiblock(){
    block=0;
}

void modeToCond(u8 mode){
    mode=mode>>4;
    if(mode==0) return 2;
    if(mode==1) return 1;
    if(mode==2) return 3;
    if(mode==3) return 0;
    if(mode==4) return 4;
    return 4;
}

void speedToCond(u8 speed){
    if(speed==0) return 3;
    if(speed==1) return 2;
    if(speed==2) return 1;
    if(speed==3) return 0;
    return 3;
}

void send(){
    u8 stop=0;
    for(u8 i=0; i<7 && !stop; ++i){
        if((needSend<<i)&1){
            stop=1;
            u8 condState[5]={0, 0, 0, 0, 0};
            if(i==0) getStatus(COND01, condState);
            else if(i==1) getStatus(COND02, condState);
            else if(i==2) getStatus(COND03, condState);
            else if(i==3) getStatus(COND04, condState);
            else if(i==4) getStatus(COND05, condState);
            else if(i==5) getStatus(COND06, condState);
            else if(i==6) getStatus(COND07, condState);
            write[8]=condState[0]%2;
            write[10]=modeToCond(condState[0]);
            write[12]=speedToCond(condState[4]);
            u16 temp=(condState[1]+5)*10;
            write[13]=temp>>8;
            write[14]=temp;
            write[0]=MODBUS[i];
            setStatus(RS485, &write);
            needSend=needSend-(1<<i);
            if(needSend) delayedCall(send, 1);
            else delayedCall(antiblock, 3);
        }
    }
}

V-ID/COND01, COND02, COND03, COND04, COND05, COND06, COND07{
    if(senderId()!=exciterId()){
        cancelDelayedCall(send);
        block=1;
        for(u8 i=0; i<7; ++i){
            if(SID[i]==senderSubId()){
                needSend|=1<<i;
            }
        }
        delayedCall(send, 1);
    }
}

u8 numRead=0;

V-ID/s:1{
    if(!block){
        u8 read[8]={0x00, 0x03, 0x00, 61, 0x00, 0x04, 0xCC, 0x16};
        ++numRead;
        if(numRead>6) numRead=0;
        read[0]=MODBUS[numRead];
        setStatus(RS485, &read);
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

void modeFromCond(u8 mode){
    if(mode==0) return 3;
    if(mode==1) return 1;
    if(mode==2) return 0;
    if(mode==3) return 2;
    if(mode==4) return 4;
    return 4;
}

void speedFromCond(u8 speed){
    if(speed==0) return 3;
    if(speed==1) return 2;
    if(speed==2) return 1;
    if(speed==3) return 0;
    return 0;
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(opt(1)==3 && optl==13){
        u8 state[5]={0, 0, 0, 0, 0};
        state[0]=modeFromCond(opt(6));
        state[0]=(state[0]<<4)|opt(4);
        state[4]=speedFromCond(opt(8));
        u16 temp=((opt(9)<<8)|opt(10))/10;
        if(temp>=5) state[1]=temp-5;
        setStatus(@ID[numRead]:@SID[numRead], &state);
    }
}