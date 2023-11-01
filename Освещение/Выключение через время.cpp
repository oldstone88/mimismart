/*
{
    desc:"Выкл. свет по таймеру",
    tag:"item",
    name:"Выкл. свет по таймеру",
    selectArea:true,
    vars:[
    {type:"comment",text:"Группа света",width:200, style:"color:red;"},
    {name:"LIGHT",type:"devices-list",required:false,filter:["lamp", "dimmer-lamp"],width:888,desc:"Свет"},
    {type:"comment",text:"Выберите что делать:",width:200, style:"color:red;"},
    {name:"TIME",type:"number",required:true,defaultValue:60,min:1,max:180,desc:"Время работы в секундах",descWidth:350},
    ]
}
*/

u8 timer = 0;

void onInit(){
    setStatus(V-ADDR, 1);
}

V-ID/s:1{
    if (([V-ADDR.0]&1)==1 && (([LIGHT.0]&1)==1)){
        ++timer;
        if(timer>=TIME) setStatus(LIGHT, 0);
    }
    else if(timer!=0) timer=0;
}

