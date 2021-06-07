/*
{
  desc:"eAirMD",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Установка",descWidth:100},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 kond[5];
u8 write=0;
u8 state[8]={0x01, 0x06, 0x0087, 0x00D2, 0xCC, 0x16};

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
  if(opt(0)%2==0)
  {
    getStatus(K00, &kond);
    kond[0]=kond[0]|1;
    setStatus(K00, &kond);
  } else
  if(opt(0)%2==1 && write==0)
  {
    state[4]=(((opt(1)+15)*10)>>8);
    state[5]=(((opt(1)+15)*10)&0xFF);
    setStatus(RS485, &state);
  } else write=0;
}

V-ID/s:10
{
  setStatus(RS485,{0x01, 0x03, 0x0087, 0x00, 0x01, 0xCC, 0x16}); //Скорость
}

void check()
{
  u16 temp=opt(3)<<8;
  temp=temp|opt(4);
  if(temp!=(([K00.1]+15)*10))
    {
      getStatus(K00, &kond);
      kond[1]=((temp/10)-15);
      write=1;
      setStatus(K00, &kond);
      srvError("Синхронизация");
    }
}

V-ID/RS485
{
  if(optl==7)
  {
    check();
  }
  //stat();
}

