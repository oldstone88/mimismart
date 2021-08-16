/*
{
    desc:"Пожарная тревога",
    tag:"item",
    selectArea:true,
    vars:[
        {name:"TIME", type:"number", defaultValue:20, required:true, desc:"Время спама, c"},
        {name:"L00",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L01",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L02",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L03",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L04",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L05",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L07",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
        {name:"L08",type:"devices-list",required:false,width:600,filter:["door-sensor"],desc:"Геркон",descWidth:100},
        {name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
    ]
}
*/

void onInit()
{
    setStatus(V-ADDR, 1);
}

V-ID/s:TIME
{
    if ([V-ADDR.0]&1==1)
    {
        #ifdef L00 if( ([L00.0]&1)==0 ) {setStatus(2047:32, {8, "T00"});} #endif
        #ifdef L01 if( ([L01.0]&1)==0 ) {setStatus(2047:32, {8, "T01"});} #endif
        #ifdef L02 if( ([L02.0]&1)==0 ) {setStatus(2047:32, {8, "T02"});} #endif
        #ifdef L03 if( ([L03.0]&1)==0 ) {setStatus(2047:32, {8, "T03"});} #endif
        #ifdef L04 if( ([L04.0]&1)==0 ) {setStatus(2047:32, {8, "T04"});} #endif
        #ifdef L05 if( ([L05.0]&1)==0 ) {setStatus(2047:32, {8, "T05"});} #endif
        #ifdef L06 if( ([L06.0]&1)==0 ) {setStatus(2047:32, {8, "T06"});} #endif
        #ifdef L07 if( ([L07.0]&1)==0 ) {setStatus(2047:32, {8, "T07"});} #endif
        #ifdef L08 if( ([L08.0]&1)==0 ) {setStatus(2047:32, {8, "T08"});} #endif
    }
}