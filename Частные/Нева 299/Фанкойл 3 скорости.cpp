/*
{
	desc:"Фанкойлы 2 скорости охлаждение",
	tag:"import-script",
	selectArea:true,
	addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"16", "t-min":"16", "vane-hor":"0x00", "vane-ver":"0x00", "funs":"0x0B", "modes":"0x02"},
  ],
	vars:[
{name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
{name:"H00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Холодная",descWidth:100},
{name:"G00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Горячая",descWidth:100},
{name:"C01",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Скорость 1",descWidth:100},
{name:"C02",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Скорость 2",descWidth:100},
{name:"C03",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Скорость 3",descWidth:100},
{name:"KOMHATA",type:"devices-list",required:true,width:600,filter:["temperature-sensor", "virtual"],desc:"Датчик температуры",descWidth:100},
{name:"D1", type:"number", defaultValue:10, required:true, desc:"Дельта первой скорости умножте на 10"},
{name:"TIME", type:"number", defaultValue:15, required:true, desc:"Время обновления"},
{name:"G1", type:"number", defaultValue:10, required:true, desc:"Гистерезис нужно умножить на 10"},


	]
}
*/

u16 tempAuto=0;
u16 tempK=0;

void speed1()
{
	if(([H00.0]&1)==0) setStatus(H00, 1);
	if(([C02.0]&1)==1) setStatus(C02, 0);
	if(([C01.0]&1)==0) setStatus(C01, 1);
}

void speed2()
{
	if(([H00.0]&1)==0) setStatus(H00, 1);
	if(([C01.0]&1)==1) setStatus(C01, 0);
	if(([C02.0]&1)==0) setStatus(C02, 1);
}

void enough()
{
	if(([H00.0]&1)==1) setStatus(H00, 0);
	if(([C02.0]&1)==1) setStatus(C02, 0);
	if(([C01.0]&1)==1) setStatus(C01, 0);
}

void taketemp()
{
  tempAuto = ([AUTO.1]+16)*10;
  tempK=( [KOMHATA.1]*10 );
  tempK=tempK+([KOMHATA.0]*10)/250;
}

V-ID/s:TIME
{
	if([AUTO.0]%2!=0)
	{
		taketemp();
		if( (tempAuto+G1)<=tempK ) //Комтана нагрелась
		{
			if([AUTO.4]==0) {if( (tempK-tempAuto)>D1) speed2(); else speed1();} else //АвтоСкорость
			if([AUTO.4]==1) {speed1();} else //Первая скорость
			if([AUTO.4]==2) {speed2();} //Вторая скорость
		} else
		if(tempAuto-G1>=tempK) //Комната охладилась
		{

			enough();
		}
	}
}

void OFF()
{
	if(([H00.0]&1)==1) setStatus(H00, 0);
	if(([C02.0]&1)==1) setStatus(C02, 0);
	if(([C01.0]&1)==0) setStatus(C01, 1);
	delayedCall(enough, 60);
}

V-ID/AUTO
{
	if((opt(0)%2)!=0)
	{
		taketemp();
		if(tempAuto+D1<tempK) speed2(); else
		if(tempAuto<tempK) speed1();
		cancelDelayedCall(enough);
	}
	else
	{
		OFF();
	}
}