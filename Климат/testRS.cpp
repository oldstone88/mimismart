/*
{
  desc:"Оазис",
  tag:"item",
  selectArea:true,
  
  vars:
  [
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 i[8]={0x01, 0x01, 0x01, 0xF6, 0x00, 0x01, 0xCC, 0x16};

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

V-ID/V-ADDR
{
  if(opt(0)==1 || opt(0)==0)
  {
    setStatus(RS485,&i);
    srvError("send");
  }
}

V-ID/RS485
{
  stat();
}