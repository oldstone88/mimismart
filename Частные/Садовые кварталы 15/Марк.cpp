/*
{
    desc:"Выкл. весь cвет",
    tag:"item",
    selectArea:true,
    vars:[

    {type:"comment",text:"Нужен ли возврат скрипта в состояние ВЫКЛ? 1 - ДА, 0 - НЕТ",width:200, style:"color:red;"},
    {name:"DELTA",type:"number",required:true,min:0,max:1,defaultValue:1,descWidth:150,desc:"Внесите значение 1 или 0"},
    {name:"TIME01",type:"number",required:true,min:1,max:100,defaultValue:3,descWidth:150,desc:"Время отскока в секундах, задайте любое значение если не нужно"},
    {type:"comment",text:"Группы света, RGB, скрипты - выключить, закрыть",width:200, style:"color:red;"},
    {name:"U00",type:"devices-list",required:false,filter:["lamp"],width:888,desc:"Устройство"},
    {name:"U01",type:"devices-list",required:false,filter:["lamp"],width:888,desc:"Устройство"},
    {name:"U02",type:"devices-list",required:false,filter:["lamp"],width:888,desc:"Устройство"},
    {name:"U03",type:"devices-list",required:false,filter:["dimer-lamp"],width:888,desc:"Устройство"},
    {name:"U04",type:"devices-list",required:false,filter:["virtual"],width:888,desc:"Устройство"},
    {name:"U05",type:"devices-list",required:false,filter:["virtual"],width:888,desc:"Устройство"},
    {name:"U06",type:"devices-list",required:false,filter:["virtual"],width:888,desc:"Устройство"},
   
   
    ]
}
*/

#ifdef U04 void Off()
{
  setStatus(U04,0);  
} #endif
#ifdef U05 void Off1()
{
  setStatus(U05,0);  
} #endif
#ifdef U06 void Off2()
{
  setStatus(U06,0);  
} #endif
void Off3()
{
  setStatus(V-ADDR,0);  
}


V-ID/V-ADDR
{
    if (([V-ADDR.0]&1)==1)
    {
        if (DELTA==1)
        {
            delayedCall(Off3,TIME01);
        }
        
        #ifdef U00 setStatus(U00,0); #endif
        #ifdef U01 setStatus(U01,0); #endif
        #ifdef U02 setStatus(U02,0); #endif
        #ifdef U03 setStatus(U03,{0,75,2}); #endif
        #ifdef U04
         if (([U04.0]&7)==1 ||([U04.0]&7)==4 ||([U04.0]&7)==5 ||([U04.0]&7)==3 )
        {
                    if (([U04.0]&7)==3)
                    {
                        delayedCall(Off,1);
                    }
                    setStatus(U04,0);

        } #endif
        #ifdef U05
         if (([U05.0]&7)==1 ||([U05.0]&7)==4 ||([U05.0]&7)==5 ||([U05.0]&7)==3 )
        {
                    if (([U05.0]&7)==3)
                    {
                        delayedCall(Off1,1);
                    }
                    setStatus(U05,0);

        } #endif
             #ifdef U06
           if (([U06.0]&7)==1 ||([U06.0]&7)==4 ||([U06.0]&7)==5 ||([U06.0]&7)==3 )
        {
                    if (([U06.0]&7)==3)
                    {
                        delayedCall(Off2,1);
                    }
                    setStatus(U06,0);

        } #endif
    } 
}

