/*
{
  desc:"Невотон",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"Горелка %", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"%"},
        {tag:"item", id:"%TARGET%", name:"В котле", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"Давление", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"Скорость", "sub-id":"%SUBID91%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"ГВС", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"Улица", "sub-id":"%SUBID87%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"Шим", "sub-id":"%SUBID85%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"Error", "sub-id":"%SUBID83%", type:"virtual", "sub-type":"text", "length":"0"},
        {tag:"item", id:"%TARGET%", name:"ГВС В/Н", "sub-id":"%SUBID81%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"ГВС В/Н", "sub-id":"%SUBID79%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
        {tag:"item", id:"%TARGET%", name:"DHW", "sub-id":"%SUBID77%", type:"virtual", "sub-type":"sensor", "length":"2", "dim":"°C"},
    ],
  vars:[
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"KOTG",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Газовый"},
    {name:"MINGAS", type:"number", defaultValue:60, required:true, desc:"Минимальная температура газового котла"},
    {name:"KOTE",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Электро"},
    {name:"MINELE", type:"number", defaultValue:0, required:true, desc:"Минимальная температура электро котла"},
    {name:"ADDR",type:"devices-list",required:false, filter:["script"],descWidth:250, desc:"Рестарт котла"},
    {name:"GTRA",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"GGOR",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"GPRE",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"GSPE",type:"hidden",value:"%TARGET%:%SUBID91%"},
    {name:"GGVS",type:"hidden",value:"%TARGET%:%SUBID89%"},
    {name:"GSTR",type:"hidden",value:"%TARGET%:%SUBID87%"},
    {name:"GSHI",type:"hidden",value:"%TARGET%:%SUBID85%"},
    {name:"GERR",type:"hidden",value:"%TARGET%:%SUBID83%"},
    {name:"GGVS48",type:"hidden",value:"%TARGET%:%SUBID81%"},
    {name:"GGVS49",type:"hidden",value:"%TARGET%:%SUBID79%"},
    {name:"GDHW",type:"hidden",value:"%TARGET%:%SUBID77%"},
 ]
}
*/

//https://nevoton.ru/product/universalnyj-shlyuz-upravleniya-kotlom-nevoton-bcg-3-0-1-w/ - инструкция газового
//https://nevoton.ru/product/shlyuz-upravleniya-kotlom-ebus-modbus/ - инструкция электро

u8 i=0;
u8 GAZ[8]={0x0A, 0x06, 0x03, 0xFA, 0x00, 0x00, 0xCC, 0x16}; // Задача температуры 4-целое, 5-дробное 
u8 ELE[8]={0x0B, 0x06, 0x03, 0xEA, 0x00, 0x00, 0xCC, 0x16};
u8 write=0;
u8 cond[5];

V-ID/s:5
{
    if(write==0)
    {
        if (i==0) {setStatus(RS485, {0x0B, 0x04, 0x03, 0xE9, 0x00, 0x01, 0xCC, 0x16}); i=1;} else //Электро котёл
        if (i==1) {setStatus(RS485, {0x0A, 0x03, 0x03, 0xEF, 0x00, 0x13, 0xCC, 0x16}); i=0;} // считываем датчики газового котла
    }
}

void RESET()
{
    setStatus(ADDR, 0);
}

//Кнопка сброса ошибки
V-ID/ADDR
{
    if((opt(0)&1)==1) setStatus(RS485, {0x0A, 0x06, 0x04, 0x03, 0x00, 0x01, 0xCC, 0x16}); 
    delayedCall(RESET, 1);
}

//Отправка газу
void sendgas()
{
    setStatus(RS485, &GAZ);
    write=0;
}

//Газовый котел(openterm) Адрес 0x0A
V-ID/KOTG
{
    if(opt(0)%2!=0)
    {
        cancelDelayedCall(sendgas);
        write=1;
        GAZ[4]=opt(1)+MINGAS;
        GAZ[5]=0x00;
        delayedCall(sendgas, 3);
    }
    else //выключаем котёл задавая ему 10 градусов
    {
        cancelDelayedCall(sendgas);
        write=1;
        GAZ[4]=0x09;
        GAZ[5]=0x00;
        delayedCall(sendgas, 3);
    }
}

void sendele()
{
    setStatus(RS485, &ELE);
    write=0;
}

//Электрокотел Адрес 0x0B
V-ID/KOTE
{
    if(opt(0)%2!=0)
    {
        cancelDelayedCall(sendele);
        write=1;
        ELE[5]=(opt(1)+MINELE);
        delayedCall(sendele, 3);
    }
}

void stat()
{
u8 res[150]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %d", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

void CHTENIEGAZ()
{
    u8 znach[2]={0, 0};
    //Мощность горелки
    znach[1]=opt(3);
    setStatus(GTRA, &znach);
    //Давление в контуре ЦО
    znach[1]=opt(5);
    setStatus(GPRE, &znach);
    //Скорость потока в контуре ГВС
    znach[1]=opt(7);
    setStatus(GSPE, &znach);
    //Температура воды в котле
    znach[1]=opt(9);
    setStatus(GGOR, &znach);
    //Температура ГВС
    znach[1]=opt(11);
    setStatus(GGVS, &znach);
    //Температура на улице
    znach[1]=opt(13);
    setStatus(GSTR, &znach);
    //Температура через ШИМ
    znach[1]=opt(15);
    setStatus(GSHI, &znach);
    //Ошибки котла от производителя
    znach[1]=opt(17);
    znach[0]=opt(18);
    u16 error=(znach[1]<<8)|(znach[0]);
    u8 text[7]="";
    if(error!=0)sprintf(text, "%d", error); else sprintf(text, "Нет");
    setStatus(GERR, &text);
    //Температура уставки
    znach[1]=opt(25);
    if(znach[1]>9 && [KOTG.0]%2==0) //На котле>9 градусов(Он включен), а элемент выключен = выключаем еще раз(задаём 9 градусов)
    {
        cancelDelayedCall(sendgas);
        write=1;
        GAZ[4]=0x09;
        GAZ[5]=0x00;
        delayedCall(sendgas, 3);
        srvError("Рассинхрон, надо выключить котёл");
    } else if(znach[1]<=9 && [KOTG.0]%2==1) //На котле <9 градусов(Он выключен), а элемент включен = задаём еще раз температуру(Ту что на кондее)
    {
        cancelDelayedCall(sendgas);
        write=1;
        GAZ[4]=[KOTG.1]+MINGAS;
        GAZ[5]=0x00;
        delayedCall(sendgas, 3);
        srvError("Рассинхрон, надо включить котёл");
    }
    //Граница ГВС 48
    znach[1]=opt(33);
    setStatus(GGVS48, &znach);
    //Граница ГВС 49
    znach[1]=opt(35);
    setStatus(GGVS49, &znach);
    //GHW
    znach[1]=opt(37);
    setStatus(GDHW, &znach);

}

V-ID/RS485
{
    //stat();

    //Считываем датчики котла
    if(optl==43 && opt(0)==10 && write==0)
    {
        CHTENIEGAZ();
    }
} 
