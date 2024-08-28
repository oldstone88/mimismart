/*
{
  desc:"Вентиляция Carel CRSTDrAHAQ",
  name:"CRSTDrAHAQ",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"0", "t-delta":"99", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F", "modes":"0x1F"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Вентиляция",defaultValue:"Кондиционер 1"},
        {name:"Cond01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Address1",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
  ]
}
*/

u8 write = 0;
u8 writehold[21]={Address1, 0x10, 0x00, 0x31, 0x00, 0x06, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 readhold[8]={Address1, 0x03, 0x00, 0x31, 0x00, 0x06, 0xCC, 0x16};

void stopwrite(){
    write=0;
}

void send(){
    cancelDelayedCall(send);
    // Вкл-Выкл
    writehold[8]=[Cond01.0]%2;
    // Надо понять что это такое
    writehold[10]=[Cond01.0]%2;
    // Вычилсяем температуру
    u16 temp=[Cond01.1]*10;
    // Уставка температуры зимнего режима
    writehold[11]=temp>>8;
    writehold[12]=temp;
    // Уставка температуры летнего режима
    writehold[13]=temp>>8;
    writehold[14]=temp;
    // Уставка скорости
    u16 supplySpeed=[Cond01.4]*200+200; // 20-40-60-80 % скорости притока
    u16 extractSpeed=supplySpeed*80/100; // скорость вытяжки - 80% от притока
    writehold[15]=supplySpeed>>8;
    writehold[16]=supplySpeed;
    writehold[17]=extractSpeed>>8;
    writehold[18]=extractSpeed;
    setStatus(RS485, &writehold);
    delayedCall(stopwrite, 3);
}

V-ID/Cond01{
    if(senderId()!=exciterId()){
        cancelDelayedCall(send);
        cancelDelayedCall(stopwrite);
        delayedCall(send, 1);
    }
}

// Вывод ответов от RS485 в лог
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

// Секция обратной связи
V-ID/s:5{
    if(write==0){
        setStatus(RS485, &readhold);
    }
}

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    if(optl==11 && opt(1)==0x03){
    }
}