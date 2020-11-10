/*
{
  desc:"Счетчик импульсов",
  tag:"import-script",
  name:"Очистить показания",
  target:"COUNTER",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"%NAME%", sub-id:"%SUBID%", type:"virtual", length:"0", sub-type:"long-text"}
  ],
  vars:[
 	{name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя счетчика",defaultValue:"Счетчик Воды",descWidth:350},
	{name:"COUNTER",type:"devices-list",required:true,filter:["door-sensor"],desc:"геркон",descWidth:350},
	{name:"STVALUE",type:"number",required:true,defaultValue:0,min:0,max:10000,filter:"0123456789",desc:"Начальное значение",descWidth:350},
	{name:"CLICKS",type:"number",required:true,defaultValue:100,min:1,max:10000,desc:"Кол-во импульсов на еденицу измерения",descWidth:350},
	{name:"PERIOD",type:"number",required:true,defaultValue:1,min:1,max:1440,desc:"Период сохранения данных в минутах",descWidth:350},
	{name:"MINCL",type:"number",required:true,defaultValue:1,min:0,max:100000,desc:"Минимальнок кол-во импульсов для сохранения (0 не сохранять дробные)",descWidth:350},
	{name:"MAXCL",type:"number",required:true,defaultValue:10,min:0,max:100000,desc:"Принудительное сохранение по достижению кол-ва кликов (0 - без принудительного сохранения)",descWidth:350},	
	{name:"EEADDR",type:"number",required:true,defaultValue:1,min:1,max:50,desc:"Номер ячейки для хранения данных",descWidth:350},
	{name:"VIRT",type:"hidden",value:"%TARGET%:%SUBID%"}
  ]
}
*/

u32 value;
u32 svalue;
u32 eeval;
u32 eesval;
u32 t = 0;
u8 data[32];
/*
V-ID/V-ADDR
{
	if (opt(0))
	if (eeEmulClean())
	setStatus(2047:32, {1, "Clean OK!"});
	else
	setStatus(2047:32, {1, "Clean Error!"});
}
*/
void save_vars() {
	u32 dif;

	dif = (value-eeval)*CLICKS+svalue-eesval;
	if (
#if MAXCL=0
#else
		(dif>MAXCL)||
#endif
		(
			(t>=PERIOD)
#if MINCL=0
			&&(eeval!=value)
#else
			&&(dif>MINCL)
#endif
		)
	) {
		// Save vars
		if (eeEmulWrite(EEADDR*2, value)) eeval = value;
		/*
		{
			
			sprintf(data,"\1 Write Success!");
			setStatus(2047:32, &data);
		}
		else
		{
			sprintf(data,"\1 Write error!");
			setStatus(2047:32, &data);
		}
		*/
		if (eeEmulWrite(EEADDR*2+1, svalue)) eesval = svalue;
		/*
		sprintf(data,"\1 Write: value = %d; svalue = %d", value, svalue);
		setStatus(2047:32, &data);
		*/
		t = 0;
	}

}

void update_virt() {
	if (CLICKS<=1)
		sprintf(data, "%d", value);
	else if (CLICKS<=100)
		sprintf(data, "Показания: %d.%02d", value, svalue*100/CLICKS);
	else	sprintf(data, "Показания: %d.%03d", value, svalue*1000/CLICKS);
	setStatus(VIRT, data);

}

V-ID/m:1 {
	++t;
	save_vars();
	update_virt();
}

void onInit() {
	// Load variables
	if (!eeEmulRead(EEADDR*2, &value))
	{
		value = STVALUE;
		/*
		sprintf(data,"\1 Read error!");
		setStatus(2047:32, &data);
		*/
	}
	if (!eeEmulRead(EEADDR*2+1, &svalue)) svalue = 0;
	/*
	sprintf(data,"\1 Read: value = %d; svalue = %d", value, svalue);
	setStatus(2047:32, &data);
	*/
	eeval = value;
	eesval = svalue;
	update_virt();
}

V-ID/COUNTER {
if (opt(0)==1) {
	++svalue;
	if (svalue==CLICKS) {
		++value;
		svalue=0;
	}
	save_vars();
	update_virt();
	}
}

