/*
{
  desc:"Intesis настройки RS br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID02%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID04%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID06%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID08%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID10%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID11%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID12%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID13%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID14%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID15%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID16%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID17%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID18%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID19%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID20%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID21%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID22%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID23%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID24%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID25%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID26%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID27%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID28%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address0",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address1",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address2",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address3",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address4",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address5",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address6",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address7",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address8",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address9",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address10",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address11",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address12",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address13",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID07%"},
        {name:"COND04",type:"hidden",value:"%TARGET%:%SUBID09%"},
        {name:"COND05",type:"hidden",value:"%TARGET%:%SUBID11%"},
        {name:"COND06",type:"hidden",value:"%TARGET%:%SUBID13%"},
        {name:"COND07",type:"hidden",value:"%TARGET%:%SUBID15%"},
        {name:"COND08",type:"hidden",value:"%TARGET%:%SUBID17%"},
        {name:"COND09",type:"hidden",value:"%TARGET%:%SUBID19%"},
        {name:"COND10",type:"hidden",value:"%TARGET%:%SUBID21%"},
        {name:"COND11",type:"hidden",value:"%TARGET%:%SUBID23%"},
        {name:"COND12",type:"hidden",value:"%TARGET%:%SUBID21%"},
        {name:"COND13",type:"hidden",value:"%TARGET%:%SUBID23%"},
        {name:"TEMPSENSOR00",type:"hidden",value:"%TARGET%:%SUBID02%"},
        {name:"TEMPSENSOR01",type:"hidden",value:"%TARGET%:%SUBID04%"},
        {name:"TEMPSENSOR02",type:"hidden",value:"%TARGET%:%SUBID06%"},
        {name:"TEMPSENSOR03",type:"hidden",value:"%TARGET%:%SUBID08%"},
        {name:"TEMPSENSOR04",type:"hidden",value:"%TARGET%:%SUBID10%"},
        {name:"TEMPSENSOR05",type:"hidden",value:"%TARGET%:%SUBID12%"},
        {name:"TEMPSENSOR06",type:"hidden",value:"%TARGET%:%SUBID14%"},
        {name:"TEMPSENSOR07",type:"hidden",value:"%TARGET%:%SUBID16%"},
        {name:"TEMPSENSOR08",type:"hidden",value:"%TARGET%:%SUBID18%"},
        {name:"TEMPSENSOR09",type:"hidden",value:"%TARGET%:%SUBID20%"},
        {name:"TEMPSENSOR10",type:"hidden",value:"%TARGET%:%SUBID22%"},
        {name:"TEMPSENSOR11",type:"hidden",value:"%TARGET%:%SUBID24%"},
        {name:"TEMPSENSOR12",type:"hidden",value:"%TARGET%:%SUBID22%"},
        {name:"TEMPSENSOR13",type:"hidden",value:"%TARGET%:%SUBID24%"},
  ]
}
*/

const u16 ID [] = {
    ADDR2ID(COND00)
    #ifdef COND01, ADDR2ID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2ID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2ID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2ID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2ID(COND05) #else ,0 #endif
    #ifdef COND06, ADDR2ID(COND06) #else ,0 #endif
    #ifdef COND07, ADDR2ID(COND07) #else ,0 #endif
    #ifdef COND08, ADDR2ID(COND08) #else ,0 #endif
    #ifdef COND09, ADDR2ID(COND09) #else ,0 #endif
    #ifdef COND10, ADDR2ID(COND10) #else ,0 #endif
    #ifdef COND11, ADDR2ID(COND11) #else ,0 #endif
    #ifdef COND12, ADDR2ID(COND12) #else ,0 #endif
    #ifdef COND13, ADDR2ID(COND13) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND00)
    #ifdef COND01, ADDR2SID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2SID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2SID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2SID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2SID(COND05) #else ,0 #endif
    #ifdef COND06, ADDR2SID(COND06) #else ,0 #endif
    #ifdef COND07, ADDR2SID(COND07) #else ,0 #endif
    #ifdef COND08, ADDR2SID(COND08) #else ,0 #endif
    #ifdef COND09, ADDR2SID(COND09) #else ,0 #endif
    #ifdef COND10, ADDR2SID(COND10) #else ,0 #endif
    #ifdef COND11, ADDR2SID(COND11) #else ,0 #endif
    #ifdef COND12, ADDR2SID(COND12) #else ,0 #endif
    #ifdef COND13, ADDR2SID(COND13) #else ,0 #endif
};
const u8 TSID [] = {
    ADDR2SID(TEMPSENSOR00)
    #ifdef TEMPSENSOR01, ADDR2SID(TEMPSENSOR01) #else ,0 #endif
    #ifdef TEMPSENSOR02, ADDR2SID(TEMPSENSOR02) #else ,0 #endif
    #ifdef TEMPSENSOR03, ADDR2SID(TEMPSENSOR03) #else ,0 #endif
    #ifdef TEMPSENSOR04, ADDR2SID(TEMPSENSOR04) #else ,0 #endif
    #ifdef TEMPSENSOR05, ADDR2SID(TEMPSENSOR05) #else ,0 #endif
    #ifdef TEMPSENSOR06, ADDR2SID(TEMPSENSOR06) #else ,0 #endif
    #ifdef TEMPSENSOR07, ADDR2SID(TEMPSENSOR07) #else ,0 #endif
    #ifdef TEMPSENSOR08, ADDR2SID(TEMPSENSOR08) #else ,0 #endif
    #ifdef TEMPSENSOR09, ADDR2SID(TEMPSENSOR09) #else ,0 #endif
    #ifdef TEMPSENSOR10, ADDR2SID(TEMPSENSOR10) #else ,0 #endif
    #ifdef TEMPSENSOR11, ADDR2SID(TEMPSENSOR11) #else ,0 #endif
    #ifdef TEMPSENSOR12, ADDR2SID(TEMPSENSOR10) #else ,0 #endif
    #ifdef TEMPSENSOR13, ADDR2SID(TEMPSENSOR11) #else ,0 #endif
};

const u8 Addr [] = {
    Address0,
    Address1, 
    Address2, 
    Address3, 
    Address4, 
    Address5, 
    Address6, 
    Address7, 
    Address8, 
    Address9, 
    Address10,
    Address11,
    Address12,
    Address13
};


u8 cond [5];
u8 counter=0;
u8 write=0;


//Опрос кондиционеров
void GetState(){
    cancelDelayedCall(GetState);
    if((ID[counter]) && (SID[counter]) && Addr[counter] && !write)
    {
        setStatus(RS485,{Addr[counter],0x03,0x0000,0x0006,0xCC16});
        ++counter;
    }
    if(counter<14) delayedCallMs(GetState,150);
    else{
        counter=0;
        delayedCallR(GetState,7);
    }
}


//Инициализация
void onInit()
{
    delayedCallR(GetState,7);
}


//Флаг чтения
void Write(){
    write=0;
}

//------------------------------------------
u16 NeedSend = 0;
u8 NumSend = 0;

//Отправка статуса
void Send() {
    cancelDelayedCall(Send);
    u8 breakpoint = 0;
    if(NeedSend){
        for(u8 i=0;(i<14) && (breakpoint==0);++i){
            u8 state [5];
            if(!i)getStatus(COND00,state);
            else if(i==1)getStatus(COND01,state);
            else if(i==2)getStatus(COND02,state);
            else if(i==3)getStatus(COND03,state);
            else if(i==4)getStatus(COND04,state);
            else if(i==5)getStatus(COND05,state);
            else if(i==6)getStatus(COND06,state);
            else if(i==7)getStatus(COND07,state);
            else if(i==8)getStatus(COND08,state);
            else if(i==9)getStatus(COND09,state);
            else if(i==10)getStatus(COND10,state);
            else if(i==11)getStatus(COND11,state);
            else if(i==12)getStatus(COND12,state);
            else if(i==13)getStatus(COND13,state);
            u8 rezh=0;
            if((state[0]&0xFE)==0) rezh=0x03; //Вентиляция
                else if((state[0]&0xFE)==16) rezh=0x04; //Охдаждение
                else if((state[0]&0xFE)==32) rezh=0x02; //Осушение
                else if((state[0]&0xFE)==48) rezh=0x01; //Нагрев
                else if((state[0]&0xFE)==64) rezh=0x00; //Авто

            if((NeedSend>>i) & 1){
                if(!NumSend){
                    NumSend = 4;
                    delayedCallMs(Send,500);
                    breakpoint=1;
                }
                else{
                    u8 SendMas [] = {Addr[i],0x06,0x00,0x00,0x00,0x00,0xCC16};
                    if(NumSend==4){
                        SendMas[5] = state[0]&1;
                    }
                    else if(NumSend==3){
                        SendMas[3] = 1;
                        SendMas[5] = rezh;
                    }
                    else if(NumSend==2){
                        SendMas[3] = 2;
                        SendMas[5] = state[4];
                    }
                    else if(NumSend==1){
                        SendMas[3] = 4;
                        SendMas[4] = (state[1]+18)*10>>8;
                        SendMas[5] = (state[1] + 18)*10;
                    }
                    write=1;
                    setStatus(RS485,SendMas);
                    --NumSend;
                    breakpoint=1;
                    if(!NumSend) NeedSend -= 1<<i;
                    if(NeedSend) delayedCallMs(Send,500);
                    else delayedCall(Write,10);
                }
            }
        }
    }
}
//------------------------------------------
u8 count = 0;
V-ID/ms:100{
    if(NeedSend) ++count;
    else count=0;
    if(count>20){
        Send();
        count=0;
    }
}

V-ID/COND00, COND01, COND02, COND03, COND04, COND05, COND06, COND07, COND08, COND09, COND10, COND11, COND12, COND13
{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<14;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId())
            {
                if(Addr[i]){
                    write=1;
                    count=0;
                    NeedSend |= 1<<i;
                    cancelDelayedCall(Send);
                    delayedCall(Send,1);
                }
            }
        }
    }
}


//вывод в лог ответов RS
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
    for(u8 i=0;i<14;++i)
    {
        if(optl==17 && opt(1)==3 && opt(0)==Addr[i] && ID[i] && SID[i] )
        {
            if(!write)
            {
                u8 kond[5]={0, 0, 0, 0, 0};
                if(opt(6)==0x00) kond[0]=64;
                else if(opt(6)==0x01) kond[0]=48;
                else if(opt(6)==0x02) kond[0]=32;
                else if(opt(6)==0x03) kond[0]=0;
                else if(opt(6)==0x04) kond[0]=16;
                kond[0]=kond[0]|opt(4);
                kond[4]=opt(8);
                kond[1]=(((opt(11)<<8)|opt(12))-180)/10; if(kond[1]>12) kond[1]=12;
                setStatus(@ID[i]:@SID[i], &kond);
                u16 temp=((opt(13)<<8)|opt(14));
                u8 ost=temp%10!=0?125:0;
                setStatus(@ID[i]:@TSID[i], {ost, temp/10});
            }
        }
    }
}