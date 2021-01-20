/*
{
  desc:"Скрипт для пульта Mitsubishi TYPE SG15D 0838",
  tag:"import-script",
  target:"IRT",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"15", "t-min":"16", "modes":"0x1F", "funs":"0x1F", "vane-hor":"0x00", "vane-ver":"0x7F"},
  ],
  vars:[
    {name:"IRT",type:"devices-list",required:true,filter:["ir-transmitter"],desc:"ИК-передатчик"},
    {name:"NAME",type:"string",required:true,min:3,max:40,desc:"COND",defaultValue:"Кондиционер"},
    {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
  ]
}
*/
u8 data[]={0x1964040002008F06010280000010B14E0390101F0D23CB26010020000036000000000000000000010280DAB710B14E0390101F0D23CB26010020180036000000000000000000};


V-ID/COND{
	u8 on_of[]={0x00,0x20};
	u8 mode[]={0x38,0x18,0x10,0x08,0x20};
	u8 van_mode[]={0x40,0x48,0x50,0x58,0x60,0x68,0x78};
	u8 van_fan_st=van_mode[opt(3)>>4]+opt(4);
	u8 temp=opt(1);
	u8 summ=0;
	data[26]=on_of[opt(0)&1];
	data[27]=mode[opt(0)>>4];
	data[28]=temp;
	data[30]=van_fan_st;
	if(data[27]==0x20)
		data[28]=0x00;
	if(data[27]==0x10)
	{
		data[28]=0x08;
		data[29]=0x32;
	}
	if(data[27]==0x38)
	{
		data[28]=0x08;
		data[29]=0x30;
	}
	if(data[27]==0x08)
		data[29]=0x30;
	if(data[27]==0x18)
		data[29]=0x36;
	
	data[30]=van_fan_st;
	for(u8 i=26;i<38;++i)
		summ+=data[i];
	data[38]=summ+0x15;
	data[57]=data[26];
	data[58]=data[27];
	data[59]=data[28];
	data[61]=data[30];
	data[69]=data[38];
	
	setStatus(IRT,&data);
    srvError("Status set on IRT");	
}
