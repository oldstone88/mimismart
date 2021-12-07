/*
{
  desc:"Скрипт проверки погоды Яндекс",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Влажность", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", length:"2", dim:"%"},
    {tag:"item", id:"%TARGET%", name:"Температура", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
  ],
  vars:[
         {name:"LAT",type:"string",required:true,filter:"1234567890.",min:5,max:50,desc:"Укажите широту",width:200},
         {name:"LON",type:"string",required:true,filter:"1234567890.",min:5,max:50,desc:"Укажите долготу",width:200},
         {name:"KEY",type:"string",required:true,filter:"",min:5,max:500,desc:"Укажите ключ API Яндекс карт",width:500},
         {name:"PERIOD",type:"list",required:true,desc:"Интервал проверки",data:{"m:30":"30 мин.","m:60":"1 час","m:120":"2 часа","m:720":"12 часов","m:1440":"24 часа"},defaultValue:"m:60",descWidth:350},
         {name:"VLAJ",type:"hidden",value:"%TARGET%:%SUBID97%"},
         {name:"OBLA",type:"hidden",value:"%TARGET%:%SUBID95%"},
         {name:"DEST",type:"hidden",value:"1000:95"},
  ]                       
}
*/

void onInit() {
    setStatus(DEST, "dev1=VLAJ|dev2=OBLA|key=KEY|lat=LAT|lon=LON");
}

V-ID/PERIOD
{
    setStatus(DEST, "dev1=VLAJ|dev2=OBLA|key=KEY|lat=LAT|lon=LON");
}
