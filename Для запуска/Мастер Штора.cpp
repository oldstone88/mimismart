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
        {name:"SLAVE07",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 7"},
        {name:"SLAVE08",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 8"},
        {name:"SLAVE09",type:"devices-list",required:false, filter:["jalousie", "virtual"],desc:"Слейв 9"},
    ]
}
*/

void OPEN()
{
    #ifdef SLAVE01 if(([SLAVE01.0]&7)==0 || ([SLAVE01.0]&7)==4 || ([SLAVE01.0]&7)==2) {setStatus(SLAVE01, 1);} #endif
    #ifdef SLAVE02 if(([SLAVE02.0]&7)==0 || ([SLAVE02.0]&7)==4 || ([SLAVE02.0]&7)==2) {setStatus(SLAVE02, 1);} #endif
    #ifdef SLAVE03 if(([SLAVE03.0]&7)==0 || ([SLAVE03.0]&7)==4 || ([SLAVE03.0]&7)==2) {setStatus(SLAVE03, 1);} #endif
    #ifdef SLAVE04 if(([SLAVE04.0]&7)==0 || ([SLAVE04.0]&7)==4 || ([SLAVE04.0]&7)==2) {setStatus(SLAVE04, 1);} #endif
    #ifdef SLAVE05 if(([SLAVE05.0]&7)==0 || ([SLAVE05.0]&7)==4 || ([SLAVE05.0]&7)==2) {setStatus(SLAVE05, 1);} #endif
    #ifdef SLAVE06 if(([SLAVE06.0]&7)==0 || ([SLAVE06.0]&7)==4 || ([SLAVE06.0]&7)==2) {setStatus(SLAVE06, 1);} #endif
    #ifdef SLAVE07 if(([SLAVE07.0]&7)==0 || ([SLAVE07.0]&7)==4 || ([SLAVE07.0]&7)==2) {setStatus(SLAVE07, 1);} #endif
    #ifdef SLAVE08 if(([SLAVE08.0]&7)==0 || ([SLAVE08.0]&7)==4 || ([SLAVE08.0]&7)==2) {setStatus(SLAVE08, 1);} #endif
    #ifdef SLAVE09 if(([SLAVE09.0]&7)==0 || ([SLAVE09.0]&7)==4 || ([SLAVE09.0]&7)==2) {setStatus(SLAVE09, 1);} #endif
}

void CLOSE()
{
    #ifdef SLAVE01 if(([SLAVE01.0]&7)==1 || ([SLAVE01.0]&7)==4 || ([SLAVE01.0]&7)==3) {setStatus(SLAVE01, 0);} #endif
    #ifdef SLAVE02 if(([SLAVE02.0]&7)==1 || ([SLAVE02.0]&7)==4 || ([SLAVE02.0]&7)==3) {setStatus(SLAVE02, 0);} #endif
    #ifdef SLAVE03 if(([SLAVE03.0]&7)==1 || ([SLAVE03.0]&7)==4 || ([SLAVE03.0]&7)==3) {setStatus(SLAVE03, 0);} #endif
    #ifdef SLAVE04 if(([SLAVE04.0]&7)==1 || ([SLAVE04.0]&7)==4 || ([SLAVE04.0]&7)==3) {setStatus(SLAVE04, 0);} #endif
    #ifdef SLAVE05 if(([SLAVE05.0]&7)==1 || ([SLAVE05.0]&7)==4 || ([SLAVE05.0]&7)==3) {setStatus(SLAVE05, 0);} #endif
    #ifdef SLAVE06 if(([SLAVE06.0]&7)==1 || ([SLAVE06.0]&7)==4 || ([SLAVE06.0]&7)==3) {setStatus(SLAVE06, 0);} #endif
    #ifdef SLAVE07 if(([SLAVE07.0]&7)==1 || ([SLAVE07.0]&7)==4 || ([SLAVE07.0]&7)==3) {setStatus(SLAVE07, 0);} #endif
    #ifdef SLAVE08 if(([SLAVE08.0]&7)==1 || ([SLAVE08.0]&7)==4 || ([SLAVE08.0]&7)==3) {setStatus(SLAVE08, 0);} #endif
    #ifdef SLAVE09 if(([SLAVE09.0]&7)==1 || ([SLAVE09.0]&7)==4 || ([SLAVE09.0]&7)==3) {setStatus(SLAVE09, 0);} #endif
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
srvError("Перезагрузка, состояние штор %d",[JALOUSIE.0] );
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
            OPEN();
            delayedCall(OPEN, 2);
            
        } else if  (statusOfJalousie == 3 || statusOfJalousie == 2) {
            // если открываеться  - остановить
            cancelDelayedCall(stopJalousie);
            //cancelDelayedCall(openJalousie);
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
            CLOSE();
            delayedCall(CLOSE, 2);
            
        } else if  (statusOfJalousie == 2 || statusOfJalousie == 3) {
            // если закрываеться - остановать
            cancelDelayedCall(stopJalousie);
            //cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
        }
    }

if(opt(0)==0xFF){
		statusOfJalousie = 4;
		setStatus(JALOUSIE, statusOfJalousie);
		cancelDelayedCall(stopJalousie);
		//cancelDelayedCall(openJalousie);
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