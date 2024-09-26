/*
{
      desc:"AUX пульт 190",
      name:"190",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "modes":"0x0A","funs":"0x01","vane-hor":"0x00", "vane-ver":"0x00"},
      ],
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
            {name:"NAME",type:"string",required:"true",min:3,max:40,desc:"Имя кондиционера",defaultValue:"190"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/

u8 mas[37];

void sendToCond(){
      setStatus(IRT, &mas);
}

V-ID/COND{
      cancelDelayedCall(sendToCond);
      if([COND.0]==1){
            u8 cold [] = {0x19640200020093060103FF00005897681685690368165E11C3500000A000200000200005F8};
            if([COND.1] == 1){cold[17]=0x81;cold[22]=0x57;cold[25]=0x58;cold[36]=0x00;}
            if([COND.1] == 2){cold[17]=0x80;cold[22]=0x57;cold[25]=0x60;cold[36]=0x08;}
            if([COND.1] == 3){cold[17]=0x83;cold[22]=0x59;cold[25]=0x68;cold[36]=0x10;}
            if([COND.1] == 4){cold[22]=0x5A;cold[25]=0x70;cold[36]=0x18;}
            if([COND.1] == 5){cold[17]=0x80;cold[22]=0x5A;cold[25]=0x78;cold[36]=0x20;}
            if([COND.1] == 6){cold[6]=0x92;cold[17]=0x80;cold[22]=0x57;cold[25]=0x80;cold[36]=0x28;}
            if([COND.1] == 7){cold[6]=0x98;cold[17]=0x81;cold[22]=0x59;cold[25]=0x88;cold[36]=0x30;}
            if([COND.1] == 8){cold[17]=0x84;cold[22]=0x5B;cold[25]=0x90;cold[36]=0x38;}
            if([COND.1] == 9){cold[6]=0x94;cold[22]=0x59;cold[25]=0x98;cold[36]=0x40;}
            if([COND.1] == 10){cold[17]=0x8A;cold[22]=0x5A;cold[25]=0xA0;cold[36]=0x48;}
            if([COND.1] == 11){cold[6]=0x95;cold[17]=0x8D;cold[22]=0x5B;cold[25]=0xA8;cold[36]=0x50;}
            if([COND.1] == 12){cold[6]=0x94;cold[17]=0x8D;cold[22]=0x5D;cold[25]=0xB0;cold[36]=0x58;}
            memcpy(&mas, &cold, 37);
      } else if([COND.0]==17){
            u8 hot [] = {0x19640200020091060103FF0000529768156E690368165711C3500000A00080000020000558};
            if([COND.1] == 1){hot[13]=0x58;hot[16]=0x16;hot[17]=0x70;hot[25]=0x58;hot[36]=0x60;}
            if([COND.1] == 2){hot[13]=0x58;hot[16]=0x16;hot[17]=0x72;hot[25]=0x60;hot[36]=0x68;}
            if([COND.1] == 3){hot[13]=0x58;hot[16]=0x16;hot[17]=0x72;hot[22]=0x59;hot[25]=0x68;hot[36]=0x70;}
            if([COND.1] == 4){hot[6]=0x92;hot[13]=0x58;hot[16]=0x16;hot[17]=0x71;hot[22]=0x5A;hot[25]=0x70;hot[36]=0x78;}
            if([COND.1] == 5){hot[6]=0x92;hot[13]=0x58;hot[16]=0x16;hot[17]=0x73;hot[25]=0x78;hot[36]=0x80;}
            if([COND.1] == 6){hot[13]=0x58;hot[16]=0x16;hot[17]=0x79;hot[22]=0x55;hot[25]=0x80;hot[36]=0x88;}
            if([COND.1] == 7){hot[6]=0x92;hot[13]=0x58;hot[16]=0x16;hot[17]=0x78;hot[25]=0x88;hot[36]=0x90;}
            if([COND.1] == 8){hot[13]=0x58;hot[16]=0x16;hot[17]=0x75;hot[22]=0x58;hot[25]=0x90;hot[36]=0x98;}
            if([COND.1] == 9){hot[6]=0x93;hot[13]=0x58;hot[16]=0x16;hot[17]=0x79;hot[22]=0x59;hot[25]=0x98;hot[36]=0xA0;}
            if([COND.1] == 10){hot[6]=0x92;hot[13]=0x58;hot[16]=0x16;hot[17]=0x79;hot[22]=0x59;hot[25]=0xA0;hot[36]=0xA8;}
            if([COND.1] == 11){hot[6]=0x92;hot[13]=0x58;hot[16]=0x16;hot[17]=0x79;hot[22]=0x5A;hot[25]=0xA8;hot[36]=0xB0;}
            if([COND.1] == 12){hot[6]=0x93;hot[13]=0x58;hot[16]=0x16;hot[17]=0x7D;hot[22]=0x5C;hot[25]=0xB0;hot[36]=0xB8;}
            memcpy(&mas, &hot, 37);
      }
      else if(([COND.0]%2)==0){
            u8 off [] = {0x19640200020090060103FF00005897681650690368165411C3B00000A00080000000000598};
            memcpy(&mas, &off, 37);
      }
      delayedCallMs(sendToCond, 750);
}