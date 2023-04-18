/*
{
  desc:"Диммер с обрезкой",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"V00",type:"devices-list",required:true,width:600,filter:["dimer-lamp", "virtual"],desc:"Диммер виртуальный",descWidth:100},
    {name:"R00",type:"devices-list",required:true,width:600,filter:["dimer-lamp", "virtual"],desc:"Диммер реальный",descWidth:100},
  ]
}
*/

u8 state [2] = {0,0};
u8 i[3] = {0,0,0};

V-ID/V00
{
    if (opt(0)==0xff)
    {
        state[0] = state[0] ? 0:1;
        setStatus(V00,state);
    }
    else if (opt(0)==0xfe)
    {
        state[1] = opt(1);
        setStatus(V00,state);
    } else
    {
        i[0]=state[0];
        i[1]=state[1];
        if(i[1]<15) i[1]=15;
        setStatus(R00, &i);
    }

}

V-ID/s:5
{
  state[0]=[R00.0];
  state[1]=[R00.1];
  setStatus(V00,state);
}