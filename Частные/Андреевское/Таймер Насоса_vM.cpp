/*
{
  desc:"Циркуляция насоса ГВС работает периодически. Время работы, Время простоя",
  tag:"item",
  selectArea:true,
  target:"NASOS",
  vars:[
    {name:"NASOS", type:"devices-list", required:true, filter:["lamp"], desc:"Насос", descWidth:370},
    {name:"TIME_WORK", type:"number", defaultValue:5, required:true, desc:"Время работы, минуты"},
    {name:"TIME_NOT_WORK", type:"number", defaultValue:5, required:true, desc:"Время простоя, минуты"},
  ]
}
*/

void WORK()
{
  setStatus(NASOS, 1);
}

void STOP()
{
	 setStatus(NASOS, 0);
}

V-ID/V-ADDR
{
	if ((opt(0)&1)) 
	{
		WORK();
	} 
	else if(!(opt(0)&1))
	{
		STOP();
		cancelDelayedCall(WORK);
		cancelDelayedCall(STOP);
	}
	
}

V-ID/NASOS
{
	if ( ([V-ADDR.0]&1) )
	{
		if ( ([NASOS.0]&1) )
		{
			delayedCallM(STOP, TIME_WORK);
		}
		else if ( !([NASOS.0]&1) )
		{
			delayedCallM(WORK, TIME_NOT_WORK);
		}
	}
}

