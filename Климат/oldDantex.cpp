/*
{
  desc:"dantex шлюз",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"ID00", type:"number", defaultValue:5, required:true, desc:"ID кондиционера"},
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write=0;
u8 on[9];
u8 r[8]={0x01, 0x03, 0x00, 0x01, 0x00, 0x03, 0xCC, 0x16};
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
  j=0;
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
  if( (opt(0)%2==0) && write==0 ) //Выключение
  {
    w[8]=0x00;
    setStatus(RS485, &w);
    write=1;
  } else
  if( (opt(0)%2!=0) && write==0)
  {
    w[8]=rezimw(opt(0));
    w[10]=speedw(opt(4));
    w[12]=[K00.1]+16;
    setStatus(RS485, &w);
    write=1;
  }
}



V-ID/s:5
{
  if (write==0) setStatus(RS485, &r);
}

//Обратная связь
void check(u8 vkl, u8 ckopoct, u8 temp)
{
  u8 prov[5];
  getStatus(K00, &prov);
  if(rezimr(vkl)!=prov[0]) {write=2; prov[0]=rezimr(vkl);}
  if(speedr(ckopoct)!=prov[4]) {write=2; prov[4]=speedr(ckopoct);}
  if((temp-16)!=prov[1]) {write=2; prov[1]=temp-16;}
  if(write==2) {setStatus(K00, &prov);}
}

//Вывод
V-ID/RS485
{
  if(optl==37 && write==0)
  {
    check(opt(4))
  }
  stat();
}
