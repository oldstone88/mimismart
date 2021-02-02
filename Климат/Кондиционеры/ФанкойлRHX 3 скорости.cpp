/*
{
	desc:"Фанкойлы сухой контакт",
	tag:"import-script",
	selectArea:true,
	
	vars:[
{name:"K1",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Нагрев",descWidth:100},
{name:"K2",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Охлаждение",descWidth:100},
{name:"C1",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 1",descWidth:100},
{name:"C2",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 2",descWidth:100},
{name:"C3",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Скорость 3",descWidth:100},
{name:"V1",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Виртуальный",descWidth:100},
{name:"T1",type:"devices-list",required:true,width:600,filter:["temperature-sensor", "virtual"],desc:"Датчик температуры",descWidth:100},
{name:"D1", type:"number", defaultValue:5, required:true, desc:"Дельта первой скорости умножте на 10"},
{name:"D2", type:"number", defaultValue:20, required:true, desc:"Дельта второй скорости умножте на 10"},
{name:"TIME", type:"number", defaultValue:30, required:true, desc:"Время обновления температуры"},
{name:"G1", type:"number", defaultValue:10, required:true, desc:"Гистерезис нужно умножить на 10"},


	]
}
*/

u8 K[6];
i32 NT=0;
i32 NV=0;

//Функция проверки выхода из диапозона
void checkRD()
{
	if( ((NT-NV+100)>(100+G1)) && ([V1.0]==17 || [V1.0]==49) )
		{setStatus(K1,0);  setStatus(K2,1);} else
	if( ((NT-NV+100)<(100-G1)) && ([V1.0]==33 || [V1.0]==49) )
		{setStatus(K2,0); setStatus(K1,1);}
}

//Функция проверки достижения температуры
void checkR()
{
	NT=([T1.1]*10+[T1.0]*10/256); //Температура с датчика х10
	NV=([V1.1]+16)*10; //Температура кондиционера установленная
	if( [K1.0]==1 && [V1.0]==33 && (NT-NV+100>=100) ) {setStatus(K1, 0); setStatus(K2, 0);} else
	if( [K2.0]==1 && [V1.0]==17 && (NT-NV+100<=100) ) {setStatus(K1, 0); setStatus(K2, 0);} else
	if( [V1.0]==49 && (([K1.0]==1 && (NT-NV+100>=100)) || ([K2.0]==1 && (NT-NV+100<=100))) ) {setStatus(K1, 0); setStatus(K2, 0);} else
	{checkRD();}
	
}


void checkQ()
{

	NT=([T1.1]*10+[T1.0]*10/256); //Температура с датчика х10
	NV=([V1.1]+16)*10; //Температура кондиционера установленная
	
	if( [V1.0]==17) //Охлаждение
	{
		if(NV-NT+100<=100-D2) {setStatus(C1,0); setStatus (C3, 0); setStatus (C2, 1);} else
		if(NV-NT+100<=100-D1) {setStatus(C2,0); setStatus (C3, 0); setStatus (C1, 1);} else
		if((NV-NT+100>=100) && ([C1.0]!=0 || [C2.0]!=0 || [C3.0]!=0)){setStatus(C1,0); setStatus (C2, 0); setStatus (C3, 0);}
	} else
	if ([V1.0]==33) //Нагрев
	{
		if(NV-NT+100>=100+D2) {setStatus(C1,0); setStatus (C3, 0); setStatus (C2, 1);} else
		if(NV-NT+100>=100+D1) {setStatus(C3,0); setStatus (C2, 0); setStatus (C1, 1);} else
		if((NV-NT+100<=100) && ([C1.0]!=0 || [C2.0]!=0 || [C3.0]!=0)){setStatus(C1,0); setStatus (C2, 0); setStatus (C3, 0);}
	} else
	{
		
	}
	
	
	
}

void puskR()
{
srvError("Пуск");
	NT=([T1.1]*10+[T1.0]*10/256); //Температура с датчика х10
	NV=([V1.1]+16)*10; //Температура кондиционера установленная
	if( (NT-NV+100>100) && ([V1.0]==17 || [V1.0]==49) )
		{setStatus(K1,0);  setStatus(K2,1);} else
	if( (NT-NV+100<100) && ([V1.0]==33 || [V1.0]==49))
		{setStatus(K2,0); setStatus(K1,1);} else
	{setStatus(K1,0); setStatus(K2,0);}
}

V-ID/V1
{
if ([V1.0]%2!=0) //Если кондиционер включен
	{

	if( [V1.0]==1) {cancelDelayedCall(checkR); setStatus(K1, 0); setStatus (K2, 0);} else //Ручная вентиляция
	if( [V1.0]==17) {cancelDelayedCall(checkR); puskR(); delayedCallR(checkR,5);} else //Ручное охлаждение
	if( [V1.0]==33) {cancelDelayedCall(checkR); puskR(); delayedCallR(checkR,5);} else // Ручной обогрев
	if( [V1.0]==49) {cancelDelayedCall(checkR); puskR(); delayedCallR(checkR, 5);} //Авто режим

	if( [V1.4]==1 ) {cancelDelayedCall(checkQ); setStatus(C2,0); setStatus (C3, 0); setStatus (C1, 1);} else //Ручная первая скорость
	if( [V1.4]==2 ) {cancelDelayedCall(checkQ); setStatus(C1,0); setStatus (C3, 0); setStatus (C2, 1);} else //Ручная вторая скорость
    if( [V1.4]==3 ) {cancelDelayedCall(checkQ); setStatus(C1,0); setStatus (C2, 0); setStatus (C3, 1);} else //Ручная третья скорость
	if( [V1.4]==0 ) {cancelDelayedCall(checkQ); setStatus(C2,0); setStatus (C3, 0); setStatus (C1, 1); checkQ(); delayedCallR(checkQ, TIME); } //Режим автомат

	}
		else {cancelDelayedCall(checkQ); cancelDelayedCall(checkR); setStatus(K1,0); setStatus(K2,0); setStatus(C1,0); setStatus(C2,0); setStatus (C3, 0);} // Выключение кондиционера
}

void onInit()
{
if ([V1.0]%2!=0)
	{

	if( [V1.0]==1) {cancelDelayedCall(checkR); setStatus(K1, 0); setStatus (K2, 0);}
	else {delayedCallR(checkR,5); srvError("Start 1");}

	if( [V1.4]==0 ) {delayedCallR(checkQ, TIME); srvError("Start 2"); }

	}
		else {cancelDelayedCall(checkQ); cancelDelayedCall(checkR); setStatus(K1,0); setStatus(K2,0); setStatus(C1,0); setStatus(C2,0); setStatus (C3, 0);} // Выключение кондиционера
}
