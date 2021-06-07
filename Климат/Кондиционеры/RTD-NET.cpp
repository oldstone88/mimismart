/*
{
  desc:"Скрипт управления платой RTD-NET Daikin по RS485 (добавляет 6 кондиционеров, ненужные потом удалить вручную) (настройки RS485: 9600, stop 1, no parity)",
  tag:"import-script",
  target:"RS485",
  selectArea:"true",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Кондиционер1", sub-id:"%SUBID01%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер2", sub-id:"%SUBID02%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер3", sub-id:"%SUBID03%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер4", sub-id:"%SUBID04%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер5", sub-id:"%SUBID05%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер6", sub-id:"%SUBID06%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
	{tag:"item", id:"%TARGET%", name:"Кондиционер7", sub-id:"%SUBID07%", type:"conditioner",funs:"0x0e",t-min:"16",t-delta:"16",vane-hor:"0x5f",vane-ver:"0"},
  ],
  vars:[
	{name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
	{name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:63,desc:"ID1 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID2",type:"number",required:false,min:1,max:63,desc:"ID2 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID3",type:"number",required:false,min:1,max:63,desc:"ID3 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID4",type:"number",required:false,min:1,max:63,desc:"ID4 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID5",type:"number",required:false,min:1,max:63,desc:"ID5 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID6",type:"number",required:false,min:1,max:63,desc:"ID6 пульта (для протокола Modbus)",descWidth:350},
	{name:"ID7",type:"number",required:false,min:1,max:63,desc:"ID7 пульта (для протокола Modbus)",descWidth:350},
	{name:"COND1",type:"hidden",value:"%TARGET%:%SUBID01%"},
	{name:"COND2",type:"hidden",value:"%TARGET%:%SUBID02%"},
	{name:"COND3",type:"hidden",value:"%TARGET%:%SUBID03%"},
	{name:"COND4",type:"hidden",value:"%TARGET%:%SUBID04%"},
	{name:"COND5",type:"hidden",value:"%TARGET%:%SUBID05%"},
	{name:"COND6",type:"hidden",value:"%TARGET%:%SUBID06%"},
	{name:"COND7",type:"hidden",value:"%TARGET%:%SUBID07%"},
  ]
}
*/

u8 cmnd_wr1[19]={ID1,0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0xCC16};
#ifdef ID2 u8 cmnd_wr2[19]={ID2, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif
#ifdef ID3 u8 cmnd_wr3[19]={ID3, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif
#ifdef ID4 u8 cmnd_wr4[19]={ID4, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif
#ifdef ID5 u8 cmnd_wr5[19]={ID5, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif
#ifdef ID6 u8 cmnd_wr6[19]={ID6, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif
#ifdef ID7 u8 cmnd_wr7[19]={ID7, 0x10, 0x0001, 0x0005, 0x0A, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0xCC16}; #endif

u8 write = 0;
u8 rezhim=0;

V-ID/COND1
{	
	if((opt(0)%2)!=0)
	{
		cmnd_wr1[16]=0x01;
		cmnd_wr1[8]=([COND1.1]+16);
		cmnd_wr1[10]=([COND1.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr1[12] = 2;
		}else if(m == 1){
			cmnd_wr1[12] = 3;
		}else if(m == 2){
			cmnd_wr1[12] = 4;
		}else if(m == 3){
			cmnd_wr1[12] = 1;
		}else if(m == 4){
			cmnd_wr1[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr1[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr1);} else write=0;
}

#ifdef ID2
V-ID/COND2
{
	if((opt(0)%2)!=0)
	{
		cmnd_wr2[16]=0x01;
		cmnd_wr2[8]=([COND2.1]+16);
		cmnd_wr2[10]=([COND2.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr2[12] = 2;
		}else if(m == 1){
			cmnd_wr2[12] = 3;
		}else if(m == 2){
			cmnd_wr2[12] = 4;
		}else if(m == 3){
			cmnd_wr2[12] = 1;
		}else if(m == 4){
			cmnd_wr2[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr2[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr2);} else write=0;
}
#endif

#ifdef ID3
V-ID/COND3
{
	if((opt(0)%2)!=0)
	{
		cmnd_wr3[16]=0x01;
		cmnd_wr3[8]=([COND3.1]+16);
		cmnd_wr3[10]=([COND3.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr3[12] = 2;
		}else if(m == 1){
			cmnd_wr3[12] = 3;
		}else if(m == 2){
			cmnd_wr3[12] = 4;
		}else if(m == 3){
			cmnd_wr3[12] = 1;
		}else if(m == 4){
			cmnd_wr3[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr3[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr3);} else write=0;
}
#endif

#ifdef ID4
V-ID/COND4
{	
	if((opt(0)%2)!=0)
	{
		cmnd_wr4[16]=0x01;
		cmnd_wr4[8]=([COND4.1]+16);
		cmnd_wr4[10]=([COND4.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr4[12] = 2;
		}else if(m == 1){
			cmnd_wr4[12] = 3;
		}else if(m == 2){
			cmnd_wr4[12] = 4;
		}else if(m == 3){
			cmnd_wr4[12] = 1;
		}else if(m == 4){
			cmnd_wr4[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr4[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr4);} else write=0;
}
#endif

#ifdef ID5
V-ID/COND5
{
	if((opt(0)%2)!=0)
	{
		cmnd_wr5[16]=0x01;
		cmnd_wr5[8]=([COND5.1]+16);
		cmnd_wr5[10]=([COND5.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr5[12] = 2;
		}else if(m == 1){
			cmnd_wr5[12] = 3;
		}else if(m == 2){
			cmnd_wr5[12] = 4;
		}else if(m == 3){
			cmnd_wr5[12] = 1;
		}else if(m == 4){
			cmnd_wr5[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr5[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr5);} else write=0;
}
#endif

#ifdef ID6
V-ID/COND6
{
	if((opt(0)%2)!=0)
	{
		cmnd_wr6[16]=0x01;
		cmnd_wr6[8]=([COND6.1]+16);
		cmnd_wr6[10]=([COND6.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr6[12] = 2;
		}else if(m == 1){
			cmnd_wr6[12] = 3;
		}else if(m == 2){
			cmnd_wr6[12] = 4;
		}else if(m == 3){
			cmnd_wr6[12] = 1;
		}else if(m == 4){
			cmnd_wr6[12] = 0;}
	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr6[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr6);} else write=0;
}
#endif

#ifdef ID7
V-ID/COND7
{
	if((opt(0)%2)!=0)
	{
		cmnd_wr7[16]=0x01;
		cmnd_wr7[8]=([COND7.1]+16);
		cmnd_wr7[10]=([COND7.4]+1);
		u8 m = (opt(0) >> 4);
		if(m == 0){
			cmnd_wr7[12] = 2;
		}else if(m == 1){
			cmnd_wr7[12] = 3;
		}else if(m == 2){
			cmnd_wr7[12] = 4;
		}else if(m == 3){
			cmnd_wr7[12] = 1;
		}else if(m == 4){
			cmnd_wr7[12] = 0;}

	}
	else if((opt(0)%2)==0)
	{
		cmnd_wr7[16]=0x00;
	}
	if (write==0) {setStatus(RS485, &cmnd_wr7);} else write=0;
}
#endif

u8 syncIndex = 0;

V-ID/s:5 {
	++syncIndex; if (syncIndex==5) syncIndex=1;
//srvError("Сканируем кондей = %d", syncIndex);
	setStatus(RS485, {syncIndex, 0x03, 0x0001, 0x0005, 0xCC16});
}

void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

void check()
{
	if (optl==15) {if (opt(1)==0x03)
		{
			//Режим
			if (opt(8) == 3) {
				rezhim = 1;
			} else if(opt(8) == 2) {
				rezhim = 0;
			} else if (opt(8) == 1) {
				rezhim = 3;
			} else if (opt(8) == 0) {
				rezhim = 4;
			} else if (opt(8) == 4) {
				rezhim = 2;}
		}
	
		u8 k[6];
	
		#ifdef ID1
		if (opt(0)==ID1 && opt(1)==0x03)
		{
			getStatus(COND1, &k);
			if ([COND1.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND1.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND1.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND1.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND1.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND1.0]>>4, rezhim);}
			if (write==1) {setStatus(COND1, &k);}
		}
		#endif
	
		#ifdef ID2
		else
		if (opt(0)==ID2 && opt(1)==0x03)
		{
			getStatus(COND2, &k);
			if ([COND2.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND2.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND2.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND2.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND2.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND2.0]>>4, rezhim);}
			if (write==1) {setStatus(COND2, &k);}
		}
		#endif
		#ifdef ID3
		else
		if (opt(0)==ID3 && opt(1)==0x03)
		{
			getStatus(COND3, &k);
			if ([COND3.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND3.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND3.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND3.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND3.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND3.0]>>4, rezhim);}
			if (write==1) {setStatus(COND3, &k);}
		}
		#endif
		#ifdef ID4
		else
		if (opt(0)==ID4 && opt(1)==0x03)
		{
			getStatus(COND4, &k);
			if ([COND4.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND4.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND4.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND4.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND4.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND4.0]>>4, rezhim);}
			if (write==1) {setStatus(COND4, &k);}
		}
		#endif
			#ifdef ID5
		else
		if (opt(0)==ID5 && opt(1)==0x03)
		{
			getStatus(COND5, &k);
			if ([COND5.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND5.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND5.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND5.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND5.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND5.0]>>4, rezhim);}
			if (write==1) {setStatus(COND5, &k);}
		}
		#endif
			#ifdef ID6
		else
		if (opt(0)==ID6 && opt(1)==0x03)
		{
			getStatus(COND6, &k);
			if ([COND6.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND6.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND6.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND6.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND6.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND6.0]>>4, rezhim);}
			if (write==1) {setStatus(COND6, &k);}
		}
		#endif
			#ifdef ID7
		else
		if (opt(0)==ID7 && opt(1)==0x03)
		{
			getStatus(COND7, &k);
			if ([COND7.0]%2!=0 && opt(12)==0) {k[0]=(k[0]&0xFE); write=1; srvError("Выключить");} else
			if ([COND7.0]%2==0 && opt(12)==1) {k[0]=(k[0]|0x01); write=1; srvError("Включить");}
			if ((opt(4)-16)!=[COND7.1]) {k[1]=(opt(4)-16); write=1; srvError("Температура");}
			if ((opt(6)-1)!=[COND7.4]) {k[4]=(opt(6)-1); write=1; srvError("Обдув");}
			if (rezhim!=([COND7.0]>>4)) {k[0]=k[0]&0x0F; k[0]=rezhim<<4|k[0]; write=1; srvError("Режим=%x , переменная=%x", [COND7.0]>>4, rezhim);}
			if (write==1) {setStatus(COND7, &k);}
		}
		#endif}
}

V-ID/RS485
{
	//stat();
	check();
}



