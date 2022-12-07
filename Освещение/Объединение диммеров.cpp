/*
{
  desc:"Звонок на медиаточку",
  
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"DIMMER",type:"devices-list",required:true, filter:["virtual"],desc:"Диммер-громкость(Виртуальный)"},
    {name:"I00",type:"devices-list",required:true, filter:["dimer-lamp"],desc:"Диммер 0"},
    {name:"I01",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 1"},
    {name:"I02",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 2"},
    {name:"I03",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 3"},
    {name:"I04",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 4"},
    {name:"I05",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 5"},
    {name:"I06",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 6"},
    {name:"I07",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 7"},
    {name:"I08",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 8"},
    {name:"I09",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 9"},
    {name:"I10",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 10"},
    {name:"I11",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 11"},
    {name:"I12",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 12"},
    {name:"I13",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 13"},
    {name:"I14",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 14"},
    {name:"I15",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 15"},
    {name:"I16",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 16"},
    {name:"I17",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 17"},
    {name:"I18",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 18"},
    {name:"I19",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 19"},
    {name:"I20",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 20"},

]
}
*/

//Необходимо создать виртуальный диммер, можно на домофоне
//<item addr="589:249" image="switch" length="0" name="громкость" sub-type="dimer-lamp" type="virtual"/>

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

V-ID/s:1
{
      #ifdef I00 setStatus(I00, {state[0], state[1], 0}); #endif
      #ifdef I01 setStatus(I01, {state[0], state[1], 0}); #endif
      #ifdef I02 setStatus(I02, {state[0], state[1], 0}); #endif
      #ifdef I03 setStatus(I03, {state[0], state[1], 0}); #endif
      #ifdef I04 setStatus(I04, {state[0], state[1], 0}); #endif
      #ifdef I05 setStatus(I05, {state[0], state[1], 0}); #endif
      #ifdef I06 setStatus(I06, {state[0], state[1], 0}); #endif
      #ifdef I07 setStatus(I07, {state[0], state[1], 0}); #endif
      #ifdef I08 setStatus(I08, {state[0], state[1], 0}); #endif
      #ifdef I09 setStatus(I09, {state[0], state[1], 0}); #endif
      #ifdef I10 setStatus(I10, {state[0], state[1], 0}); #endif
      #ifdef I11 setStatus(I11, {state[0], state[1], 0}); #endif
      #ifdef I12 setStatus(I12, {state[0], state[1], 0}); #endif
      #ifdef I13 setStatus(I13, {state[0], state[1], 0}); #endif
      #ifdef I14 setStatus(I14, {state[0], state[1], 0}); #endif
      #ifdef I15 setStatus(I15, {state[0], state[1], 0}); #endif
      #ifdef I16 setStatus(I16, {state[0], state[1], 0}); #endif
      #ifdef I17 setStatus(I17, {state[0], state[1], 0}); #endif
      #ifdef I18 setStatus(I18, {state[0], state[1], 0}); #endif
      #ifdef I19 setStatus(I19, {state[0], state[1], 0}); #endif
      #ifdef I20 setStatus(I20, {state[0], state[1], 0}); #endif
}