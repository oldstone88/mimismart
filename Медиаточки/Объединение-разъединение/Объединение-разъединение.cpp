/*
{
  desc:"Точки объеденить-разъединить",
  tag:"item",
  selectArea:true,
  name:"Установить параметры",
  
  vars:[
    {name:"ID",type:"number",required:true,defaultValue:1,min:1,max:100,desc:"ID cкрипта",descWidth:350},
  ]
}
*/

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        setStatus(1000:ID, 1);
    }
    else if((opt(0)&1)==0)
    {
        setStatus(1000:ID, 2);
    }
}