/*
{
    desc:"Komfovent C5 br 19200 EP stop 1.0 - 2024",
    tag:"import-script",
    target:"RS485",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"5", "t-delta":"35", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x00"},
    ],
    vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"V00",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},    
    ]
}
*/

u8 cond [5];
u8 read[8]={Address, 0x03, 0x00, 0x00, 0x00, 0x01, 0xCC, 0x16};
u8 writeOnOff[]={Address, 0x06, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 writeOther[19]={Address, 0x10, 0x00, 0x78, 0x00, 0x05, 0x0A, 0x00, 0x00, 0x01, 0xF4, 0x00, 0x00, 0x01, 0xF4, 0x00, 0x00, 0xCC, 0x16};
u8 write=0;
u8 count=0;
u8 protect=0;

void setSpeed(u16 speed){
    writeOther[9]=speed>>8;
    writeOther[10]=speed;
    writeOther[13]=speed>>8;
    writeOther[14]=speed;
}

void thirdSend(){
    // Поток воздуха
    // Приток(9 и 10), Вытяжка(13 и 14)
    if([V00.4]==0){
        // 200
        setSpeed(200);
    }
    else if([V00.4]==1){
        // 500
        setSpeed(500);
    }
    else if([V00.4]==2){
        // 800
       setSpeed(800);
    }
    else if([V00.4]==3){
        // 1000
        setSpeed(1000);
    }
    // Температура
    writeOther[15]=([V00.1]+5)*10>>8;
    writeOther[16]=([V00.1]+5)*10;
    setStatus(RS485, &writeOther);
}

void secondSend(){
    writeOnOff[3]=0x00;
    writeOnOff[5]=[V00.0]%2;
    if(([V00.0]%2)==1){
        cancelDelayedCall(thirdSend);
        delayedCall(thirdSend, 1);
    }
    setStatus(RS485, &writeOnOff);
}

V-ID/V00{
    if(senderId()!=exciterId()){
        u8 changeMode[8]={Address, 0x06, 0x00, 0x63, 0x00, 0x05, 0xCC, 0x16};
        setStatus(RS485, &changeMode);
        write=1;
        cancelDelayedCall(secondSend);
        cancelDelayedCall(thirdSend);
        delayedCall(secondSend, 1);
    }
}

//Опрос вентиляции
V-ID/s:5{
    if(!write){
        if(count==0){
            read[3]=0x00;
            read[5]=0x01;
            ++count;
        }
        else {
            read[3]=0x78;
            read[5]=0x05;
            count=0;
        }
        setStatus(RS485, &read);
    }
    else {
        ++protect;
        if(protect>=2) {write=0; protect=0;}
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
        getStatus(V00, cond);
        if(opt(5)==0x01 && opt(6)==0xF4) cond[4]=1;
        else if(opt(5)==0x03 && opt(6)==0x20) cond[4]=2;
        else if(opt(5)==0x03 && opt(6)==0xE8) cond[4]=3;
        else cond[4]=0;
        u16 temp=(((opt(11)<<8)|opt(12))/10)-5;
        if(temp>=5) cond[1]=temp; else srvError("Температура не корректная");
        setStatus(V00, &cond);
    }
    else if(optl==7 && opt(1)==0x03){
        getStatus(V00, cond);
        cond[0]=cond[0]&0xF0;
        cond[0]=cond[0]|opt(4);
        setStatus(V00, &cond);
    }
}