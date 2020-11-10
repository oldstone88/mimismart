/*
{
desc:"NESTDIM",
"name":"NESTDIM",
"name-ru":"NESTDIM",  
tag:"item",
vars:[

{name:"G0",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости обогрев"},
{name:"G1",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 2й скорости обогрев"},
{name:"G2",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости охлаждение"},
{name:"G3",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 2й скорости охлаждение"},
{name:"T0",type:"devices-list",required:true, filter:["temperature-sensor"],desc:"Датчик температуры"},
{name:"D0",type:"devices-list",required:true, filter:["dimer-lamp"],desc:"Вентилятор"},
{name:"R0",type:"devices-list",required:true, filter:["valve-heating"],desc:"Радиатор"},
{name:"V0",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
{name:"Porog0", type:"number", required:true, defaultValue:1, min:1, max:10, desc:"Порог 1й скорости", descWidth:300},
{name:"Porog1", type:"number", required:true, defaultValue:3, min:1, max:15, desc:"Порог 2й скорости", descWidth:300},
{name:"Porog2", type:"number", required:true, defaultValue:4, min:1, max:20, desc:"Порог 3й скорости", descWidth:300},

  ]                       
}ьд
*/

u8 i;
u8 k[5];

V-ID/V-ADDR
{
if( [V-ADDR.0]==1 )
	{
	//Отопление
	setStatus(1000:102, "R0\0as:-4");
	if( [G1.0]==1 ) {setStatus(D0, {1,175,0}); setStatus(R0,1);} else
	if( [G0.0]==1 ) {setStatus(D0, {1,75,0}); setStatus(R0,1);} else
	{setStatus(D0, 0); setStatus(R0,0);}
	//Кондиционер
	if( [G2.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=1; setStatus(V0, &k);} else
	if( [G3.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=2; setStatus(V0, &k);} else
	{getStatus(V0, &k); k[0]=16; setStatus(V0, &k);}
	}
	else
	{
	setStatus(1000:102, "R0\0Mode");
	i=[R0.2];
	srvError("Температура = %d", i);
	if ( i-[T0.1]+100>Porog2+100 ) setStatus(D0, {1,250,0}); else
	if ( i-[T0.1]+100>Porog1+100 ) setStatus(D0, {1,175,0}); else
	if ( i-[T0.1]+100>Porog0+100 ) setStatus(D0, {1,75,0}); else
	setStatus(D0,0);
	}
}

V-ID/s:5
{
if( [V-ADDR.0]==1 )
	{
	//Отопление
	if( [G1.0]==1 ) {setStatus(D0, {1,175,0}); setStatus(R0,1);} else
	if( [G0.0]==1 ) {setStatus(D0, {1,75,0}); setStatus(R0,1);} else
	{setStatus(D0, 0); setStatus(R0,0);}
	//Кондиционер
	if( [G2.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=1; setStatus(V0, &k);} else
	if( [G3.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=2; setStatus(V0, &k);} else
	{getStatus(V0, &k); k[0]=16; setStatus(V0, &k);}
	}
	else
if( [R0.0]!=0 && [R0.5]!=255 )
	{
	i=[R0.2];
	//srvError("Температура = %d", i);
	if ( i-[T0.1]+100>Porog2+100 ) setStatus(D0, {1,250,0}); else
	if ( i-[T0.1]+100>Porog1+100 ) setStatus(D0, {1,175,0}); else
	if ( i-[T0.1]+100>Porog0+100 ) setStatus(D0, {1,75,0}); else
	setStatus(D0,0);
	} else
	if( [R0.0]==0 ) setStatus(D0,0);
}	
