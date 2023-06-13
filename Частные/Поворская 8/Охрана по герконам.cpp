/*
{
desc:"Охрана",
tag:"item",
selectArea:true,

vars:[
{type:"comment",text:"Датчики протечки:",width:200, style:"color:red;"},
{name:"H00",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H01",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H02",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
]
}
*/

u8 antispam[3]={0, 0, 0};

V-ID/V-ADDR{
    if((opt(0)&1)==0){
        for(u8 i=0; i<3; ++i){
            antispam[i]=0;
        }
    }
}

V-ID/s:1
{
    if( ([V-ADDR.0]&1)==1 ){
        #ifdef H00 if([H00.0]==1 && antispam[0]==0) {setStatus(2047:32, {8, "T00"}); ++antispam[0];} if(antispam[0]>180) antispam[0]=0; #endif
        #ifdef H01 if([H01.0]==1 && antispam[1]==0) {setStatus(2047:32, {8, "T01"}); ++antispam[1];} if(antispam[1]>180) antispam[1]=0; #endif
        #ifdef H02 if([H02.0]==1 && antispam[2]==0) {setStatus(2047:32, {8, "T02"}); ++antispam[2];} if(antispam[2]>180) antispam[2]=0; #endif
    }
}
