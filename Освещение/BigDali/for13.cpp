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
    ADDR2SID(D06),
    ADDR2SID(D07),
    ADDR2SID(D08),
    ADDR2SID(D09),
    ADDR2SID(D10),
    ADDR2SID(D11),
    ADDR2SID(D12),
};

u16 NeedSend=0;
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


V-ID/D00, D01, D02, D03, D04, D05, D06, D07, D08, D09, D10, D11, D12{
    for(u16 i=0; i<6; ++i){
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
    else if(((NeedSend>>6)&1)==1){
        u8 writetors[50]={""};
        if(([D06.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=6;OFF]}");} else
        if(([D06.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=6;VALUE=%d]}", [D06.1]);}
        setStatus(RS485, &writetors);
        marker=7;
    }
    else if(((NeedSend>>7)&1)==1){
        u8 writetors[50]={""};
        if(([D07.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=7;OFF]}");} else
        if(([D07.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=7;VALUE=%d]}", [D07.1]);}
        setStatus(RS485, &writetors);
        marker=8;
    }
    else if(((NeedSend>>8)&1)==1){
        u8 writetors[50]={""};
        if(([D08.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=8;OFF]}");} else
        if(([D08.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=8;VALUE=%d]}", [D08.1]);}
        setStatus(RS485, &writetors);
        marker=9;
    }
    else if(((NeedSend>>9)&1)==1){
        u8 writetors[50]={""};
        if(([D09.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=9;OFF]}");} else
        if(([D09.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=9;VALUE=%d]}", [D09.1]);}
        setStatus(RS485, &writetors);
        marker=10;
    }
    else if(((NeedSend>>10)&1)==1){
        u8 writetors[50]={""};
        if(([D10.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=10;OFF]}");} else
        if(([D10.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=10;VALUE=%d]}", [D10.1]);}
        setStatus(RS485, &writetors);
        marker=11;
    }
    else if(((NeedSend>>11)&1)==1){
        u8 writetors[50]={""};
        if(([D11.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=11;OFF]}");} else
        if(([D11.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=11;VALUE=%d]}", [D11.1]);}
        setStatus(RS485, &writetors);
        marker=12;
    }
    else if(((NeedSend>>12)&1)==1){
        u8 writetors[50]={""};
        if(([D12.0]&1)==0) {sprintf(writetors, "{[WRITE:1;GP=12;OFF]}");} else
        if(([D12.0]&1)==1) {sprintf(writetors, "{[WRITE:1;GP=12;VALUE=%d]}", [D12.1]);}
        setStatus(RS485, &writetors);
        marker=12;
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
    if(marker<=10)strsub(buff00, res, 16, 1);
    else strsub(buff00, res, 16, 2);
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
    setStatus(D06, {0xFE, 250, 0});
    setStatus(D07, {0xFE, 250, 0});
    setStatus(D08, {0xFE, 250, 0});
    setStatus(D09, {0xFE, 250, 0});
    setStatus(D10, {0xFE, 250, 0});
    setStatus(D11, {0xFE, 250, 0});
    setStatus(D12, {0xFE, 250, 0});
}
