/*
{
desc:"Вытяжка",
tag:"import-script",
selectArea:true,
addItems:[
        {tag:"item", id:"%TARGET%", name:"Вытяжка", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"1", "t-delta":"1", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x00", "modes":"0x01", "dim":" "},
  ],
vars:[
    {name:"EXTR",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Скорость 1",descWidth:100},
    {name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Скорость 2",descWidth:100},
]
}
*/

V-ID/s:1{
    if(([EXTR.0]%2) == 1){
        if([EXTR.1] == 0){
            setStatus(L01, 0); setStatus(L00, 1);
        }
        else if([EXTR.1] == 1){
            setStatus(L00, 0); setStatus(L01, 1);
        }
    }
    else{
        setStatus(L00, 0); setStatus(L01, 0);
    }
}
