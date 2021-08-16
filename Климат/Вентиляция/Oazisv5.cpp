/*
{
  desc:"Оазис",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Установка",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 zapr=0;
u8 write=0;
u8 on=0;
u16 temp=0;
u8 obduv=0;
u8 kond[6];
u8 i[8]={0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16};

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

V-ID/K00
{
  if(write!=2)
  {
    //Секция ВКЛ-ВЫКЛ
    if(opt(0)%2!=0 && on==0) {on=1; setStatus(RS485,{0x01, 0x06, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); write=1;} else
    if(opt(0)%2==0 && on==1) {on=0; setStatus(RS485,{0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0xCC, 0x16}); write=1;} else
    //Секция температуры
    if(on==1)
      {
        if(opt(1)!=((temp/10)-15)) {temp=((opt(1)+15)*10); i[3]=0x1F; i[4]=temp<<8; i[5]=temp; setStatus(RS485,&i); write=1;} else
        if(opt(4)!=obduv) {obduv=opt(4); i[3]=0x20; i[4]=0; i[5]=obduv; setStatus(RS485,&i); write=1;}
      }
  }
}


//Секция обратной связи
void check()
{
  if(on==1 && ([K00.0]%2==0)) {write=2; getStatus(K00, &kond); kond[0]=1; setStatus(K00, &kond); srvError("Включение");} else
  if(on==0 && ([K00.0]%2!=0)) {write=2; getStatus(K00, &kond); kond[0]=0; setStatus(K00, &kond); srvError("Выключение");} else
  if(on==1 && (obduv!=[K00.4])) { write=2; getStatus(K00, &kond); kond[4]=obduv; setStatus(K00, &kond); srvError("Обдув");} else
  if(on==1 && (temp!=([K00.1]+15)*10)) {write=2; getStatus(K00, &kond); kond[1]=((temp/10)-15); setStatus(K00, &kond); srvError("Температура");} else
  write=0;
}


V-ID/s:10
{
  if(write==0)
    {
      if(zapr==0) {setStatus(RS485,{0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); zapr=1;} else //Вкл-Выкл
      if(zapr==1) {setStatus(RS485,{0x01, 0x04, 0x00, 0x19, 0x00, 0x01, 0xCC, 0x16}); zapr=2;} else //Скорость
      if(zapr==2) {setStatus(RS485,{0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xCC, 0x16}); zapr=0;} //Температура
    }  else write=0;
}

V-ID/RS485
{
  //stat();
  if (zapr==1 && write==0) {on=(opt(4)&3);} else
  if (zapr==2 && write==0) {obduv=opt(4);} else
  if (zapr==0 && write==0) {temp=(opt(3)<<8|opt(4));}
  check();
}