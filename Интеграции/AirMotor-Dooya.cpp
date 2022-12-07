/*
{
  desc:"Мотор Airmotor",
  tag:"item",
  name:"Уставка адреса",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Шторы", "sub-id":"%SUBID01%", type:"virtual", sub-type:"dimer-blinds", length:"0"},
  ],
  vars:
  [
    {name:"SHADE",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
    {name:"ID", type:"number", defaultValue:1, min:0, max:50, required:true, desc:"Какой адрес присвоить"},
  ]
}
*/

u8 k0[8]={0x55, 0x01, 0x01, 0x03, 0x04, 0x00, 0xCC, 0x16}; // Команда в процентах
u8 k1[7]={0x55, 0x01, 0x01, 0x03, 0x03, 0xCC, 0x16}; //Стоп
u8 state[2] = {0,0};

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

//Отсылка состояния
void OTPR()
{
  setStatus(RS485, &k0);
}

//Уставка адреса
V-ID/V-ADDR
{
  u8 i[10]={0x55, 0x00, 0x00, 0x02, 0x00, 0x02, ID, ID, 0xCC, 0x16};
  setStatus(RS485, &i);
}

//Управление виртуальной шторой
V-ID/SHADE
{
    if (opt(0)==0xff)
    {
        state[0] = state[0] ? 0:1;
        setStatus(SHADE,state);
    }
    else if (opt(0)==0xfe)
    {
        state[1] = opt(1);
        setStatus(SHADE,state);
    }
    else
    {
      state[0]=opt(0);
      state[1]=opt(1);
      cancelDelayedCall(OTPR);
      k0[5]=(state[1]);
      srvError("Процент=%d", state[1]);
      delayedCall(OTPR, 1);
    }
}

V-ID/RS485
{
  stat();
}