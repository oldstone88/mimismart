/*
{
    desc:"Добавление виртуального устройства для управления жалюзи",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"virtual", "sub-type":"jalousie120", "length":"1"},
    ],
    vars:[
        {name:"L00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть",descWidth:100},
        {name:"L01",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть",descWidth:100},
        {type:"comment",text:"Введите название для устройства:"},
        {name:"NAME",type:"string",required:true,min:3,max:40},
        {type:"comment",text:"Введите время хода мотора:"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"JALOUSIE",type:"hidden",value:"%TARGET%:%SUBID%"}
    ]
}
*/
u8 i=0;
u8 statusOfJalousie = 0;

void VIKL()
{setStatus(L01, 0); }

void VKL()
{setStatus(L00, 1); }

void OFF()
{
    setStatus(L00, 0);
    delayedCallMs(VIKL, 100);
}

void openJalousie(){
    statusOfJalousie = 1;
    setStatus(JALOUSIE, statusOfJalousie);
}
void closeJalousie(){
    statusOfJalousie = 0;
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
            delayedCall(openJalousie, TIME);
            setStatus(L00, 1);
            delayedCallMs(OFF, 500);
            
        } else if  (statusOfJalousie == 3 || statusOfJalousie == 2) {
            // если открываеться  - остановить
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(L01, 1);
            delayedCallMs(VKL, 100);
            delayedCallMs(OFF, 500);
            
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
            setStatus(L01, 1);
            delayedCallMs(OFF, 500);
            
        } else if  (statusOfJalousie == 2 || statusOfJalousie == 3) {
            // если закрываеться - остановать
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(L01, 1);
            delayedCallMs(VKL, 100);
            delayedCallMs(OFF, 500);
        }
    }

if(opt(0)==0xFF){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    cancelDelayedCall(closeJalousie);
    cancelDelayedCall(openJalousie);
    setStatus(L01, 1);
    delayedCallMs(VKL, 100);
    delayedCallMs(OFF, 500);
  }

}

