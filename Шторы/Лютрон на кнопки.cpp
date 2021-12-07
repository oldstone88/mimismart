/*
{
  desc:"Лютрон",
  tag:"import-script",
  selectArea:true,
  
  vars:[
    {type:"comment",text:"Все димеры кроме СУ:",width:200, style:"color:red;"},
    {name:"B00",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 0",descWidth:100},
    {name:"B01",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 2",descWidth:100},
    {name:"B02",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 3",descWidth:100},
    {name:"B03",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 4",descWidth:100},
    {name:"B04",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 5",descWidth:100},
    {name:"B05",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 6",descWidth:100},
    {name:"B06",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 7 и 8",descWidth:100},
    {name:"B07",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 8 и 7",descWidth:100},
    {name:"B08",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 9 и 10",descWidth:100},
    {name:"B09",type:"devices-list",required:false,width:800,filter:["virtual"],desc:"Устройство 10 и 9",descWidth:100},
    {name:"BUTTONUP0",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP1",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP2",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP3",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP4",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP5",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONUP6",type:"devices-list",required:false,filter:["script"],desc:"Открыть",descWidth:300,width:600},
    {name:"BUTTONDOWN0",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN1",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN2",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN3",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN4",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN5",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
    {name:"BUTTONDOWN6",type:"devices-list",required:false,filter:["script"],desc:"Закрыть",descWidth:300,width:600},
  ]
}
*/

V-ID/BUTTONUP0
{
    setStatus(B00, {0, 100});
}
V-ID/BUTTONDOWN0
{
    setStatus(B00, {0, 0});
}

V-ID/BUTTONUP1
{
    setStatus(B01, {0, 100});
}
V-ID/BUTTONDOWN1
{
    setStatus(B01, {0, 0});
}

V-ID/BUTTONUP2
{
    setStatus(B02, {0, 100});
}
V-ID/BUTTONDOWN2
{
    setStatus(B02, {0, 0});
}

V-ID/BUTTONUP3
{
    setStatus(B03, {0, 100});
}
V-ID/BUTTONDOWN3
{
    setStatus(B03, {0, 0});
}

void up4()
{
  setStatus(B05, {0, 100});
}

V-ID/BUTTONUP4
{
    setStatus(B04, {0, 100});
    delayedCallMs(up4, 500);
}

void down4()
{
  setStatus(B05, {0, 0});
}

V-ID/BUTTONDOWN4
{
    setStatus(B04, {0, 0});
    delayedCallMs(down4, 500);
}

void up5()
{
  setStatus(B07, {0, 100});
}

V-ID/BUTTONUP5
{
    setStatus(B06, {0, 100});
    delayedCallMs(up5, 500);
}

void down5()
{
  setStatus(B07, {0, 0});
}

V-ID/BUTTONDOWN5
{
    setStatus(B06, {0, 0});
    delayedCallMs(down5, 500);
}

void up6()
{
  setStatus(B09, {0, 100});
}

V-ID/BUTTONUP6
{
    setStatus(B08, {0, 100});
    delayedCallMs(up6, 500);
}

void down6()
{
  setStatus(B09, {0, 0});
}

V-ID/BUTTONDOWN6
{
    setStatus(B08, {0, 0});
    delayedCallMs(down6, 500);
}