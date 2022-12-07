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
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID06%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID07%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID08%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID09%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
        {tag:"item", id:"%TARGET%", name:"Кондиционер", "sub-id":"%SUBID10%", "type":"conditioner", "t-min":"16", "t-delta":"14", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x0F"},
    ],
    vars:[
        {name:"T01",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 1",descWidth:100},
        {name:"T02",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 2",descWidth:100},
        {name:"T03",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 3",descWidth:100},
        {name:"T04",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 4",descWidth:100},
        {name:"T05",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 5",descWidth:100},
        {name:"T06",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 6",descWidth:100},
        {name:"T07",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 7",descWidth:100},
        {name:"T08",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 8",descWidth:100},
        {name:"T09",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 9",descWidth:100},
        {name:"T10",type:"devices-list",required:false,width:300,filter:["temperature-sensor"],desc:"Температура 10",descWidth:100},
        {name:"Z01",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 1",descWidth:100},
        {name:"Z02",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 2",descWidth:100},
        {name:"Z03",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 3",descWidth:100},
        {name:"Z04",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 4",descWidth:100},
        {name:"Z05",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 5",descWidth:100},
        {name:"Z06",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 6",descWidth:100},
        {name:"Z07",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 7",descWidth:100},
        {name:"Z08",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 8",descWidth:100},
        {name:"Z09",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 9",descWidth:100},
        {name:"Z10",type:"devices-list",required:false,width:300,filter:["dimer-lamp"],desc:"Заслонка 10",descWidth:100},
        {name:"V01",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 1",descWidth:100},
        {name:"V02",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 2",descWidth:100},
        {name:"V03",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 3",descWidth:100},
        {name:"V04",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 4",descWidth:100},
        {name:"V05",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 5",descWidth:100},
        {name:"V06",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 6",descWidth:100},
        {name:"V07",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 7",descWidth:100},
        {name:"V08",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 8",descWidth:100},
        {name:"V09",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 9",descWidth:100},
        {name:"V10",type:"devices-list",required:false,width:300,filter:["dimer-lamp","lamp"],desc:"Вытяжка 10",descWidth:100},
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

u8 state[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

V-ID/s:5
{
    #ifdef Z01
    if([KOND01.0]%2!=0)
    {
        state[1]=1;
    #ifdef V01 setStatus(V01, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND01.4]==1) {setStatus(Z01, {1, 75, 0});} else   //Первая мощность
        if([KOND01.4]==2) {setStatus(Z01, {1, 150, 0});} else  //Вторая мощность
        if([KOND01.4]==3) {setStatus(Z01, {1, 250, 0});} else  //Треться мощность
        if([KOND01.4]==0) {  //Авто
        if(([KOND01.1]+16)+2>[T01.1]) {setStatus(Z01, {1, 250, 0});}
        else if(([KOND01.1]+16)+1>[T01.1]) {setStatus(Z01, {1, 188, 0});}
        else if(([KOND01.1]+16)>[T01.1]) {setStatus(Z01, {1, 125, 0});}
        else {setStatus(Z01, {1, 63, 0});}}
    } else if([KOND01.0]%2==0 && state[1]==1){
        state[1]=0;
        setStatus(Z01, {0, 0, 0});
        #ifdef V01 setStatus(V01, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
    #ifdef Z02
    if([KOND02.0]%2!=0)
    {
        state[2]=1;
    #ifdef V02 setStatus(V02, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND02.4]==1) {setStatus(Z02, {1, 75, 0});} else   //Первая мощность
        if([KOND02.4]==2) {setStatus(Z02, {1, 150, 0});} else  //Вторая мощность
        if([KOND02.4]==3) {setStatus(Z02, {1, 250, 0});} else  //Треться мощность
        if([KOND02.4]==0) {  //Авто
        if(([KOND02.1]+16)+2>[T02.1]) {setStatus(Z02, {1, 250, 0});}
        else if(([KOND02.1]+16)+1>[T02.1]) {setStatus(Z02, {1, 188, 0});}
        else if(([KOND02.1]+16)>[T02.1]) {setStatus(Z02, {1, 125, 0});}
        else {setStatus(Z02, {1, 63, 0});}}
    } else if([KOND02.0]%2==0 && state[2]==1){
        state[2]=0;
        setStatus(Z02, {0, 0, 0});
        #ifdef V02 setStatus(V02, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z03
    if([KOND03.0]%2!=0)
    {
        state[3]=1;
    #ifdef V03 setStatus(V03, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND03.4]==1) {setStatus(Z03, {1, 75, 0});} else   //Первая мощность
        if([KOND03.4]==2) {setStatus(Z03, {1, 150, 0});} else  //Вторая мощность
        if([KOND03.4]==3) {setStatus(Z03, {1, 250, 0});} else  //Треться мощность
        if([KOND03.4]==0) {  //Авто
        if(([KOND03.1]+16)+2>[T03.1]) {setStatus(Z03, {1, 250, 0});}
        else if(([KOND03.1]+16)+1>[T03.1]) {setStatus(Z03, {1, 188, 0});}
        else if(([KOND03.1]+16)>[T03.1]) {setStatus(Z03, {1, 125, 0});}
        else {setStatus(Z03, {1, 63, 0});}}
    } else if([KOND03.0]%2==0 && state[3]==1){
        state[3]=0;
        setStatus(Z03, {0, 0, 0});
        #ifdef V03 setStatus(V03, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z04
    if([KOND04.0]%2!=0)
    {
        state[0]=4;
    #ifdef V04 setStatus(V04, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND04.4]==1) {setStatus(Z04, {1, 75, 0});} else   //Первая мощность
        if([KOND04.4]==2) {setStatus(Z04, {1, 150, 0});} else  //Вторая мощность
        if([KOND04.4]==3) {setStatus(Z04, {1, 250, 0});} else  //Треться мощность
        if([KOND04.4]==0) {  //Авто
        if(([KOND04.1]+16)+2>[T04.1]) {setStatus(Z04, {1, 250, 0});}
        else if(([KOND04.1]+16)+1>[T04.1]) {setStatus(Z04, {1, 188, 0});}
        else if(([KOND04.1]+16)>[T04.1]) {setStatus(Z04, {1, 125, 0});}
        else {setStatus(Z04, {1, 63, 0});}}
    } else if([KOND04.0]%2==0 && state[4]==1){
        state[4]=0;
        setStatus(Z04, {0, 0, 0});
        #ifdef V04 setStatus(V04, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z05
    if([KOND05.0]%2!=0)
    {
        state[5]=1;
    #ifdef V05 setStatus(V05, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND05.4]==1) {setStatus(Z05, {1, 75, 0});} else   //Первая мощность
        if([KOND05.4]==2) {setStatus(Z05, {1, 150, 0});} else  //Вторая мощность
        if([KOND05.4]==3) {setStatus(Z05, {1, 250, 0});} else  //Треться мощность
        if([KOND05.4]==0) {  //Авто
        if(([KOND05.1]+16)+2>[T05.1]) {setStatus(Z05, {1, 250, 0});}
        else if(([KOND05.1]+16)+1>[T05.1]) {setStatus(Z05, {1, 188, 0});}
        else if(([KOND05.1]+16)>[T05.1]) {setStatus(Z05, {1, 125, 0});}
        else {setStatus(Z05, {1, 63, 0});}}
    } else if([KOND05.0]%2==0 && state[5]==1){
        state[5]=0;
        setStatus(Z05, {0, 0, 0});
        #ifdef V05 setStatus(V05, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z06
    if([KOND06.0]%2!=0)
    {
        state[6]=1;
    #ifdef V06 setStatus(V06, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND06.4]==1) {setStatus(Z06, {1, 75, 0});} else   //Первая мощность
        if([KOND06.4]==2) {setStatus(Z06, {1, 150, 0});} else  //Вторая мощность
        if([KOND06.4]==3) {setStatus(Z06, {1, 250, 0});} else  //Треться мощность
        if([KOND06.4]==0) {  //Авто
        if(([KOND06.1]+16)+2>[T06.1]) {setStatus(Z06, {1, 250, 0});}
        else if(([KOND06.1]+16)+1>[T06.1]) {setStatus(Z06, {1, 188, 0});}
        else if(([KOND06.1]+16)>[T06.1]) {setStatus(Z06, {1, 125, 0});}
        else {setStatus(Z06, {1, 63, 0});}}
    } else if([KOND06.0]%2==0 && state[6]==1){
        state[6]=0;
        setStatus(Z06, {0, 0, 0});
        #ifdef V06 setStatus(V06, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z07
    if([KOND07.0]%2!=0)
    {
        state[7]=1;
    #ifdef V07 setStatus(V07, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND07.4]==1) {setStatus(Z07, {1, 75, 0});} else   //Первая мощность
        if([KOND07.4]==2) {setStatus(Z07, {1, 150, 0});} else  //Вторая мощность
        if([KOND07.4]==3) {setStatus(Z07, {1, 250, 0});} else  //Треться мощность
        if([KOND07.4]==0) {  //Авто
        if(([KOND07.1]+16)+2>[T07.1]) {setStatus(Z07, {1, 250, 0});}
        else if(([KOND07.1]+16)+1>[T07.1]) {setStatus(Z07, {1, 188, 0});}
        else if(([KOND07.1]+16)>[T07.1]) {setStatus(Z07, {1, 125, 0});}
        else {setStatus(Z07, {1, 63, 0});}}
    } else if([KOND07.0]%2==0 && state[7]==1){
        state[7]=0;
        setStatus(Z07, {0, 0, 0});
        #ifdef V07 setStatus(V07, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z08
    if([KOND08.0]%2!=0)
    {
        state[8]=1;
    #ifdef V08 setStatus(V08, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND08.4]==1) {setStatus(Z08, {1, 75, 0});} else   //Первая мощность
        if([KOND08.4]==2) {setStatus(Z08, {1, 150, 0});} else  //Вторая мощность
        if([KOND08.4]==3) {setStatus(Z08, {1, 250, 0});} else  //Треться мощность
        if([KOND08.4]==0) {  //Авто
        if(([KOND08.1]+16)+2>[T08.1]) {setStatus(Z08, {1, 250, 0});}
        else if(([KOND08.1]+16)+1>[T08.1]) {setStatus(Z08, {1, 188, 0});}
        else if(([KOND08.1]+16)>[T08.1]) {setStatus(Z08, {1, 125, 0});}
        else {setStatus(Z08, {1, 63, 0});}}
    } else if([KOND08.0]%2==0 && state[8]==1){
        state[8]=0;
        setStatus(Z08, {0, 0, 0});
        #ifdef V08 setStatus(V08, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z09
    if([KOND09.0]%2!=0)
    {
        state[9]=1;
    #ifdef V09 setStatus(V09, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND09.4]==1) {setStatus(Z09, {1, 75, 0});} else   //Первая мощность
        if([KOND09.4]==2) {setStatus(Z09, {1, 150, 0});} else  //Вторая мощность
        if([KOND09.4]==3) {setStatus(Z09, {1, 250, 0});} else  //Треться мощность
        if([KOND09.4]==0) {  //Авто
        if(([KOND09.1]+16)+2>[T09.1]) {setStatus(Z09, {1, 250, 0});}
        else if(([KOND09.1]+16)+1>[T09.1]) {setStatus(Z09, {1, 188, 0});}
        else if(([KOND09.1]+16)>[T09.1]) {setStatus(Z09, {1, 125, 0});}
        else {setStatus(Z09, {1, 63, 0});}}
    } else if([KOND09.0]%2==0 && state[9]==1){
        state[9]=0;
        setStatus(Z09, {0, 0, 0});
        #ifdef V09 setStatus(V09, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
        #ifdef Z10
    if([KOND10.0]%2!=0)
    {
        state[10]=1;
    #ifdef V10 setStatus(V10, {1, 125, 0}); #endif //Включаем вытяжку на 50%
    if([KOND10.4]==1) {setStatus(Z10, {1, 75, 0});} else   //Первая мощность
        if([KOND10.4]==2) {setStatus(Z10, {1, 150, 0});} else  //Вторая мощность
        if([KOND10.4]==3) {setStatus(Z10, {1, 250, 0});} else  //Треться мощность
        if([KOND10.4]==0) {  //Авто
        if(([KOND10.1]+16)+2>[T10.1]) {setStatus(Z10, {1, 250, 0});}
        else if(([KOND10.1]+16)+1>[T10.1]) {setStatus(Z10, {1, 188, 0});}
        else if(([KOND10.1]+16)>[T10.1]) {setStatus(Z10, {1, 125, 0});}
        else {setStatus(Z10, {1, 63, 0});}}
    } else if([KOND10.0]%2==0 && state[10]==1){
        state[10]=0;
        setStatus(Z10, {0, 0, 0});
        #ifdef V10 setStatus(V10, {1, 75, 0}); #endif //Включаем вытяжку на 30%
    }
    #endif
}