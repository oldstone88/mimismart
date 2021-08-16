/*
{
  desc:"Полная охрана c дополнительными функциями по сработке",
  
  tag:"item",
  selectArea:false,
  vars:[
 	{name:"TOOUT",type:"number",required:false,width:100,defaultValue:15,min:1,max:180,desc:"Время на выход в секундах"},
 	{name:"TOWORK",type:"number",required:false,width:100,defaultValue:15,min:1,max:180,desc:"Время на снятие охраны"},
   	{name:"MOTION0",type:"devices-list",required:true, filter:["motion-sensor"],desc:"Датчик движения1"},
   	{name:"MOTION1",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения2"},
	{name:"MOTION2",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения3"},
   	{name:"MOTION3",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения4"},
   	{name:"MOTION4",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения5"},
   	{name:"MOTION5",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения6"},
   	{name:"MOTION6",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения7"},
   	{name:"MOTION7",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения8"},
	{name:"MOTION8",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения2"},
	{name:"MOTION9",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения3"},
   	{name:"MOTIONA",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения4"},
   	{name:"MOTIONB",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения5"},
   	{name:"MOTIONC",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения6"},
   	{name:"MOTIOND",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения7"},
   	{name:"MOTIONE",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения8"},
   	{name:"MRMR",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
	{name:"VOLUME",type:"number",required:false,width:100,defaultValue:125,min:1,max:250,desc:"Громкость оповещения"},
	{name:"L00",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Cвет для мигания"},
	{name:"L01",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Cвет для мигания"},
	{name:"L02",type:"devices-list",required:false, filter:["lamp", "dimer-lamp"],desc:"Cвет для мигания"},
	]
}
*/

u16 porog = 0x2000; // treshold
u8 statutOn = 0;
u8 alarm=0;
u8 ohrana=0;

void LIGHT()
{
	#ifdef L00 setStatus(L00, 0xFF); #endif
	#ifdef L01 setStatus(L01, 0xFF); #endif
	#ifdef L02 setStatus(L02, 0xFF); #endif
}

void alarm()
{
	#ifdef MRMR
		setStatus(MRMR,{1, VOLUME, 0, "http://192.168.1.125/ohrana/alarm.mp3"});
	#endif
	setStatus(2047:32, {1,"Тревога!"});
	delayedCallR(LIGHT, 1);
}

//постановка
void on()
{
    if(([MOTION0]<porog) 
    	#ifdef MOTION1 && ([MOTION1]<porog) #endif
    	#ifdef MOTION2 && ([MOTION2]<porog) #endif 
    	#ifdef MOTION3 && ([MOTION3]<porog) #endif
    	#ifdef MOTION4 && ([MOTION4]<porog) #endif
    	#ifdef MOTION5 && ([MOTION5]<porog) #endif
    	#ifdef MOTION6 && ([MOTION6]<porog) #endif
    	#ifdef MOTION7 && ([MOTION7]<porog) #endif
	#ifdef MOTION8 && ([MOTION8]<porog) #endif
    	#ifdef MOTION9 && ([MOTION9]<porog) #endif 
    	#ifdef MOTIONA && ([MOTIONA]<porog) #endif
    	#ifdef MOTIONB && ([MOTIONB]<porog) #endif
    	#ifdef MOTIONC && ([MOTIONC]<porog) #endif
    	#ifdef MOTIOND && ([MOTIOND]<porog) #endif
    	#ifdef MOTIONE && ([MOTIONE]<porog) #endif
    	)
    {				
		ohrana = 1;
		setStatus(2047:32, {1,"Под охраной"});				
			#ifdef MRMR 
				setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/ohrana/поставлено.wav"});
			#endif
		#ifdef V00 if ([V00.0]%2!=0) setStatus(V00, 0); #endif
		#ifdef V01 if ([V01.0]%2!=0) setStatus(V01, 0); #endif
		#ifdef V02 if ([V02.0]%2!=0) setStatus(V02, 0); #endif
		#ifdef V03 if ([V03.0]%2!=0) setStatus(V03, 0); #endif
		#ifdef V04 if ([V04.0]%2!=0) setStatus(V04, 0); #endif
		#ifdef V05 if ([V05.0]%2!=0) setStatus(V05, 0); #endif
		#ifdef V06 if ([V06.0]%2!=0) {u8 kond[6]; getStatus(V06, &kond); kond[0]=kond[0]&0xFE; setStatus(V06, &kond);} #endif
	}else
	{
        setStatus(2047:32, {1,"Не успели выйти!"});
		setStatus(V-ADDR,0);			 
			#ifdef MRMR 
				setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/ohrana/не_успели.wav"});
			#endif
	}
}

//снятие
void off()
{
    if ([V-ADDR]==0)
    {
  	 	setStatus(2047:32, {1,"Без охраны"});
			#ifdef MRMR 
				setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/ohrana/снято.wav"});
			#endif
			#ifdef L00 setStatus(L00, 0); #endif
			#ifdef L01 setStatus(L01, 0); #endif
			#ifdef L02 setStatus(L02, 0); #endif
	}
}


//сработака
V-ID/s:1
{
	if ([V-ADDR]==1 && ohrana==1)
	{   
					if (([MOTION0:avgs:10]>porog)
						#ifdef MOTION1 || ([MOTION1:avgs:10]>porog) #endif
						#ifdef MOTION2 || ([MOTION2:avgs:10]>porog) #endif
						#ifdef MOTION3 || ([MOTION3:avgs:10]>porog) #endif
						#ifdef MOTION4 || ([MOTION4:avgs:10]>porog) #endif
						#ifdef MOTION5 || ([MOTION5:avgs:10]>porog) #endif 
						#ifdef MOTION6 || ([MOTION6:avgs:10]>porog) #endif
						#ifdef MOTION7 || ([MOTION7:avgs:10]>porog) #endif
						#ifdef MOTION8 || ([MOTION8:avgs:10]>porog) #endif
						#ifdef MOTION9 || ([MOTION9:avgs:10]>porog) #endif
						#ifdef MOTIONA || ([MOTIONA:avgs:10]>porog) #endif
						#ifdef MOTIONB || ([MOTIONB:avgs:10]>porog) #endif
						#ifdef MOTIONC || ([MOTIONC:avgs:10]>porog) #endif 
						#ifdef MOTIOND || ([MOTIOND:avgs:10]>porog) #endif
						#ifdef MOTIONE || ([MOTIONE:avgs:10]>porog) #endif
						 )
					{ 
						if (alarm==0 && ohrana==1) {delayedCallR (alarm, TOWORK); alarm=1;}
						#ifdef MRMR 
							setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/ohrana/снятие.wav"});         
						#endif
					}
						
	}
}

V-ID/V-ADDR
{
	if(opt(0)==1)
	{	
		setStatus(2047:32, {1,"Попытка поставить на охрану"});	 
		statutOn = 1;
		delayedCall (on, TOOUT); //время на выход
		#ifdef MRMR 
			setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/ohrana/постановка.wav"});
		#endif
	}else
		if (statutOn==1)
			{
				statutOn=0;
				ohrana=0;
				alarm=0;
				off();
				cancelDelayedCall(alarm); 
				cancelDelayedCall(on);
				cancelDelayedCall(LIGHT); 
			}
}

