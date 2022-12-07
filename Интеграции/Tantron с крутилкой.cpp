/*
{
  desc:"Tantron",
  tag:"import-script",
  selectArea:true,
  
  vars:
  [
    {name:"ID",type:"number",min:"1",max:"255",required:true,defaultValue:"1",desc:"ID Тантрона(по таблице)"},
    {name:"COND1",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 1",descWidth:100},
    {name:"RS485",type:"devices-list",required:false,width:600,filter:["com-port"],desc:"RS",descWidth:100},
    {name:"B01",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp", "script", "light-scheme"],desc:"Свет",descWidth:100},
    {name:"B02",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp", "script", "light-scheme"],desc:"Свет",descWidth:100},
    {name:"B03",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp", "script", "light-scheme"],desc:"Свет",descWidth:100},
    {name:"B04",type:"devices-list",required:false,width:600,filter:["lamp", "dimer-lamp", "script", "light-scheme"],desc:"Свет",descWidth:100},
    {name:"B05",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы",descWidth:100},
    {name:"B06",type:"devices-list",required:false,width:600,filter:["jalousie"],desc:"Шторы",descWidth:100},

  ]
}
*/

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

//Расшифровка команд от RS:WW XX YY ZZ
//WW Номер устройства
//XX: В KNX - 01 из KNX - 02
//YY: Если перый 0, то кондиционер: Температура - 01, скорость - 02, ВКЛ-ВЫКЛ - 03
//YY: Если вначале 1, то кнопки: 10 - первая кнопка, 11 - вторая кнопка и тд
//ZZ: Состояние, Уставка
//Назначение кнопок прописать в скрипте в зависимости от нужд

u8 i[4]={0x00, 0x00, 0x00, 0x00};

void sendspeed()
{
  i[0]=ID; i[1]=0x01; i[2]=0x02; i[3]=[COND1.4];
  setStatus(RS485, &i);
}
void sendtemp()
{
  i[0]=ID; i[1]=0x01; i[2]=0x01; i[3]=[COND1.1];
  if(i[3]==10) i[3]=0x10;
  else if(i[3]==11) i[3]=0x11;
  else if(i[3]==12) i[3]=0x12;
  setStatus(RS485, &i);
  delayedCallMs(sendspeed, 150);
}
void sendonoff()
{
  i[0]=ID; i[1]=0x01; i[2]=0x03; i[3]=([COND1.0]%2);
  setStatus(RS485, &i);
  delayedCallMs(sendtemp, 150);
}

V-ID/COND1
{
  if(senderId()!=exciterId())
  {
    cancelDelayedCall(sendonoff);
    delayedCall(sendonoff, 1);
  }
}

void setCond(u8 parameter, u8 value)
{
  u8 k[5];
  if(value==0x10) value=10;
  else if(value==0x11) value=11;
  else if(value==0x12) value=12;
    getStatus(COND1, &k);
    if(parameter==0x01) k[1]=value;
    else if(parameter==0x02) k[4]=value;
    else if(parameter==0x03) k[0]=value;
    setStatus(COND1, &k);
}

void setLight(u8 parameter)
{
  //Свет
    #ifdef B01 if(number==0x11) setStatus(B01, 0xFF); #endif
    #ifdef B01 if(number==0x12) setStatus(B02, 0xFF); #endif
    #ifdef B01 if(number==0x13) setStatus(B03, 0xFF); #endif
    #ifdef B01 if(number==0x14) setStatus(B04, 0xFF); #endif
    //Шторы
    #ifdef B01 if(number==0x15) setStatus(B05, 1); #endif
    #ifdef B01 if(number==0x16) setStatus(B06, 0); #endif
}

V-ID/RS485
{
  stat();
  if(opt(0)==ID && opt(1)==0x02)
  {
    if(opt(2)<0x10) setCond(opt(2), opt(3)); //Кондиционер
    else setLight(opt(2)); //Кнопки
  }
}