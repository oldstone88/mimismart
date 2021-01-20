/*
{
	desc:"Скрипт для кондиционера Intesis FJ-RC-MBS-1",
	tag:"import-script",
	target:"RS485",
	selectArea:true,
	addItems:[
		{tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
        {tag:"item", id:"%TARGET%", name:"NAME2", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
        {tag:"item", id:"%TARGET%", name:"NAME3", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
        {tag:"item", id:"%TARGET%", name:"NAME4", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
	],
	vars:[
		{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
		{name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 1"},
		{name:"NAME2",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 2"},
		{name:"NAME3",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 3"},
		{name:"NAME4",type:"string",required:false,min:3,max:40,desc:"Имя кондиционера",defaultValue:"Кондиционер 4"},
		{name:"Cond01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Cond02",type:"hidden",value:"%TARGET%:%SUBID02%"},
        {name:"Cond03",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"Cond04",type:"hidden",value:"%TARGET%:%SUBID04%"},
        {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address2",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address3",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"Address4",type:"number",min:"1",max:"127",required:false,defaultValue:"1",desc:"Адрес Modbus"},
        {type:"comment", text:"Режимы кондиционера 1:"},
        {name:"Fan1",  type:"checkbox", checked:true,desc:"Вентиляция"},
        {name:"Cool1", type:"checkbox", checked:true,desc:"Охлаждение"},
        {name:"Dry1",  type:"checkbox", checked:true,desc:"Осушение"},
        {name:"Heat1", type:"checkbox", checked:true,desc:"Нагрев"},
        {name:"Auto1", type:"checkbox", checked:true,desc:"Авто"},
        {type:"comment", text:"Режимы кондиционера 2:"},
        {name:"Fan2",  type:"checkbox", checked:false,desc:"Вентиляция"},
        {name:"Cool2", type:"checkbox", checked:false,desc:"Охлаждение"},
        {name:"Dry2",  type:"checkbox", checked:false,desc:"Осушение"},
        {name:"Heat2", type:"checkbox", checked:false,desc:"Нагрев"},
        {name:"Auto2", type:"checkbox", checked:false,desc:"Авто"},
        {type:"comment", text:"Режимы кондиционера 3:"},
        {name:"Fan3",  type:"checkbox", checked:false,desc:"Вентиляция"},
        {name:"Cool3", type:"checkbox", checked:false,desc:"Охлаждение"},
        {name:"Dry3",  type:"checkbox", checked:false,desc:"Осушение"},
        {name:"Heat3", type:"checkbox", checked:false,desc:"Нагрев"},
        {name:"Auto3", type:"checkbox", checked:false,desc:"Авто"},
        {type:"comment", text:"Режимы кондиционера 4:"},
        {name:"Fan4",  type:"checkbox", checked:false,desc:"Вентиляция"},
        {name:"Cool4", type:"checkbox", checked:false,desc:"Охлаждение"},
        {name:"Dry4",  type:"checkbox", checked:false,desc:"Осушение"},
        {name:"Heat4", type:"checkbox", checked:false,desc:"Нагрев"},
        {name:"Auto4", type:"checkbox", checked:false,desc:"Авто"}
	]
}
*/
const u16 ID [] = {
    ADDR2ID(Cond01)
    #ifdef Cond02, ADDR2ID(Cond02) #else ,0 #endif
    #ifdef Cond03, ADDR2ID(Cond03) #else ,0 #endif
    #ifdef Cond04, ADDR2ID(Cond04) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(Cond01)
    #ifdef Cond02, ADDR2SID(Cond02) #else ,0 #endif
    #ifdef Cond03, ADDR2SID(Cond03) #else ,0 #endif
    #ifdef Cond04, ADDR2SID(Cond04) #else ,0 #endif
};
u8 modes [] = {
    0xFF
    , #ifdef Fan1  3 #else 0xFF#endif
    , #ifdef Cool1 4 #else 0xFF#endif
    , #ifdef Dry1  2 #else 0xFF#endif
    , #ifdef Heat1 1 #else 0xFF#endif
    , #ifdef Auto1 0 #else 0xFF#endif
    , #ifdef Fan2  3 #else 0xFF#endif
    , #ifdef Cool2 4 #else 0xFF#endif
    , #ifdef Dry2  2 #else 0xFF#endif
    , #ifdef Heat2 1 #else 0xFF#endif
    , #ifdef Auto2 0 #else 0xFF#endif
    , #ifdef Fan3  3 #else 0xFF#endif
    , #ifdef Cool3 4 #else 0xFF#endif
    , #ifdef Dry3  2 #else 0xFF#endif
    , #ifdef Heat3 1 #else 0xFF#endif
    , #ifdef Auto3 0 #else 0xFF#endif
    , #ifdef Fan4  3 #else 0xFF#endif
    , #ifdef Cool4 4 #else 0xFF#endif
    , #ifdef Dry4  2 #else 0xFF#endif
    , #ifdef Heat4 1 #else 0xFF#endif
    , #ifdef Auto4 0 #else 0xFF#endif
};
const u8 Addr [] = {
    Address1
    #ifdef Address2, Address2 #else ,0#endif
    #ifdef Address3, Address3 #else ,0#endif
    #ifdef Address4, Address4 #else ,0#endif
};


u8 cond [5];
u16 Error [] = {0,0,0,0};
u8 counter=0;
u8 write=0;

void GetState(){
    cancelDelayedCall(GetState);
    if((ID[counter]) && (SID[counter]) && Addr[counter] && !write){
        setStatus(RS485,{Addr[counter],0x03,0x0000,0x000C,0xCC16});
        ++counter;
    }
    if(counter<4) delayedCallMs(GetState,150);
    else{
        counter=0;
        delayedCallR(GetState,7);
    }
}

void onInit(){
	delayedCallR(GetState,7);
    for(u8 i=0;i<4;++i){
        for(u8 x=0;x<5;++x){
            for(u8 j=1;j<6;++j){
                if(modes[i*5 + j]==0xFF && j<5){
                    modes[i*5 + j] = modes[i*5 + 1 + j];
                    modes[i*5 + 1 + j] = 0xFF;
                }
            }
        }
    }
}

void Write(){
    write=0;
}

//------------------------------------------
u8 NeedSend = 0;
u8 NumSend = 0;

void Send() {
    cancelDelayedCall(Send);
    u8 breakpoint = 0;
    if(NeedSend){
        for(u8 i=0;(i<4) && (breakpoint==0);++i){
            u8 state [5];
            if(!i)getStatus(Cond01,state);
            else if(i==1)getStatus(Cond02,state);
            else if(i==2)getStatus(Cond03,state);
            else if(i==3)getStatus(Cond04,state);

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
                        SendMas[5] = modes[1+(state[0]>>4) + 5*i];
                    }
                    else if(NumSend==2){
                        SendMas[3] = 2;
                        SendMas[5] = state[4];
                    }
                    else if(NumSend==1){
                        SendMas[3] = 4;
                        SendMas[5] = state[1] + 18;
                    }
                    write=1;
                    setStatus(RS485,SendMas);
                    --NumSend;
                    breakpoint=1;
                    if(!NumSend) NeedSend -= 1<<i;
                    if(NeedSend) delayedCallMs(Send,500);
                    else delayedCall(Write,2);
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

V-ID/Cond01#ifdef Cond02, Cond02#endif#ifdef Cond03, Cond03#endif#ifdef Cond04, Cond04#endif{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<4;++i){
            if(ID[i] && SID[i] && SID[i]==senderSubId()){
                if(Error[i]) setStatus(@exciterId():32,"\1На кондиционере %d стоит ошибка №%d!",i,Error[i]);
                else if(Addr[i]){
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

V-ID/RS485{
    u8 Conds0 [] = {[Cond01.0] 
    #ifdef Cond02, [Cond02.0] #endif
    #ifdef Cond03, [Cond03.0] #endif
    #ifdef Cond04, [Cond04.0] #endif
    };
    
    u8 Conds1 [] = {[Cond01.1] 
    #ifdef Cond02, [Cond02.1] #endif
    #ifdef Cond03, [Cond03.1] #endif
    #ifdef Cond04, [Cond04.1] #endif
    };

    for(u8 i=0;i<4;++i){
        if(optl==29 && opt(1)==3 && opt(0)==Addr[i] && ID[i] && SID[i] ){
            Error[i] = (opt(25)<<8) | opt(26);
            u8 mode = 0xFF;
            u8 fan = opt(8);

            for(u8 j=0;j<5;++j)
                if(modes[1+j + 5*i]==opt(6))
                    mode = j<<4;
            if(mode==0xFF) mode = Conds0[i]&0xF0;
            u8 temp = ((opt(12)<=30) & (opt(12)>=18)) ? opt(12) : (Conds1[i]+18);
            if(!write) setStatus(@ID[i]:@SID[i],{(opt(4)&1) | mode, temp-18,0, 0, fan});
        }
    }
}