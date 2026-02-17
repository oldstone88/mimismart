/*
{
  desc:"Запоминание MimiSmart",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:500,max:599,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {name:"DIMMER09",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"DIMMER10",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"DIMMER11",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"DIMMER12",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
    {name:"DIMMER13",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 13",width:500},
    {name:"DIMMER14",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 14",width:500},
    {name:"DIMMER15",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 15",width:500},
    {name:"DIMMER16",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 16",width:500},
  ]
}
*/

u8 resultOfWrite = 0;

// Запоминание состояний
void remember01(){
	resultOfWrite = eeEmulWrite(88, [DIMMER01.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 88");
	resultOfWrite = eeEmulWrite(89, [DIMMER01.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 89");
}

V-ID/DIMMER01{
	
		cancelDelayedCall(remember01);
		delayedCall(remember01, 1);
	
}

void remember02(){
	resultOfWrite = eeEmulWrite(90, [DIMMER02.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 90");
	resultOfWrite = eeEmulWrite(91, [DIMMER02.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 91");
}

V-ID/DIMMER02{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember02);
		delayedCall(remember02, 1);
	}
}

void remember03(){
	resultOfWrite = eeEmulWrite(92, [DIMMER03.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 92");
	resultOfWrite = eeEmulWrite(93, [DIMMER03.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 93");
}

V-ID/DIMMER03{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember03);
		delayedCall(remember03, 1);
	}
}

void remember04(){
	resultOfWrite = eeEmulWrite(94, [DIMMER04.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 94");
	resultOfWrite = eeEmulWrite(95, [DIMMER04.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 95");
}

V-ID/DIMMER04{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember04);
		delayedCall(remember04, 1);
	}
}

void remember05(){
	resultOfWrite = eeEmulWrite(96, [DIMMER05.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 96");
	resultOfWrite = eeEmulWrite(97, [DIMMER05.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 97");
}

V-ID/DIMMER05{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember05);
		delayedCall(remember05, 1);
	}
}

void remember06(){
	resultOfWrite = eeEmulWrite(98, [DIMMER06.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 98");
	resultOfWrite = eeEmulWrite(99, [DIMMER06.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 99");
}

V-ID/DIMMER06{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember06);
		delayedCall(remember06, 1);
	}
}

void remember07(){
	resultOfWrite = eeEmulWrite(100, [DIMMER07.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 100");
	resultOfWrite = eeEmulWrite(101, [DIMMER07.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 101");
}

V-ID/DIMMER07{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember07);
		delayedCall(remember07, 1);
	}
}

void remember08(){
	resultOfWrite = eeEmulWrite(102, [DIMMER08.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 102");
	resultOfWrite = eeEmulWrite(103, [DIMMER08.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 103");
}

V-ID/DIMMER08{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember08);
		delayedCall(remember08, 1);
	}
}

void remember09(){
	resultOfWrite = eeEmulWrite(104, [DIMMER09.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 104");
	resultOfWrite = eeEmulWrite(105, [DIMMER09.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 105");
}

V-ID/DIMMER09{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember09);
		delayedCall(remember09, 1);
	}
}

void remember10(){
	resultOfWrite = eeEmulWrite(106, [DIMMER10.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 106");
	resultOfWrite = eeEmulWrite(107, [DIMMER10.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 107");
}

V-ID/DIMMER10{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember10);
		delayedCall(remember10, 1);
	}
}

void remember11(){
	resultOfWrite = eeEmulWrite(108, [DIMMER11.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 108");
	resultOfWrite = eeEmulWrite(109, [DIMMER11.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 109");
}

V-ID/DIMMER11{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember11);
		delayedCall(remember11, 1);
	}
}

void remember12(){
	resultOfWrite = eeEmulWrite(110, [DIMMER12.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 110");
	resultOfWrite = eeEmulWrite(111, [DIMMER12.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 111");
}

V-ID/DIMMER12{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember12);
		delayedCall(remember12, 1);
	}
}

void remember13(){
	resultOfWrite = eeEmulWrite(112, [DIMMER13.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 112");
	resultOfWrite = eeEmulWrite(113, [DIMMER13.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 113");
}

V-ID/DIMMER13{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember13);
		delayedCall(remember13, 1);
	}
}

void remember14(){
	resultOfWrite = eeEmulWrite(114, [DIMMER14.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 114");
	resultOfWrite = eeEmulWrite(115, [DIMMER14.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 115");
}

V-ID/DIMMER14{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember14);
		delayedCall(remember14, 1);
	}
}

void remember15(){
	resultOfWrite = eeEmulWrite(116, [DIMMER15.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 116");
	resultOfWrite = eeEmulWrite(117, [DIMMER15.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 117");
}
V-ID/DIMMER15{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember15);
		delayedCall(remember15, 1);
	}
}

void remember16(){
	resultOfWrite = eeEmulWrite(118, [DIMMER16.0]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 118");
	resultOfWrite = eeEmulWrite(119, [DIMMER16.1]);
	if(resultOfWrite == 0) srvError("Ошибка при записи в 119");
}

V-ID/DIMMER16{
	if(senderId()!=exciterId()){
		cancelDelayedCall(remember16);
		delayedCall(remember16, 1);
	}
}

u32 startOnOff = 0;
u32 startBright = 0;
u8 resultOfRead = 0;

void setStartValue(){
	resultOfRead =  eeEmulRead(88, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 88");
	else {
		resultOfRead =  eeEmulRead(89, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 89");
		else setStatus(DIMMER01, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(90, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 90");
	else {
		resultOfRead =  eeEmulRead(91, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 91");
		else setStatus(DIMMER02, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(92, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 92");
	else {
		resultOfRead =  eeEmulRead(93, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 93");
		else setStatus(DIMMER03, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(94, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 94");
	else {
		resultOfRead =  eeEmulRead(95, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 95");
		else setStatus(DIMMER04, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(96, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 96");
	else {
		resultOfRead =  eeEmulRead(97, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 97");
		else setStatus(DIMMER05, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(98, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 98");
	else {
		resultOfRead =  eeEmulRead(99, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 99");
		else setStatus(DIMMER06, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(100, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 100");
	else {
		resultOfRead =  eeEmulRead(101, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 101");
		else setStatus(DIMMER07, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(102, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 102");
	else {
		resultOfRead =  eeEmulRead(103, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 103");
		else setStatus(DIMMER08, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(104, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 104");
	else {
		resultOfRead =  eeEmulRead(105, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 105");
		else setStatus(DIMMER09, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(106, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 106");
	else {
		resultOfRead =  eeEmulRead(107, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 107");
		else setStatus(DIMMER10, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(108, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 108");
	else {
		resultOfRead =  eeEmulRead(109, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 109");
		else setStatus(DIMMER11, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(110, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 110");
	else {
		resultOfRead =  eeEmulRead(111, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 111");
		else setStatus(DIMMER12, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(112, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 112");
	else {
		resultOfRead =  eeEmulRead(113, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 113");
		else setStatus(DIMMER13, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(114, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 114");
	else {
		resultOfRead =  eeEmulRead(115, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 115");
		else setStatus(DIMMER14, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(116, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 116");
	else {
		resultOfRead =  eeEmulRead(117, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 117");
		else setStatus(DIMMER15, {startOnOff, startBright, 0});
	}
	resultOfRead =  eeEmulRead(118, &startOnOff);
	if(resultOfRead == 0) srvError("Ошибка чтения с 118");
	else {
		resultOfRead =  eeEmulRead(119, &startBright);
		if(resultOfRead == 0) srvError("Ошибка чтения с 119");
		else setStatus(DIMMER16, {startOnOff, startBright, 0});
	}
}

void onInit(){
	delayedCall(setStartValue, 3);
}
