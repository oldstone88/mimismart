/*
{
    desc:"Работа с телеграмм бот @smart48.ru - Отправка уведомлений о протечках",
    tag:"import-script",
    selectArea:true,
    name:"Уведомления о протечке",
    vars:[
        {type:"comment",text:"Настройка ТЕЛЕГРАММ получателя",width:888, style:"color:red;"},
        {name:"TELEGRAMMID_1",type:"string",required:true,desc:"Укажите id получателя в телеграмм-боте",width:880},     
        {name:"TXT_1",type:"string",required:true,desc:"Текст уведомления",width:880},
        {name:"ANTIFLOOD_1",type:"number",required:false,min:0,max:600,defaultValue:60,desc:"Контроль множетсвенной отправки сообщения сек(0 - не контролировать, 0< - интервал игнорирования отправки сообщения)",descWidth:340,width:100},
        {name:"H00",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H01",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H02",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H03",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H04",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H05",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H06",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H07",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H08",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        {name:"H09",type:"devices-list",required:false,width:800,filter:["leak-sensor"],desc:"Датчик",descWidth:100},
        ]
}
*/
u8 antiflood=0;

void onInit(){
    setStatus(V-ADDR, 1);
}

void send() {
    setStatus(1000:90, "TELEGRAMMID_1||TXT_1||||");
}

V-ID/H00#ifdef H01, H01#endif#ifdef H02, H02#endif#ifdef H03, H03#endif#ifdef H04, H04#endif#ifdef H05, H05#endif#ifdef H06, H06#endif#ifdef H07, H07#endif#ifdef H08, H08#endif#ifdef H09, H09#endif { 
    if ((opt(0)%2)==1 && antiflood==0){
        send();
        antiflood=1;
    }
}

V-ID/s:1{
    if(antiflood){
        ++antiflood;
        if(antiflood>=ANTIFLOOD_1) antiflood=0;
    }
}