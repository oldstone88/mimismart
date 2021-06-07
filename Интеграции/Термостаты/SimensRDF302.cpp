/*
{
  desc:"Термостат RS Simens",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
	],
  vars:[
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"COND",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Кондиционер"},
    {name:"SENSOR",type:"hidden",value:"%TARGET%:%SUBID%"},
 ]
}
*/

u32 temp=0;
u8 kond[6];
u8 i[8]={0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0xCC, 0x16};

V-ID/s:5
{
    setStatus(RS485, {0x01, 0x04, 0x03, 0xEA, 0x00, 0x01, 0xCC, 0x16});
}

void chek()
{
  u8 x=temp%50;
  if (x>4) x=125; else x=0; 
  temp=temp/50;
  setStatus(SENSOR,{x, temp});
}

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

V-ID/RS485
{
stat();
temp=opt(3)<<8|opt(4);
srvError("temp=%x", temp);
chek();
}

