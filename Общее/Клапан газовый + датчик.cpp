/*
{
    desc:"Перекрытие Метана",
    tag:"item",
    selectArea:true,
    vars:[
        {name:"METAN",type:"devices-list",required:true,width:600,filter:["humidity-sensor"],desc:"Датчик метана",descWidth:100},
        {type:"comment",text:"Введите время хода мотора:"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"OPEN",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть",descWidth:100},
        {name:"CLOSE",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть",descWidth:100},
    ]
}
*/

V-ID/s:300
{
    if([METAN.1]>15 && ([V-ADDR.0]&1)==0) {setStatus(V-ADDR, 0); setStatus(2047:32, {8, "Высокий уровень ГАЗА!"});}
}

V-ID/s:5
{
    if([METAN.1]>15 && ([V-ADDR.0]&1)==1) {setStatus(V-ADDR, 0); setStatus(2047:32, {8, "Утечка ГАЗА!!!"});}
}

void stop()
{
    setStatus(OPEN, 0);
    setStatus(CLOSE, 0);
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1 && [METAN.1]<15)
    {
        setStatus(CLOSE, 0);
        setStatus(OPEN, 1);
        delayedCall(stop, TIME);
    } else
    if((opt(0)&1)==1 && [METAN.1]>=15)
    {
        setStatus(2047:32, {8, "Уровень газа еще высок!"});
        setStatus(V-ADDR, 0);
    }
    else
    if((opt(0)&1)==0)
    {
        setStatus(2047:32, {8, "Газ перекрыт!"});
        setStatus(OPEN, 0);
        setStatus(CLOSE, 1);
        delayedCall(stop, TIME);
    }
}