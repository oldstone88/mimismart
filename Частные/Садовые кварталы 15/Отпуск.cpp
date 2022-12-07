/*
{
    desc:"Отпуск",
    tag:"item",
    name:"Отпуск",
    selectArea:true,
    
    vars:[
    {name:"I00",type:"devices-list",required:true,width:600,filter:["script"],desc:"Все ушли",descWidth:100},
    {name:"I01",type:"devices-list",required:true,width:600,filter:["script"],desc:"Присутствие",descWidth:100},
    {name:"I02",type:"devices-list",required:true,width:600,filter:["script"],desc:"Я пришел",descWidth:100},
    {name:"V00",type:"devices-list",required:true,width:600,filter:["valve"],desc:"Вода",descWidth:100},
    ]
}
*/

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        setStatus(2047:32, {4, "Отпуск активирован!"});
        setStatus(I00, 1);
        setStatus(V00, 1);
    } else
    {
        setStatus(2047:32, {4, "Отпуск выключен!"});
        setStatus(I01, 0);
        setStatus(V00, 0);
        if( ([I02.0]&1)==0) setStatus(I02, 1);
    }
}

V-ID/s:60
{
    u8 res = timeInRange(19:00-00:00);
    if( (([V-ADDR.0]&1)==1) && (([I01.0]&1)==0) && (res!=0) ) setStatus(I01, 1);
    else if( (([V-ADDR.0]&1)==1) && (([I01.0]&1)==1) && (res==0) ) setStatus(I01, 0);
}