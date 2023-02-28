/*
{
desc:"AC3-rezhimi",
tag:"item",
selectArea:true,
name:"Bluetooth",

addItems:[
    {tag:"item", id:"%TARGET%", name:"Bluetooth", "sub-id":"%SUBID97%", type:"script"},
    {tag:"item", id:"%TARGET%", name:"Optical", "sub-id":"%SUBID95%", type:"script"},
  ],

vars:[
    {name:"IP",type:"text",required:true,defaultValue:"192.168.1.100",filter:"0123456789.",desc:"IP Адрес AC3"},
    {name:"ID",type:"number",required:true,min:0,max:99,defaultValue:49},
    {name:"BLT",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"SPDIF",type:"hidden",value:"%TARGET%:%SUBID95%"},
]
}
*/

void OFF()
{
    setStatus(V-ADDR, 0);
    setStatus(BLT, 0);
    setStatus(SPDIF,0);
}

V-ID/V-ADDR
{
    if(opt(0)&1==1) {setStatus(1000:ID, "signal=1|address=IP|"); delayedCall(OFF, 1);}
}

V-ID/BLT
{
    if(opt(0)&1==1) {setStatus(1000:ID, "signal=2|address=IP|"); delayedCall(OFF, 1);}
}

V-ID/SPDIF
{
    if(opt(0)&1==1) {setStatus(1000:ID, "signal=3|address=IP|"); delayedCall(OFF, 1);}
}