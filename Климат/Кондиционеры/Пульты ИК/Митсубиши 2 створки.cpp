/*
{
  desc:"Скрипт для пульта Mitsubishi TYPE XG16A 31A7 ",
  tag:"import-script",
  target:"IRT",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"15", "t-min":"16", "modes":"0x1F", "funs":"0x1F", "vane-hor":"0x00", "vane-ver":"0x7E"},
  ],
  vars:[
    {name:"IRT",type:"devices-list",required:true,filter:["ir-transmitter"],desc:"ИК-передатчик"},
    {name:"NAME",type:"string",required:true,min:3,max:40,desc:"COND",defaultValue:"Кондиционер"},
    {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
  ]
}
*/
V-ID/COND{
    u8 on_of[]={0x00,0x20};
    u8 data[]={0x1964040002008C060102800000109F4E0328101C0D23CB2601000102806294109E4E0390101C0D23CB26010000000036000000000010000013};
    u8 mode[]={0x38,0x58,0x50,0x48,0x60};
    u8 l_van_mode[]={0x08,0x10,0x18,0x20,0x28,0x38};
    u8 r_van_mode[]={0x48,0x50,0x58,0x60,0x68,0x78};
    u8 fan_st=0x40+opt(4);
    u8 temp=opt(1);
    u8 summ=0;
    data[44]=on_of[opt(0)&1];
    data[45]=mode[opt(0)>>4];
    data[46]=temp;
    data[48]=fan_st | r_van_mode[opt(3)>>4];
    data[55]=l_van_mode[opt(3)>>4];
    if(data[45]==0x50)
    {
        data[46]=0x08;
        data[47]=0x32;
    }
    if(data[45]==0x38)
    {
        data[46]=0x08;
        data[47]=0x30;
    }
    if(data[45]==0x48)
        data[47]=0x30;
    if(data[45]==0x58)
        data[47]=0x36;
    for(u8 i=44;i<56;++i)
        summ+=data[i];
    data[56]=summ-0xEB;
    setStatus(IRT,&data);
    u8 buffer[250];

}
