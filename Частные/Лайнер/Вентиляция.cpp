/*
{
	desc:"Вентиляция",
	tag:"item",
	selectArea:true,
	name:"Отпуск",
	vars:[
	{type:"comment",text:"Уровень CO2 для отсечки:"},
	{name:"BIGCO2",type:"number",required:true,min:500, max:2000},
	{type:"comment",text:"Спальня:"},
	{name:"CO20",type:"devices-list",required:false,width:1000,filter:["co2-sensor"],desc:"Датчик CO2",descWidth:100},
	{name:"V00",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Гардероб",descWidth:100},
	{name:"V01",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Туалет",descWidth:100},
	{name:"V02",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Душевая",descWidth:100},
	{type:"comment",text:"Зал:"},
	{name:"CO21",type:"devices-list",required:false,width:1000,filter:["co2-sensor"],desc:"Датчик CO2",descWidth:100},
	{name:"V03",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Кухня приток",descWidth:100},
	{name:"V04",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Кухня вытяжка",descWidth:100},
	{name:"V05",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Зал",descWidth:100},
	{type:"comment",text:"Детская:"},
	{name:"CO22",type:"devices-list",required:false,width:1000,filter:["co2-sensor"],desc:"Датчик CO2",descWidth:100},
	{name:"V06",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Ванная",descWidth:100},
	{name:"V07",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Гостевая",descWidth:100},
	{type:"comment",text:"Спорт-зал"},
	{name:"CO23",type:"devices-list",required:false,width:1000,filter:["co2-sensor"],desc:"Датчик CO2",descWidth:100},
	{name:"V08",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Спортзал В",descWidth:100},
	{name:"V09",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Спортзал П",descWidth:100},
	{name:"V10",type:"devices-list",required:false,width:1000,filter:["valve"],desc:"Магистральный",descWidth:100},
	{type:"comment",text:"Вентиляция"},
	{name:"VENT",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Вентиляция",descWidth:100},
	]
}
*/

V-ID/s:5
{
	u8 kond[5];
	u8 error=0; //Флаг привышения
	u8 level=([CO20.1]*100+[CO20.0]*100/255); // расчет со2
	if( level>BIGCO2 )
		{
			error |= 1<<0;
			#ifdef V00 if( ([V00.0]&1)==1 ) setStatus(V00, 0); #endif
			#ifdef V01 if( ([V01.0]&1)==1 ) setStatus(V01, 0); #endif
			#ifdef V02 if( ([V02.0]&1)==1 ) setStatus(V02, 0); #endif
		} else
		{
			#ifdef V00 if( ([V00.0]&1)==0 ) setStatus(V00, 1); #endif
			#ifdef V01 if( ([V01.0]&1)==0 ) setStatus(V01, 1); #endif
			#ifdef V02 if( ([V02.0]&1)==0 ) setStatus(V02, 1); #endif
		}

	level=([CO21.1]*100+[CO21.0]*100/255);
	if( level>BIGCO2 )
		{
			error |= 1<<1;
			#ifdef V03 if( ([V03.0]&1)==1 ) setStatus(V03, 0); #endif
			#ifdef V04 if( ([V04.0]&1)==1 ) setStatus(V04, 0); #endif
			#ifdef V05 if( ([V05.0]&1)==1 ) setStatus(V05, 0); #endif
		} else
		{
			#ifdef V03 if( ([V03.0]&1)==0 ) setStatus(V03, 1); #endif
			#ifdef V04 if( ([V04.0]&1)==0 ) setStatus(V04, 1); #endif
			#ifdef V05 if( ([V05.0]&1)==0 ) setStatus(V05, 1); #endif
		}

	level=([CO22.1]*100+[CO22.0]*100/255);
	if( level>BIGCO2 )
		{
			error |= 1<<2;
			#ifdef V06 if( ([V06.0]&1)==1 ) setStatus(V06, 0); #endif
			#ifdef V07 if( ([V07.0]&1)==1 ) setStatus(V07, 0); #endif
		} else
		{
			#ifdef V06 if( ([V06.0]&1)==0 ) setStatus(V06, 1); #endif
			#ifdef V07 if( ([V07.0]&1)==0 ) setStatus(V07, 1); #endif
		}

	level=([CO23.1]*100+[CO23.0]*100/255);
	if( level>BIGCO2 )
		{
			error |= 1<<3;
			#ifdef V08 if( ([V08.0]&1)==1 ) setStatus(V08, 0); #endif
			#ifdef V09 if( ([V09.0]&1)==1 ) setStatus(V09, 0); #endif
		} else
		{
			#ifdef V08 if( ([V08.0]&1)==0 ) setStatus(V08, 1); #endif
			#ifdef V09 if( ([V09.0]&1)==0 ) setStatus(V09, 1); #endif
		}
	//Логика магистрального клапана и скоростей
	if(([V-ADDR.0]&1)==1) //Отпуск
	{
		if( [VENT.0]==0 || [VENT.4]!=1 ) {getStatus(VENT, &kond); kond[0]=1; kond[4]=1; setStatus(VENT, kond);}
	}
	else if(!error) //Всё в порядке
	{
		if(([V10.0]&1)==1)setStatus(V10, 0);
		if( [VENT.0]==0 || [VENT.4]!=2 ) {getStatus(VENT, &kond); kond[0]=1; kond[4]=2; setStatus(VENT, kond);}
	}
	else if(error==8) //Спорт режим
	{
		if(([V10.0]&1)==0)setStatus(V10, 1);
		if( [VENT.0]==0 || [VENT.4]!=3 ) {getStatus(VENT, &kond); kond[0]=1; kond[4]=3; setStatus(VENT, kond);}
	}
	else if(error) //Есть превышение, но не спорт
	{
		if(([V10.0]&1)==1) setStatus(V10, 0);
		if( [VENT.0]==0 || [VENT.4]!=3 ) {getStatus(VENT, &kond); kond[0]=1; kond[4]=3; setStatus(VENT, kond);}
	}
}