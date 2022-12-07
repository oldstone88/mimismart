/*
{
    desc:"Чудо увлажнители",
    tag:"import-script",
    selectArea:true,
    
    vars:[

{name:"H0",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 0",descWidth:100},
{name:"H1",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 1",descWidth:100},
{name:"H2",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 2",descWidth:100},
{name:"H3",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 3",descWidth:100},
{name:"H4",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 4",descWidth:100},
{name:"H5",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 5",descWidth:100},
{name:"H6",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 6",descWidth:100},
{name:"H7",type:"devices-list",required:false,width:1000,filter:["conditioner"],desc:"Увлажнитель 7",descWidth:100},


{name:"B0",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"Кнопка 0",descWidth:100},
{name:"B1",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 1",descWidth:100},
{name:"B2",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 2",descWidth:100},
{name:"B3",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 3",descWidth:100},
{name:"B4",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 4",descWidth:100},
{name:"B5",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 5",descWidth:100},
{name:"B6",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 6",descWidth:100},
{name:"B7",type:"devices-list",required:false,width:1000,filter:["lamp"],desc:"Кнопка 7",descWidth:100},


{name:"D0",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},
{name:"D1",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 1",descWidth:100},
{name:"D2",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 2",descWidth:100},
{name:"D3",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 3",descWidth:100},
{name:"D4",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 4",descWidth:100},
{name:"D5",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 5",descWidth:100},
{name:"D6",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 6",descWidth:100},
{name:"D7",type:"devices-list",required:false,width:1000,filter:["humidity-sensor"],desc:"Датчик 7",descWidth:100},


    ]
}
*/

V-ID/s:30
{
    if(([TIMER.0]&1)==1)
    {
        if( ([H0.0]%2==1) && ([H0.1]+25>[D0.1]) ) {setStatus(B0, 1);} else if([H0.0]%2==0) {setStatus(B0, 0);} else if( ([H0.1]+30)<=[D0.1] ) {setStatus(B0, 0);}

        #ifdef H1
        if( ([H1.0]%2==1) && ([H1.1]+25>[D1.1]) ) {setStatus(B1, 1);} else if([H1.0]%2==0) {setStatus(B1, 0);} else if( ([H1.1]+30)<=[D1.1] ) {setStatus(B1, 0);}
        #endif

        #ifdef H2
        if( ([H2.0]%2==1) && ([H2.1]+25>[D2.1]) ) {setStatus(B2, 1);} else if([H2.0]%2==0) {setStatus(B2, 0);} else if( ([H2.1]+30)<=[D2.1] ) {setStatus(B2, 0);}
        #endif

        #ifdef H3
        if( ([H3.0]%2==1) && ([H3.1]+25>[D3.1]) ) {setStatus(B3, 1);} else if([H3.0]%2==0) {setStatus(B3, 0);} else if( ([H3.1]+30)<=[D3.1] ) {setStatus(B3, 0);}
        #endif

        #ifdef H4
        if( ([H4.0]%2==1) && ([H4.1]+25>[D4.1]) ) {setStatus(B4, 1);} else if([H4.0]%2==0) {setStatus(B4, 0);} else if( ([H4.1]+30)<=[D4.1] ) {setStatus(B4, 0);}
        #endif

        #ifdef H5
        if( ([H5.0]%2==1) && ([H5.1]+25>[D5.1]) ) {setStatus(B5, 1);} else if([H5.0]%2==0) {setStatus(B5, 0);} else if( ([H5.1]+30)<=[D5.1] ) {setStatus(B5, 0);}
        #endif

        #ifdef H6
        if( ([H6.0]%2==1) && ([H1.6]+25>[D6.1]) ) {setStatus(B6, 1);} else if([H6.0]%2==0) {setStatus(B6, 0);} else if( ([H6.1]+30)<=[D6.1] ) {setStatus(B6, 0);}
        #endif

        #ifdef H7
        if( ([H7.0]%2==1) && ([H7.1]+25>[D7.1]) ) {setStatus(B7, 1);} else if([H7.0]%2==0) {setStatus(B7, 0);} else if( ([H7.1]+30)<=[D7.1] ) {setStatus(B7, 0);}
        #endif
    }
    else
    {
        if( ([B0.0]&1)==1 ) setStatus(B0, 0);
        #ifdef B1 if( ([B1.0]&1)==1 ) setStatus(B1, 0); #endif
        #ifdef B2 if( ([B2.0]&1)==1 ) setStatus(B2, 0); #endif
        #ifdef B3 if( ([B3.0]&1)==1 ) setStatus(B3, 0); #endif
        #ifdef B4 if( ([B4.0]&1)==1 ) setStatus(B4, 0); #endif
        #ifdef B5 if( ([B5.0]&1)==1 ) setStatus(B5, 0); #endif
        #ifdef B6 if( ([B6.0]&1)==1 ) setStatus(B6, 0); #endif
        #ifdef B7 if( ([B7.0]&1)==1 ) setStatus(B7, 0); #endif
    }
}
