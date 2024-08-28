/*
{
      desc:"Скрипт для пульта Cond_031",
      name:"Cond_031",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"14", "t-min":"16", "modes":"0x10","funs":"0x01","vane-hor":"0x00", "vane-ver":"0x00"},
      ],
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
            {name:"NAME",type:"string",required:"true",min:3,max:40,desc:"Имя кондиционера",defaultValue:"Cond_031"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/

u8 command[47];

void cmdSet(){
      setStatus(IRT, &command);
}

void cmdOff(){
      u8 off[]={0x19640500020084060103FF000058986718916A032318B11201002050020002554201011A0000032018B112012000D0};
      setStatus(IRT, &off);
}
V-ID/COND{
      // Отменяем предыдущую команду
      cancelDelayedCall(cmdSet);
      cancelDelayedCall(cmdOff);
      if(([COND.0]%2)==0){
            delayedCall(cmdOff, 1);
      } else {
            u8 mas [] = {0x19640500020088060103FF000058986718996A032318A81209002050020002764201011A0000032018BC1201200050};
            if([COND.1] == 1){mas[6]=0x8A;mas[17]=0xBA;mas[22]=0xA2;mas[25]=0x01;mas[31]=0x78;mas[41]=0xBF;mas[46]=0x60;}
            if([COND.1] == 2){mas[6]=0x86;mas[17]=0xC4;mas[22]=0xA3;mas[25]=0x02;mas[31]=0x84;mas[41]=0xB3;mas[46]=0x70;}
            if([COND.1] == 3){mas[6]=0x89;mas[17]=0xCF;mas[22]=0x9A;mas[25]=0x03;mas[31]=0xAD;mas[41]=0xCA;mas[46]=0x80;}
            if([COND.1] == 4){mas[17]=0xBD;mas[22]=0xA3;mas[25]=0x04;mas[31]=0x8C;mas[41]=0xC0;mas[46]=0x90;}
            if([COND.1] == 5){mas[17]=0xC3;mas[22]=0x9A;mas[25]=0x05;mas[31]=0xAF;mas[41]=0xBE;mas[46]=0xA0;}
            if([COND.1] == 6){mas[6]=0x86;mas[17]=0xC7;mas[22]=0x9A;mas[25]=0x06;mas[31]=0xAF;mas[41]=0xB3;mas[46]=0xB0;}
            if([COND.1] == 7){mas[6]=0x87;mas[17]=0xC3;mas[22]=0x93;mas[25]=0x07;mas[31]=0x86;mas[41]=0xBD;mas[46]=0xC0;}
            if([COND.1] == 8){mas[6]=0x84;mas[17]=0xCD;mas[22]=0xA3;mas[25]=0x08;mas[31]=0x90;mas[41]=0xB4;mas[46]=0xD0;}
            if([COND.1] == 9){mas[6]=0x86;mas[17]=0xCD;mas[22]=0x9A;mas[25]=0x09;mas[31]=0xB1;mas[41]=0xB3;mas[46]=0xE0;}
            if([COND.1] == 10){mas[6]=0x8A;mas[17]=0xC7;mas[22]=0x9A;mas[25]=0x0A;mas[31]=0xA5;mas[41]=0xA9;mas[46]=0xF0;}
            if([COND.1] == 11){mas[6]=0x8E;mas[17]=0xC6;mas[22]=0x93;mas[25]=0x0B;mas[31]=0x89;mas[41]=0xD6;mas[46]=0x00;}
            if([COND.1] == 12){mas[6]=0x8E;mas[17]=0xCC;mas[22]=0x9B;mas[25]=0x0C;mas[31]=0xBC;mas[41]=0xCB;mas[46]=0x10;}
            if([COND.1] == 13){mas[6]=0x85;mas[17]=0xC1;mas[22]=0x93;mas[25]=0x0D;mas[31]=0x81;mas[41]=0xC8;mas[46]=0x20;}
            if([COND.1] == 14){mas[6]=0x8A;mas[17]=0xC8;mas[22]=0x93;mas[25]=0x0E;mas[31]=0x8B;mas[41]=0xBE;mas[46]=0x30;}
            memcpy(&command, &mas, 47); // Копируем локальный массив в общий
            delayedCall(cmdSet, 1); // Делаем задержку на отсылку команд, чтоб если щелкают много не забивался передатчик
      }
}