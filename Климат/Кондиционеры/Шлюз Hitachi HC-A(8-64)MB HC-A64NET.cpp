/*
{
  desc:"Intesis настройки RS br 9600 stop 1.0",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер 1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 2", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 3", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 4", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 5", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 6", "sub-id":"%SUBID11%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 7", "sub-id":"%SUBID13%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 8", "sub-id":"%SUBID15%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 9", "sub-id":"%SUBID17%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 10", "sub-id":"%SUBID19%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 11", "sub-id":"%SUBID21%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 12", "sub-id":"%SUBID23%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 13", "sub-id":"%SUBID25%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 14", "sub-id":"%SUBID27%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 15", "sub-id":"%SUBID29%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 16", "sub-id":"%SUBID31%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 17", "sub-id":"%SUBID33%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер 18", "sub-id":"%SUBID35%", "type":"conditioner", "t-min":"17", "t-delta":"13", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
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
        {name:"COND12",type:"hidden",value:"%TARGET%:%SUBID25%"},
        {name:"COND13",type:"hidden",value:"%TARGET%:%SUBID27%"},
        {name:"COND14",type:"hidden",value:"%TARGET%:%SUBID29%"},
        {name:"COND15",type:"hidden",value:"%TARGET%:%SUBID31%"},
        {name:"COND16",type:"hidden",value:"%TARGET%:%SUBID33%"},
        {name:"COND17",type:"hidden",value:"%TARGET%:%SUBID35%"},
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
    #ifdef COND14, ADDR2ID(COND14) #else ,0 #endif
    #ifdef COND15, ADDR2ID(COND15) #else ,0 #endif
    #ifdef COND16, ADDR2ID(COND16) #else ,0 #endif
    #ifdef COND17, ADDR2ID(COND17) #else ,0 #endif
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
    #ifdef COND14, ADDR2SID(COND14) #else ,0 #endif
    #ifdef COND15, ADDR2SID(COND15) #else ,0 #endif
    #ifdef COND16, ADDR2SID(COND16) #else ,0 #endif
    #ifdef COND17, ADDR2SID(COND17) #else ,0 #endif
};

u8 cond [5];
u8 counter=0;
u8 write=0;
u32 NeedSend=0; // Флаги какой кондиционер требует отправки состояния

void startread(){
    write=0;
}

void Send(){
    u8 breakpoint = 0;
    cancelDelayedCall(Send);
    if(NeedSend){
        for(u8 i=0; i<18 && (breakpoint==0); ++i){
            if((NeedSend>>i)&1){
                breakpoint=1;
                if(!i){getStatus(COND00, cond);} else
                if(i==1){getStatus(COND01, cond);} else
                if(i==2){getStatus(COND02, cond);} else
                if(i==3){getStatus(COND03, cond);} else
                if(i==4){getStatus(COND04, cond);} else
                if(i==5){getStatus(COND05, cond);} else
                if(i==6){getStatus(COND06, cond);} else
                if(i==7){getStatus(COND07, cond);} else
                if(i==8){getStatus(COND08, cond);} else
                if(i==9){getStatus(COND09, cond);} else
                if(i==10){getStatus(COND10, cond);} else
                if(i==11){getStatus(COND11, cond);} else
                if(i==12){getStatus(COND12, cond);} else
                if(i==13){getStatus(COND13, cond);} else
                if(i==14){getStatus(COND14, cond);} else
                if(i==15){getStatus(COND15, cond);} else
                if(i==16){getStatus(COND16, cond);} else
                if(i==17){getStatus(COND17, cond);}
                u16 modbusregister = 20000 + i*32 + 3; // Вычисляется адрес первого регистра для записи
                u8 condstatus[]={Address, 0x10, modbusregister>>8, modbusregister, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
                condstatus[8] = cond[0]%2; // ВКЛ-ВЫКЛ
                // Режим
                if((cond[0]==0) condstatus[10]=2;
                else if((cond[0]>>4)%2==1) condstatus[10]=0;
                else if((cond[0]>>5)%2==1) condstatus[10]=1;
                else if((cond[0]>>6)%2==1) condstatus[10]=3;
                else if((cond[0]>>7)%2==1) condstatus[10]=4;
                // Скорость
                if(cond[4]==0) condstatus[12]=4;
                else if(cond[4]==1) condstatus[12]=0;
                else if(cond[4]==2) condstatus[12]=1;
                else if(cond[4]==3) condstatus[12]=2;
                condstatus[14] = cond[1]+17; // Температура
                write = 1;
                setStatus(RS485, &condstatus); // Отправка состояния
                NeedSend -= 1<<i;
                if(NeedSend) {delayedCallMs(Send, 500);} else delayedCall(startread, 10); 
            }
        }
    }
}

V-ID/COND00, COND01, COND02, COND03, COND04, COND05, COND06, COND07, COND08, COND09, COND10, COND11, COND12, COND13, COND14, COND15, COND16, COND17{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<17;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId()){
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
}