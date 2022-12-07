/*
{
  desc:"Регулировка клапаном подачи теплоносителя в контур теплы полов",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"70", "t-min":"10", "vane-ver":"0x00", "vane-hor":"0x00", "modes":"0x00", "funs":"0x00"},
  ],
  vars:[
    {name:"TEMP",type:"hidden",value:"%TARGET%:%SUBID%"},
    {name:"CONDSTART", type:"number", defaultValue:22, required:true, desc:"Минимальная температура"},
    {name:"D00", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры", descWidth:370},
    {name:"G00", type:"number", defaultValue:20, required:true, desc:"Гистерезис(1 градус = 10 пунктов)"},
    {name:"TIME", type:"number", defaultValue:60, required:true, desc:"Время опроса, с"},
    {name:"LITTLE", type:"number", defaultValue:5, required:true, desc:"Калибровки, с"},
    {name:"POINT", type:"number", defaultValue:120, required:true, desc:"Время полного открытия"},
    {name:"L00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Клапан откр",descWidth:100},
    {name:"L01",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Клапан закр/Питание",descWidth:100},
  ]
}
*/

i16 tempK=0;
u8 cond[5];
u8 i[2]={0, 0}; //ограничитель 0-открытия, 1 - закрытия

void STOP()
{
//srvError("Stop TP");
  setStatus(L00, 0);
  setStatus(L01, 0);
}

V-ID/s:TIME
{ 
//srvError("Chek TP");
  if( ([TEMP.0]%2) == 1 )
  {
    tempK=( [D00.1]*10 ); //Считаем температуру на датчике х10 целая часть
    tempK=tempK+([D00.0]*10)/250; //Считаем температуру на датчике х10 дробная часть
    //srvError("на датчике=%d", tempK);
    u16 tempZ=([TEMP.1]+CONDSTART)*10; //Считаем температуру уставки х10
    //srvError("То что считаем=%d", tempZ);
    
if( (tempK < (tempZ-G00)) && i[0] < 25 ) //Сравнение на открытие
    {
    	srvError("TP Low. Open");
    	i[0]=i[0]+1; i[1]=0;
		setStatus(L01, 1);
    	setStatus(L00, 1);
    	delayedCall(STOP, LITTLE);
    } 
    else  if( (tempK >  (tempZ+G00)) && i[1] <25 ) //Сравнение на закрытие
    {
		srvError("TP High. Close");
    	i[1]=i[1]+1; i[0]=0;
    	setStatus(L01, 1);
    	setStatus(L00, 0);
    	delayedCall(STOP, LITTLE);
    } 
    else //Вошли в зону комфорта
    {
      i[0]=0; i[1]=0;
      if ( ([L00.0]&1) == 1 ) setStatus(L00, 0);
      if ( ([L00.0]&1) == 1 ) setStatus(L01, 0);
    }
  }
}

V-ID/TEMP
{
  if(opt(0)%2==0)
  {
    setStatus(L00, 1);
    setStatus(L01, 1);
    delayedCall(STOP, POINT);
  }
  else
    cancelDelayedCall(STOP);
    STOP();
}