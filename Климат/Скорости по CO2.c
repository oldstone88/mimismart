/*
{
  desc:"Автоматизация скорости вентиляции по СО2",
  name:"АвтоСкорости",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"VENT",type:"devices-list",required:true, filter:["conditioner"],desc:"Вентиляция"},
    {name:"CO200",type:"devices-list",required:true, filter:["co2-sensor"],desc:"Датчик CO2"},
    {name:"CO201",type:"devices-list",required:true, filter:["co2-sensor"],desc:"Датчик CO2"},
    {name:"CO202",type:"devices-list",required:true, filter:["co2-sensor"],desc:"Датчик CO2"},
    {name:"CO203",type:"devices-list",required:true, filter:["co2-sensor"],desc:"Датчик CO2"},
    {name:"DANGERHI",type:"number",min:"400",max:"1500",required:true,defaultValue:"1",desc:"Порог максимум"},
    {name:"DANGERMED",type:"number",min:"400",max:"1500",required:true,defaultValue:"1",desc:"Порог средний"},

	]
}
*/

u8 state[5];
u16 pokazanie0 = 0;
u16 pokazanie1 = 0;
u16 pokazanie2 = 0;
u16 pokazanie3 = 0;

void onInit(){
  setStatus(V-ADDR, 1);
}

V-ID/s:15{

  pokazanie0 = (([CO200.0]*100/255)+([CO200.1]*100));
  pokazanie1 = (([CO201.0]*100/255)+([CO201.1]*100));
  pokazanie2 = (([CO202.0]*100/255)+([CO202.1]*100));
  pokazanie3 = (([CO203.0]*100/255)+([CO203.1]*100));

  if(([V-ADDR.0]&1) == 1){
    // Если показания выше чем максимум - включаем скорость максимум
    if( (pokazanie0 > DANGERHI) || (pokazanie1 > DANGERHI) || (pokazanie2 > DANGERHI) || (pokazanie3 > DANGERHI)){
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 2;
      setStatus(VENT, &state);
    }
    else if( (pokazanie0 > DANGERMED) || (pokazanie1 > DANGERMED) || (pokazanie2 > DANGERMED)){
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 1;
      setStatus(VENT, &state);
    } else {
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 0;
      setStatus(VENT, &state);
    }
  }
}
