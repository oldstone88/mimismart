/*
{
  desc:"Авто выключение",
  tag:"item",
  name:"АвтоТёплыйПол",
  selectArea:true,
  vars:[
        {name:"H00",type:"devices-list",required:false,filter:["valve-heating"], widht:500, desc:"Тёплый пол 0"},
        {name:"H01",type:"devices-list",required:false,filter:["valve-heating"], widht:500, desc:"Тёплый пол 1"},
        {name:"H02",type:"devices-list",required:false,filter:["valve-heating"], widht:500, desc:"Тёплый пол 2"},
        {name:"H03",type:"devices-list",required:false,filter:["valve-heating"], widht:500, desc:"Тёплый пол 3"},
        {name:"H04",type:"devices-list",required:false,filter:["valve-heating"], widht:500, desc:"Тёплый пол 4"},
        {name:"TIME",type:"number",required:true,min:0},
  ]
}
*/

void onInit(){
    setStatus(V-ADDR, 1);
}

u16 timer[5] = {0, 0, 0, 0, 0};

V-ID/s:1{
    if( ([V-ADDR.0]&1)==1 ){
        #ifdef H00
        if( ([H00.0]==1) && timer[0]<TIME ) {++timer[0];}
        else if( ([H00.0]==1) && timer[0]>=TIME ) {setStatus(1000:102,"H00\0as:-4"); setStatus(H00, 0);}
        else {timer[0]=0;}
        #endif

        #ifdef H01
        if( ([H01.0]==1) && timer[1]<TIME ) {++timer[1];}
        else if( ([H01.0]==1) && timer[1]>=TIME ) {setStatus(1000:102,"H01\0as:-4"); setStatus(H01, 0);}
        else {timer[1]=0;}
        #endif

        #ifdef H02
        if( ([H02.0]==1) && timer[2]<TIME ) {++timer[2];}
        else if( ([H02.0]==1) && timer[2]>=TIME ) {setStatus(1000:102,"H02\0as:-4"); setStatus(H02, 0);}
        else {timer[2]=0;}
        #endif

        #ifdef H03
        if( ([H03.0]==1) && timer[3]<TIME ) {++timer[3];}
        else if( ([H03.0]==1) && timer[3]>=TIME ) {setStatus(1000:102,"H03\0as:-4"); setStatus(H03, 0);}
        else {timer[3]=0;}
        #endif

        #ifdef H04
        if( ([H04.0]==1) && timer[4]<TIME ) {++timer[4];}
        else if( ([H04.0]==1) && timer[4]>=TIME ) {setStatus(1000:102,"H04\0as:-4"); setStatus(H04, 0);}
        else {timer[4]=0;}
        #endif
    }
}