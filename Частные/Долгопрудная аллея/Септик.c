/*
{
  desc:"Переполнение бочки",
  tag:"item",
  name:"Переполнение",
  selectArea:true,
  vars:[
        {type:"comment",text:"Выберите герконы:"},
        {name:"HI",type:"devices-list",required:false,filter:["door-sensor"],desc:"Переполнен"},
        {name:"NORMAL",type:"devices-list",required:false,filter:["door-sensor"],desc:"В норме"},
  ]
}
*/



void onInit(){
    setStatus(V-ADDR, 1);
}

V-ID/s:60{
    if( ([HI.0]&1)==0 && ([V-ADDR.0]&1)==1) {setStatus(2047:32, {8, "Достигнут максимальный уровень!"});}
    else if( ([NORMAL.0]&1)==0 && ([V-ADDR.0]&1)==1) {setStatus(2047:32, {8, "Уроверь меньше минимального!"});}
}