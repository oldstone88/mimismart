/*
{
  desc:"Я ушел",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"L00",type:"devices-list",required:false,filter:["script"],desc:"Выкл. весь свет"},
    {name:"K00",type:"devices-list",required:false,filter:["conditioner"],desc:"Весь климат"},
  ]
}
*/

u8 k[5];

void OFF()
{setStatus(V-ADDR, 0);}

V-ID/V-ADDR
{
  if( (opt(0)&1)==1 )
  {
    setStatus(L00, 1);
    getStatus(K00, &k);
    if(k[0]%2==1) {k[0]=k[0]&0xFE; setStatus(K00, &k);}
    setStatus(1000:100, "Эко");
    delayedCall(OFF, 1);
  }
}