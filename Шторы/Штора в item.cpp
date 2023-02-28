/*
{
	desc-ru:"Штора по кнопке",
	tag:"item",
	selectArea:true,

	vars:[

    {type:"comment",text:"Укажите устройства:",width:200, style:"color:red;"},
    {name:"B00",type:"devices-list",required:true,filter:["jalousie", "virtual"],width:888,desc:"Штора"},
	]
}
*/

u8 i=0;

V-ID/V-ADDR
{
    if ( ([B00.0]&7)==0 ) {setStatus(B00, 1); i=1;} else
    if ( ([B00.0]&7)==1 ) {setStatus(B00, 0); i=0;} else
    if ( ([B00.0]&7)==4 && i==1 ) {setStatus(B00, 0); i=0;} else
    if ( ([B00.0]&7)==4 && i==0 ) {setStatus(B00, 1); i=1;} else
    {setStatus(B00, 1);}
}