/*
{
    desc:"Кондиционеры",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID02%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID03%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID04%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID05%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID08%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID10%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
    ],
    vars:[
        {name:"T01",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T02",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T03",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T04",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T05",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T06",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T07",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T08",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T09",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"T10",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура",descWidth:100},
        {name:"Z01",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z02",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z03",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z04",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z05",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z06",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z07",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z08",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z09",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"Z10",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка",descWidth:100},
        {name:"V01",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка",descWidth:100},
        {name:"V02",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка",descWidth:100},
        {name:"V03",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка",descWidth:100},
        {name:"V04",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка",descWidth:100},
        {name:"V05",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка",descWidth:100},
        {name:"KOND01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"KOND02",type:"hidden",value:"%TARGET%:%SUBID02%"},
        {name:"KOND03",type:"hidden",value:"%TARGET%:%SUBID03%"},
        {name:"KOND04",type:"hidden",value:"%TARGET%:%SUBID04%"},
        {name:"KOND05",type:"hidden",value:"%TARGET%:%SUBID05%"},
        {name:"KOND06",type:"hidden",value:"%TARGET%:%SUBID06%"},
        {name:"KOND07",type:"hidden",value:"%TARGET%:%SUBID07%"},
        {name:"KOND08",type:"hidden",value:"%TARGET%:%SUBID08%"},
        {name:"KOND09",type:"hidden",value:"%TARGET%:%SUBID09%"},
        {name:"KOND10",type:"hidden",value:"%TARGET%:%SUBID10%"},
    ]
}
*/

void START(u16 kondid, u8 kondsid, u16 zid, u8 zsid, u16 did, u8 dsid)
{
    srvError("Зашли в функцию kondid=%d kondsid=%d", kondid, kondsid);
    u8 j[5];
    u8 k[2];
    getStatus(@kondid:@kondsid, &j);
    getStatus(@did:@dsid, &k);
    srvError("j[0]=%d, k[0]=%d", j[0], k[0]);
    if(j[0]%2!=0)
    {
        if(j[4]==1) {setStatus(@zid:@zsid, {1, 75, 0});} else   //Первая мощность
        if(j[4]==2) {setStatus(@zid:@zsid, {1, 150, 0});} else  //Вторая мощность
        if(j[4]==3) {setStatus(@zid:@zsid, {1, 250, 0});} else  //Треться мощность
        if(j[4]==0) {  //Авто
        if(j[1]+16+2>k[1]) {setStatus(@zid:@zsid, {1, 250, 0});}
        else if(j[1]+16+1>k[1]) {setStatus(@zid:@zsid, {1, 188, 0});}
        else if(j[1]+16>k[1]) {setStatus(@zid:@zsid, {1, 125, 0});}
        else {setStatus(@zid:@zsid, {1, 63, 0});}}
    }
}

u8 j[5];

V-ID/s:5
{
    #ifdef Z01 START(ADDR2ID(KOND01), ADDR2SID(KOND01), ADDR2ID(Z01), ADDR2SID(Z01), ADDR2ID(T01), ADDR2SID(T01)); #endif
    #ifdef Z02 START(ADDR2ID(KOND02), ADDR2SID(KOND02), ADDR2ID(Z02), ADDR2SID(Z02), ADDR2ID(T02), ADDR2SID(T02)); #endif
    #ifdef Z03 START(ADDR2ID(KOND03), ADDR2SID(KOND03), ADDR2ID(Z03), ADDR2SID(Z03), ADDR2ID(T03), ADDR2SID(T03)); #endif
    #ifdef Z04 START(ADDR2ID(KOND04), ADDR2SID(KOND04), ADDR2ID(Z04), ADDR2SID(Z04), ADDR2ID(T04), ADDR2SID(T04)); #endif
    #ifdef Z05 START(ADDR2ID(KOND05), ADDR2SID(KOND05), ADDR2ID(Z05), ADDR2SID(Z05), ADDR2ID(T05), ADDR2SID(T05)); #endif
    #ifdef Z06 START(ADDR2ID(KOND06), ADDR2SID(KOND06), ADDR2ID(Z06), ADDR2SID(Z06), ADDR2ID(T06), ADDR2SID(T06)); #endif
    #ifdef Z07 START(ADDR2ID(KOND07), ADDR2SID(KOND07), ADDR2ID(Z07), ADDR2SID(Z07), ADDR2ID(T07), ADDR2SID(T07)); #endif
    #ifdef Z08 START(ADDR2ID(KOND08), ADDR2SID(KOND08), ADDR2ID(Z08), ADDR2SID(Z08), ADDR2ID(T08), ADDR2SID(T08)); #endif
    #ifdef Z09 START(ADDR2ID(KOND09), ADDR2SID(KOND09), ADDR2ID(Z09), ADDR2SID(Z09), ADDR2ID(T09), ADDR2SID(T09)); #endif
    #ifdef Z10 START(ADDR2ID(KOND10), ADDR2SID(KOND10), ADDR2ID(Z10), ADDR2SID(Z10), ADDR2ID(T10), ADDR2SID(T10)); #endif
}