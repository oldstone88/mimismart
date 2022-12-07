/*
{
  desc:"Диммер по времени",
  tag:"import-script",
  selectArea:true,
  
  vars:[
    {type:"comment",text:"Яркость с 6:00 до 9:00",width:200, style:"color:red;"},
    {name:"YAR10",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 1 0-250"},
    {type:"comment",text:"Яркость с 9:01 до 16:00",width:200, style:"color:red;"},
    {name:"YAR11",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 1 0-250"},
    {type:"comment",text:"Яркость с 16:01 до 22:00",width:200, style:"color:red;"},
    {name:"YAR12",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 1 0-250"},
    {type:"comment",text:"Яркость с 22:01 до 5:59",width:200, style:"color:red;"},
    {name:"YAR13",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 1 0-250"},
    {name:"LAMP1",type:"devices-list",required:true,width:800,filter:["dimer-lamp"],desc:"Устройство 1",descWidth:100},
    {type:"comment",text:"Яркость с 6:00 до 9:00",width:200, style:"color:red;"},
    {name:"YAR20",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 2 0-250"},
    {type:"comment",text:"Яркость с 9:01 до 16:00",width:200, style:"color:red;"},
    {name:"YAR21",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 2 0-250"},
    {type:"comment",text:"Яркость с 16:01 до 22:00",width:200, style:"color:red;"},
    {name:"YAR22",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 2 0-250"},
    {type:"comment",text:"Яркость с 22:01 до 5:59",width:200, style:"color:red;"},
    {name:"YAR23",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 2 0-250"},
    {name:"LAMP2",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 2",descWidth:100},
    {type:"comment",text:"Яркость с 6:00 до 9:00",width:200, style:"color:red;"},
    {name:"YAR30",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 3 0-250"},
    {type:"comment",text:"Яркость с 9:01 до 16:00",width:200, style:"color:red;"},
    {name:"YAR31",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 3 0-250"},
    {type:"comment",text:"Яркость с 16:01 до 22:00",width:200, style:"color:red;"},
    {name:"YAR32",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 3 0-250"},
    {type:"comment",text:"Яркость с 22:01 до 5:59",width:200, style:"color:red;"},
    {name:"YAR33",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 3 0-250"},
    {name:"LAMP3",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 3",descWidth:100},
    {type:"comment",text:"Яркость с 6:00 до 9:00",width:200, style:"color:red;"},
    {name:"YAR40",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 4 0-250"},
    {type:"comment",text:"Яркость с 9:01 до 16:00",width:200, style:"color:red;"},
    {name:"YAR41",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 4 0-250"},
    {type:"comment",text:"Яркость с 16:01 до 22:00",width:200, style:"color:red;"},
    {name:"YAR42",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 4 0-250"},
    {type:"comment",text:"Яркость с 22:01 до 5:59",width:200, style:"color:red;"},
    {name:"YAR43",type:"number",min:"0",max:"250",required:true,defaultValue:"1",desc:"Яркость лампы 4 0-250"},
    {name:"LAMP4",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Устройство 4",descWidth:100},
  ]
}
*/

u8 britnes[4];

V-ID/s:5
{
  u8 res = timeInRange(6:00-9:00);
  if (res!=0)
    {
      britnes[0]=YAR10;
      britnes[1]=YAR20;
      britnes[2]=YAR30;
      britnes[3]=YAR40;
    } else
  {
    res=timeInRange(9:01-16:00);
    if (res!=0)
      {
        britnes[0]=YAR11;
        britnes[1]=YAR21;
        britnes[2]=YAR31;
        britnes[3]=YAR41;
      } else
    {
      res=timeInRange(16:01-22:00);
      if (res!=0)
        {
          britnes[0]=YAR12;
          britnes[1]=YAR22;
          britnes[2]=YAR32;
          britnes[3]=YAR42;
        } else
      {
        britnes[0]=YAR13;
        britnes[1]=YAR23;
        britnes[2]=YAR33;
        britnes[3]=YAR43;
      }
    }
  }
}

u8 i[4];

#ifdef LAMP1
  V-ID/
  {if (([~LAMP1.0]&1)==1 && i[1]==0) {setStatus(LAMP1, {0xFE, britnes[0], 0}); i[0]=1;} else if(([LAMP1.0]&1)==0) {i[0]=0;}}
#endif

#ifdef LAMP2
  V-ID/
  {if (([~LAMP2.0]&1)==1 && i[2]==0) {setStatus(LAMP2, {0xFE, britnes[1], 0}); i[1]=1;} else if(([LAMP2.0]&1)==0) {i[1]=0;}}
#endif

  #ifdef LAMP3
  V-ID/
  {if (([~LAMP3.0]&1)==1 && i[3]==0) {setStatus(LAMP3, {0xFE, britnes[2], 0}); i[2]=1;} else if(([LAMP3.0]&1)==0) {i[2]=0;}}
#endif

  #ifdef LAMP4
  V-ID/
  {if (([~LAMP4.0]&1)==1 && i[4]==0) {setStatus(LAMP4, {0xFE, britnes[3], 0}); i[3]=1;} else if(([LAMP4.0]&1)==0) {i[3]=0;}}
#endif
