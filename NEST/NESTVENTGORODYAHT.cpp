/*
{
desc:"NESTVENT",
"name":"NESTVENT",
"name-ru":"NESTVENT",
selectArea:true,  
tag:"import-script",
vars:[
{type:"comment",text:"Скрипт NEST",width:200, style:"color:red;"},
{name:"L0",type:"devices-list",required:true, filter:["script","lamp"],desc:"NEST 1"},
{name:"L1",type:"devices-list",required:true, filter:["script","lamp"],desc:"NEST 2"},
{name:"L2",type:"devices-list",required:true, filter:["script","lamp"],desc:"NEST 3"},

{name:"G0",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости охлаждения 1 НЕСТ"},
{name:"G1",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости охлаждения 2 НЕСТ"},
{name:"G2",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости охлаждение 3 НЕСТ"},

{name:"T0",type:"devices-list",required:true, filter:["temperature-sensor"],desc:"Датчик температуры улицы"},
{name:"D0",type:"devices-list",required:true, filter:["conditioner"],desc:"Вентиляция"},

{name:"Porog0", type:"number", required:true, defaultValue:2, min:1, max:30, desc:"Сколько прибавить к значению до 18", descWidth:300},
{name:"Porog1", type:"number", required:true, defaultValue:5, min:1, max:30, desc:"Сколько прибавить к значению до 21", descWidth:300},

  ]                       
}
*/

u8 KOND[6];

void control()
{

    if ([G0.0]==1 || [G1.0]==1 || [G2.0]==1)
    {
        if ([T0.1]<18) {KOND[0]=1; KOND[1]=Porog0; setStatus(D0, &KOND); srvError("VENT1");} else {setStatus(D0, 0); srvError("VENTOFF");}
    } else
    {
    KOND[0]=1; KOND[1]=Porog1; setStatus(D0, &KOND); srvError("VENT2");
    }

}

V-ID/s:10
{
    if ([L0.0]==1 || [L1.0]==1 || [L2.0]==1)
    {
        control();
    }
    else
    {

    }

}