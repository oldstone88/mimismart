/*
{
  desc:"Жалюзи с ламели",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Выберите жалюзи",descWidth:300,width:300},
    {type:"comment",text:"Время замыкания в милисекундах!",width:600, "style":"color:red; font-weight:bold"},
    {name:"TIME",type:"number",required:true,defaultValue:"1500", min:"150", max:"5000"},
    {type:"comment",text:"Кнопки открыть",width:600, "style":"color:red; font-weight:bold"},
    {name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {name:"BUTTONUP2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {name:"BUTTONUP3",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {type:"comment",text:"Кнопки закрыть",width:600, "style":"color:red; font-weight:bold"},
    {name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {name:"BUTTONDOWN3",type:"devices-list",required:false,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
  ]
}
*/

void check()
{
    if( ([BUTTONUP1.0]==0xFD) ) {setStatus(BLINDS0, 1);} else
    if( ([BUTTONDOWN1.0]==0xFD) ) {setStatus(BLINDS0, 0);}
}

V-ID/BUTTONUP1, #ifdef BUTTONUP2 BUTTONUP2, #endif #ifdef  BUTTONUP3 BUTTONUP3 #endif
{
    if(opt(0) == 0xFC)
    {
        setStatus(BLINDS0, 1); // Open
        delayedCallMs(check, TIME);
    }
}

V-ID/BUTTONDOWN1, #ifdef BUTTONDOWN2 BUTTONDOWN2, #endif #ifdef BUTTONDOWN3 BUTTONDOWN3, #endif
{
    if(opt(0) == 0xFC)
    {
        setStatus(BLINDS0, 0); // Close
        delayedCallMs(check, TIME);
    }
}
