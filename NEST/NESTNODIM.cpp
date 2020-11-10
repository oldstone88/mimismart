/*
{
desc:"NEST",
"name":"NEST",
"name-ru":"NEST",  
tag:"item",
vars:[

{name:"G0",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости отопление"},
{name:"G1",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 2й скорости отопление"},

{name:"G2",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 1й скорости охлаждение"},
{name:"G3",type:"devices-list",required:true, filter:["door-sensor"],desc:"Геркон 2й скорости охлаждение"},

{name:"R0",type:"devices-list",required:true, filter:["valve-heating"],desc:"Радиатор"},
{name:"V0",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Кондиционер",descWidth:100},

  ]                       
}
*/

u8 k[5];

V-ID/V-ADDR
{
if( [V-ADDR.0]==1 )
	{
	// отопление
	setStatus(1000:102, "R0\0as:-4");
	if( [G0.0]==1 ) setStatus(R0, 1); else
	setStatus(R0, 0);
	//Кондиционер
	if( [G2.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=1; setStatus(V0, &k);} else
	if( [G3.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=2; setStatus(V0, &k);} else
	{getStatus(V0, &k); k[0]=16; setStatus(V0, &k);}
	}
	else
	{
	setStatus(1000:102, "R0\0Mode");
	}
}

V-ID/s:5
{
if( [V-ADDR.0]==1 )
	{
	//Отопление
	if( [G0.0]==1 ) setStatus(R0, 1); else
	setStatus(R0, 0);
	//Кондиционер
	if( [G2.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=1; setStatus(V0, &k);} else
	if( [G3.0]==1 ) {getStatus(V0, &k); k[0]=17; k[4]=2; setStatus(V0, &k);} else
	{getStatus(V0, &k); k[0]=16; setStatus(V0, &k);}
	}
	
}