/*
{
  desc:"ВКЛ-ВЫКЛ Daikin",
  tag:"item",
  target:"IRT",
  name:"ВЫКЛ.КОНД",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"ВКЛ.КОНД", sub-id:"%SUBID01%", type:"script"},
  ],
  vars:[
 {name:"IRT",type:"devices-list",required:true,filter:["ir-transmitter"],desc:"ИК-передатчик"},
 {name:"COND",type:"devices-list",required:true,filter:["conditioner"],desc:"Кондиционер"},
 {name:"VKL",type:"hidden",value:"%TARGET%:%SUBID01%"}

  ]
}
*/

u8 OFF[]={0x19640b000200c10601011000000306108a0d0000023f8a010280000010f6500340108a0d11da2700c55000270002428b010280000010f6500340108b0d11da2700420000540002608c010280000010f5500398108b0d11da27000048c032a0000006600000c1000114};
u8 ON[]={0x19640B000200C10601011000000306108A0D0000023F8A010280000010F6500340108A0D11DA2700C55000270002428B010280000010F6500340108B0D11DA2700420000540002608C010280000010F5500398108B0D11DA270000392800A0000006600000C100003A};
u8 i[5];

void SBROS()
{
	if(([V-ADDR.0]&1)==1) setStatus(V-ADDR, 0);
	if(([VKL.0]&1)==1) setStatus(VKL, 0);
}

V-ID/V-ADDR
{
	if((opt(0)&1)==1)
	{
		if(([COND.0]%2)==1){getStatus(COND, &i); i[0]=i[0]&0xFE; setStatus(COND, &i);} else
		if(([COND.0]%2)==0)setStatus(IRT, &OFF);
		delayedCall(SBROS, 1);
	}
}

V-ID/VKL
{
	if((opt(0)&1)==1)
	{
		if(([COND.0]%2)==0){getStatus(COND, &i); i[0]=i[0]|0x01; setStatus(COND, &i);} else
		if(([COND.0]%2)==1)setStatus(IRT, &ON);
		delayedCall(SBROS, 1);
	}
}