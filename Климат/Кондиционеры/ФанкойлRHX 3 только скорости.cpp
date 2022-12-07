/*
{
	desc:"Фанкойлы сухой контакт",
	tag:"import-script",
	selectArea:true,
	
	vars:[
{name:"C1",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 1",descWidth:100},
{name:"C2",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 2",descWidth:100},
{name:"C3",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 3",descWidth:100},
{name:"AUTO",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Виртуальный",descWidth:100},
{name:"KOMHATA",type:"devices-list",required:true,width:600,filter:["temperature-sensor", "virtual"],desc:"Датчик температуры",descWidth:100},
{name:"D1", type:"number", defaultValue:10, required:true, desc:"Дельта первой скорости умножте на 10"},
{name:"D2", type:"number", defaultValue:20, required:true, desc:"Дельта второй скорости умножте на 10"},
{name:"TIME", type:"number", defaultValue:15, required:true, desc:"Время обновления"},
{name:"G1", type:"number", defaultValue:10, required:true, desc:"Гистерезис нужно умножить на 10"},


	]
}
*/

u16 tempAuto=0;
u16 tempK=0;
u8 stop=0;

void speed1()
{
	if(([C3.0]&1)==1) setStatus(C3, 0);
	if(([C2.0]&1)==1) setStatus(C2, 0);
	if(([C1.0]&1)==0) setStatus(C1, 1);
}

void speed2()
{
	if(([C3.0]&1)==1) setStatus(C3, 0);
	if(([C1.0]&1)==1) setStatus(C1, 0);
	if(([C2.0]&1)==0) setStatus(C2, 1);
}

void speed3()
{
	if(([C1.0]&1)==1) setStatus(C1, 0);
	if(([C2.0]&1)==1) setStatus(C2, 0);
	if(([C3.0]&1)==0) setStatus(C3, 1);
}

void enough()
{
	if(([C3.0]&1)==1) setStatus(C3, 0);
	if(([C2.0]&1)==1) setStatus(C2, 0);
	if(([C1.0]&1)==1) setStatus(C1, 0);
}

V-ID/s:TIME
{
	if([AUTO.4]==0 && [AUTO.0]%2!=0)
	{
		tempAuto = [AUTO.1]*10;
	    tempK=( [KOMHATA.1]*10 );
	    tempK=tempK+([KOMHATA.0]*10)/250;
		//1-Охлаждение, 17-Нагрев
		if([AUTO.0]==1)
		{
			if(stop==1 && (tempK>=tempAuto+160+G1)) {stop=0;}
			if(tempK>tempAuto+160+D2 && stop==0) //Диапозон 3-й скорости
			{
				speed3();
			} else
			if((tempK<=tempAuto+160+D2) && (tempK>tempAuto+160+D1) && stop==0) //Диапозон 2-й скорости
			{
				speed2();
			} else
			if((tempK<=tempAuto+160+D1) && (tempK>tempAuto+160-G1) && stop==0) //Диапозон 1-й скорости
			{
				speed1();
			} else
			{
				enough();
				stop=1;
			}
		} else if([AUTO.0]==17)
		{
			if(stop==1 && (tempK<=tempAuto+160-G1)) {stop=0;}
			
			if((tempK>=tempAuto+160-D1) && (tempK<tempAuto+160+G1) && stop==0) // Диапозон 1-й скорости
			{
				speed1();
			} else
			if((tempK>=tempAuto+160-D2) && (tempK<tempAuto+160-D1) && stop==0) //Диапозон 2-й скорости
			{
				speed2();
			} else
			if(tempK<tempAuto+160-D2 && stop==0) //Диапозон 3-й скорости
			{
				speed3();
			} else
			{
				enough();
				stop=1;
			}
		}
	}
	else if([AUTO.0]%2!=0 && [AUTO.4]!=0)
	{
		if([AUTO.4]==1)
		{
			stop=0;
			speed1();
		} else if([AUTO.4]==2)
		{
			stop=0;
			speed2();
		} else if([AUTO.4]==3)
		{
			stop=0;
			speed3();
		}
	}
	else if([AUTO.0]%2==0)
	{
		enough();
	}

}