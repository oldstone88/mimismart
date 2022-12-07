/*
{
  desc:"Звонок на медиаточку",
  
  tag:"item",
  selectArea:true,
  vars:[
    {name:"DIMMER",type:"devices-list",required:false, filter:["virtual"],desc:"Диммер-громкость(Виртуальный)"},
    {name:"MRMR0",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR1",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR2",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR3",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
    {name:"MRMR4",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
]
}
*/

//Необходимо создать виртуальный диммер, можно на домофоне
//<item addr="589:249" image="switch" length="0" name="громкость" sub-type="dimer-lamp" type="virtual"/>

u8 i0[2];
#ifdef MRMR1 u8 i1[2]; #endif
#ifdef MRMR2 u8 i2[2]; #endif
#ifdef MRMR3 u8 i3[2]; #endif
#ifdef MRMR4 u8 i4[2]; #endif

u8 state [] = {0,0};

V-ID/DIMMER
{
    if (opt(0)==0xff)
    {
        state[0] = state[0] ? 0:1;
        setStatus(DIMMER,state);
    }
    else if (opt(0)==0xfe)
    {
        state[1] = opt(1);
        setStatus(DIMMER,state);
    }
    else
    {
      state[0]=opt(0);
      state[1]=opt(1);
    }
}

void onInit()
{
  setStatus(DIMMER, {1, 125});
}

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
        setStatus(2047:32, {3, "Звонок в дверь!"});
        if(state[0]==1) {getStatus(MRMR0, &i0);
                setStatus(MRMR0,{1, state[1], 1, "http://192.168.1.125/Ding.mp3"});
                delayedCall(V0, 3);}
        #ifdef MRMR1
        if(state[0]==1){getStatus(MRMR1, &i1);
                setStatus(MRMR1,{1, state[1], 1, "http://192.168.1.125/Ding.mp3"});
                delayedCall(V1, 3);}
        #endif
        #ifdef MRMR2
        if(state[0]==1){getStatus(MRMR2, &i2);
                setStatus(MRMR2,{1, state[1], 1, "http://192.168.1.125/Ding.mp3"});
                delayedCall(V2, 3);}
        #endif
        #ifdef MRMR3
        if(state[0]==1){getStatus(MRMR3, &i3);
                setStatus(MRMR3,{1, state[1], 1, "http://192.168.1.125/Ding.mp3"});
                delayedCall(V3, 3);}
        #endif
        #ifdef MRMR4
        if(state[0]==1) {getStatus(MRMR4, &i4);
                setStatus(MRMR4,{1, state[1], 1, "http://192.168.1.125/Ding.mp3"});
                delayedCall(V4, 3);}
        #endif

         delayedCallMs(DOM, 200 );
     
        }
}
