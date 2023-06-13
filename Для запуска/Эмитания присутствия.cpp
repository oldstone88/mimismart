/*
{
    desc:"Присутствие",
    tag:"item",
    name:"Присутствие",
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
u8 count=0;

void onInit(){
    #ifdef L0 ++count; #endif
    #ifdef L1 ++count; #endif
    #ifdef L2 ++count; #endif
    #ifdef L3 ++count; #endif
    #ifdef L4 ++count; #endif
    #ifdef L5 ++count; #endif
    #ifdef L6 ++count; #endif
    #ifdef L7 ++count; #endif
    #ifdef L8 ++count; #endif
    #ifdef L9 ++count; #endif
}

void prisutstvie()
{
    check=0;
    for(u8 i=0; i<count; ++i) {k[i]=rand()%2; if(k[i]==1) ++check;}
    if(check==0){setStatus(L0, 1);} else
        {
            #ifdef L0 setStatus(L0, k[0]); #endif
            #ifdef L1 setStatus(L1, k[1]); #endif
            #ifdef L2 setStatus(L2, k[2]); #endif
            #ifdef L3 setStatus(L3, k[3]); #endif
            #ifdef L4 setStatus(L4, k[4]); #endif
            #ifdef L5 setStatus(L5, k[0]); #endif
            #ifdef L6 setStatus(L6, k[1]); #endif
            #ifdef L7 setStatus(L7, k[2]); #endif
            #ifdef L8 setStatus(L8, k[3]); #endif
            #ifdef L9 setStatus(L9, k[4]); #endif
        }
        time=rand()%15+45;
        start=0;
}

V-ID/s:5{
    if(([V-ADDR.0]&1)==1 && start==0){
      u8 res = timeInRange(19:00-01:00);
      if(res!=0){
        delayedCallM(prisutstvie, time);
        start=1;  
      }
    }
}

V-ID/V-ADDR
{
    if((opt(0)&1)==0) {
        cancelDelayedCall(prisutstvie);
            start=0;
    }
}