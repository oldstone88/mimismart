/*
{
  desc:"Оазис",
  tag:"import-script",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"34", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0E"},
    ],
  vars:
  [
    {name:"K00",type:"hidden",value:"%TARGET%:%SUBID01%"}
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

//Скорость в приложении в скорость установки(Если более 3х скоростей, иначе равны)
void progtoust(u8 j)
{
  u8 k=0;
  if (j==1) {k=0x02; return(k);}
  if (j==2) {k=0x06; return(k);}
  if (j==3) {k=0x0A; return(k);}
}

//Скорость установки в скорость приложения(Обратная операция)
void usttoprog(u8 j)
{
  u8 k=0;
  if (j==0x02) {k=1; return(k);}
  if (j==0x06) {k=2; return(k);}
  if (j==0x0A) {k=3; return(k);}
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
        if(opt(1)!=((temp/10)-5)) {temp=((opt(1)+5)*10); i[3]=0x1F; i[4]=temp>>8; i[5]=temp; setStatus(RS485,&i); write=1;} else
        if(opt(4)!=usttoprog(obduv)) {obduv=progtoust(opt(4)); i[3]=0x20; i[4]=0; i[5]=obduv; setStatus(RS485,&i); write=1;}
      }
  }
}


//Секция обратной связи
void check()
{
  if(on==1 && ([K00.0]%2==0)) {write=2; getStatus(K00, &kond); kond[0]=1; setStatus(K00, &kond); srvError("Включение");} else
  if(on==0 && ([K00.0]%2!=0)) {write=2; getStatus(K00, &kond); kond[0]=0; setStatus(K00, &kond); srvError("Выключение");} else
  if(on==1 && (obduv!=progtoust([K00.4]))) { write=2; getStatus(K00, &kond); kond[4]=usttoprog(obduv); setStatus(K00, &kond); srvError("Обдув");} else
  if(on==1 && (temp!=([K00.1]+5)*10)) {write=2; getStatus(K00, &kond); kond[1]=((temp/10)-5); setStatus(K00, &kond); srvError("Температура");} else
  write=0;
}


V-ID/s:5
{
  if(write==0)
    {
      if(zapr==0) {setStatus(RS485,{0x01, 0x04, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16}); zapr=1;} else //Вкл-Выкл
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

