/*
{
desc:"Релле",
tag:"import-script",
selectArea:true,
name:"Релле",

vars:[
    {name:"IP",type:"text",required:true,defaultValue:"192.168.1.124",filter:"0123456789.",desc:"IP Адрес MICRO"},
    {name:"EXE",type:"text",required:true,defaultValue:"192.168.1.124",filter:"0123456789",desc:"ID скрипта"},
    {name:"CM",type:"number",required:true,min:500,max:599,defaultValue:525,desc:"ID MICRO"},
    {name:"L01",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 1",descWidth:100},
    {name:"L02",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 2",descWidth:100},
    {name:"L03",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 3",descWidth:100},
    {name:"L04",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 4",descWidth:100},
    {name:"L05",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 5",descWidth:100},
    {name:"L06",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 6",descWidth:100},
    {name:"L07",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 7",descWidth:100},
    {name:"L08",type:"devices-list",required:false,width:800,filter:["lamp", "virtual"],desc:"Лампа 8",descWidth:100},
    {name:"D01",type:"devices-list",required:false,width:800,filter:["dimer-lamp", "virtual"],desc:"Диммер 1",descWidth:100},
    {name:"D02",type:"devices-list",required:false,width:800,filter:["dimer-lamp", "virtual"],desc:"Диммер 2",descWidth:100},
]
}
*/

V-ID/L01
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=1|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L02
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=2|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}


V-ID/L03
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=3|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L04
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=4|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L05
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=5|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L06
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=6|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L07
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=7|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/L08
{
    u8 znachenie = (opt(0)&1);
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=8|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/D01
{
    u8 znachenie = (opt(0)&1)?opt(1):0;
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=9|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}

V-ID/D02
{
    u8 znachenie = (opt(0)&1)?opt(1):0;
    u8 strForMess[100];
    sprintf(strForMess, "ipaddr=IP|sidaddr=10|cmaddr=CM|state=%d", znachenie);
    setStatus(1000:EXE, &strForMess);
}