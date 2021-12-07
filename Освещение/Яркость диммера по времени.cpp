/*
{
  desc:"По времени",
  tag:"import-script",
  selectArea:true,
  
  vars:[
    {type:"comment",text:"Все димеры кроме СУ:",width:200, style:"color:red;"},
    {name:"LAMP1",type:"devices-list",required:true,width:800,filter:["dimer-lamp"],desc:"Устройство 1",descWidth:100},
    {name:"LAMP2",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 2",descWidth:100},
    {name:"LAMP3",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 3",descWidth:100},
    {name:"LAMP4",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 4",descWidth:100},
    {name:"LAMP5",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 5",descWidth:100},
    {name:"LAMP6",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 6",descWidth:100},
    {name:"LAMP7",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 7",descWidth:100},
    {name:"LAMP8",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 8",descWidth:100},
    {name:"LAMP9",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 9",descWidth:100},
    {name:"LAMP10",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 10",descWidth:100},
    {name:"LAMP20",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 20",descWidth:100},
    {name:"LAMP30",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 30",descWidth:100},
    {name:"LAMP40",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 40",descWidth:100},
    {name:"LAMP50",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 50",descWidth:100},
    {name:"LAMP60",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 60",descWidth:100},
    {name:"LAMP70",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 70",descWidth:100},
    {name:"LAMP80",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 80",descWidth:100},
    {name:"LAMP90",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 90",descWidth:100},
  ]
}
*/

u8 britnes=0;

V-ID/s:5
{
  u8 res = timeInRange(20:30-7:00);
  if (res!=0) britnes=107; else
  britnes=250;
  
}

u8 i[19];

#ifdef LAMP1
  V-ID/
  {if (([~LAMP1.0]&1)==1 && i[1]==0) {setStatus(LAMP1, {0xFE, britnes, 0}); i[1]=1;} else if(([LAMP1.0]&1)==0) {i[1]=0;}}
#endif

#ifdef LAMP2
  V-ID/
  {if (([~LAMP2.0]&1)==1 && i[2]==0) {setStatus(LAMP2, {0xFE, britnes, 0}); i[2]=1;} else if(([LAMP2.0]&1)==0) {i[2]=0;}}
#endif

  #ifdef LAMP3
  V-ID/
  {if (([~LAMP3.0]&1)==1 && i[3]==0) {setStatus(LAMP3, {0xFE, britnes, 0}); i[3]=1;} else if(([LAMP3.0]&1)==0) {i[3]=0;}}
#endif

  #ifdef LAMP4
  V-ID/
  {if (([~LAMP4.0]&1)==1 && i[4]==0) {setStatus(LAMP4, {0xFE, britnes, 0}); i[4]=1;} else if(([LAMP4.0]&1)==0) {i[4]=0;}}
#endif

  #ifdef LAMP5
  V-ID/
  {if (([~LAMP5.0]&1)==1 && i[5]==0) {setStatus(LAMP5, {0xFE, britnes, 0}); i[5]=1;} else if(([LAMP5.0]&1)==0) {i[5]=0;}}
#endif

  #ifdef LAMP6
  V-ID/
  {if (([~LAMP6.0]&1)==1 && i[6]==0) {setStatus(LAMP6, {0xFE, britnes, 0}); i[6]=1;} else if(([LAMP6.0]&1)==0) {i[6]=0;}}
#endif

  #ifdef LAMP7
  V-ID/
  {if (([~LAMP7.0]&1)==1 && i[7]==0) {setStatus(LAMP7, {0xFE, britnes, 0}); i[7]=1;} else if(([LAMP7.0]&1)==0) {i[7]=0;}}
#endif

  #ifdef LAMP8
  V-ID/
  {if (([~LAMP8.0]&1)==1 && i[8]==0) {setStatus(LAMP8, {0xFE, britnes, 0}); i[8]=1;} else if(([LAMP8.0]&1)==0) {i[8]=0;}}
#endif

  #ifdef LAMP9
  V-ID/
  {if (([~LAMP9.0]&1)==1 && i[9]==0) {setStatus(LAMP9, {0xFE, britnes, 0}); i[9]=1;} else if(([LAMP9.0]&1)==0) {i[9]=0;}}
#endif

  #ifdef LAMP10
  V-ID/
  {if (([~LAMP10.0]&1)==1 && i[10]==0) {setStatus(LAMP10, {0xFE, britnes, 0}); i[10]=1;} else if(([LAMP10.0]&1)==0) {i[10]=0;}}
#endif

  #ifdef LAMP20
  V-ID/
  {if (([~LAMP20.0]&1)==1 && i[11]==0) {setStatus(LAMP20, {0xFE, britnes, 0}); i[11]=1;} else if(([LAMP20.0]&1)==0) {i[11]=0;}}
#endif

  #ifdef LAMP30
  V-ID/
  {if (([~LAMP30.0]&1)==1 && i[12]==0) {setStatus(LAMP30, {0xFE, britnes, 0}); i[12]=1;} else if(([LAMP30.0]&1)==0) {i[12]=0;}}
#endif

  #ifdef LAMP40
  V-ID/
  {if (([~LAMP40.0]&1)==1 && i[13]==0) {setStatus(LAMP40, {0xFE, britnes, 0}); i[13]=1;} else if(([LAMP40.0]&1)==0) {i[13]=0;}}
#endif

  #ifdef LAMP50
  V-ID/
  {if (([~LAMP50.0]&1)==1 && i[14]==0) {setStatus(LAMP50, {0xFE, britnes, 0}); i[14]=1;} else if(([LAMP50.0]&1)==0) {i[14]=0;}}
#endif

  #ifdef LAMP60
  V-ID/
  {if (([~LAMP60.0]&1)==1 && i[15]==0) {setStatus(LAMP60, {0xFE, britnes, 0}); i[15]=1;} else if(([LAMP60.0]&1)==0) {i[15]=0;}}
#endif

  #ifdef LAMP70
  V-ID/
  {if (([~LAMP70.0]&1)==1 && i[16]==0) {setStatus(LAMP70, {0xFE, britnes, 0}); i[16]=1;} else if(([LAMP70.0]&1)==0) {i[16]=0;}}
#endif

  #ifdef LAMP80
  V-ID/
  {if (([~LAMP80.0]&1)==1 && i[17]==0) {setStatus(LAMP80, {0xFE, britnes, 0}); i[17]=1;} else if(([LAMP80.0]&1)==0) {i[17]=0;}}
#endif

  #ifdef LAMP90
  V-ID/
  {if (([~LAMP90.0]&1)==1 && i[18]==0) {setStatus(LAMP90, {0xFE, britnes, 0}); i[18]=1;} else if(([LAMP90.0]&1)==0) {i[18]=0;}}
#endif