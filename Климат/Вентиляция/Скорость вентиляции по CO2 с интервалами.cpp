/*
{
desc:"Авто СО2",
tag:"item",
selectArea:true,

vars:[
{name:"TIME", type:"number", defaultValue:60, required:true, desc:"Время обновления показаний"},
{name:"D00",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D01",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D02",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D03",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D04",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D05",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D06",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"D07",type:"devices-list",required:false,width:800,filter:["co2-sensor"],desc:"Датчик СО2",descWidth:100},
{name:"V00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Вентиляция",descWidth:100},
]
}
*/

u8 i[8]={0, 0, 0, 0, 0, 0, 0, 0}; //Превышение
u8 k=0; //Сумма
u8 vent[5];
u8 msg=0;

void onInit()
{
	setStatus(V-ADDR, 1);
}

V-ID/s:TIME
{
	#ifdef D00
	u16 CO2=(([D00.1]*100)+([D00.0]*100/250));
	if(CO2>=1300) i[0]=1; else if(CO2<800) i[0]=0;
	#endif

	#ifdef D01
	CO2=(([D01.1]*100)+([D01.0]*100/250));
	if(CO2>=1300) i[1]=1; else if(CO2<800) i[1]=0;
	#endif

	#ifdef D02
	CO2=(([D02.1]*100)+([D02.0]*100/250));
	if(CO2>=1300) i[2]=1; else if(CO2<800) i[2]=0;
	#endif

	#ifdef D03
	CO2=(([D03.1]*100)+([D03.0]*100/250));
	if(CO2>=1300) i[3]=1; else if(CO2<800) i[3]=0;
	#endif

	#ifdef D04
	CO2=(([D04.1]*100)+([D04.0]*100/250));
	if(CO2>=1300) i[4]=1; else if(CO2<800) i[4]=0;
	#endif

	#ifdef D05
	CO2=(([D05.1]*100)+([D05.0]*100/250));
	if(CO2>=1300) i[5]=1; else if(CO2<800) i[5]=0;
	#endif

	#ifdef D06
	CO2=(([D06.1]*100)+([D06.0]*100/250));
	if(CO2>=1300) i[6]=1; else if(CO2<800) i[6]=0;
	#endif

	#ifdef D07
	CO2=(([D07.1]*100)+([D07.0]*100/250));
	if(CO2>=1300) i[7]=1; else if(CO2<800) i[7]=0;
	#endif
	
	k=0;
	
	for (u8 z=0; z<9; ++z) {k=k+i[z];}

	if ((k!=0) && (([V-ADDR.0]&1)==1) && msg==0) 
	{
		getStatus(V00, &vent);
		u8 res= timeInRange(22:00-6:00);
		if(res!=0) {vent[4]=2;} else {vent[4]=3; setStatus(2047:32, {1, "Уровень СО2 превышен!"});}
		vent[0]=vent[0]|1;
		msg=1;
		setStatus(V00, &vent);
	} else 
	if((k==0) && (([V-ADDR.0]&1)==1) && (msg==1))
	{
		u8 res= timeInRange(22:00-6:00);
		if(res==0) {setStatus(2047:32, {1, "Уровень СО2 ниже 800ppm"});}
		getStatus(V00, &vent);
		vent[4]=1;
		vent[0]=vent[0]|1;
		setStatus(V00, &vent);
		msg=0;
	}

}