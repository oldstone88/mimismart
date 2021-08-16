/*
{
desc:"Вытяжка",
tag:"import-script",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Вытяжка",descWidth:100},
{name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Скорость 1",descWidth:100},
{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Скорость 2",descWidth:100},
{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Скорость 3",descWidth:100},
{name:"O00",type:"devices-list",required:true,width:600,filter:["co2-sensor"],desc:"Сенсор 1",descWidth:100},
{name:"O01",type:"devices-list",required:true,width:600,filter:["co2-sensor"],desc:"Сенсор 2",descWidth:100},
]
}
*/

u8 kond[5];

V-ID/s:10
{
    u16 pokazanie0=(([O00.0]*100/255)+([O00.1]*100));
    u16 pokazanie1=(([O01.0]*100/255)+([O01.1]*100));
    if ([K00.0]==17)
        {
            getStatus(K00, &kond);
            if (pokazanie1>900 || pokazanie0>900)
                {
                    kond[1]=2; setStatus(K00, &kond);
                } else
            if (pokazanie1>=600 || pokazanie0>=600)
                {
                    kond[1]=1; setStatus(K00, &kond);
                } else
            if (pokazanie1<600 || pokazanie0<600)
                {
                    kond[1]=0; setStatus(K00, &kond);
                }
        }
}

V-ID/K00
{
    if(opt(0)%2!=0) 
    {
        if([K00.1]==0) {setStatus(L02, 0); setStatus(L01, 0); setStatus(L00, 1);} else
        if([K00.1]==1) {setStatus(L00, 0); setStatus(L02, 0); setStatus(L01, 1);} else
        if([K00.1]==2) {setStatus(L00, 0); setStatus(L01, 0); setStatus(L02, 1);}
    } else
    {setStatus(L00, 0); setStatus(L01, 0); setStatus(L02, 0);}
}
