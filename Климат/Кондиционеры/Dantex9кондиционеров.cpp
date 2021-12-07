/*
{
  desc:"dantex шлюз",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K01",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K02",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K03",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K04",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K05",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K06",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K07",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"K08",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write=0;
u8 on[9];
u8 marker=0;
u8 r[8]={0x01, 0x01, 0x00, 0x00, 0x00, 0x0F, 0xCC, 0x16};
u8 rt[8]={0x01, 0x04, 0x00, 0x03, 0x00, 0x02, 0xCC, 0x16};
u8 w[15]={0x01, 0x10, 0x00, 0x01, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

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
  if(k==1) j=0x81; else
  if(k==17) j=0x88; else
  if(k==33) j=0x82; else
  if(k==49) j=0x84; else
  if(k==65) j=0x90;
  return(j);
}

void rezimr(u8 k)
{
  u8 j=0;
  if(k==0x81) j=1; else
  if(k==0x88) j=17; else
  if(k==0x82) j=33; else
  if(k==0x84) j=49; else
  if(k==0x90) j=65; else
  if(k==0x00) j=0;
  return(j);
}

// функция скорости
void speedw(u8 k)
{
  u8 j=0;
  if(k==0) j=0x80; else
  if(k==1) j=0x04; else
  if(k==2) j=0x02; else
  if(k==3) j=0x01;
  return(j);
}

void speedr(u8 k)
{
  u8 j=0;
  if(k==0x80) j=0; else
  if(k==0x04) j=1; else
  if(k==0x02) j=2; else
  if(k==0x01) j=3;
  return(j);
}


V-ID/K00
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x01;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00;
    w[3]=0x01;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4)); 
    w[12]=[K00.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K01
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x21;
    w[8]=0x00;
    setStatus(RS485, &w); srvError("OFF");
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00;
    w[3]=0x21;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K01.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K02
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0x41;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00;
    w[3]=0x41;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K02.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K03
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0;
    w[3]=97;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0;
    w[3]=97;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K03.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K04
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0;
    w[3]=129;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0;
    w[3]=129;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K04.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K05
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0x00;
    w[3]=0xA1;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1; srvError("OFF");
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0x00;
    w[3]=0xA1;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K05.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K06
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0;
    w[3]=193;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0;
    w[3]=193;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K06.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K07
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=0;
    w[3]=225;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=0;
    w[3]=225;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K07.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

V-ID/K08
{
  if( (opt(0)%2==0) && write!=2 ) //Выключение
  {
    w[2]=1;
    w[3]=1;
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write!=2)
  {
    w[2]=1;
    w[3]=1;
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K08.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}

void tepmscan()
{
  setStatus(RS485, &rt);
}

void OFF()
{
  write=0;
}

V-ID/s:3
{
  if (write==0 && marker==0) {r[2]=0x00; r[3]=0x00; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0x03; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==1) {r[2]=0x00; r[3]=0x80; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0x23; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==2) {r[2]=0x01; r[3]=0x00; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0x43; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==3) {r[2]=0x01; r[3]=0x80; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0x63; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==4) {r[2]=0x02; r[3]=0x00; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0x83; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==5) {r[2]=0x02; r[3]=0x80; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0xA3; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==6) {r[2]=0x03; r[3]=0x00; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0xC3; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==7) {r[2]=0x03; r[3]=0x80; setStatus(RS485, &r); rt[2]=0x00; rt[3]=0xE3; delayedCall(tepmscan, 1);} else
  if (write==0 && marker==8) {r[2]=0x04; r[3]=0x00; setStatus(RS485, &r); rt[2]=0x01; rt[3]=0x03; delayedCall(tepmscan, 1);} else
  delayedCall(OFF, 25);
}

//Обратная связь
void check(u8 vkl, u8 ckopoct)
{
  u8 prov[5];
  if (marker==0) getStatus(K00, &prov); else
  if (marker==1) getStatus(K01, &prov); else
  if (marker==2) getStatus(K02, &prov); else
  if (marker==3) getStatus(K03, &prov); else
  if (marker==4) getStatus(K04, &prov); else
  if (marker==5) getStatus(K05, &prov); else
  if (marker==6) getStatus(K06, &prov); else
  if (marker==7) getStatus(K07, &prov); else
  if (marker==8) getStatus(K08, &prov);
  if(rezimr(vkl)!=prov[0] && rezimr(vkl)!=0) {write=2; prov[0]=rezimr(vkl);} else if(rezimr(vkl)==0 && prov[0]%2!=0) {write=2; prov[0]=(prov[0]&0xFE);}
  if(speedr(ckopoct)!=prov[4] && speedr(ckopoct)!=0) {write=2; prov[4]=speedr(ckopoct);}

  if(write==2 && marker==0) {setStatus(K00, &prov); srvError("Sync0");} else
  if(write==2 && marker==1) {setStatus(K01, &prov); srvError("Sync1");} else
  if(write==2 && marker==2) {setStatus(K02, &prov); srvError("Sync2");} else
  if(write==2 && marker==3) {setStatus(K03, &prov); srvError("Sync3");} else
  if(write==2 && marker==4) {setStatus(K04, &prov); srvError("Sync4");} else
  if(write==2 && marker==5) {setStatus(K05, &prov); srvError("Sync5");} else
  if(write==2 && marker==6) {setStatus(K06, &prov); srvError("Sync6");} else
  if(write==2 && marker==7) {setStatus(K07, &prov); srvError("Sync7");} else
  if(write==2 && marker==8) {setStatus(K08, &prov); srvError("Sync8");}
}

void checkt(u8 temp)
{
   u8 prov[5];
  if (marker==0) getStatus(K00, &prov); else
  if (marker==1) getStatus(K01, &prov); else
  if (marker==2) getStatus(K02, &prov); else
  if (marker==3) getStatus(K03, &prov); else
  if (marker==4) getStatus(K04, &prov); else
  if (marker==5) getStatus(K05, &prov); else
  if (marker==6) getStatus(K06, &prov); else
  if (marker==7) getStatus(K07, &prov); else
  if (marker==8) getStatus(K08, &prov);
  if (temp<16) temp=16;
  if((temp-16)!=prov[1]) {write=2; prov[1]=temp-16;}

  if(write==2 && marker==0) {setStatus(K00, &prov); srvError("TEMP0");} else
  if(write==2 && marker==1) {setStatus(K01, &prov); srvError("TEMP1");} else
  if(write==2 && marker==2) {setStatus(K02, &prov); srvError("TEMP2");} else
  if(write==2 && marker==3) {setStatus(K03, &prov); srvError("TEMP3");} else
  if(write==2 && marker==4) {setStatus(K04, &prov); srvError("TEMP4");} else
  if(write==2 && marker==5) {setStatus(K05, &prov); srvError("TEMP5");} else
  if(write==2 && marker==6) {setStatus(K06, &prov); srvError("TEMP6");} else
  if(write==2 && marker==7) {setStatus(K07, &prov); srvError("TEMP7");} else
  if(write==2 && marker==8) {setStatus(K08, &prov); srvError("TEMP8");}

  ++marker; if(marker==9) marker=0;
}

//Вывод
V-ID/RS485
{
  if(optl==7 && write==0)
  {
    check(opt(3), opt(4));
  }
  if(optl==9 && write==0)
  {
    checkt(opt(4));
  }
  stat();
}


