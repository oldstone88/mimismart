/*
{
  desc:"DALI",
  tag:"import-script",
  target:"RS485",
  name:"DaliToRS",
  selectArea:true,
  vars:[
        {type:"comment",text:"Выберите RS485:"},
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {type:"comment",text:"Выберите диммеры:"},
        {name:"D00",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 0"},
        {name:"D01",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 1"},
        {name:"D02",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 2"},
        {name:"D03",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 3"},
        {name:"D04",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 4"},
        {name:"D05",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 5"},
        {name:"D06",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 6"},
        {name:"D07",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 7"},
        {name:"D08",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 8"},
        {name:"D09",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 9"},
        {name:"D10",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 10"},
        {name:"D11",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 11"},
        {name:"D12",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 12"},
        {name:"D13",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 13"},
        {name:"D14",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 14"},
        {name:"D15",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 15"},
  ]
}
*/

const u16 ID [] = {
    ADDR2ID(D00)
    #ifdef D01, ADDR2ID(D01) #else ,0 #endif
    #ifdef D02, ADDR2ID(D02) #else ,0 #endif
    #ifdef D03, ADDR2ID(D03) #else ,0 #endif
    #ifdef D04, ADDR2ID(D04) #else ,0 #endif
    #ifdef D05, ADDR2ID(D05) #else ,0 #endif
    #ifdef D06, ADDR2ID(D06) #else ,0 #endif
    #ifdef D07, ADDR2ID(D07) #else ,0 #endif
    #ifdef D08, ADDR2ID(D08) #else ,0 #endif
    #ifdef D09, ADDR2ID(D09) #else ,0 #endif
    #ifdef D10, ADDR2ID(D10) #else ,0 #endif
    #ifdef D11, ADDR2ID(D11) #else ,0 #endif
    #ifdef D12, ADDR2ID(D12) #else ,0 #endif
    #ifdef D13, ADDR2ID(D13) #else ,0 #endif
    #ifdef D14, ADDR2ID(D14) #else ,0 #endif
    #ifdef D15, ADDR2ID(D15) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(D00)
    #ifdef D01, ADDR2SID(D01) #else ,0 #endif
    #ifdef D02, ADDR2SID(D02) #else ,0 #endif
    #ifdef D03, ADDR2SID(D03) #else ,0 #endif
    #ifdef D04, ADDR2SID(D04) #else ,0 #endif
    #ifdef D05, ADDR2SID(D05) #else ,0 #endif
    #ifdef D06, ADDR2SID(D06) #else ,0 #endif
    #ifdef D07, ADDR2SID(D07) #else ,0 #endif
    #ifdef D08, ADDR2SID(D08) #else ,0 #endif
    #ifdef D09, ADDR2SID(D09) #else ,0 #endif
    #ifdef D10, ADDR2SID(D10) #else ,0 #endif
    #ifdef D11, ADDR2SID(D11) #else ,0 #endif
    #ifdef D12, ADDR2SID(D12) #else ,0 #endif
    #ifdef D13, ADDR2SID(D13) #else ,0 #endif
    #ifdef D14, ADDR2SID(D14) #else ,0 #endif
    #ifdef D15, ADDR2SID(D15) #else ,0 #endif
};

u8 writetors[100]={""};

void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), "%c", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

void clean()
{
    for(u8 i=0; i<101; ++i)
    {
        writetors[i]="";
    }
}

void sendtors()
{
    setStatus(RS485, &writetors);
    //srvError("%s", &writetors);  
}

V-ID/D00#ifdef D01, D01#endif#ifdef D02, D02#endif#ifdef D03, D03#endif#ifdef D04, D04#endif#ifdef D05, D05#endif#ifdef D06, D06#endif#ifdef D07, D07#endif#ifdef D08, D08#endif#ifdef D09, D09#endif#ifdef D10, D10#endif#ifdef D11, D11#endif#ifdef D12, D12#endif#ifdef D13, D13#endif#ifdef D14, D14#endif#ifdef D15, D15#endif
{
    for(u8 i=0;i<16;++i)
    {
        if(ID[i] && SID[i] && SID[i]==senderSubId())
        {
            clean();
            if((opt(0)&1)==0) {sprintf(writetors, "{[WRITE:1;GP=%d;OFF]}", i);} else
            if((opt(0)&1)==1) {sprintf(writetors, "{[WRITE:1;GP=%d;VALUE=%d]}", i, opt(1));}
            cancelDelayedCall(sendtors);
            delayedCallMs(sendtors, 250);
        }
    }
}

V-ID/RS485
{
    //stat();
}   