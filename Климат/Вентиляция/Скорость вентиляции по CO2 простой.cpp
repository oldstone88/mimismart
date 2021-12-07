/*
{
  desc:"Скорости вентиляции по CO2",
  tag:"item",
  selectArea:true,
  
  vars:
  [
    {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Установка",descWidth:100},
    {name:"O00",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 1",descWidth:100},
    {name:"O01",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 2",descWidth:100},
    {name:"O02",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 3",descWidth:100},
    {name:"O03",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 4",descWidth:100},
    {name:"O04",type:"devices-list",required:false,width:600,filter:["co2-sensor"],desc:"Сенсор 5",descWidth:100},
  ]
}
*/

u8 k[5];

V-ID/s:5
{
  if(([V-ADDR.0]&1)==1)
  {
    #ifdef O00 u16 pokazanie0=(([O00.0]*100/255)+([O00.1]*100)); #endif
    #ifdef O01 u16 pokazanie1=(([O01.0]*100/255)+([O01.1]*100)); #endif
    #ifdef O02 u16 pokazanie2=(([O02.0]*100/255)+([O02.1]*100)); #endif
    #ifdef O03 u16 pokazanie3=(([O03.0]*100/255)+([O03.1]*100)); #endif
    #ifdef O04 u16 pokazanie4=(([O04.0]*100/255)+([O04.1]*100)); #endif

    if (pokazanie0>700 #ifdef O01 || pokazanie1>700 #endif #ifdef O02 || pokazanie2>700 #endif #ifdef O03 || pokazanie3>700 #endif #ifdef O04 || pokazanie4>700 #endif)
        {getStatus(K00, &k); k[0]==1; k[4]=3; setStatus(K00, &k);} else
    if (pokazanie0>550 #ifdef O01 || pokazanie1>550 #endif #ifdef O02 || pokazanie2>550 #endif #ifdef O03 || pokazanie3>550 #endif #ifdef O04 || pokazanie4>550 #endif)
        {getStatus(K00, &k); k[0]==1; k[4]=2; setStatus(K00, &k);} else
    if (pokazanie0<=550 #ifdef O01 || pokazanie1<=550 #endif #ifdef O02 || pokazanie2<=550 #endif #ifdef O03 || pokazanie3<=550 #endif #ifdef O04 || pokazanie4<=550 #endif)
        {getStatus(K00, &k); k[0]==1; k[4]=1; setStatus(K00, &k);}
  }
}

