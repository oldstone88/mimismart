/*
{
    desc:"Охрана",
    tag:"item",
    selectArea:true,
    vars:[
        {name:"COME", type:"number", defaultValue:30, required:true, desc:"Время после входа, c(Кратно 10)"},
        {name:"OUT", type:"number", defaultValue:30, required:true, desc:"Время на выход, c"},
        {name:"L00",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L01",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L02",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L03",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L04",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L05",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L07",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L08",type:"devices-list",required:false,width:600,filter:["script"],desc:"Зона",descWidth:100},
        {name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
    ]
}
*/

void onInit()
{
    setStatus(2047:32, {4, "Была перезагрузка! Проверьте охрану!"});
}

u8 i=0; //Счетчик работы
u8 ohrana=0; //Стоит ли на охране

V-ID/s:10
{
    if (([V-ADDR.0]&1)==1 && ohrana==1)
    {
        if( #ifdef L00 [L00.0]==1 #endif
        #ifdef L01 || [L01.0]==1 #endif
        #ifdef L02 || [L02.0]==1 #endif
        #ifdef L03 || [L03.0]==1 #endif
        #ifdef L04 || [L04.0]==1 #endif
        #ifdef L05 || [L05.0]==1 #endif
        #ifdef L06 || [L06.0]==1 #endif
        #ifdef L07 || [L07.0]==1 #endif
        #ifdef L08 || [L08.0]==1 #endif
        ) {++i; if((i*10)>COME) setStatus(2047:32, {4, "Сработка охраны!!!"});}
    }
}

void start()
{
    if( #ifdef L00 [L00.0]==0 #endif
        #ifdef L01 || [L01.0]==0 #endif
        #ifdef L02 || [L02.0]==0 #endif
        #ifdef L03 || [L03.0]==0 #endif
        #ifdef L04 || [L04.0]==0 #endif
        #ifdef L05 || [L05.0]==0 #endif
        #ifdef L06 || [L06.0]==0 #endif
        #ifdef L07 || [L07.0]==0 #endif
        #ifdef L08 || [L08.0]==0 #endif
        ) {ohrana=1; setStatus(2047:32, {4, "Под охраной!!!"});}
    else {setStatus(2047:32, {4, "Не успели выйти!!!"}); setStatus(V-ADDR, 0);}
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        setStatus(2047:32, {4, "Попытка поставить на охрану!"});
        delayedCall(start, OUT);
    }
    else if((opt(0)&1)==0)
    {
        i=0;
        ohrana=0;
        setStatus(2047:32, {4, "Без охраны!"});
    }
}