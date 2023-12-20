/*
{
  desc:"Carel",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Увлажнитель", sub-id:"%SUBID01%", type:"conditioner",funs:"0x00",t-min:"20",t-delta:"50", modes:"0x04", funs:"0x00",vane-hor:"0x00",vane-ver:"00", dim:"%"},
  ],
  vars:
  [
    {name:"K00",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
  ]
}
*/

u8 write=0;
u8 kond[5];

void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

void VklVikl(u8 zhachenie){
  u8 OnOff[8]={0x04, 0x05, 0x00, 0x08, zhachenie, 0x00, 0xCC, 0x16};
  setStatus(RS485, &OnOff);
}

void Humidity(){
  u8 i[8]={0x04, 0x06, 0x00, 0x0F, 0x00, 0x01, 0xCC, 0x16};
  i[1]=0x06;
  i[3]=0x0F;
  i[4]=([K00.1]+20)*10>>8;
  i[5]=([K00.1]+20)*10;
  setStatus(RS485, &i);
}

V-ID/K00
{
  if(write==0){
    if((opt(0)%2)==1){
    VklVikl(0xFF); // Делаем ВКЛ-ВЫКЛ
    cancelDelayedCall(Humidity);
    delayedCallMs(Humidity, 300); //Уставка
    }
    else if((opt(0)%2)==0){
      VklVikl(0x00);
    }
  } else write=0;
}

V-ID/s:10
{
  //srvError("Запрос");
  setStatus(RS485,{0x04, 0x03, 0x00, 0x0F, 0x00, 0x01, 0xCC, 0x16}); //Влажность
}

V-ID/RS485
{
  //stat();
  u16 temp=(opt(3)<<8)|opt(4);
  if( (([K00.1]+20)*10)!=temp && optl==7) {srvError("Рассинхрон Увлажнения"); write=1; getStatus(K00, &kond); kond[1]=((temp/10)-20); setStatus(K00, &kond);}
}
