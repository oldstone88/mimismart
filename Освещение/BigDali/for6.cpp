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
  ]
}
*/

const u8 SID[]={
    ADDR2SID(D00),
    ADDR2SID(D01),
    ADDR2SID(D02),
    ADDR2SID(D03),
    ADDR2SID(D04),
    ADDR2SID(D05),
};

u8 NeedSend=0;
u8 marker = 0;
u8 stopper = 0;

void stat(){
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


V-ID/D00, D01, D02, D03, D04, D05{
    for(u8 i=0; i<6; ++i){
        if(SID[i]==senderSubId()){
            NeedSend|=1<<i;
        }
    }
}

V-ID/ms:300
{
    if((NeedSend&1)==1){
        u8 writetors[50]={""};
        if(([D00.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=0;OFF]}");} else
        if(([D00.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=0;VALUE=%d]}", [D00.1]);}
        setStatus(RS485, &writetors);
        marker=1;
    }
    else if(((NeedSend>>1)&1)==1){
        u8 writetors[50]={""};
        if(([D01.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=1;OFF]}");} else
        if(([D01.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=1;VALUE=%d]}", [D01.1]);}
        setStatus(RS485, &writetors);
        marker=2;
    }
    else if(((NeedSend>>2)&1)==1){
        u8 writetors[50]={""};
        if(([D02.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=2;OFF]}");} else
        if(([D02.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=2;VALUE=%d]}", [D02.1]);}
        setStatus(RS485, &writetors);
        marker=3;
    }
    else if(((NeedSend>>3)&1)==1){
        u8 writetors[50]={""};
        if(([D03.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=3;OFF]}");} else
        if(([D03.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=3;VALUE=%d]}", [D03.1]);}
        setStatus(RS485, &writetors);
        marker=4;
    }
    else if(((NeedSend>>4)&1)==1){
        u8 writetors[50]={""};
        if(([D04.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=4;OFF]}");} else
        if(([D04.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=4;VALUE=%d]}", [D04.1]);}
        setStatus(RS485, &writetors);
        marker=5;
    }
    else if(((NeedSend>>5)&1)==1){
        u8 writetors[50]={""};
        if(([D05.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=5;OFF]}");} else
        if(([D05.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=5;VALUE=%d]}", [D05.1]);}
        setStatus(RS485, &writetors);
        marker=6;
    }
}

V-ID/RS485{
    u8 res[100]="";
    u8 *st = opt;
    u8 i = 0;
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), "%c", st[i]);
    }
    srvError(&res);
    u8 buff00[100]="";
    strsub(buff00, res, 16, 1);
    u8 buff01 = atol(buff00);
    if(optl>=12){
        if((marker-1)==buff01) {NeedSend-=1<<(marker-1);}
    }
}   

void onInit(){
    setStatus(D00, {0xFE, 250, 0});
    setStatus(D01, {0xFE, 250, 0});
    setStatus(D02, {0xFE, 250, 0});
    setStatus(D03, {0xFE, 250, 0});
    setStatus(D04, {0xFE, 250, 0});
    setStatus(D05, {0xFE, 250, 0});
}