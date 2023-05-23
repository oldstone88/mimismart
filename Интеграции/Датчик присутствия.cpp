/*
{
  desc:"Датчик расстояния br 256000",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
    {tag:"item", id:"%TARGET%", name:"Расстояние", "sub-id":"%SUBID99%", type:"virtual", "sub-type":"long-text", "length":"0"},
  ],
  vars:[
   {type:"comment", style:"color:red", text:"АДРЕССА ТЕРМОСТАТОВ ДОЛЖНЫ СТРОГО НАЧИНАТЬСЯ С 1 И ИДТИ ПО ПОРЯДКУ!!!"},
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"SENSOR00",type:"hidden",value:"%TARGET%:%SUBID99%"},
 ]
}
*/

void stat()
{
  u8 res[100]="";
    u8 *st = opt;
    u8 i = 0;
    sprintf(res,"%d ",optl);
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), " %d", st[i]);
    }
    sprintf(res+strlen(res), "\10");
    srvError(&res);
}

V-ID/RS485
{
  //stat();
  u8 text[70]={"Объект: "};
  if(opt(8)==0) sprintf(text+strlen(text), "НЕТ\10");
  else if(opt(8)==1) sprintf(text+strlen(text), "СПОРТ\10");
  if(opt(8)==2) sprintf(text+strlen(text), "ЕСТЬ\10");
  if(opt(8)==3) sprintf(text+strlen(text), "ДВИЖЕТСЯ\10");
  sprintf(text+strlen(text), "Movement: %d\10Stationary: %d\10Detection: %d", opt(9), opt(12), opt(15));
  setStatus(SENSOR00, &text);
}
