/*
{
desc:"Датчик",
tag:"item",
name:"Утро-Вечер",
selectArea:true,

vars:[
    {name:"I00",type:"devices-list",required:false,width:800,filter:["script"],desc:"Отпуск",descWidth:100},
    {name:"V00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V01",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V02",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V03",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V04",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V05",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
    {name:"V06",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление",descWidth:100},
]
}
*/

V-ID/V-ADDR
{
    if((opt(0)&1)==1 && ([I00.0]&1)==0)
    {
        setStatus(1000:102, "V00\0Комфорт");
        setStatus(1000:102, "V01\0Комфорт");
        setStatus(1000:102, "V02\0Комфорт");
        setStatus(1000:102, "V03\0Комфорт");
        setStatus(1000:102, "V04\0Комфорт");
        setStatus(1000:102, "V05\0Комфорт");
        setStatus(1000:102, "V06\0Комфорт");
    }
    else if((opt(0)&1)==0 && ([I00.0]&1)==0)
    {
        setStatus(1000:102, "V00\0Эко");
        setStatus(1000:102, "V01\0Эко");
        setStatus(1000:102, "V02\0Эко");
        setStatus(1000:102, "V03\0Эко");
        setStatus(1000:102, "V04\0Эко");
        setStatus(1000:102, "V05\0Эко");
        setStatus(1000:102, "V06\0Эко");
    }
}