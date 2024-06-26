/*
{
  desc:"UTY-VMSX",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME2", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME3", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
        {tag:"item", id:"%TARGET%", name:"NAME4", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"18", "t-delta":"12", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"}
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

  ]
}
*/

u8 breakpoint = 0;
u8 write[17]={0x00, 0x10, 0x00, 0x01, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 read[8]={0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0xCC, 0x16};
//u8 read[8]={0x00, 0x04, 0x00, 0x36, 0x00, 0x01, 0xCC, 0x16};
u8 count=0;

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

const u8 Addr [] = {
    Address1
    #ifdef Address2, Address2 #else ,0#endif
    #ifdef Address3, Address3 #else ,0#endif
    #ifdef Address4, Address4 #else ,0#endif
};


//------------------------------------------

void setmode (u8 rezhim){
    if (rezhim==0) rezhim=5; return rezhim; //Обдув
    if (rezhim==1) rezhim=2; return rezhim; //Охлаждение
    if (rezhim==2) rezhim=3; return rezhim; //Сушка
    if (rezhim==3) rezhim=4; return rezhim; //Обогрев
    if (rezhim==4) rezhim=1; return rezhim; //Авто
}

void backmode (u8 rezhim){
    if (rezhim==5) rezhim=0; return rezhim; //Обдув
    if (rezhim==2) rezhim=1; return rezhim; //Охлаждение
    if (rezhim==3) rezhim=2; return rezhim; //Сушка
    if (rezhim==4) rezhim=3; return rezhim; //Обогрев
    if (rezhim==1) rezhim=4; return rezhim; //Авто
}

V-ID/Cond01#ifdef Cond02, Cond02#endif#ifdef Cond03, Cond03#endif#ifdef Cond04, Cond04#endif#ifdef Cond05, Cond05#endif#ifdef Cond06, Cond06#endif{
    if(senderId()!=exciterId()){
        for(u8 i=0;i<4;++i){
          if(SID[i]==senderSubId()){
            breakpoint=1; //Останавливаем чтение
            write[0]=Addr[i]; //Адрес
            write[8]=setmode(opt(0)>>4); //Режим
            write[10]=(opt(0)%2)+1; //Вкл-Выкл
            u16 temperature = (((opt(1)+18)*4)<<1)|1; //Температура
            write[11]=temperature>>8;
            write[12]=temperature;
            write[14]=opt(4)+1; //Скорость
            setStatus(RS485, &write);
          }
        }
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

//Секция обратной связи
V-ID/s:1{
    if(breakpoint==0){
        if(count==0){read[0]=Address1; setStatus(RS485, &read);}
        else if(count==1){read[0]=Address2; setStatus(RS485, &read);}
        else if(count==2){read[0]=Address3; setStatus(RS485, &read);}
        else if(count==3){read[0]=Address4; setStatus(RS485, &read);}
        if(count!=4) ++count; else count=0;
    } else breakpoint=0;
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl==13 && opt(1)==0x03){
        u8 cond[5]={0, 0, 0, 0, 0};
        cond[0]=backmode(opt(4)); //Режим
        u8 onOff=0;
        if(opt(6)==1) onOff=0; else onOff=1;
        cond[0]=cond[0]<<4|onOff; //Вкл-Выкл
        //Температура
        u16 temperature = (((opt(7)<<8|opt(8))>>1)/4);
        if(temperature>=18) cond[1]=temperature-18;
        // Скорость
        cond[4]=opt(10)?opt(10)-1:opt(10);
        // srvError("Температура=%d, скорость=%d", cond[1]+18, cond[4]);
        if(opt(0)==Address1){setStatus(Cond01, &cond);}
        else if(opt(0)==Address2){setStatus(Cond02, &cond);}
        else if(opt(0)==Address3){setStatus(Cond03, &cond);}
        else if(opt(0)==Address4){setStatus(Cond04, &cond);}
    }
}