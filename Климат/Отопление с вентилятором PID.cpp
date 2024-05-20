/*
{
  desc:"ПИД",
  tag:"import-script",
  selectArea:true,
  vars:[
  {name:"ROOM", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:100, width:700},
  {name:"FAN", type:"devices-list", required:true, filter:["dimer-lamp"], desc:"Вентилятор", descWidth:100, width:700},
  {name:"VALVE", type:"devices-list", required:false, filter:["valve-heating"], desc:"Отопление", descWidth:100, width:700},
  {name:"kP",type:"number",required:true,defaultValue:12,min:0,max:100,desc:"Коофициент П",descWidth:350},
  {name:"kI",type:"number",required:true,defaultValue:1,min:0,max:100,desc:"Коофициент И",descWidth:350},
  {name:"kD",type:"number",required:true,defaultValue:60,min:0,max:100,desc:"Коофициент Д",descWidth:350},
  ]
}
*/

i16 integral = 0;
i16 prevError = 0;

void PID(u16 input, u16 setpoint, u8 kp, u8 ki, u8 kd, u8 dt){
  i16 err = setpoint - input;
  integral = integral + err * dt * ki;
  i16 D = (err - prevError) / dt;
  i16 bright = err * kp + integral + D * kd;
  if(bright<0) bright=0;
  else if (bright>2500) bright=2500;
  prevError = err;
  return bright/10;
}

V-ID/s:5{
  if([VALVE.0]==1 && ([VALVE.5]!=255 || [VALVE.5]!=254)){
     u16 realTemperature = ([ROOM.1] * 10) + ([ROOM.0]*10)/250;
    //srvError("В комнате = %d", realTemperature);
    u16 ambitional = [VALVE.2]*10;
    //srvError("Цель = %d", ambitional);
    i16 signal = PID(realTemperature, ambitional, kP, kI, kD, 5); // Последний параметр - время обновления. Должен быть равен времени обновления.
    //srvError("Выходной сигнал = %d", signal);
    setStatus(FAN, {1, signal, 1});
  } else if([VALVE.0]==0 && ([VALVE.5]!=255 || [VALVE.5]==254)){
    setStatus(FAN, {0, 0, 0});
  }
}