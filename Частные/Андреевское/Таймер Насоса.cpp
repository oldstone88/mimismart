/*
{
  desc:"Циркуляция насоса ГВС работает периодически. Время работы, Время простоя",
  tag:"item",
  selectArea:true,
  target:"NASOS",
  vars:[
    {name:"NASOS", type:"devices-list", required:true, filter:["lamp"], desc:"Насос", descWidth:370},
    {name:"TIME_WORK", type:"number", defaultValue:5, required:true, desc:"Время работы, минуты"},
    {name:"TIME_NOT_WORK", type:"number", defaultValue:5, required:true, desc:"Время простоя, минуты"},
  ]
}
*/

u8 timer=0;

V-ID/m:1
{
	if( ([V-ADDR.0]&1)==1 ) 															//Если скрипт включен
	{
		++timer; 																						//добавляем минуту
		if(
		( (timer>=TIME_WORK) && (([NASOS.0]&1)==1) ) 				//Таймер > или = времени работы
		|| ( (timer>=TIME_NOT_WORK) && (([NASOS.0]&1)==1) ) //Таймер > или = времени простоя
		) {setStatus(NASOS, 0xFF);} 								//Меняем состояни насоса и обнуляем таймер
	}
}

//Обнуляем таймер если насос изменил состояние
V-ID/NASOS
{
	timer=0;
}