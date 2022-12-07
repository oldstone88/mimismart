/*
{
      desc:"Скрипт для пульта Dantex",
      name:"Dantex",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"13", "t-min":"17", "modes":"0x00","funs":"0x01","vane-hor":"0x00", "vane-ver":"0x41"},
      ],
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
            {name:"NAME",type:"string",required:"true",min:3,max:40,desc:"Имя кондиционера",defaultValue:"Dantex"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/
u8 prev_stateonoff = 0;
u8 tempprew=0;
const u8 mas_start [] = {0x19640400020091060102A9000016CB8803301637114DB2FD0200FF0102A9295B16C98803301639114DB2FD0200FF}; //Стартовый массив
u8 mas [sizeof(mas_start)]; //Массив для задачи температуры

void OnInit(){
      prev_stateonoff = 0;
}

//Задача температуры при старте
void START(){
      setStatus(IRT, &mas);
}

//Начать качание
void start_wing(){
      u8 wstart[]={0x1964040002008E060102A9000016AD8803301631114DB2D62907F80102A90D5B16978803301633114DB2D62907F8};
      setStatus(IRT, &wstart);
}

//Стоп качание
void stop_wing(){
      u8 wstop[]={0x1964040002008E060102A9000016AD8803301631114DB2D62907F80102A90D5B16978803301633114DB2D62907F8};
      setStatus(IRT, &wstop);
}

void cmdOn(){
      u8 on[]={0x19640400020091060102A9000016CB8803301637114DB2FD0200FF0102A9295B16C98803301639114DB2FD0200FF};
      setStatus(IRT, &on);
}
void cmdOff(){
      u8 off[]={0x1964040002008C060102A9000016A98803301631114DB2DE2107F80102A9095B16948803301632114DB2DE2107F8};
      setStatus(IRT, &off);
}
V-ID/COND{
      memcpy(&mas, &mas_start, sizeof(mas_start)); //Копируем начальный массив
      u8 temp = opt(1);
      u8 onoff= opt(0)&0x01;

if(temp == 1){mas[14]=0xCD;mas[25]=0x08;mas[26]=0xF7;mas[30]=0x2A;mas[33]=0xCD;mas[44]=0x08;mas[45]=0xF7;}
if(temp == 2){mas[14]=0xD3;mas[25]=0x0C;mas[26]=0xF3;mas[30]=0x2E;mas[33]=0xD0;mas[38]=0x3A;mas[44]=0x0C;mas[45]=0xF3;}
if(temp == 3){mas[14]=0xD2;mas[25]=0x04;mas[26]=0xFB;mas[30]=0x2C;mas[33]=0xD0;mas[38]=0x3A;mas[44]=0x04;mas[45]=0xFB;}
if(temp == 4){mas[14]=0xCF;mas[25]=0x06;mas[26]=0xF9;mas[30]=0x2A;mas[33]=0xCC;mas[44]=0x06;mas[45]=0xF9;}
if(temp == 5){mas[6]=0x8E;mas[14]=0xB5;mas[19]=0x32;mas[25]=0x0E;mas[26]=0xF1;mas[30]=0x13;mas[33]=0x9D;mas[38]=0x34;mas[44]=0x0E;mas[45]=0xF1;}
if(temp == 6){mas[6]=0x8E;mas[14]=0xB6;mas[19]=0x33;mas[25]=0x0A;mas[26]=0xF5;mas[30]=0x14;mas[33]=0xA1;mas[38]=0x35;mas[44]=0x0A;mas[45]=0xF5;}
if(temp == 7){mas[6]=0x8C;mas[14]=0xB7;mas[19]=0x33;mas[25]=0x02;mas[26]=0xFD;mas[30]=0x14;mas[33]=0xA0;mas[38]=0x35;mas[44]=0x02;mas[45]=0xFD;}
if(temp == 8){mas[6]=0x8E;mas[14]=0xB2;mas[19]=0x32;mas[25]=0x03;mas[26]=0xFC;mas[30]=0x11;mas[33]=0x9C;mas[38]=0x34;mas[44]=0x03;mas[45]=0xFC;}
if(temp == 9){mas[6]=0x8E;mas[14]=0xB5;mas[19]=0x32;mas[25]=0x0B;mas[26]=0xF4;mas[30]=0x14;mas[33]=0x9E;mas[38]=0x34;mas[44]=0x0B;mas[45]=0xF4;}
if(temp == 10){mas[6]=0x8E;mas[14]=0xB4;mas[19]=0x32;mas[25]=0x09;mas[26]=0xF6;mas[30]=0x12;mas[33]=0x9D;mas[38]=0x34;mas[44]=0x09;mas[45]=0xF6;}
if(temp == 11){mas[6]=0x8E;mas[14]=0xB6;mas[19]=0x33;mas[25]=0x01;mas[26]=0xFE;mas[30]=0x15;mas[33]=0xA2;mas[38]=0x35;mas[44]=0x01;mas[45]=0xFE;}
if(temp == 13){mas[6]=0x8E;mas[14]=0xB4;mas[19]=0x33;mas[25]=0x0D;mas[26]=0xF2;mas[30]=0x14;mas[33]=0x9F;mas[38]=0x34;mas[44]=0x0D;mas[45]=0xF2;}
if(temp == 12){mas[6]=0x8D;mas[14]=0xA9;mas[19]=0x31;mas[25]=0x05;mas[26]=0xFA;mas[30]=0x09;mas[33]=0x94;mas[38]=0x32;mas[44]=0x05;mas[45]=0xFA;}


      if(!prev_stateonoff && onoff){
            cancelDelayedCall(cmdOn);
            delayedCallMs(cmdOn, 50);
            delayedCall(START, 1);
            prev_stateonoff = 1;
            return 0;
      }
      if(!onoff){
            cancelDelayedCall(cmdOff);
            delayedCallMs(cmdOff, 50);
            prev_stateonoff = 0;
            return 0;
      }

//Качание
      if(temp==tempprew && opt(3)==0) {stop_wing();} else
      if(temp==tempprew && opt(3)==16) {start_wing();} else
      {setStatus(IRT, &mas); tempprew = temp;} //Смена температуры
}