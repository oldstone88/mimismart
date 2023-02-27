/*
{
  desc:"Термостат RS LCF Touch",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID99%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID95%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID91%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID87%", type:"conditioner", "t-delta":"14", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00"},
		{tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID85%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
	],
  vars:[
   {type:"comment", style:"color:red", text:"АДРЕССА ТЕРМОСТАТОВ ДОЛЖНЫ СТРОГО НАЧИНАТЬСЯ С 1 И ИДТИ ПО ПОРЯДКУ!!!"},
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"SENSOR00",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"COND00",type:"hidden",value:"%TARGET%:%SUBID99%"},
    {name:"SENSOR01",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"COND01",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"SENSOR02",type:"hidden",value:"%TARGET%:%SUBID89%"},
    {name:"COND02",type:"hidden",value:"%TARGET%:%SUBID91%"},
    {name:"SENSOR03",type:"hidden",value:"%TARGET%:%SUBID85%"},
    {name:"COND03",type:"hidden",value:"%TARGET%:%SUBID87%"},
 ]
}
*/

const u16 ID [] = {
    ADDR2ID(COND00),
    ADDR2ID(COND01),
    ADDR2ID(COND02),
    ADDR2ID(COND03)
};

const u8 SID [] = {
    ADDR2SID(COND00),
    ADDR2SID(COND01),
    ADDR2SID(COND02),
    ADDR2SID(COND03)
};

V-ID/COND00, COND01, COND02, COND03
{
	if(senderId()!=exciterId()){
		for(u8 i=0; i<4; ++i){
			if(SID[i]==senderSubId()){
				u8 send[17]={i+1, 0x10, 0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
				//Режим
				if((opt(0)>>4)==0) send[8]=0x04;
				else if((opt(0)>>4)==1) send[8]=0x01;
				else if((opt(0)>>4)==2) send[8]=0x08;
				//ВКЛ-ВЫКЛ
				send[14]=opt(0)%2;
				//Скорость
				if(opt(4)==0) send[10]=0x02;
				else if(opt(4)==1) send[10]=0x04;
				else if(opt(4)==2) send[10]=0x08;
				//Температура
				send[11]=((opt(1)+16)*10)<<8;
				send[12]=((opt(1)+16)*10);
				//Отправка
				setStatus(RS485, &send);
			}
		}
	}
}


//Чтение уставки
u8 countRead=0;

V-ID/s:1
{
	u8 read[8]={0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0xCC, 0x16};
	if(countRead==0) {read[0]=1; setStatus(RS485, &read); countRead=1;}
	else if(countRead==1) {read[0]=2; setStatus(RS485, &read); countRead=2;}
	else if(countRead==2) {read[0]=3; setStatus(RS485, &read); countRead=3;}
	else if(countRead==3) {read[0]=4; setStatus(RS485, &read); countRead=0;}
}


//Обработка уставок термостата
void setParamsToAPP(u8 IDC, u8 ONOFF, u8 MODE, u16 TEMP, u8 SPEED)
{
	u8 tempmode=0;
	u8 mass[5];
	//Режим и ВКЛ-ВЫКЛ
	mass[0]= ONOFF?1:0;
	if(MODE==1) tempmode=1;
	else if(MODE==4) tempmode=0;
	else if(MODE==8) tempmode=2;
	mass[0]=tempmode<<4|mass[0];
	//Температура
	mass[1]=(TEMP/10)-16;
	//Скорость
	if(SPEED==2) mass[4]=0;
	else if(SPEED==4) mass[4]=1;
	else if(SPEED==8) mass[4]=2;
	//Уставка
	for(u8 i=0; i<5; ++i){
		if((IDC-1)==i) setStatus(@ID[i]:@SID[i], &mass);
	}
}

void stat()
{
	u8 res[100]="";
    u8 *st = opt;
    u8 i = 0;
    sprintf(res,"%d ",optl);
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), " %d", st[i]);
    }
    sprintf(res+strlen(res), "\10");
    srvError(&res);
}

V-ID/RS485
{
	stat();
	if(opt(1)==3 && optl==13) {setParamsToAPP(opt(0), opt(10), opt(4), (opt(7)<<8)|opt(8), opt(6));}
}
