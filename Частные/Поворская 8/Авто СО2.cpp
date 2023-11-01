/*
{
  desc:"Уровень CO2",
  tag:"import-script",
  selectArea:true,
  vars:[
	{name:"CO2MAX",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Уровень СО2"},
	{name:"SENSOR",type:"devices-list",required:true, filter:["co2-sensor"],descWidth:250, desc:"Датчик СО2"},
	{name:"SUPPLY",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Приточка"},
	{name:"EXTRACT",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Вытяжка"},
 ]
}
*/

V-ID/s:5{
	if([CO2MAX.0]%2==1){
		// Вычисляем значения уровня и уставки СО2
		u8 kond[5];
		u16 co2lvlneed = ([CO2MAX.1]+50)*10;
		u16 co2lvlreal = [SENSOR.1]*100+[SENSOR.0]*100/250;
		srvError("Уровень СО2 задан = %d, Уровень СО2 на датчике = %d", co2lvlneed, co2lvlreal);
		// Превышен уровень СО2
		if(co2lvlreal > co2lvlneed){
			// Выставляем 3ю скорость
			getStatus(SUPPLY, kond);
			kond[0] = 1;
			kond[1] = 3;
			setStatus(SUPPLY, &kond);
			getStatus(EXTRACT, kond);
			kond[0] = 1;
			kond[1] = 3;
			setStatus(EXTRACT, &kond);
			// Уровень СО2 менее 400
		} else if(co2lvlreal < 400){
			getStatus(SUPPLY, kond);
			kond[0] = 0;
			setStatus(SUPPLY, &kond);
			getStatus(EXTRACT, kond);
			kond[0] = 0;
			setStatus(EXTRACT, &kond);
			// Уровень СО2 в норме
		} else if(co2lvlreal < co2lvlneed - 100){
			getStatus(SUPPLY, kond);
			kond[0] = 1;
			kond[1] = 1;
			setStatus(SUPPLY, &kond);
			getStatus(EXTRACT, kond);
			kond[0] = 1;
			kond[1] = 1;
			setStatus(EXTRACT, &kond);
		}
	}
}