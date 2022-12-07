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
    {name:"I10",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"I20",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"I30",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"I40",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"I50",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"I60",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
    {name:"J01",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 1",descWidth:100},
    {name:"J02",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 2",descWidth:100},
    {name:"J03",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 3",descWidth:100},
    {name:"J04",type:"devices-list",required:false,width:600,filter:["virtual"],desc:"Штора 4",descWidth:100},
    {name:"J05",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 5",descWidth:100},
    {name:"J06",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 6",descWidth:100},
    {name:"J07",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 7",descWidth:100},
    {name:"J08",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 8",descWidth:100},
    {name:"J09",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Штора 9",descWidth:100},
    {name:"J10",type:"devices-list",required:false,width:600,filter:["virtual"],desc:"Штора 10",descWidth:100},
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
      getStatus(COND1, &k);
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
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I10, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I10, &k);}} 
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I10, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I10, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND1, &k); k[0]=((~k[0])&1); setStatus(COND1, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I10, &k); k[0]=((~k[0])&1); setStatus(I10, &k);}
      if(opt(2)==0x51 || opt(2)==0x50) {setStatus(J02, 0xFF); setStatus(J03, 0xFF); setStatus(J04, 0xFF); setStatus(J05, 0xFF);}
      if(opt(2)==0x61 || opt(2)==0x60) {setStatus(J06, 0xFF);}
      if(opt(2)==0x71 || opt(2)==0x70) setStatus(J10, 1);
      if(opt(2)==0x81 || opt(2)==0x80) setStatus(J10, 0);
    } else
    if(opt(1)==0x21) //Кнопка
    {
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I20, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I20, &k);}}
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I20, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I20, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND2, &k); k[0]=((~k[0])&1); setStatus(COND2, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I20, &k); k[0]=((~k[0])&1); setStatus(I20, &k);}
      if(opt(2)==0x51 || opt(2)==0x50) {setStatus(J07, 0xFF); setStatus(J08, 0xFF);}
      if(opt(2)==0x61 || opt(2)==0x60) {setStatus(J09, 0xFF);}
      if(opt(2)==0x71 || opt(2)==0x70) setStatus(J10, 1);
      if(opt(2)==0x81 || opt(2)==0x80) setStatus(J10, 0);
    } else
    if(opt(1)==0x31) //Кнопка
    {
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I30, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I30, &k);}} 
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I30, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I30, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND3, &k); k[0]=((~k[0])&1); setStatus(COND3, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I30, &k); k[0]=((~k[0])&1); setStatus(I30, &k);}
      //if(opt(2)==0x51 || opt(2)==0x50) {setStatus(I34, 0xFF);}
      //if(opt(2)==0x61 || opt(2)==0x60) {setStatus(I35, 0xFF);}
    } else
    if(opt(1)==0x41) //Кнопка
    {
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I40, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I40, &k);}}
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I40, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I40, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND4, &k); k[0]=((~k[0])&1); setStatus(COND4, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I40, &k); k[0]=((~k[0])&1); setStatus(I40, &k);}
      //if(opt(2)==0x51 || opt(2)==0x50) setStatus(I44, 0xFF);
      //if(opt(2)==0x61 || opt(2)==0x60) setStatus(I45, 0xFF);
    } else
    if(opt(1)==0x51) //Кнопка
    {
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I50, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I50, &k);}}
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I50, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I50, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND5, &k); k[0]=((~k[0])&1); setStatus(COND5, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I50, &k); k[0]=((~k[0])&1); setStatus(I50, &k);}
      //if(opt(2)==0x51 || opt(2)==0x50) setStatus(I54, 0xFF);
      //if(opt(2)==0x61 || opt(2)==0x60) setStatus(I55, 0xFF);
    } else
    if(opt(1)==0x61) //Кнопка
    {
      if(opt(2)==0x11 || opt(2)==0x10) {getStatus(I60, &k); if(k[1]>1) {k[1]=k[1]-1; setStatus(I60, &k);}}
      if(opt(2)==0x21 || opt(2)==0x20) {getStatus(I60, &k); if(k[1]<39) {k[1]=k[1]+1; setStatus(I60, &k);}}
      if(opt(2)==0x31 || opt(2)==0x30) {getStatus(COND6, &k); k[0]=((~k[0])&1); setStatus(COND6, &k);}
      if(opt(2)==0x41 || opt(2)==0x40) {getStatus(I60, &k); k[0]=((~k[0])&1); setStatus(I60, &k);}
      //if(opt(2)==0x51 || opt(2)==0x50) setStatus(I64, 0xFF);
      //if(opt(2)==0x61 || opt(2)==0x60) setStatus(I65, 0xFF);
    }
  }
}