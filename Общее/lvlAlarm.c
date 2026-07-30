/*
{
    desc:"Оповещения от датчиков",
    tag:"item",
    selectArea:true,
    vars:[
        {name:"GIST", type:"number", required:true, defaultValue:7200, min:1800, max:21600, desc:"Порог сработки", descWidth:370},
        {name:"L00",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L01",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L02",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L03",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L04",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L05",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T05",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L06",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L07",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L08",type:"devices-list",required:false,width:600,filter:["humidity-sensor"],desc:"Датчик",descWidth:100},
        {name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
    ]
}
*/

void onInit(){
    setStatus(V-ADDR, 1);
}

#ifdef L00
V-ID/L00{
    if(([L00.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T00"});
}
#endif

#ifdef L01
V-ID/L01{
    if(([L01.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T01"});
}
#endif

#ifdef L02
V-ID/L02{
    if(([L02.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T02"});
}
#endif

#ifdef L03
V-ID/L03{
    if(([L03.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T03"});
}
#endif

#ifdef L04
V-ID/L04{
    if(([L04.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T04"});
}
#endif

#ifdef L05
V-ID/L05{
    if(([L05.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T05"});
}
#endif

#ifdef L06
V-ID/L06{
    if(([L06.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T06"});
}
#endif

#ifdef L07
V-ID/L07{
    if(([L07.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T07"});
}
#endif

#ifdef L08
V-ID/L08{
    if(([L08.1] > GIST) && (([V-ADDR.0] & 1) == 1))
        setStatus(2047:32, {8, "T08"});
}
#endif
