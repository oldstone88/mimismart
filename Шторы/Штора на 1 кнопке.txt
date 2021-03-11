/*
{
	desc-ru:"Штора по кнопке",
	tag:"import-script",
	selectArea:true,

	vars:[

    {type:"comment",text:"Укажите устройства:",width:200, style:"color:red;"},
    {name:"D00",type:"devices-list",required:true,filter:["jalousie"],width:888,desc:"Штора"},
    {name:"B00",type:"devices-list",required:true,filter:["switch"],width:888,desc:"Кнопка 0"},
    {name:"B01",type:"devices-list",required:false,filter:["switch"],width:888,desc:"Кнопка 1"},
   
	]
}
*/
u8 i=0;
u8 k=0;


void F3()
{
    i=1;
}

void F2()
{
    if ([D00.0]==1) {setStatus(D00,0); k=0;}
        else if ([D00.0]==0) {setStatus(D00, 1); k=1;}
        else if (k==0) {setStatus(D00, 1); k=1;}
        else if (k==1) {setStatus(D00, 0); k=0;}
    delayedCall(F3, 2);
}

V-ID/B00, #ifdef B01 B01 #endif
{

if (opt(0)==0xFC)
{
    srvError("нажали");
    i=0;
    cancelDelayedCall(F3);
    if ([D00.0]==2 || [D00.0]==3 || [D00.0]==0xFF) setStatus(D00, 1); else
    F2();
}
if (opt(0)==0xFF)
{
//    srvError("Отжали");
    cancelDelayedCall(F3);
    if (i==1 && ( [D00.0]==2 || [D00.0]==3 || [D00.0]==0xFF) ) setStatus(D00, 1); else
    i=0;
}
}