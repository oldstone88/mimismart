/*
{
    desc:"Скоро буду",
    tag:"item",
    name:"Скоро буду",
    selectArea:true,
    
    vars:[
{name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Климат",descWidth:100},
{name:"I00",type:"devices-list",required:false,width:600,filter:["script"],desc:"Отпуск",descWidth:100},
    ]
}
*/

u8 kond[5];

void OFF()
{
    setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        #ifdef I00 setStatus(I00, 0); #endif
        getStatus(K00, &kond); kond[0]=1; kond[1]=6;
        setStatus(K00, &kond);
        delayedCall(OFF, 1);
    }
}