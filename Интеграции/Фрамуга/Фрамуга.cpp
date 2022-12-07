/*
{
  desc:"Фрамуга",
  name:"Фрамуга",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", sub-id:"%SUBID%", type:"virtual", sub-type:"dimer-lamp", name:"Фрамуга"},
  ],
  vars:[
    {name:"ID", type:"number", defaultValue:70, required:true, desc:"ID скрипта"},
    {name:"DIMMER",type:"hidden",value:"%TARGET%:%SUBID%"}
]
}
*/

u8 state [] = {0,0};

void gostatus()
{
    setStatus(1000:ID, (state[1]*100/250));
}

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
        cancelDelayedCall(gostatus);
      state[0]=opt(0);
      state[1]=opt(1);
      delayedCall(gostatus, 1);
    }
}
