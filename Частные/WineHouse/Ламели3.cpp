/*
{
  desc:"Жалюзи с ламели",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"BLINDS0",type:"devices-list",required:true,filter:["virtual","jalousie"],desc:"Выберите жалюзи",descWidth:300,width:300},
    {name:"BLINDS1",type:"devices-list",required:false,filter:["virtual","jalousie"],desc:"Выберите жалюзи",descWidth:300,width:300},
    {name:"BLINDS2",type:"devices-list",required:false,filter:["virtual","jalousie"],desc:"Выберите жалюзи",descWidth:300,width:300},
    {type:"comment",text:"Время замыкания в милисекундах!",width:600, "style":"color:red; font-weight:bold"},
    {name:"TIME",type:"number",required:true,defaultValue:"1500", min:"150", max:"5000"},
    {type:"comment",text:"Кнопки открыть",width:600, "style":"color:red; font-weight:bold"},
    {name:"BUTTONUP1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ОТКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
    {type:"comment",text:"Кнопки закрыть",width:600, "style":"color:red; font-weight:bold"},
    {name:"BUTTONDOWN1",type:"devices-list",required:true,filter:["switch"],desc:"Выберите кнопку, которая будет ЗАКРЫВАТЬ шторы(гардины, жалюзи)",descWidth:300,width:300},
  ]
}
*/

void check()
{
    if( ([BUTTONUP1.0]==0xFD) )
        {
            setStatus(BLINDS0, 1);
            #ifdef BLINDS1 setStatus(BLINDS1, 1); #endif
            #ifdef BLINDS2 setStatus(BLINDS2, 1); #endif
        } else
    if( ([BUTTONDOWN1.0]==0xFD) )
        {
            setStatus(BLINDS0, 0);
            #ifdef BLINDS1 setStatus(BLINDS1, 0); #endif
            #ifdef BLINDS2 setStatus(BLINDS2, 0); #endif
        }
}

V-ID/BUTTONUP1
{
    if(opt(0) == 0xFC)
    {
        setStatus(BLINDS0, 1); // Open
        #ifdef BLINDS1 setStatus(BLINDS1, 1); #endif
        #ifdef BLINDS2 setStatus(BLINDS2, 1); #endif
        delayedCallMs(check, TIME);
    }
}

V-ID/BUTTONDOWN1
{
    if(opt(0) == 0xFC)
    {
        setStatus(BLINDS0, 0); // Close
        #ifdef BLINDS1 setStatus(BLINDS1, 0); #endif
        #ifdef BLINDS2 setStatus(BLINDS2, 0); #endif
        delayedCallMs(check, TIME);
    }
}
