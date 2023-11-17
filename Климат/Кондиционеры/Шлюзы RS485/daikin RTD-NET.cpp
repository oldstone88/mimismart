/*
{
  desc:"Скрипт управления платой RTD-NET Daikin по RS485 (добавляет 6 кондиционеров, ненужные потом удалить вручную) (настройки RS485: 9600, stop 1, no parity)",
  tag:"import-script",
  target:"RS485",
  selectArea:"true",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер1", sub-id:"%SUBID01%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер2", sub-id:"%SUBID02%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер3", sub-id:"%SUBID03%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер4", sub-id:"%SUBID04%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер5", sub-id:"%SUBID05%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер6", sub-id:"%SUBID06%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер7", sub-id:"%SUBID07%", type:"conditioner",modes:"0xA",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0",vane-ver:"0"},
  ],
  vars:[
	{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
	{name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:63,desc:"ID1 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID2",type:"number",required:false,min:1,max:63,desc:"ID2 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID3",type:"number",required:false,min:1,max:63,desc:"ID3 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID4",type:"number",required:false,min:1,max:63,desc:"ID4 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID5",type:"number",required:false,min:1,max:63,desc:"ID5 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID6",type:"number",required:false,min:1,max:63,desc:"ID6 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID7",type:"number",required:false,min:1,max:63,desc:"ID7 пульта (для протокола Modbus)",descWidth:350},
	{name:"COND1",type:"hidden",value:"%TARGET%:%SUBID01%"},
	{name:"COND2",type:"hidden",value:"%TARGET%:%SUBID02%"},
	{name:"COND3",type:"hidden",value:"%TARGET%:%SUBID03%"},
	{name:"COND4",type:"hidden",value:"%TARGET%:%SUBID04%"},
	{name:"COND5",type:"hidden",value:"%TARGET%:%SUBID05%"},
	{name:"COND6",type:"hidden",value:"%TARGET%:%SUBID06%"},
	{name:"COND7",type:"hidden",value:"%TARGET%:%SUBID07%"},
  ]
}
*/

//u8 cmnd_wr1[19]={ID1,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16};
u8 cmnd_wr[19]={ID1,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16};
#define IDS ID1
#ifdef ID2 
	//u8 cmnd_wr2[19]={ID2,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID2 
#endif
#ifdef ID3 
	//u8 cmnd_wr3[19]={ID3,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID3 
#endif
#ifdef ID4 
	//u8 cmnd_wr4[19]={ID4,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID4 
#endif
#ifdef ID5 
	//u8 cmnd_wr5[19]={ID5,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID5 
#endif
#ifdef ID6 
	//u8 cmnd_wr6[19]={ID6,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID6 
#endif
#ifdef ID7 
	//u8 cmnd_wr7[19]={ID7,0x10000100050A,0x0010,0x0001,0x0001,0x0001,0x0000,0xcc16}; 
	#define IDS IDS,ID7 
#endif
u8 change[7] = {0,0,0,0,0,0,0};
u8 ids[] = {IDS};
#define SCRIPT_ID 2
#define CHANGE_ID 0x80
#define SYNC_ID 3
u8 syncFlag = 0;
u8 syncIndex = 0;

void onInit() {
	srvMessage("---------------------------STATRT INIT---------------------------");
}
/*void genCMND(u8* _cmnd, u8* _opt, u8 optl, u8 _syncFlag, u16 _id, u8 _sid)
{
	if (syncFlag == _syncFlag && _opt[2] == 0) {
		syncFlag = 0;
		return;
	} else if ((_opt[2] & 0x80) == CHANGE_ID) {
		syncFlag = _syncFlag;
		if ((_opt[2] & 0x7F) == SCRIPT_ID) {
			setStatus(@_id:@_sid, {_opt[0], _opt[1], 0, _opt[3], _opt[4]});
		}
		return;
	} else if (_opt[2] == SCRIPT_ID) {
		u8 sendFlag = CHANGE_ID | SCRIPT_ID;
		setStatus(@_id:@_sid, {_opt[0], _opt[1], sendFlag, _opt[3], _opt[4]});
		return;
	} else if (!(_opt[2] == 0 || _opt[2] == SCRIPT_ID)) return;
	u8 isOn = (_opt[0] & 0x01);
	u8 m = (_opt[0] >> 4);
	u8 t = (_opt[1]+16);
	u8 f = (_opt[4]) + 1;		
	_cmnd[16] = isOn;
	_cmnd[8] = t;
	_cmnd[10] = f;
	_cmnd[12] = m;
	if(!m)
	{
		_cmnd[12] = 3;
	}
	if((_syncFlag - 1) < sizeof(ids))
		change[--_syncFlag] = 1;
}*/
V-ID/COND1
{	
	cmnd_wr[0]=ID1;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}

#ifdef ID2
V-ID/COND2
{
	cmnd_wr[0]=ID2;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

#ifdef ID3
V-ID/COND3
{
	cmnd_wr[0]=ID3;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

#ifdef ID4
V-ID/COND4
{	
	cmnd_wr[0]=ID4;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

#ifdef ID5
V-ID/COND5
{
	cmnd_wr[0]=ID5;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

#ifdef ID6
V-ID/COND6
{
	cmnd_wr[0]=ID6;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

#ifdef ID7
V-ID/COND7
{
	cmnd_wr[0]=ID7;
	cmnd_wr[16]=opt(0)&1;
	cmnd_wr[8]=opt(1)+16;
	cmnd_wr[10]=opt(4)+1;
	cmnd_wr[12]=opt(0)>>4;
	if (cmnd_wr[12]==0) cmnd_wr[12]=3;
	else cmnd_wr[12]=1;
	setStatus(RS485, &cmnd_wr);
}
#endif

V-ID/s:5 {
	setStatus(RS485, {ids[syncIndex], 0x03, 0x0001, 0x0005, 0xCC16});
	if(syncIndex < sizeof(ids))
	{
		++syncIndex;
	}
	else
	{
		syncIndex = 0;
	}
}

void stat(){
	u8 res[100]="";
	u8 *st = opt;
	u8 i = 0;
	sprintf(res,"%d ",optl);
	for(i = 0; i < optl; ++i){
		sprintf(res+strlen(res), "%.2X ", st[i]);
	}
	sprintf(res+strlen(res), "\10");
	srvError(&res);
}

V-ID/RS485
{
		stat();
		if (opt(1) == 0x03) {
		u8 data[4];
		data[0] = opt(12); //Вкл-Выкл
		data[1] = opt(8); //Режим
		if (data[1] == 3) {data[1] = 0;}
		if(opt(4)>=16) data[2] = opt(4) - 16; else {data[2] = 1; srvError("Сбой температуры, кондиционер выдал = %d", opt(4));} //Скорость
		if(opt(6)>0) data[3] = opt(6) - 1; else data[3] = 0;
		if (opt(0) == ID1) {
			setStatus(COND1, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#ifdef ID2 else if (opt(0) == ID2) {
			setStatus(COND2, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif 
		#ifdef ID3 else if (opt(0) == ID3) {
			setStatus(COND3, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif 
		#ifdef ID4 else if (opt(0) == ID4) {
			setStatus(COND4, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif 
		#ifdef ID5 else if (opt(0) == ID5) {
			setStatus(COND5, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif 
		#ifdef ID6 else if (opt(0) == ID6) {
			setStatus(COND6, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif 
		#ifdef ID7 else if (opt(0) == ID7) {
			setStatus(COND7, {data[0] | (data[1] << 4), data[2], 0, 0, data[3]});
		}
		#endif
	}
}

