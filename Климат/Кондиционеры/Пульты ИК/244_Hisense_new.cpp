/*
{
  desc:"Скрипт для кондиционера HISENSE",
  tag:"import-script",
  selectArea:true,
  target:"IRT",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"13", "t-min":"17", "vane-ver":"0x7E", "vane-hor":"0x00", "modes":"0xF", "funs":"0xF"},
  ],
  vars:[
    {name:"IRT",type:"devices-list",required:true,filter:["ir-transmitter"],desc:"ИК-передатчик"},
    {name:"NAME",type:"string",required:true,min:3,max:40,desc:"COND",defaultValue:"Кондиционер"},
    {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
  ]
}
*/

u8 j[5];

void onInit()
{
  getStatus(COND, &j);
}

V-ID/COND{
  u8 data[]={0x19, 0x64, 0x02, 0x00, 0x02, 0x00, 0x00, 0x06, 0x01, 0x02, 0x82, 0x00, 0x00, 0x11, 0x00, 0x4F, 0x03, 0xB8, 0x11, 0x00, 0x0D, 0x01, 0x10,//23
          0x00, 0x40, 0xBF, 0xFF, 0x00, 0xE6, 0x19, 0x89, 0x76, 0x01, 0xFE, 0x3F, 0xC0, 0x1D, 0xE2, 0x16, 0xE9, 0x00, 0xFF, 0x90, 0x6F };//21
  
  if(j[0]!=[COND.0] || j[3]!=[COND.3])
  {
    u8 modes[] = {2,6,4,8};
    u8 vanes[] = {0x00, 0x02, 0x04, 0x06, 0x08, 0x01};
    u8 onOff = 0xA0;
    if(opt(0)&0x01==1) onOff=0x90;
    u8 temp = 13 + (opt(1)+4)*2;
    u8 vane = vanes[(opt(3)>>4)];
    u8 mode = modes[opt(0)>>4];
    u8 fan = (opt(4)&0x0F)+1;
    if(fan==3) ++fan;
    data[36] = temp;
    data[37] = ~temp;
    data[38] = (fan<<4)|mode;
    data[39] = ~((fan<<4)|mode);
    data[40] = vane;
    data[41] = ~vane;
    data[42] = onOff;
    data[43] = ~onOff;
    getStatus(COND, &j);
    setStatus(IRT,&data);
  } else
  if(j[4]!=[COND.4])
  {
    u8 speed[38]={0x1964020002007E060102800000106B4F0388104E0D01100040BFFF00E31C897605FA3FC08679};
    if(opt(4)==1) {speed[36]=0x16; speed[37]=0xE9;}
    else if(opt(4)==2) {speed[36]=0x26; speed[37]=0xD9;}
    else if(opt(4)==3) {speed[36]=0x46; speed[37]=0xB9;}
    setStatus(IRT, &speed);
    getStatus(COND, &j);
  }
  else
  {
    u8 settemp[]={0x1964020002008606010281000010834F038810510D01100040BFFF00E31C897609F63FC01DE2};
    u8 temp = 13 + (opt(1)+4)*2;
    settemp[36] = temp;
    settemp[37] = ~temp;
    setStatus(IRT, &settemp);
  }
  
}