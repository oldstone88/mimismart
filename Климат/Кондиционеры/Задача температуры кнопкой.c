/*
{
desc:"Климат 21",
"name":"Климат 21",  
selectArea:true,
tag:"item",
vars:[

{type:"comment",text:"Выберите вентиляцию",width:200, style:"color:red;"},
{name:"V00",type:"devices-list",required:true, filter:["conditioner"],width:888,desc:"Вентиляция"},
{name:"T00",type:"number",required:true,min:1,max:30,defaultValue:21,descWidth:150,desc:"Нужная температура"},

  ]                       
}
*/
u8 kond[6];

void OFF ()
{
    setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
    if ([V-ADDR.0]==1)
    {
        getStatus(V00, &kond);
        kond[1]=T00-16;
        setStatus(V00, &kond);
        delayedCall(OFF, 1);
    }
}