/*
{
  desc:"Блоки питания",
  tag:"import-script",
  selectArea:true,
  vars:[
{name:"P00",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D00",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P01",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D01",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P02",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D02",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P03",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D03",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P04",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D04",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P05",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D05",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P06",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D06",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P07",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D07",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P08",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D08",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
{name:"P09",type:"devices-list",required:false, filter:["lamp"],desc:"Блок питания"},
{name:"D09",type:"devices-list",required:false, filter:["dimer-lamp","rgb-lamp"],desc:"Диммер"},
  ]                       
}
*/

V-ID/D00
{
  if( (opt(0)&1)==1 ) {setStatus(P00, 1);} else if( (opt(0)&1)==0 ) {setStatus(P00, 0);}
}

#ifdef D01
V-ID/D01
{
  if( (opt(0)&1)==1 ) {setStatus(P01, 1);} else if( (opt(0)&1)==0 ) {setStatus(P01, 0);}
}
#endif

#ifdef D02
V-ID/D02
{
  if( (opt(0)&1)==1 ) {setStatus(P02, 1);} else if( (opt(0)&1)==0 ) {setStatus(P02, 0);}
}
#endif

#ifdef D03
V-ID/D03
{
  if( (opt(0)&1)==1 ) {setStatus(P03, 1);} else if( (opt(0)&1)==0 ) {setStatus(P03, 0);}
}
#endif

#ifdef D04
V-ID/D04
{
  if( (opt(0)&1)==1 ) {setStatus(P04, 1);} else if( (opt(0)&1)==0 ) {setStatus(P04, 0);}
}
#endif

#ifdef D05
V-ID/D05
{
  if( (opt(0)&1)==1 ) {setStatus(P05, 1);} else if( (opt(0)&1)==0 ) {setStatus(P05, 0);}
}
#endif

#ifdef D06
V-ID/D06
{
  if( (opt(0)&1)==1 ) {setStatus(P06, 1);} else if( (opt(0)&1)==0 ) {setStatus(P06, 0);}
}
#endif

#ifdef D07
V-ID/D07
{
  if( (opt(0)&1)==1 ) {setStatus(P07, 1);} else if( (opt(0)&1)==0 ) {setStatus(P07, 0);}
}
#endif

#ifdef D08
V-ID/D08
{
  if( (opt(0)&1)==1 ) {setStatus(P08, 1);} else if( (opt(0)&1)==0 ) {setStatus(P08, 0);}
}
#endif

#ifdef D09
V-ID/D09
{
  if( (opt(0)&1)==1 ) {setStatus(P09, 1);} else if( (opt(0)&1)==0 ) {setStatus(P09, 0);}
}
#endif