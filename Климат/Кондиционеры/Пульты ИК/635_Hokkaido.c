/*
{
      desc:"Скрипт для пульта 635",
      name:"Hokkaido",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "modes":"0x0E","funs":"0x01","vane-hor":"0x00", "vane-ver":"0x00"},
      ],
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
            {name:"NAME",type:"string",required:"true",min:3,max:40,desc:"Имя кондиционера",defaultValue:"33"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/

u8 masCold [] = {0x19640400020092060102A9000014908B033014F9104DB2FD0208F70102AA036214338B033014FA104DB2FD0208F7};
u8 strartCold[] = {0x19640400020092060102A9000014908B033014F9104DB2FD0208F70102AA036214338B033014FA104DB2FD0208F7};
u8 humidity[] = {0x19640400020094060102AB000014B88B033014FD104DB2F80728D70102AA196214548B033014FE104DB2F80728D7};
u8 masVent[] = {0x19640400020094060102A8000014BC8B033014FE104DB2FC032FD00102AA1C6214578B033014FF104DB2FC032FD0};
u8 off[] = {0x19640400020092060102AB000014918B033014F9104DB2DE2107F80102A8046214338B033014FA104DB2DE2107F8};

void cmdOff(){
      setStatus(IRT, &off);
}

void cmdOn(){
      setStatus(IRT, &mas);
}

V-ID/COND{
      cancelDelayed(cmdOff);
      cancelDelayed(cmdOn);
      // Вентиляция
      if(opt(0) == 1){
            memcpy(&mas, &masVent, 45);
      }
      // Холод
      if(opt(0) == 17){
            memcpy(&mas, &strartCold, 45); // обнуляем массив до стартовых 18
            if(opt(1) == 1) {mas[6]=0x93;mas[10]=0xAB;mas[14]=0x92;mas[25]=0x0C;mas[26]=0xF3;mas[30]=0x05;mas[33]=0x38;mas[38]=0xFB;mas[44]=0x0C;mas[45]=0xF3;}
            if(opt(1) == 2) {mas[10]=0xAB;mas[14]=0x92;mas[25]=0x04;mas[26]=0xFB;mas[30]=0x05;mas[33]=0x37;mas[38]=0xFB;mas[44]=0x04;mas[45]=0xFB;}
            if(opt(1) == 3) {mas[10]=0xAB;mas[14]=0x93;mas[25]=0x06;mas[26]=0xF9;mas[30]=0x05;mas[33]=0x37;mas[38]=0xFB;mas[44]=0x06;mas[45]=0xF9;}
            if(opt(1) == 4) {mas[6]=0x93;mas[10]=0xAB;mas[14]=0x94;mas[19]=0xFA;mas[25]=0x0E;mas[26]=0xF1;mas[30]=0x06;mas[33]=0x39;mas[38]=0xFB;mas[44]=0x0E;mas[45]=0xF1;}
            if(opt(1) == 5) {mas[10]=0xAB;mas[14]=0x93;mas[25]=0x0A;mas[26]=0xF5;mas[30]=0x06;mas[33]=0x39;mas[38]=0xFB;mas[44]=0x0A;mas[45]=0xF5;}
            if(opt(1) == 6) {mas[6]=0x93;mas[10]=0xAB;mas[14]=0x96;mas[19]=0xFA;mas[25]=0x02;mas[26]=0xFD;mas[30]=0x07;mas[33]=0x3A;mas[38]=0xFB;mas[44]=0x02;mas[45]=0xFD;}
            if(opt(1) == 7) {mas[6]=0x93;mas[10]=0xAB;mas[14]=0x93;mas[19]=0xFA;mas[25]=0x03;mas[26]=0xFC;mas[30]=0x07;mas[33]=0x39;mas[38]=0xFB;mas[44]=0x03;mas[45]=0xFC;}
            if(opt(1) == 8) {mas[6]=0x93;mas[14]=0x96;mas[19]=0xFA;mas[25]=0x0B;mas[26]=0xF4;mas[29]=0xA9;mas[30]=0x07;mas[33]=0x3A;mas[38]=0xFB;mas[44]=0x0B;mas[45]=0xF4;}
            if(opt(1) == 9) {mas[6]=0x93;mas[10]=0xAB;mas[14]=0x93;mas[19]=0xFA;mas[25]=0x09;mas[26]=0xF6;mas[30]=0x08;mas[33]=0x3B;mas[38]=0xFB;mas[44]=0x09;mas[45]=0xF6;}
            if(opt(1) == 10) {mas[10]=0xAB;mas[14]=0x94;mas[19]=0xFA;mas[25]=0x01;mas[26]=0xFE;mas[30]=0x07;mas[33]=0x3A;mas[38]=0xFB;mas[44]=0x01;mas[45]=0xFE;}
            if(opt(1) == 11) {mas[6]=0x93;mas[14]=0x97;mas[19]=0xFA;mas[25]=0x05;mas[26]=0xFA;mas[30]=0x08;mas[33]=0x3A;mas[38]=0xFB;mas[44]=0x05;mas[45]=0xFA;}
            if(opt(1) == 12) {mas[6]=0xA6;mas[10]=0xAA;mas[13]=0x13;mas[14]=0x94;mas[19]=0xFA;mas[25]=0x0D;mas[26]=0xF2;mas[29]=0xA7;mas[30]=0x08;mas[33]=0x3A;mas[38]=0xFB;mas[44]=0x0D;mas[45]=0xF2;}
      }
      // Осушение
      else if(opt(0) == 33){
            memcpy(&mas, &humidity, 45);
      }
      // Нагрев
      else if(opt(0)%2 == 49){
            memcpy(&mas, &strartCold, 45);
            if(temp == 0){mas[6]=0x93;mas[10]=0xA8;mas[13]=0x13;mas[14]=0x9F;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x38;mas[26]=0xC7;mas[30]=0x0D;mas[33]=0x43;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x38;mas[45]=0xC7;}
            if(temp == 1){mas[10]=0xAB;mas[14]=0xA1;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x3C;mas[26]=0xC3;mas[30]=0x0C;mas[33]=0x42;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x3C;mas[45]=0xC3;}
            if(temp == 2){mas[10]=0xAB;mas[14]=0xA0;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x34;mas[26]=0xCB;mas[30]=0x0E;mas[33]=0x40;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x34;mas[45]=0xCB;}
            if(temp == 3){mas[10]=0xAB;mas[14]=0xA3;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x36;mas[26]=0xC9;mas[30]=0x0E;mas[33]=0x44;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x36;mas[45]=0xC9;}
            if(temp == 4){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA2;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x3E;mas[26]=0xC1;mas[30]=0x0D;mas[33]=0x44;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x3E;mas[45]=0xC1;}
            if(temp == 5){mas[6]=0x93;mas[10]=0xAA;mas[14]=0xA0;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x3A;mas[26]=0xC5;mas[30]=0x0D;mas[33]=0x43;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x3A;mas[45]=0xC5;}
            if(temp == 6){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA2;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x32;mas[26]=0xCD;mas[30]=0x0E;mas[33]=0x46;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x32;mas[45]=0xCD;}
            if(temp == 7){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA5;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x33;mas[26]=0xCC;mas[30]=0x0F;mas[33]=0x46;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x33;mas[45]=0xCC;}
            if(temp == 8){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA5;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x3B;mas[26]=0xC4;mas[30]=0x10;mas[33]=0x47;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x3B;mas[45]=0xC4;}
            if(temp == 9){mas[6]=0x93;mas[10]=0xAA;mas[14]=0xA3;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x39;mas[26]=0xC6;mas[30]=0x11;mas[33]=0x4A;mas[38]=0xFD;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x39;mas[45]=0xC6;}
            if(temp == 10){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA1;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x31;mas[26]=0xCE;mas[30]=0x0F;mas[33]=0x47;mas[38]=0xFD;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x31;mas[45]=0xCE;}
            if(temp == 11){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA4;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x35;mas[26]=0xCA;mas[30]=0x10;mas[33]=0x45;mas[38]=0xFC;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x35;mas[45]=0xCA;}
            if(temp == 12){mas[6]=0x93;mas[10]=0xAB;mas[14]=0xA3;mas[19]=0xFB;mas[23]=0xF9;mas[24]=0x06;mas[25]=0x3D;mas[26]=0xC2;mas[30]=0x10;mas[33]=0x47;mas[38]=0xFD;mas[42]=0xF9;mas[43]=0x06;mas[44]=0x3D;mas[45]=0xC2;}
      }
      // Отправка команды
      if(opt(0)%2 == 0) delayedCall(cmdOff, 1); else delayedCall(cmdOn, 1);
}