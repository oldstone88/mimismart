/*
{
    desc:"Штора RHX Серединка",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"virtual", "sub-type":"jalousie120", "length":"1"},
    ],
    vars:[
        {type:"comment",text:"Ввведите название для устройства:"},
        {name:"NAME",type:"string",required:true,min:3,max:40},
        {type:"comment",text:"Введите время хода мотора:"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"JALOUSIE",type:"hidden",value:"%TARGET%:%SUBID%"},
        {name:"OPEN",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть",descWidth:100},
        {name:"CLOSE",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть",descWidth:100},
    ]
}
*/
u8 i=0;
u8 statusOfJalousie = 0;

void openJalousie(){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(OPEN, 0);
    setStatus(CLOSE, 0);
}
void closeJalousie(){
    statusOfJalousie = 4;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(OPEN, 0);
    setStatus(CLOSE, 0);
}

void onInit()
{
    statusOfJalousie=4;
    setStatus(JALOUSIE, statusOfJalousie);
}


V-ID/JALOUSIE {
    // пришла команда открыть
    if(opt(0) == 1) {
    
        if(statusOfJalousie == 0 || statusOfJalousie == 4) {
            // если было закрыто - открыть
            statusOfJalousie = 3;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(openJalousie, TIME);
            setStatus(OPEN, 1);
            
        } else if  (statusOfJalousie == 3 || statusOfJalousie == 2) {
            // если открываеться  - остановить
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(OPEN, 0);
            setStatus(CLOSE, 0);
            
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
            setStatus(CLOSE, 1);
            
        } else if  (statusOfJalousie == 2 || statusOfJalousie == 3) {
            // если закрываеться - остановать
            cancelDelayedCall(closeJalousie);
            cancelDelayedCall(openJalousie);
            statusOfJalousie = 4;
            setStatus(JALOUSIE, statusOfJalousie);
            setStatus(OPEN, 0);
            setStatus(CLOSE, 0);
        }
    }

if(opt(0)==0xFF){
		statusOfJalousie = 4;
		setStatus(JALOUSIE, statusOfJalousie);
		cancelDelayedCall(closeJalousie);
		cancelDelayedCall(openJalousie);
        setStatus(OPEN, 0);
        setStatus(CLOSE, 0);
	}

}
