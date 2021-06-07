/*
{
  desc:"ВeнтБокс",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Установка",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write=0;
u8 kond[6];
u8 i[13]={0x01, 0x10, 0x0114, 0x0002, 0x04, 0x0039, 0x0020, 0xCC, 0x16}; //Скорость-режим-вкл-выкл 8й бит

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
  if( (opt(0)%2)!=0 )
  {
    if((opt(0)==1) && (opt(4)==0)) i[8]=49; else
    if((opt(0)==1) && (opt(4)==1)) i[8]=37; else
    if((opt(0)==1) && (opt(4)==2)) i[8]=41; else
    if((opt(0)==1) && (opt(4)==3)) i[8]=45; else
    if((opt(0)==17) && (opt(4)==0)) i[8]=81; else
    if((opt(0)==17) && (opt(4)==1)) i[8]=69; else
    if((opt(0)==17) && (opt(4)==1)) i[8]=73; else
    if((opt(0)==17) && (opt(4)==2)) i[8]=77; 
    i[10]=opt(1)+10;
  } else 
  if( (opt(0)%2)==0 )
  {
    i[8]=i[8]&0xFE;
  }
  if (write==0) {setStatus(RS485, &i); srvError("i=%d", opt(0));} else write=0;
}

V-ID/s:10
{
  setStatus(RS485,{0x01, 0x03, 0x0114, 0x00, 0x02, 0xCC, 0x16}); //Скорость и включение
}

void check()
{
  getStatus(K00, &kond);
  if( (opt(4)%2)!=([K00.0]%2) ) 
    {
      if( (opt(4)%2!=0) && (opt(4)<66) ) {kond[0]=1;} else
      if( (opt(4)%2!=0) && (opt(4)>66) ) {kond[0]=17;} else
      {kond[0]=0; setStatus(K00, &kond);}
      write=1;
    }
  if( (kond[1]+10)!=opt(6))
    {
      kond[1]=opt(6)-10;
      write=1;
    }
  if (write==1) {
    srvError("Синхронизация");
    setStatus(K00, &kond);
  }
}

V-ID/RS485
{
  if (optl==9) check();
  stat();
}

