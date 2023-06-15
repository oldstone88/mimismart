/*
{
    desc:"Ворота откр-стоп-закр",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"virtual", "sub-type":"jalousie120", "length":"1"},
    ],
    vars:[
        {name:"UP",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть",descWidth:100},
        {name:"DOWN",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть",descWidth:100},
        {name:"STOP",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Стоп",descWidth:100},
        {name:"HOPEN",type:"devices-list",required:true,width:600,filter:["door-sensor"],desc:"Верхний геркон",descWidth:100},
        {name:"HCLOSE",type:"devices-list",required:true,width:600,filter:["door-sensor"],desc:"Нижний геркон",descWidth:100},
        {type:"comment",text:"Введите название для устройства:"},
        {name:"NAME",type:"string",required:true,min:3,max:40},
        {type:"comment",text:"Введите время до аварийного оповещения"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"JALOUSIE",type:"hidden",value:"%TARGET%:%SUBID%"}
    ]
}
*/
u8 i=0;
u8 statusOfJalousie = 0;

//Импульс закрыть
void VIKL(){
    setStatus(DOWN, 0);
}

//Импульс остановки
void OST(){
    setStatus(STOP, 0);
}

//Импульс открыть
void OFF(){
    setStatus(UP, 0);
}

void openJalousie(){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(2047:32, {4, "Ворота открыты по таймеру! Проверьте геркон!!!"});
}

void closeJalousie(){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(2047:32, {4, "Ворота закрыты по таймеру! Проверьте геркон!!!"});
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
            delayedCall(openJalousie, TIME);
            setStatus(UP, 1);
            delayedCallMs(OFF, 500);
            
        } else if  (statusOfJalousie == 3 || statusOfJalousie == 2) {
            // если открываеться  - остановить
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(STOP, 1);
            delayedCallMs(OST, 500);
            
        }
    }
    
    // пришла команда закрыть
    if(opt(0) == 0) {
    
        if(statusOfJalousie == 1 || statusOfJalousie == 4 || i==0) {
            // если было открыто или где-то по середине - закрыть
            i=1;
            statusOfJalousie = 2;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(closeJalousie, TIME);
            setStatus(DOWN, 1);
            delayedCallMs(VIKL, 500);
            
        } else if  (statusOfJalousie == 2 || statusOfJalousie == 3) {
            // если закрываеться - остановать
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(STOP, 1);
            delayedCallMs(STOP, 500);
        }
    }

if(opt(0)==0xFF){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    cancelDelayedCall(closeJalousie);
    cancelDelayedCall(openJalousie);
    setStatus(OST, 1);
    delayedCallMs(OST, 500);
  }

}

//Секция герконов
V-ID/s:1
{
    if ([HOPEN.0]==0){
        statusOfJalousie=1;
        cancelDelayedCall(openJalousie);
        cancelDelayedCall(closeJalousie);
        setStatus(JALOUSIE, statusOfJalousie);
    }
    if ([CLOSE.0]==0){
        statusOfJalousie=0;
        cancelDelayedCall(openJalousie);
        cancelDelayedCall(closeJalousie);
        setStatus(JALOUSIE, statusOfJalousie);
    }
}
