/*
{
  desc:"Кулмастер",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K01",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K02",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K03",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K04",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K05",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K06",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K07",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K08",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write=0;
u8 on[8];
u8 marker=0;
u8 r[8]={0x50, 0x03, 0x00, 0x20, 0x00, 0x04, 0xCC, 0x16};
u8 w[17]={0x50, 0x10, 0x00, 0x20, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

//Функция вывода состояния
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

//Функция режима
void rezimw(u8 k)
{
  u8 j=0;
  if(k==1) j=0x05; else
  if(k==17) j=0x00; else
  if(k==33) j=0x03; else
  if(k==49) j=0x01; else
  if(k==65) j=0x02;
  return(j);
}

void rezimr(u8 k)
{
  u8 j=0;
  if(k==0x05) j=0; else
  if(k==0x00) j=16; else
  if(k==0x03) j=32; else
  if(k==0x01) j=48; else
  if(k==0x02) j=64; 
  return(j);
}

// функция скорости
void speedw(u8 k)
{
  u8 j=0;
  if(k==0) j=0x03; else
  if(k==1) j=0x00; else
  if(k==2) j=0x01; else
  if(k==3) j=0x02;
  return(j);
}

void speedr(u8 k)
{
  u8 j=0;
  if(k==0x03) j=0; else
  if(k==0x00) j=1; else
  if(k==0x01) j=2; else
  if(k==0x02) j=3;
  return(j);
}

V-ID/K01
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x20;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x20; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K02
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x30;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x30; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K03
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x40;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x40; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K04
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x50;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x50; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K05
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x60;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x60; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K06
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x70;
    w[14]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x70; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ-ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K08
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00; //Адрес
    w[3]=0x10; //Адрес
    w[14]=0x00; //ВЫКЛ
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00; //Адрес
    w[3]=0x10; //Адрес
    w[8]=rezimw(opt(0)); //Режим
    w[10]=speedw(opt(4)); //Скорость
    w[11]=((opt(1)+20)*10)>>8; //Температура*10 HI
    w[12]=((opt(1)+20)*10)&0xFF; //Температура*10 LOW
    w[14]=0x01; //ВКЛ
    setStatus(RS485, &w);
    write=1;
  }
}

void OFF()
{
  write=0;
}

V-ID/s:1
{
  if (write==0 && marker==1) {r[2]=0x00; r[3]=0x20; setStatus(RS485, &r);} else
  if (write==0 && marker==2) {r[2]=0x00; r[3]=0x30; setStatus(RS485, &r);} else
  if (write==0 && marker==3) {r[2]=0x00; r[3]=0x40; setStatus(RS485, &r);} else
  if (write==0 && marker==4) {r[2]=0x00; r[3]=0x50; setStatus(RS485, &r);} else
  if (write==0 && marker==5) {r[2]=0x00; r[3]=0x60; setStatus(RS485, &r);} else
  if (write==0 && marker==6) {r[2]=0x00; r[3]=0x70; setStatus(RS485, &r);} else
  if (write==0 && marker==0) {r[2]=0x00; r[3]=0x10; setStatus(RS485, &r);} else
  write=0;
}

//Обратная связь
void check(u8 mode, u8 ckopoct, u8 temphi, u8 templo, u8 vkl)
{
  u8 prov[5];
  if (marker==1) getStatus(K01, &prov); else
  if (marker==2) getStatus(K02, &prov); else
  if (marker==3) getStatus(K03, &prov); else
  if (marker==4) getStatus(K04, &prov); else
  if (marker==5) getStatus(K05, &prov); else
  if (marker==6) getStatus(K06, &prov); else
  if (marker==0) getStatus(K08, &prov);

  if(rezimr(mode)!=(prov[0]&0xFE)) {write=2; prov[0]=((rezimr(mode)&0xFE)|(prov[0]&1));}
  if(vkl!=(prov[0]&1)) {write=2; if(vkl==1) prov[0]=prov[0]|1; else prov[0]=prov[0]&0xFE;}
  if(speedr(ckopoct)!=prov[4]) {write=2; prov[4]=speedr(ckopoct);}
  u16 temp=((temphi<<8|templo)/10);
  if (temp<20) temp=20;
  temp=temp-20;
  if(temp!=prov[1]) {write=2; prov[1]=temp;}

  if(write==2 && marker==1) {setStatus(K01, &prov); srvError("Sync1");} else
  if(write==2 && marker==2) {setStatus(K02, &prov); srvError("Sync2");} else
  if(write==2 && marker==3) {setStatus(K03, &prov); srvError("Sync3");} else
  if(write==2 && marker==4) {setStatus(K04, &prov); srvError("Sync4");} else
  if(write==2 && marker==5) {setStatus(K05, &prov); srvError("Sync5");} else
  if(write==2 && marker==6) {setStatus(K06, &prov); srvError("Sync6");} else
  if(write==2 && marker==0) {setStatus(K08, &prov); srvError("Sync0");}

  ++marker; if(marker==7) marker=0;
}

//Вывод
V-ID/RS485
{
  if(optl==13 && write==0)
  {
    check(opt(4), opt(6), opt(7), opt(8), opt(10));
  }
  //stat();
}

