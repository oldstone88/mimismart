/*
{
  desc:"Я пришел",
  tag:"item",
  
  selectArea:true,
  vars:[
   	{name:"ITEM1",type:"devices-list",required:true, filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 1",descWidth:170},
   	{name:"ITEM2",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM3",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM4",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM5",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM6",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM7",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	
   	{name:"ITEM8",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp"],desc:"Элемент 2 (опционально)",descWidth:170},	



  ]
}
*/

void OFF()
{
    setStatus(V-ADDR, 0);
}

#ifdef ITEM8
void start8()
{
    setStatus(ITEM8, 1);
}
#endif

#ifdef ITEM7
void start7()
{
    setStatus(ITEM7, 1);
    #ifdef ITEM8 delayedCall(start8, 1); #endif
}
#endif

#ifdef ITEM6
void start6()
{
    setStatus(ITEM6, 1);
    #ifdef ITEM7 delayedCall(start7, 1); #endif
}
#endif

#ifdef ITEM5
void start5()
{
    setStatus(ITEM5, 1);
    #ifdef ITEM6 delayedCall(start6, 1); #endif
}
#endif

#ifdef ITEM4
void start4()
{
    setStatus(ITEM4, 1);
    #ifdef ITEM5 delayedCall(start5, 1); #endif
}
#endif

#ifdef ITEM3
void start3()
{
    setStatus(ITEM3, 1);
    #ifdef ITEM4 delayedCall(start4, 1); #endif
}
#endif

#ifdef ITEM2
void start2()
{
    setStatus(ITEM2, 1);
    #ifdef ITEM3 delayedCall(start3, 1); #endif
}
#endif

void start1()
{
    setStatus(ITEM1, 1);
    #ifdef ITEM2 delayedCall(start2, 1); #endif
}

V-ID/V-ADDR
{
	if (opt(0)) {start1(); delayedCall(OFF, 1);}
}