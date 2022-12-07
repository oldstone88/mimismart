/*
{
desc:"Климат 21",
"name":"Климат 21",  
selectArea:true,
tag:"item",
vars:[

{type:"comment",text:"Выберите кондиционеры",width:200, style:"color:red;"},
{name:"V00",type:"devices-list",required:false, filter:["conditioner"],width:888,desc:"Кондиционер"},
{name:"V01",type:"devices-list",required:false, filter:["conditioner"],width:888,desc:"Кондиционер"},
{name:"V02",type:"devices-list",required:false, filter:["conditioner"],width:888,desc:"Кондиционер"},
{name:"V03",type:"devices-list",required:false, filter:["conditioner"],width:888,desc:"Кондиционер"},
{name:"V04",type:"devices-list",required:false, filter:["conditioner"],width:888,desc:"Кондиционер"},
{name:"T00",type:"number",required:true,min:1,max:30,defaultValue:21,descWidth:150,desc:"Нужная температура"},

  ]                       
}
*/

//Нужно делать маски под ваш кондиционер!!!

void OFF ()
{
    setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
    if ([V-ADDR.0]==1)
    {   
        u8 kond[5]={49, T00-16, 0, 0, 0};
        #ifdef V00
        setStatus(V00, &kond);
        #endif
        #ifdef V01
        setStatus(V01, &kond);
        #endif
        #ifdef V02
        setStatus(V02, &kond);
        #endif
        #ifdef V03
        setStatus(V03, &kond);
        #endif
        #ifdef V04
        setStatus(V04, &kond);
        #endif
        delayedCall(OFF, 1);
    }
}