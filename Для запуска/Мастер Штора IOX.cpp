/*
{
    desc:"Групповое управление шторами",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"virtual", "sub-type":"jalousie120", "length":"1"},
    ],
    vars:[
        {type:"comment",text:"Введите название для устройства:"},
        {name:"NAME",type:"string",required:true,min:3,max:40},
        {name:"JALOUSIE",type:"hidden",value:"%TARGET%:%SUBID%"},
        {name:"SLAVE01",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 1"},
        {name:"SLAVE02",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 2"},
        {name:"SLAVE03",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 3"},
        {name:"SLAVE04",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 4"},
        {name:"SLAVE05",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 5"},
        {name:"SLAVE06",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 6"},
    ]
}
*/

const u16 ID [] = {
    ADDR2ID(SLAVE01)
    #ifdef SLAVE02, ADDR2ID(SLAVE02) #else ,0 #endif
    #ifdef SLAVE03, ADDR2ID(SLAVE03) #else ,0 #endif
    #ifdef SLAVE04, ADDR2ID(SLAVE04) #else ,0 #endif
    #ifdef SLAVE05, ADDR2ID(SLAVE05) #else ,0 #endif
    #ifdef SLAVE06, ADDR2ID(SLAVE06) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2SID(SLAVE01)
    #ifdef SLAVE02, ADDR2SID(SLAVE02) #else ,0 #endif
    #ifdef SLAVE03, ADDR2SID(SLAVE03) #else ,0 #endif
    #ifdef SLAVE04, ADDR2SID(SLAVE04) #else ,0 #endif
    #ifdef SLAVE05, ADDR2SID(SLAVE05) #else ,0 #endif
    #ifdef SLAVE06, ADDR2SID(SLAVE06) #else ,0 #endif
};

u8 count=0;

void OPEN()
{
    setStatus(@ID[count]:@SID[count], 1);
    ++count;
    if(ID[count]){
        delayedCall(OPEN, 1);
    }
}

void CLOSE()
{
    setStatus(@ID[count]:@SID[count], 0);
    ++count;
    if(ID[count]){
        delayedCall(CLOSE, 1);
    }
}

u8 i=0;
u8 statusOfJalousie = 0;

void openJalousie(){
    statusOfJalousie = 1;
    setStatus(JALOUSIE, statusOfJalousie);
}
void closeJalousie(){
    statusOfJalousie = 0;
    setStatus(JALOUSIE, statusOfJalousie);
}

void stopJalousie(){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
}

void onInit()
{
if ([JALOUSIE.0]==1) {statusOfJalousie=1; srvError("%d", statusOfJalousie);} else
if ([JALOUSIE.0]==4) {statusOfJalousie=4; srvError("%d", statusOfJalousie);}
}


V-ID/JALOUSIE {
    
    // пришла команда открыть
    if(opt(0) == 1) {
    
        if(statusOfJalousie == 0 || statusOfJalousie == 4) {
            // если было закрыто - открыть
            statusOfJalousie = 3;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(stopJalousie, 3);
            cancelDelayedCall(CLOSE);
            count=0;
            OPEN();
            
        } else if  (statusOfJalousie == 3 || statusOfJalousie == 2) {
            // если открываеться  - остановить
            cancelDelayedCall(stopJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            
        }
    }
    
    // пришла команда закрыть
    if(opt(0) == 0) {
    
        if(statusOfJalousie == 1 || statusOfJalousie == 4 || i==0) {
            // если было открыто или где-то по середине - закрыть
            i=1;
            statusOfJalousie = 2;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(stopJalousie, 3);
            cancelDelayedCall(OPEN);
            count=0;
            CLOSE();
            
        } else if  (statusOfJalousie == 2 || statusOfJalousie == 3) {
            // если закрываеться - остановать
            cancelDelayedCall(stopJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
        }
    }

    if(opt(0)==0xFF){
		statusOfJalousie = 4;
		setStatus(JALOUSIE, statusOfJalousie);
		cancelDelayedCall(stopJalousie);
	}

}

V-ID/s:5
{
    if(([SLAVE01.0]&7)==0
    #ifdef SLAVE02 && ([SLAVE02.0]&7)==0 #endif
    #ifdef SLAVE03 && ([SLAVE03.0]&7)==0 #endif
    #ifdef SLAVE04 && ([SLAVE04.0]&7)==0 #endif
    #ifdef SLAVE05 && ([SLAVE05.0]&7)==0 #endif
    #ifdef SLAVE06 && ([SLAVE06.0]&7)==0 #endif
    #ifdef SLAVE07 && ([SLAVE07.0]&7)==0 #endif
    #ifdef SLAVE08 && ([SLAVE08.0]&7)==0 #endif
    #ifdef SLAVE09 && ([SLAVE09.0]&7)==0 #endif
        ) closeJalousie(); else
    if(([SLAVE01.0]&7)==1
    #ifdef SLAVE02 && ([SLAVE02.0]&7)==1 #endif
    #ifdef SLAVE03 && ([SLAVE03.0]&7)==1 #endif
    #ifdef SLAVE04 && ([SLAVE04.0]&7)==1 #endif
    #ifdef SLAVE05 && ([SLAVE05.0]&7)==1 #endif
    #ifdef SLAVE06 && ([SLAVE06.0]&7)==1 #endif
    #ifdef SLAVE07 && ([SLAVE07.0]&7)==1 #endif
    #ifdef SLAVE08 && ([SLAVE08.0]&7)==1 #endif
    #ifdef SLAVE09 && ([SLAVE09.0]&7)==1 #endif
        ) openJalousie(); else {stopJalousie();}


}
