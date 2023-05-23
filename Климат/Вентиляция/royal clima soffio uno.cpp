/*
{
  desc:"Soffio Uno",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
		{tag:"item", id:"%TARGET%", name:"Вентиляция", "sub-id":"%SUBID99%", type:"conditioner", "t-delta":"3", "t-min":"0", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"В комнате", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"На улице", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Вытяжка", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Разморозка", "sub-id":"%SUBID91%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
	],
  vars:[
   {type:"comment", style:"color:red", text:"Заполните поля:"},
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID99%"},
    {name:"ROOM",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"STREET",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"EXHAUST",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"DEFROSTING",type:"hidden",value:"%TARGET%:%SUBID91%"},
 ]
}
*/

u8 stopread=0;

V-ID/COND00{
	if(senderId()!=exciterId()){
		stopread=1;
		if([COND00.0]%2==1){
			u8 speed=0;
			if([COND00.1]==1) speed=2;
			else if([COND00.1]==2) speed=3;
			else if([COND00.1]==3) speed=5;
			else speed=0;
			u8 write[15]={0x01, 0x10, 0x00, 0x09, 0x00, 0x03, 0x06, 0x00, ([COND00.0]&1), 0x00, speed, 0x00, speed, 0xCC, 0x16};
			setStatus(RS485, &write);
		}
		else{
			u8 write[8]={0x01, 0x06, 0x00, 0x09, 0x00, 0x00, 0xCC, 0x16};
			setStatus(RS485, &write);
		}
	}
}

void stat(){
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

V-ID/s:5{
	if(stopread==0){
		u8 read[8]={0x01, 0x03, 0x00, 0x09, 0x00, 0x07, 0xCC, 0x16};
		setStatus(RS485, &read);
	}
	else stopread=0;
}

void transformSpeed(u8 speed){
	if(speed==2) speed=1;
	else if(speed==3) speed=2;
	else if(speed==5) speed=3;
	else speed=0;
	return speed;
}

V-ID/RS485{
	//stat();
	if(opt(0)==1 && optl==19){
		u8 condStatus[5]={0, 0, 0, 0, 0};
		condStatus[0]=opt(4);
		condStatus[1]=transformSpeed(opt(6));
		setStatus(COND00, &condStatus);
		//В комнате
		i8 temp[2]={0, (opt(10)-40)};
		setStatus(ROOM, &temp);
		//На улице
		temp[1]=opt(12)-40;
		setStatus(STREET, &temp);
		//Вытяжной воздух
		temp[1]=opt(14)-40;
		setStatus(EXHAUST, &temp);
		//Температура разморозки
		temp[1]=opt(16)-40;
		setStatus(DEFROSTING, &temp);
	}
}