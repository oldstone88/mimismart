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
        {name:"I00",type:"devices-list",required:false,width:300,filter:["lamp"],desc:"СК ККБ",descWidth:100},
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

//Массив кондиционеров
const u16 IDK [] = {
    ADDR2ID(KOND01)
    #ifdef KOND02, ADDR2ID(KOND02) #else ,0 #endif
    #ifdef KOND03, ADDR2ID(KOND03) #else ,0 #endif
    #ifdef KOND04, ADDR2ID(KOND04) #else ,0 #endif
    #ifdef KOND05, ADDR2ID(KOND05) #else ,0 #endif
    #ifdef KOND06, ADDR2ID(KOND06) #else ,0 #endif
    #ifdef KOND07, ADDR2ID(KOND04) #else ,0 #endif
    #ifdef KOND08, ADDR2ID(KOND05) #else ,0 #endif
    #ifdef KOND09, ADDR2ID(KOND06) #else ,0 #endif
    #ifdef KOND10, ADDR2ID(KOND06) #else ,0 #endif
};
const u8 SIDK [] = {
    ADDR2SID(KOND01)
    #ifdef KOND02, ADDR2SID(KOND02) #else ,0 #endif
    #ifdef KOND03, ADDR2SID(KOND03) #else ,0 #endif
    #ifdef KOND04, ADDR2SID(KOND04) #else ,0 #endif
    #ifdef KOND05, ADDR2SID(KOND05) #else ,0 #endif
    #ifdef KOND06, ADDR2SID(KOND06) #else ,0 #endif
    #ifdef KOND07, ADDR2SID(KOND07) #else ,0 #endif
    #ifdef KOND08, ADDR2SID(KOND08) #else ,0 #endif
    #ifdef KOND09, ADDR2SID(KOND09) #else ,0 #endif
    #ifdef KOND10, ADDR2SID(KOND10) #else ,0 #endif
};
//Массив заслонок
const u16 IDZ [] = {
    ADDR2ID(T01)
    #ifdef T02, ADDR2ID(T02) #else ,0 #endif
    #ifdef T03, ADDR2ID(T03) #else ,0 #endif
    #ifdef T04, ADDR2ID(T04) #else ,0 #endif
    #ifdef T05, ADDR2ID(T05) #else ,0 #endif
    #ifdef T06, ADDR2ID(T06) #else ,0 #endif
    #ifdef T07, ADDR2ID(T04) #else ,0 #endif
    #ifdef T08, ADDR2ID(T05) #else ,0 #endif
    #ifdef T09, ADDR2ID(T06) #else ,0 #endif
    #ifdef T10, ADDR2ID(T06) #else ,0 #endif
};
const u8 SIDZ [] = {
    ADDR2SID(T01)
    #ifdef T02, ADDR2SID(T02) #else ,0 #endif
    #ifdef T03, ADDR2SID(T03) #else ,0 #endif
    #ifdef T04, ADDR2SID(T04) #else ,0 #endif
    #ifdef T05, ADDR2SID(T05) #else ,0 #endif
    #ifdef T06, ADDR2SID(T06) #else ,0 #endif
    #ifdef T07, ADDR2SID(T07) #else ,0 #endif
    #ifdef T08, ADDR2SID(T08) #else ,0 #endif
    #ifdef T09, ADDR2SID(T09) #else ,0 #endif
    #ifdef T10, ADDR2SID(T10) #else ,0 #endif
};

//Массив вытяжки
const u16 IDV [] = {
    ADDR2ID(V01)
    #ifdef V02, ADDR2ID(V02) #else ,0 #endif
    #ifdef V03, ADDR2ID(V03) #else ,0 #endif
    #ifdef V04, ADDR2ID(V04) #else ,0 #endif
};
const u8 SIDV [] = {
    ADDR2SID(V01)
    #ifdef V02, ADDR2SID(V02) #else ,0 #endif
    #ifdef V03, ADDR2SID(V03) #else ,0 #endif
    #ifdef V04, ADDR2SID(V04) #else ,0 #endif
};

//Массив вытяжек
const u16 IDZ [] = {
    ADDR2ID(T01)
    #ifdef T02, ADDR2ID(T02) #else ,0 #endif
    #ifdef T03, ADDR2ID(T03) #else ,0 #endif
    #ifdef T04, ADDR2ID(T04) #else ,0 #endif
    #ifdef T05, ADDR2ID(T05) #else ,0 #endif
    #ifdef T06, ADDR2ID(T06) #else ,0 #endif
    #ifdef T07, ADDR2ID(T04) #else ,0 #endif
    #ifdef T08, ADDR2ID(T05) #else ,0 #endif
    #ifdef T09, ADDR2ID(T06) #else ,0 #endif
    #ifdef T10, ADDR2ID(T06) #else ,0 #endif
};
const u8 SIDZ [] = {
    ADDR2SID(T01)
    #ifdef T02, ADDR2SID(T02) #else ,0 #endif
    #ifdef T03, ADDR2SID(T03) #else ,0 #endif
    #ifdef T04, ADDR2SID(T04) #else ,0 #endif
    #ifdef T05, ADDR2SID(T05) #else ,0 #endif
    #ifdef T06, ADDR2SID(T06) #else ,0 #endif
    #ifdef T07, ADDR2SID(T07) #else ,0 #endif
    #ifdef T08, ADDR2SID(T08) #else ,0 #endif
    #ifdef T09, ADDR2SID(T09) #else ,0 #endif
    #ifdef T10, ADDR2SID(T10) #else ,0 #endif
};

V-ID/s:5
{
    for(u8 i, i<11, ++i)
    {
        if([@IDK[i]:@SIDK[i].0]%2!=0)
        {
            if()
        }
    }
}