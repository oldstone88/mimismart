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
V-ID/COND{
	u8 data[]={0x19, 0x64, 0x02, 0x00, 0x02, 0x00, 0x00, 0x06, 0x01, 0x02, 0x82, 0x00, 0x00, 0x11, 0x00, 0x4F, 0x03, 0xB8, 0x11, 0x00, 0x0D, 0x01, 0x10,//23
					0x00, 0x40, 0xBF, 0xFF, 0x00, 0xE6, 0x19, 0x89, 0x76, 0x01, 0xFE, 0x3F, 0xC0, 0x1D, 0xE2, 0x16, 0xE9, 0x00, 0xFF, 0x90, 0x6F };//21
	u8 modes[] = {2,6,4,8};
	u8 vanes[] = {0x00, 0x02, 0x06, 0x0A, 0x0C, 0x01};
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
	setStatus(IRT,&data);
}