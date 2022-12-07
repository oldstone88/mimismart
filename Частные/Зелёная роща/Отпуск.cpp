/*
{
  desc:"Отпуск",
  tag:"item",
  selectArea:true,
  
  vars:
  [
    {name:"IOFF00",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Выкл. 0",descWidth:100},
    {name:"IOFF01",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Выкл. 1",descWidth:100},
    {name:"IOFF02",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Выкл. 2",descWidth:100},
    {name:"IOFF03",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Выкл. 3",descWidth:100},
    {name:"IOFF04",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Выкл. 4",descWidth:100},
    {name:"ION00",type:"devices-list",required:false,width:600,filter:["script"],desc:"Присутствие",descWidth:100},
    {name:"ION01",type:"devices-list",required:false,width:600,filter:["script"],desc:"Выкл. Весь свет",descWidth:100},
    {name:"ION02",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Вкл. 2",descWidth:100},
    {name:"ION03",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Вкл. 3",descWidth:100},
    {name:"ION04",type:"devices-list",required:false,width:600,filter:["script"],desc:"Сценарий Вкл. 4",descWidth:100},
    {name:"B00",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 00",descWidth:100},
    {name:"B01",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 01",descWidth:100},
    {name:"B02",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 02",descWidth:100},
    {name:"B03",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 03",descWidth:100},
    {name:"B04",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 04",descWidth:100},
    {name:"B05",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 05",descWidth:100},
    {name:"B06",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 06",descWidth:100},
    {name:"B07",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 07",descWidth:100},
    {name:"B08",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 08",descWidth:100},
    {name:"B09",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 09",descWidth:100},
    {name:"B10",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 10",descWidth:100},
    {name:"B11",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 11",descWidth:100},
    {name:"B12",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 12",descWidth:100},
    {name:"B13",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 13",descWidth:100},
    {name:"B14",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 14",descWidth:100},
    {name:"B15",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 15",descWidth:100},
    {name:"B16",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 16",descWidth:100},
    {name:"B17",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 17",descWidth:100},
    {name:"B18",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 18",descWidth:100},
    {name:"B19",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы 19",descWidth:100},
  ]
}
*/

const u16 ID [] = {
    ADDR2ID(B00)
    #ifdef B01, ADDR2ID(B01) #else ,0 #endif
    #ifdef B02, ADDR2ID(B02) #else ,0 #endif
    #ifdef B03, ADDR2ID(B03) #else ,0 #endif
    #ifdef B04, ADDR2ID(B04) #else ,0 #endif
    #ifdef B05, ADDR2ID(B05) #else ,0 #endif
    #ifdef B06, ADDR2ID(B06) #else ,0 #endif
    #ifdef B07, ADDR2ID(B07) #else ,0 #endif
    #ifdef B08, ADDR2ID(B08) #else ,0 #endif
    #ifdef B09, ADDR2ID(B09) #else ,0 #endif
    #ifdef B10, ADDR2ID(B10) #else ,0 #endif
    #ifdef B11, ADDR2ID(B11) #else ,0 #endif
    #ifdef B12, ADDR2ID(B12) #else ,0 #endif
    #ifdef B13, ADDR2ID(B13) #else ,0 #endif
    #ifdef B14, ADDR2ID(B14) #else ,0 #endif
    #ifdef B15, ADDR2ID(B15) #else ,0 #endif
    #ifdef B16, ADDR2ID(B16) #else ,0 #endif
    #ifdef B17, ADDR2ID(B17) #else ,0 #endif
    #ifdef B18, ADDR2ID(B18) #else ,0 #endif
    #ifdef B19, ADDR2ID(B19) #else ,0 #endif
};
const u8 SID [] = {
    ADDR2ID(B00)
    #ifdef B01, ADDR2ID(B01) #else ,0 #endif
    #ifdef B02, ADDR2ID(B02) #else ,0 #endif
    #ifdef B03, ADDR2ID(B03) #else ,0 #endif
    #ifdef B04, ADDR2ID(B04) #else ,0 #endif
    #ifdef B05, ADDR2ID(B05) #else ,0 #endif
    #ifdef B06, ADDR2ID(B06) #else ,0 #endif
    #ifdef B07, ADDR2ID(B07) #else ,0 #endif
    #ifdef B08, ADDR2ID(B08) #else ,0 #endif
    #ifdef B09, ADDR2ID(B09) #else ,0 #endif
    #ifdef B10, ADDR2ID(B10) #else ,0 #endif
    #ifdef B11, ADDR2ID(B11) #else ,0 #endif
    #ifdef B12, ADDR2ID(B12) #else ,0 #endif
    #ifdef B13, ADDR2ID(B13) #else ,0 #endif
    #ifdef B14, ADDR2ID(B14) #else ,0 #endif
    #ifdef B15, ADDR2ID(B15) #else ,0 #endif
    #ifdef B16, ADDR2ID(B16) #else ,0 #endif
    #ifdef B17, ADDR2ID(B17) #else ,0 #endif
    #ifdef B18, ADDR2ID(B18) #else ,0 #endif
    #ifdef B19, ADDR2ID(B19) #else ,0 #endif
};

u8 i=0;

void CLOSE()
{
  u8 buff=0;
  getStatus(@ID:@SID, &buff);
  if( ID[i]!=0 || buff!=2 || buff!=3 ) {setStatus(@ID[i]:@SID[i], 0);} else cancelDelayedCall(CLOSE);
}

V-ID/V-ADDR
{
  if( (opt(0)&1)==1 )
  {
    #ifdef IOFF00 if(([IOFF00.0]&1)==1) setStatus(IOFF00, 0); #endif
    #ifdef IOFF01 if(([IOFF00.0]&1)==1) setStatus(IOFF01, 0); #endif
    #ifdef IOFF02 if(([IOFF00.0]&1)==1) setStatus(IOFF02, 0); #endif
    #ifdef IOFF03 if(([IOFF00.0]&1)==1) setStatus(IOFF03, 0); #endif
    #ifdef IOFF04 if(([IOFF00.0]&1)==1) setStatus(IOFF04, 0); #endif

    #ifdef ION01 if(([ION00.0]&1)==0) setStatus(ION01, 1); #endif
    #ifdef ION02 if(([ION00.0]&1)==0) setStatus(ION02, 1); #endif
    #ifdef ION03 if(([ION00.0]&1)==0) setStatus(ION03, 1); #endif
    #ifdef ION04 if(([ION00.0]&1)==0) setStatus(ION04, 1); #endif
    setStatus(1000:100, "Отпуск");
    delayedCallR(CLOSE, 1);
  }
  else
    if( (opt(0)&1)==0 ) {if ( ([ION00.0]&1)==1 ) setStatus(ION00, 0);  setStatus(1000:100, "Комфорт");}
}

V-ID/s:5
{
  if( ([V-ADDR.0]&1)==1 )
  {u8 res = timeInRange(19:00-00:30);
    if(res!=0 || ([ION00.0]&1)==0) setStatus(ION00, 1); else
    if(res==0 || ([ION00.0]&1)==1) setStatus(ION00, 0);}
}