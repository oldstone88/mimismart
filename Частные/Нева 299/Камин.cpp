/*
{
  desc:"Камин",
  tag:"import-script",
  selectArea:true,
  vars:[
  {name:"ON", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Включить"},
  {name:"OFF", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Вылючить"},
  {name:"PRESET1", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Пресет 1"},
  {name:"PRESET2", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Пресет 2"},
  {name:"PRESET3", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Пресет 3"},
  {name:"PRESET4", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Пресет 4"},
  {name:"SOUND0", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Звук 0"},
  {name:"SOUND1", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Звук 1"},
  {name:"SOUND2", type:"devices-list", required:true, filter:["script"], descWidth:370, desc:"Звук 2"},
  ]
}
*/

//Нужно создать элемент script в логике для каждого значения
// <item addr="571:244" name="Звук 1" type="script"/>
// Не забудьте положить sh скрипт в папку /mimismart/exe/

void SBROS()
{
  setStatus(ON, 0);
  setStatus(OFF, 0);
  setStatus(PRESET1, 0);
  setStatus(PRESET2, 0);
  setStatus(PRESET3, 0);
  setStatus(PRESET4, 0);
  setStatus(SOUND0, 0);
  setStatus(SOUND0, 0);
  setStatus(SOUND0, 0);
}

V-ID/ON
{
  if((opt(0)&1)==1) {setStatus(1000:49, 1); delayedCall(SBROS, 1);}
}

V-ID/OFF
{
  if((opt(0)&1)==1) {setStatus(1000:49, 2); delayedCall(SBROS, 1);}
}

V-ID/PRESET1
{
  if((opt(0)&1)==1) {setStatus(1000:49, 3); delayedCall(SBROS, 1);}
}

V-ID/PRESET2
{
  if((opt(0)&1)==1) {setStatus(1000:49, 4); delayedCall(SBROS, 1);}
}

V-ID/PRESET3
{
  if((opt(0)&1)==1) {setStatus(1000:49, 5); delayedCall(SBROS, 1);}
}

V-ID/PRESET4
{
  if((opt(0)&1)==1) {setStatus(1000:49, 6); delayedCall(SBROS, 1);}
}

V-ID/SOUND0
{
  if((opt(0)&1)==1) {setStatus(1000:49, 7); delayedCall(SBROS, 1);}
}

V-ID/SOUND1
{
  if((opt(0)&1)==1) {setStatus(1000:49, 8); delayedCall(SBROS, 1);}
}

V-ID/SOUND2
{
  if((opt(0)&1)==1) {setStatus(1000:49, 9); delayedCall(SBROS, 1);}
}