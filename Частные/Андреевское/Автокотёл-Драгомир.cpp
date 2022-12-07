/*
{
desc:"АвтоКотёл",
tag:"item",
selectArea:true,

vars:[
{type:"comment",text:"Бойлер",width:600, "style":"color:red; font-weight:bold"},
{name:"B00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Бойлер",descWidth:100},
{type:"comment",text:"Котёл которы греет бойлер",width:600, "style":"color:red; font-weight:bold"},
{name:"K00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Котёл",descWidth:100},
]
}
*/

void onInit()
{
	setStatus(V-ADDR, 1);
}

V-ID/s:10
{
   if( ([B00.0]&1)==1 )
   {
      if( ([K00.0]&1)==0 ) {setStatus(1000:102,"K00\0as:-4"); setStatus(K00, 1);}
   }
   else if( ([B00.0]&1)==0 )
   {
      if( ([K00.0]&1)==1 ) {setStatus(1000:102,"K00\0as:-1");}
   }
}