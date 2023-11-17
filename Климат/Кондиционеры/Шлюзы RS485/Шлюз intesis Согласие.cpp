/*
{
  desc:"INMBSMIT050C000",
  tag:"import-script",
  selectArea:true,
  name:"Шлюз Intesis",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер1", sub-id:"%SUBID01%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер2", sub-id:"%SUBID02%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер3", sub-id:"%SUBID03%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер4", sub-id:"%SUBID04%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер5", sub-id:"%SUBID05%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер6", sub-id:"%SUBID06%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер7", sub-id:"%SUBID07%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер8", sub-id:"%SUBID08%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
    {tag:"item", id:"%TARGET%", name:"Кондиционер9", sub-id:"%SUBID09%", type:"conditioner",funs:"0x0e",t-min:"19",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
  ],
  vars:
  [
    {name:"RS485",type:"devices-list",required:false,width:600,filter:["com-port"],desc:"RS",descWidth:100},
    {name:"COND1",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"COND2",type:"hidden",value:"%TARGET%:%SUBID02%"},
    {name:"COND3",type:"hidden",value:"%TARGET%:%SUBID03%"},
    {name:"COND4",type:"hidden",value:"%TARGET%:%SUBID04%"},
    {name:"COND5",type:"hidden",value:"%TARGET%:%SUBID05%"},
    {name:"COND6",type:"hidden",value:"%TARGET%:%SUBID06%"},
    {name:"COND7",type:"hidden",value:"%TARGET%:%SUBID07%"},
    {name:"COND8",type:"hidden",value:"%TARGET%:%SUBID08%"},
    {name:"COND9",type:"hidden",value:"%TARGET%:%SUBID09%"},
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

u8 read[8]={0x01, 0x03, 0x00, 0x64, 0x00, 0x01, 0xCC, 0x16};
u8 write[19]={0x01, 0x10, 0x00, 0x00, 0x00, 0x05, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

const u16 ID [] = {
    ADDR2ID(COND1)
    #ifdef COND2, ADDR2ID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2ID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2ID(COND4) #else ,0 #endif
    #ifdef COND5, ADDR2ID(COND5) #else ,0 #endif
    #ifdef COND6, ADDR2ID(COND6) #else ,0 #endif
    #ifdef COND7, ADDR2ID(COND7) #else ,0 #endif
    #ifdef COND8, ADDR2ID(COND8) #else ,0 #endif
    #ifdef COND9, ADDR2ID(COND8) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(COND1)
    #ifdef COND2, ADDR2SID(COND2) #else ,0 #endif
    #ifdef COND3, ADDR2SID(COND3) #else ,0 #endif
    #ifdef COND4, ADDR2SID(COND4) #else ,0 #endif
    #ifdef COND5, ADDR2SID(COND5) #else ,0 #endif
    #ifdef COND6, ADDR2SID(COND6) #else ,0 #endif
    #ifdef COND7, ADDR2SID(COND7) #else ,0 #endif
    #ifdef COND8, ADDR2SID(COND8) #else ,0 #endif
    #ifdef COND9, ADDR2SID(COND9) #else ,0 #endif
};

V-ID/COND1, COND2, COND3, COND4, COND5, COND6, COND7, COND8, COND9
{
  if(senderId()!=exciterId())
  {
    for(u8 i=0;i<9;++i)
    {
      if(ID[i] && SID[i] && SID[i]==senderSubId())
      {
        //Определяем адрес
        write[2]=((i*100)+100)>>8;
        write[3]=((i*100)+100);
        //ВКЛ-ВЫКЛ
        write[8]=opt(0)%2;
        //Режимы
        if((opt(0)>>4)==0) write[10]=3;
        else if((opt(0)>>4)==1) write[10]=4;
        else write[10]=opt(0)>>4;
        //Cкорость
        write[12]=opt(4);
        //Температура
        write[15]=(opt(1)+19)*10>>8;
        write[16]=(opt(1)+19)*10;
        setStatus(RS485, &write);
      }
    }
  }
}

u8 counter=0;

V-ID/s:1
{
  u16 addr=(counter*100)+100;
  u8 HI=counter>>8;
  u8 LOW=counter;
  u8 read[8]={counter, 0x03, HI, LOW, 0x00, 0x05, 0xCC, 0x16};
  ++counter;
}

void convert()
{
  
}

V-ID/RS485
{
  stat();
  u8 cond[5]={0, 0, 0, 0, 0}
  if(opt(0)==1 && opt(1)==0x03 && optl==15)
  {
    if(counter==1) {};
    else(counter==2) {};
    else(counter==3) {};
    else(counter==4) {};
    else(counter==5) {};
    else(counter==6) {};
    else(counter==7) {};
    else(counter==8) {};
    else(counter==9) {};
  }
}