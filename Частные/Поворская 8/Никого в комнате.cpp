/*
{
desc:"Отпуск",
tag:"item",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Все кондеи",descWidth:100},
{name:"H00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Все увлажнители",descWidth:100},
{name:"E00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Электро",descWidth:100},
{name:"E01",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Электро",descWidth:100},
{name:"E02",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Электро",descWidth:100},
{name:"W00",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Водяной",descWidth:100},
{name:"TP0",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Тёплый пол",descWidth:100},
]
}
*/

u8 kond[5];
u8 oldk[5];
u8 oldh[5];

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        getStatus(K00, &oldk); getStatus(K00, &kond); kond[0]=kond[0]&0xFE; setStatus(K00, &kond);
        getStatus(H00, &oldh); getStatus(H00, &kond); kond[0]=kond[0]&0xFE; setStatus(H00, &kond);
        #ifdef E00 setStatus(1000:102,"E00\0as:-1"); #endif
        #ifdef E01 setStatus(1000:102,"E01\0as:-1"); #endif
        #ifdef E02 setStatus(1000:102,"E02\0as:-1"); #endif
        #ifdef W00 setStatus(1000:102,"W00\0Авто"); #endif
        #ifdef TP0 setStatus(1000:102,"TP0\0as:-1"); #endif
    } else
    if((opt(0)&1)==0 && (senderId()!=exciterId()) )
    {
        u8 error[2]={0, 0};
        for(u8 i=0; i<5; ++i)
        {
            error[0]=error[0]+oldk[i];
            error[1]=error[1]+oldh[i];
        }
        if( error[0]>0 ) setStatus(K00, &oldk); else srvError("Записей нет!");
        if( error[1]>0 ) setStatus(H00, &oldh); else srvError("Записей нет!");
        #ifdef TP0 setStatus(1000:102,"TP0\0as:-2"); #endif
    }
}

V-ID/s:5
{
    if( (([K00.0]%2)==1 || ([H00.0]%2)==1) && [V-ADDR.0]==1 ) {setStatus(V-ADDR, 0);}
}