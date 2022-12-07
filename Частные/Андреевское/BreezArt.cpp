/*
{
  desc:"BreezArt - вода",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Фильтр", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", length:"2", dim:"%"},
    {tag:"item", id:"%TARGET%", name:"На выходе", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"В помещении ", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Улица", "sub-id":"%SUBID91%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Теплоноситель", "sub-id":"%SUBID83%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Критические", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", length:"2"},
    {tag:"item", id:"%TARGET%", name:"Некритические", "sub-id":"%SUBID87%", type:"virtual", "sub-type":"sensor", length:"2"},
    {tag:"item", id:"%TARGET%", name:"BreezArt", "sub-id":"%SUBID85%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00", "funs":"0x0F", "modes":"0x0B"},
  ],
  vars:[
    {name:"T00",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"T01",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"T02",type:"hidden",value:"%TARGET%:%SUBID91%"},
    {name:"T03",type:"hidden",value:"%TARGET%:%SUBID83%"},
    {name:"E00",type:"hidden",value:"%TARGET%:%SUBID89%"},
    {name:"E01",type:"hidden",value:"%TARGET%:%SUBID87%"},
    {name:"FILTER",type:"hidden",value:"%TARGET%:%SUBID97%"},,
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"ID диммера",descWidth:350},
  ]
}
*/

u8 writestate[25]={ID1, 0x10, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
u8 write=0;
u8 i=0;

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

V-ID/V00
{

    if(senderId()!=exciterId())
    {
        //ВКЛ-ВЫКЛ
        if(opt(0)%2==1) {writestate[14]=0x01;}
        else if(opt(0)%2==0) {writestate[14]=0x00;}
        //Скорость в %
        u16 speed=0;
        if(opt(4)==0) speed=100*100; else
        if(opt(4)==1) speed=25*100; else
        if(opt(4)==2) speed=50*100; else
        if(opt(4)==3) speed=75*100;
        writestate[7]=speed>>8; writestate[8]=speed;
        // Температура
        u16 temp=(opt(1)+16)*10;
        writestate[9]=temp>>8; writestate[10]=temp;
        //Зима-Лето
        u8 rezhim=0;
        if(opt(0)==1 || opt(0)==0) rezhim=0; else
        if(opt(0)==17 || opt(0)==16) rezhim=1; else
        if(opt(0)==33 || opt(0)==32) rezhim=2;
        writestate[21]=0x00; writestate[22]=rezhim;
        write=1;
        setStatus(RS485, &writestate);
    }
}

//Обратная связь
void backlink()
{
    u8 cond[5]={0 ,0 ,0 ,0 , 0};
    u8 speed=((opt(3)<<8)|(opt(4)))/100;
    if(speed==25) cond[4]=1; else
    if(speed==50) cond[4]=2; else
    if(speed==75) cond[4]=3; else
    cond[4]=0;
    u8 temp=((opt(5)<<8)|(opt(6)))/10;
    cond[1]=temp-16;
    u8 rezhim=opt(10);
    if(opt(18)==0) rezhim=rezhim; else
    if(opt(18)==1) rezhim=rezhim|0x10; else
    if(opt(18)==2) rezhim=rezhim|0x20;
    cond[0]=rezhim;
    setStatus(V00, &cond);
}

//Чтение ошибок
void errorread()
{
    if((opt(3)+opt(4)+opt(5)+opt(6))>0) {setStatus(E00, 100);} else setStatus(E00, 0);
    if((opt(7)+opt(8)+opt(9)+opt(10))>0) {setStatus(E01, 100);} else setStatus(E01, 0);
}

//Фильтры
void filterread()
{
    u8 dirty=((opt(3)<<8)|opt(4))/100;
    setStatus(FILTER, {0, dirty});
}

//Чтение датчиков
void sensorread()
{
    u16 temper=(opt(3)<<8)|opt(4);
    setStatus(T00, {(temper%10)*25,(temper/10)});
    temper=(opt(11)<<8)|opt(12);
    setStatus(T01, {(temper%10)*25,(temper/10)});
    temper=(opt(19)<<8)|opt(20);
    setStatus(T02, {(temper%10)*25,(temper/10)});
    temper=(opt(27)<<8)|opt(28);
    setStatus(T03, {(temper%10)*25,(temper/10)});
}

V-ID/s:3
{
    if(write==0)
    {
        u8 readstate[8]={ID1, 0x03, 0x00, 0x00, 0x00, 0x08, 0xCC, 0x16};
        //srvError("i=%d", i);
        if(i==0) {++i;} else //Чтение данных об установке
        if(i==1) {readstate[1]=0x04; readstate[3]=0x13; readstate[5]=0x04; ++i;} else //Чтение аварий
        if(i==2) {readstate[1]=0x04; readstate[2]=0x14; readstate[3]=0x50; readstate[5]=0x01; ++i;} else //Чтение фильтров
        if(i==3) {readstate[1]=0x04; readstate[3]=0x32; readstate[5]=0x0E; i=0;} //Чтение датчиков
        setStatus(RS485, &readstate);
    }
    else write=0;
}

V-ID/RS485
{
    //stat();
    if(optl==21 && opt(1)==0x03) backlink(); else
    if(optl==13 && opt(1)==0x04) errorread(); else
    if(optl==7 && opt(1)==0x04) filterread(); else
    if(optl==33 && opt(1)==0x04) sensorread();
}