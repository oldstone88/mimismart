/*
{
  desc:"Расчет CRC16 для modbus",
  tag:"item",
  selectArea:true,
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
  ]
}
*/

u8 onMass = 0;
u8 test1[8]={0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00};
u8 test2[13]={0x01, 0x10, 0x00, 0x02, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void CRC16modbus(u8 size){
  u16 reg=0XFFFF;
  u16 pol=0xA001;
  // size-2 потому что 2 байта как раз контрольная сумма
  for(u8 j=0; j<(size-2); ++j){
    if(onMass==1) reg=reg^test1[j];
    else if (onMass==2) reg=reg^test2[j];
    for(u8 g=0; g<8; ++g){
      if((reg&0x01)==1){
        reg=reg>>1;
        reg=reg^pol;
      } else{
        reg=reg>>1;
      }
    }
  }
    return reg;
}

V-ID/V-ADDR{
  if((opt(0)&1)==1){
    onMass = 1; // Метка для какого массива считаем CRC
    u16 summ = CRC16modbus(sizeof(test1));
    // Записываем значения в последние байты
    test1[6]=summ;
    test1[7]=summ>>8;
    srvError("%x %x", test1[6], test1[7] );
  } else{
    onMass = 2; // Метка для какого массива считаем CRC
    u16 summ = CRC16modbus(sizeof(test2));
    // Записываем значения в последние байты
    test2[11]=summ;
    test2[12]=summ>>8;
    srvError("%x %x", test2[11], test2[12] );
  }
}