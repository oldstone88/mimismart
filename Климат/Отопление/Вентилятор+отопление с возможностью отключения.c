/*
{
  desc:"Отопление со скоростями",
  tag:"item",
  selectArea:true,
  vars:[
{type:"comment",text:"Выберите элементы, которые нужно выключить",width:600, "style":"color:red; font-weight:bold"},

{name:"V0",type:"devices-list",required:true, filter:["valve-heating"],descWidth:150, desc:"Батарея"},
{name:"D0",type:"devices-list",required:true, filter:["dimer-lamp"],desc:"Вентилятор"},
{name:"T0",type:"devices-list",required:true, filter:["temperature-sensor"],descWidth:150, desc:"Датчик темпиратуры"},


  ]                       
}
*/

V-ID/s:5{
  if(([V-ADDR.0]&1)==1){
    if( (([V0.0]&1)==1) && ([V0.5]!=255) && ([V0.5]!=254) ){
      if( ([V0.2])>([T0.1]+4)) {setStatus(D0, {1,250,5});} else
      if( ([V0.2])>([T0.1]+3)) {setStatus(D0, {1,200,5});} else
      if( ([V0.2])>([T0.1]+2)) {setStatus(D0, {1,150,5});} else
      if( ([V0.2])>([T0.1]+1)) {setStatus(D0, {1,100,5});} else
      if( ([V0.2])>([T0.1])) {setStatus(D0, {1,50,5});} else
      setStatus(D0, {0,0,5});
    } else if([V0.5]!=255) setStatus(D0, {0,0,5});
  }
}


V-ID/V-ADDR{
  if((opt(0)&1)==0) setStatus(D0, {0,0,5});
}