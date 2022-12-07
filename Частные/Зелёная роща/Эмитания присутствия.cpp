/*
{
    desc:"Присутствие",
    tag:"item",
    selectArea:true,
    
    vars:[
{name:"L0",type:"devices-list",required:true,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 1",descWidth:100},
{name:"L1",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 2",descWidth:100},
{name:"L2",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 3",descWidth:100},
{name:"L3",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 4",descWidth:100},
{name:"L4",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 5",descWidth:100},
{name:"L5",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 6",descWidth:100},
{name:"L6",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 7",descWidth:100},
{name:"L7",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 8",descWidth:100},
{name:"L8",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 9",descWidth:100},
{name:"L9",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp"],desc:"Лампа 10",descWidth:100},
    ]
}
*/

u8 k[10];
u8 check=0;
u8 time=20;
u8 start=0;

void prisutstvie()
{
    check=0;
    for(u8 i=0; i<10; ++i) {k[i]=rand()%2; if(k[i]==1) ++check;}
    if(check==0){setStatus(L0, 1);} else
        {
            setStatus(L0, k[0]);
            setStatus(L1, k[1]);
            setStatus(L2, k[2]);
            setStatus(L3, k[3]);
            setStatus(L4, k[4]);
            setStatus(L5, k[5]);
            setStatus(L6, k[6]);
            setStatus(L7, k[7]);
            setStatus(L8, k[8]);
            setStatus(L9, k[9]);
        }
        time=rand()%15+45;
        start=0;
}

V-ID/s:5
{
    if(([V-ADDR.0]&1)==1 && start==0) {delayedCallM(prisutstvie, time); start=1;}
}

V-ID/V-ADDR
{
    if((opt(0)&1)==0) {
        cancelDelayedCall(prisutstvie);
        setStatus(L0, 0);
        setStatus(L1, 0);
        setStatus(L2, 0);
        setStatus(L3, 0);
        setStatus(L4, 0);
        setStatus(L5, 0);
        setStatus(L6, 0);
        setStatus(L7, 0);
        setStatus(L8, 0);
        setStatus(L9, 0);
        start=0;
    }
}