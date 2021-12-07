/*
{
  desc:"Датчик WirenBoard",
  tag:"import-script",
  selectArea:true,
  
  addItems:[
    {tag:"item", id:"%TARGET%", name:"WirenBoard:", sub-id:"%SUBID01%", type:"virtual", sub-type:"long-text", length:"0"},
  ],

  vars:
  [
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
    {name:"ID", type:"number", defaultValue:190, min:0, max:250, required:true, desc:"ID датчика"},
    {name:"D00",type:"hidden",value:"%TARGET%:%SUBID01%"},
  ]
}
*/

u8 k=0; //переключатель диапозона считывания
u8 i[8]={ID, 0x04, 0x00, 0x03, 0x00, 0x03, 0xCC, 0x16};
u16 temp=0;
u16 hum=0;
u16 noize=0;
u16 co2=0;
u32 quality=0;
u16 light=0;
u8 data[250];

void result()
{
  for(u8 g=0; ++g; g<201) {data[g]="";} //Отчистка
  sprintf(data, "Температура = %d,%02d C \10", temp/100, temp%100);
  sprintf(data+strlen(data), "Влажность = %d,%02d % \10", hum/100, hum%100);
  sprintf(data+strlen(data), "Уровень шума = %d,%02d дБ \10", noize/100, hum%100);
  sprintf(data+strlen(data), "Концентрация СО2 = %d PPM \10", co2);
  sprintf(data+strlen(data), "Качество воздуха = %d ppb \10", quality);
  sprintf(data+strlen(data), "Освещенность = %d,%02d лк \10", light/100, light%100);
  setStatus(D00, &data);
}

void stat()
{
u8 res[50]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

V-ID/ms:500
{
  if( k==0 ) 
  {
    i[3]=0x03;
    i[5]=0x03;
    k=1;
    setStatus(RS485, &i);
  } else
  {
    i[3]=0x08;
    i[5]=0x04;
    k=0;
    setStatus(RS485, &i);
  }
}

V-ID/RS485
{
  //stat();
  if( k==1 )
  {
    temp=(opt(5)<<8)|opt(6);
    hum=(opt(7)<<8)|opt(8);
    noize=(opt(3)<<8)|opt(4);
  } else
  {
    co2=(opt(3)<<8)|opt(4);

    quality=(opt(9)<<8)|opt(10);

    light=(opt(5)<<8)|opt(6);
    light=light<<16;
    light=light|((opt(7)<<8)|opt(8));
    result();
  }
}