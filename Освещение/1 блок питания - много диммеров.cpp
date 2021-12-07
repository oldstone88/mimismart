/*
{
    desc:"Диммеры по БП",
    tag:"import-script",
    selectArea:true,
    
    vars:[
{name:"P00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Блок питания",descWidth:100},
{name:"D00",type:"devices-list",required:true,width:600,filter:["dimer-lamp"],desc:"Диммер 0",descWidth:100},
{name:"D01",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 1",descWidth:100},
{name:"D02",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 2",descWidth:100},
{name:"D03",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 3",descWidth:100},
{name:"D04",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 4",descWidth:100},
{name:"D05",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 5",descWidth:100},
{name:"D06",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 6",descWidth:100},
{name:"D07",type:"devices-list",required:false,width:600,filter:["dimer-lamp"],desc:"Диммер 7",descWidth:100},
    ]
}
*/

u8 i=0;

V-ID/
{
    if (([~D00.0]&1)==1
        #ifdef D01 || ([~D01.0]&1)==1 #endif
        #ifdef D02 || ([~D02.0]&1)==1 #endif
        #ifdef D03 || ([~D03.0]&1)==1 #endif
        #ifdef D04 || ([~D04.0]&1)==1 #endif
        #ifdef D05 || ([~D05.0]&1)==1 #endif
        #ifdef D06 || ([~D06.0]&1)==1 #endif
        #ifdef D07 || ([~D07.0]&1)==1 #endif
        && ( ([P00.0]&1)==0) )
        {
            setStatus (P00, 1);
        }
}

V-ID/s:5
{
    if (([D00.0]&1)==0
        #ifdef D01 && ([D01.0]&1)==0 #endif
        #ifdef D02 && ([D02.0]&1)==0 #endif
        #ifdef D03 && ([D03.0]&1)==0 #endif
        #ifdef D04 && ([D04.0]&1)==0 #endif
        #ifdef D05 && ([D05.0]&1)==0 #endif
        #ifdef D06 && ([D06.0]&1)==0 #endif
        #ifdef D07 && ([D07.0]&1)==0 #endif
        && ( ([P00.0]&1)==1))
    {
        ++i;
        if (i>=60 && ([P00.0]&1)==1) setStatus(P00, 0);
    } else {i=0;}
}