/*
{
  desc:"Звонок на медиаточку",
  
  tag:"item",
  selectArea:true,
  vars:[
   	{name:"MRMR0",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR1",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR2",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR3",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR4",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},

{name:"VOLUME",type:"number",required:true,width:100,defaultValue:200,min:0,max:250,desc:"Громкость оповещения"},

]
}
*/

u8 i0[2];
u8 i1[2];
u8 i2[2];
u8 i3[2];
u8 i4[2];

void DOM()
{
  setStatus(V-ADDR, 0);
}

void V0()
{
  if(i0[0]==1) setStatus(MRMR0,{4, i0[1]}); else setStatus(MRMR0,{4, 75});
}

#ifdef MRMR1
void V1()
{
  if(i1[0]==1) setStatus(MRMR1,{4, i1[1]}); else setStatus(MRMR1,{4, 75});
}
#endif

#ifdef MRMR2
void V2()
{
  if(i2[0]==1) setStatus(MRMR2,{4, i2[1]}); else setStatus(MRMR2,{4, 75});
}
#endif

#ifdef MRMR3
void V3()
{
  if(i3[0]==1) setStatus(MRMR3,{4, i3[1]}); else setStatus(MRMR3,{4, 75});
}
#endif

#ifdef MRMR4
void V4()
{
  if(i4[0]==1) setStatus(MRMR4,{4, i4[1]}); else setStatus(MRMR4,{4, 75});
}
#endif

V-ID/V-ADDR{ 
if(opt(0) == 1)
    {
        getStatus(MRMR0, &i0);
        setStatus(MRMR0,{1, VOLUME, 0, "http://192.168.1.125/Ding.mp3"});
        delayedCall(V0, 2);
        #ifdef MRMR1
        getStatus(MRMR1, &i1);
        setStatus(MRMR1,{1, VOLUME, 0, "http://192.168.1.125/Ding.mp3"});
        delayedCall(V1, 2);
        #endif
        #ifdef MRMR2
        getStatus(MRMR2, &i2);
        setStatus(MRMR2,{1, VOLUME, 0, "http://192.168.1.125/Ding.mp3"});
        delayedCall(V2, 2);
        #endif
        #ifdef MRMR3
        getStatus(MRMR3, &i3);
        setStatus(MRMR3,{1, VOLUME, 0, "http://192.168.1.125/Ding.mp3"});
        delayedCall(V3, 2);
        #endif
        #ifdef MRMR4
        getStatus(MRMR4, &i4);
        setStatus(MRMR4,{1, VOLUME, 0, "http://192.168.1.125/Ding.mp3"});
        delayedCall(V4, 2);
        #endif

         delayedCallMs(DOM, 200 );
     
        }
}
