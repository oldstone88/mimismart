/*
{
      desc:"Скрипт для пульта 932_Universal",
      name:"932_Universal",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "modes":"0x10","funs":"0x01","vane-hor":"0x00", "vane-ver":"0x41"},
      ],
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
            {name:"NAME",type:"string",required:"true",min:3,max:40,desc:"Имя кондиционера",defaultValue:"932_Universal"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/

//stop wing 1964040002008C060102A90000168288033016D7104540FFFFFF7E0102A9C65B168A880330160111BABF00000081
//start wing 1964040002008C060102A90000168288033016D6104540FFFFFF7E0102A9C25B167A880330160011BABF00000081

u8 prev_stateonoff = 0;
u8 tempprew=0;
const u8 mas_start []={0x1964040002008F060102A9000016ED88033016EB10854102FFFF3A0102A9C45B16E188033016F5107ABEFD0000C5};
u8 mas [sizeof(mas_start)]; //Массив для задачи температуры

void OnInit(){
      prev_stateonoff = 0;
}

//Начать качание
void start_wing(){
      u8 wstart[]={0x1964040002008C060102A90000168288033016D6104540FFFFFF7E0102A9C25B167A880330160011BABF00000081};
      setStatus(IRT, &wstart);
}

//Стоп качание
void stop_wing(){
      u8 wstop[]={0x1964040002008C060102A90000168288033016D7104540FFFFFF7E0102A9C65B168A880330160111BABF00000081};
      setStatus(IRT, &wstop);
}

//Установка температуры при старте
void START(){
      setStatus(IRT, &mas);
}

//Включение
void cmdOn(){
      u8 on[]={0x1964040002008F060102A9000016E388033016E5108505E2FFFF960102A9BD5B16D788033016FA107AFA1D000069};
      setStatus(IRT, &on);
}

//Выключение
void cmdOff(){
      u8 off[]={0x1964040002008E060102A9000016E388033016E5108504E2FFFF970102A9BC5B16D588033016FA107AFB1D000068};
      setStatus(IRT, &off);
}

V-ID/COND{

      memcpy(&mas, &mas_start, sizeof(mas_start)); //Копируем начальный массив
      u8 temp = opt(1);
      u8 onoff= opt(0)&0x01;

      if(temp == 1){mas[30]=0xC2;}
if(temp == 2){mas[14]=0xEC;mas[19]=0xE7;mas[23]=0x82;mas[26]=0xBA;mas[29]=0xA8;mas[30]=0x2C;mas[31]=0x5C;mas[33]=0x99;mas[38]=0xF9;mas[42]=0x7D;mas[45]=0x45;}
if(temp == 3){mas[14]=0xEE;mas[19]=0xE6;mas[23]=0x42;mas[26]=0xFA;mas[38]=0xFB;mas[42]=0xBD;mas[45]=0x05;}
if(temp == 4){mas[14]=0xF2;mas[19]=0xE6;mas[23]=0xC2;mas[26]=0x7A;mas[30]=0xC6;mas[38]=0xFB;mas[42]=0x3D;mas[45]=0x85;}
if(temp == 5){mas[14]=0xF1;mas[19]=0xEC;mas[23]=0x22;mas[26]=0x1A;mas[30]=0xC5;mas[33]=0xE4;mas[42]=0xDD;mas[45]=0xE5;}
if(temp == 6){mas[14]=0xF0;mas[19]=0xE7;mas[23]=0xA2;mas[26]=0x9A;mas[29]=0xA8;mas[30]=0x2F;mas[31]=0x5C;mas[33]=0x9B;mas[38]=0xF9;mas[42]=0x5D;mas[45]=0x65;}
if(temp == 7){mas[6]=0x90;mas[14]=0xF2;mas[19]=0xE6;mas[23]=0x62;mas[26]=0xDA;mas[30]=0xC6;mas[33]=0xE5;mas[38]=0xFC;mas[42]=0x9D;mas[45]=0x25;}
if(temp == 8){mas[14]=0xF2;mas[19]=0xE6;mas[23]=0xE2;mas[26]=0x5A;mas[30]=0xC6;mas[33]=0xE3;mas[38]=0xFC;mas[42]=0x1D;mas[45]=0xA5;}
if(temp == 9){mas[14]=0xF1;mas[19]=0xEC;mas[23]=0x12;mas[26]=0x2A;mas[30]=0xC5;mas[33]=0xE4;mas[42]=0xED;mas[45]=0xD5;}
if(temp == 10){mas[14]=0xF2;mas[19]=0xE8;mas[23]=0x92;mas[26]=0xAA;mas[29]=0xA8;mas[30]=0x2F;mas[31]=0x5C;mas[33]=0x9A;mas[38]=0xFA;mas[42]=0x6D;mas[45]=0x55;}
if(temp == 11){mas[6]=0x90;mas[14]=0xF3;mas[19]=0xE6;mas[23]=0x52;mas[26]=0xEA;mas[30]=0xC6;mas[33]=0xE3;mas[38]=0xFC;mas[42]=0xAD;mas[45]=0x15;}
if(temp == 12){mas[14]=0xEE;mas[19]=0xE6;mas[23]=0xD2;mas[26]=0x6A;mas[30]=0xC5;mas[33]=0xE2;mas[38]=0xFB;mas[42]=0x2D;mas[45]=0x95;}
if(temp == 13){mas[14]=0xF1;mas[19]=0xEC;mas[23]=0x32;mas[26]=0x0A;mas[30]=0xC5;mas[33]=0xE4;mas[42]=0xCD;mas[45]=0xF5;}
if(temp == 14){mas[14]=0xEF;mas[19]=0xE8;mas[23]=0xB2;mas[26]=0x8A;mas[29]=0xA8;mas[30]=0x2E;mas[31]=0x5C;mas[33]=0x9A;mas[38]=0xF9;mas[42]=0x4D;mas[45]=0x75;}

      //Включение + стартовая температура
      if(!prev_stateonoff && onoff){
            cancelDelayedCall(cmdOn);
            delayedCallMs(cmdOn, 50);
            delayedCall(START, 1);
            prev_stateonoff = 1;
            return 0;
      }
      //Выключение
      if(!onoff){
            cancelDelayedCall(cmdOff);
            {delayedCallMs(cmdOff, 50);}
            prev_stateonoff = 0;
            return 0;
      }
      //Качание
      if(temp==tempprew && opt(3)==0) {stop_wing();} else
      if(temp==tempprew && opt(3)==16) {start_wing();} else
      {setStatus(IRT, &mas); tempprew = temp;} //Смена температуры
}
