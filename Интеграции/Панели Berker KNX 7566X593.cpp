/*
{
  desc:"Berker",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"COND1",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 1",descWidth:100},
    {name:"COND2",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 2",descWidth:100},
    {name:"COND3",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 3",descWidth:100},
    {name:"COND4",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 4",descWidth:100},
    {name:"COND5",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 5",descWidth:100},
    {name:"COND6",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 6",descWidth:100},
    {name:"RS485",type:"devices-list",required:false,width:600,filter:["com-port"],desc:"RS",descWidth:100},
  ]
}
*/

void stat()
{
u8 res[50]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

//Расшифровка команд от RS: XX YY ZZ
//XX: В KNX - 11 из KNX - 12
//YY: L1 - кнопка, L2 - кондиционер L - номер выключателя(последняя цифра)
//ZZ: Номер кнопки или градус
//Назначение кнопок прописать в скрипте в зависимости от нужд

u8 i[3]={0x00, 0x00, 0x00};
u8 k[5];

void send()
{
  setStatus(RS485, &i);
}

V-ID/COND1
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x12; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/COND2
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x22; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/COND3
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x32; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/COND4
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x42; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/COND5
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x52; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/COND6
{
  if((opt(0)%2)==1)
  {
    i[0]=0x11; i[1]=0x62; i[2]=opt(1)+18;
    cancelDelayedCall(send);
    delayedCall(send, 1);
  }
}

V-ID/RS485
{
  stat();
  if(optl==3 && opt(0)==0x12)
  {
    if(opt(1)==0x12) //кондиционер
    {
      getStatus(CON1, &k);
      if( (opt(2)-18)!=[COND1.1] ) {k[1]=opt(2)-18; setStatus(COND1, &k);}
    } else
  if(opt(1)==0x22) //кондиционер
    {
      getStatus(COND2, &k);
      if( (opt(2)-18)!=[COND2.1] ) {k[1]=opt(2)-18; setStatus(COND2, &k);}
    } else
  if(opt(1)==0x32) //кондиционер
    {
      getStatus(COND3, &k);
      if( (opt(2)-18)!=[COND3.1] ) {k[1]=opt(2)-18; setStatus(COND3, &k);}
    } else
  if(opt(1)==0x12) //кондиционер
    {
      getStatus(COND4, &k);
      if( (opt(2)-18)!=[COND4.1] ) {k[1]=opt(2)-18; setStatus(COND4, &k);}
    } else
  if(opt(1)==0x12) //кондиционер
    {
      getStatus(COND5, &k);
      if( (opt(2)-18)!=[COND5.1] ) {k[1]=opt(2)-18; setStatus(COND5, &k);}
    } else
  if(opt(1)==0x12) //кондиционер
    {
      getStatus(COND6, &k);
      if( (opt(2)-18)!=[COND6.1] ) {k[1]=opt(2)-18; setStatus(COND6, &k);}
    } else
    if(opt(1)==0x11) //Кнопка
    {
      #ifdef I10 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I10, 0xFF); #endif
      #ifdef I11 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I11, 0xFF); #endif
      #ifdef I12 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I12, 0xFF); #endif
      #ifdef I13 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I13, 0xFF); #endif
      #ifdef I14 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I14, 0xFF); #endif
      #ifdef I15 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I15, 0xFF); #endif
      #ifdef I16 if(opt(2)==0x71 || opt(2)==0x70) setStatus(I16, 0xFF); #endif
      #ifdef I17 if(opt(2)==0x81 || opt(2)==0x80) setStatus(I17, 0xFF); #endif
    } else
    if(opt(1)==0x21) //Кнопка
    {
      #ifdef I20 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I20, 0xFF); #endif
      #ifdef I21 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I21, 0xFF); #endif
      #ifdef I22 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I22, 0xFF); #endif
      #ifdef I23 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I23, 0xFF); #endif
      #ifdef I24 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I24, 0xFF); #endif
      #ifdef I25 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I25, 0xFF); #endif
      #ifdef I26 if(opt(2)==0x71 || opt(2)==0x70) setStatus(I26, 0xFF); #endif
      #ifdef I27 if(opt(2)==0x81 || opt(2)==0x80) setStatus(I27, 0xFF); #endif
    } else
    if(opt(1)==0x31) //Кнопка
    {
      #ifdef I30 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I30, 0xFF); #endif
      #ifdef I31 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I31, 0xFF); #endif
      #ifdef I32 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I32, 0xFF); #endif
      #ifdef I33 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I33, 0xFF); #endif
      #ifdef I34 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I34, 0xFF); #endif
      #ifdef I35 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I35, 0xFF); #endif
    } else
    if(opt(1)==0x41) //Кнопка
    {
      #ifdef I40 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I40, 0xFF); #endif
      #ifdef I41 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I41, 0xFF); #endif
      #ifdef I42 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I42, 0xFF); #endif
      #ifdef I43 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I43, 0xFF); #endif
      #ifdef I44 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I44, 0xFF); #endif
      #ifdef I45 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I45, 0xFF); #endif
    } else
    if(opt(1)==0x51) //Кнопка
    {
      #ifdef I50 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I50, 0xFF); #endif
      #ifdef I51 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I51, 0xFF); #endif
      #ifdef I52 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I52, 0xFF); #endif
      #ifdef I53 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I53, 0xFF); #endif
      #ifdef I54 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I54, 0xFF); #endif
      #ifdef I55 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I55, 0xFF); #endif
    } else
    if(opt(1)==0x61) //Кнопка
    {
      #ifdef I60 if(opt(2)==0x11 || opt(2)==0x10) setStatus(I60, 0xFF); #endif
      #ifdef I61 if(opt(2)==0x21 || opt(2)==0x20) setStatus(I61, 0xFF); #endif
      #ifdef I62 if(opt(2)==0x31 || opt(2)==0x30) setStatus(I62, 0xFF); #endif
      #ifdef I63 if(opt(2)==0x41 || opt(2)==0x40) setStatus(I63, 0xFF); #endif
      #ifdef I64 if(opt(2)==0x51 || opt(2)==0x50) setStatus(I64, 0xFF); #endif
      #ifdef I65 if(opt(2)==0x61 || opt(2)==0x60) setStatus(I65, 0xFF); #endif
    }
  }
}