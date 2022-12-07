/*
{
    desc:"Общий климат",
    tag:"import-script",
    selectArea:true,
    addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"40", "t-min":"30", "vane-hor":"0x00", "vane-ver":"0x00", "funs":"0x01", "modes":"0x00"},
    ],
    vars:[
        {name:"AUTO",type:"hidden",value:"%TARGET%:%SUBID%"},
        {name:"COND00", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO0", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND01", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO1", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND02", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO2", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND03", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO3", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND04", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO4", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND05", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO5", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND06", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO6", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND07", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO7", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND08", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO8", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
        {name:"COND09", type:"devices-list", required:false, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
        {name:"ECO9", type:"devices-list", required:false, filter:["script"], descWidth:370, desc:"Эко"},
    ]
}
*/

u8 k[5];

V-ID/AUTO
{
        getStatus(AUTO, &k);
        #ifdef COND00 if( ([ECO0.0]&1)==0 ) {setStatus(COND00, &k);} #endif
        #ifdef COND01 if( ([ECO1.0]&1)==0 ) {setStatus(COND01, &k);} #endif
        #ifdef COND02 if( ([ECO2.0]&1)==0 ) {setStatus(COND02, &k);} #endif
        #ifdef COND03 if( ([ECO3.0]&1)==0 ) {setStatus(COND03, &k);} #endif
        #ifdef COND04 if( ([ECO4.0]&1)==0 ) {setStatus(COND04, &k);} #endif
        #ifdef COND05 if( ([ECO5.0]&1)==0 ) {setStatus(COND05, &k);} #endif
        #ifdef COND06 if( ([ECO6.0]&1)==0 ) {setStatus(COND06, &k);} #endif
        #ifdef COND07 if( ([ECO7.0]&1)==0 ) {setStatus(COND07, &k);} #endif
        #ifdef COND08 if( ([ECO8.0]&1)==0 ) {setStatus(COND08, &k);} #endif
        #ifdef COND09 if( ([ECO9.0]&1)==0 ) {setStatus(COND09, &k);} #endif
}