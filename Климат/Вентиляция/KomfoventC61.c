/*
{
  desc:"Komfovent C6.1 br 19200 EP stop 1.0",
  name:"Komfovent C6.1",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"5", "t-delta":"40", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x00", "modes":"0x08"},
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Address",type:"number",min:"1",max:"127",required:true,defaultValue:"1",desc:"Адрес Modbus"},
        {name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя бассейн",defaultValue:"Бассейн"},
        {name:"VENT",type:"hidden",value:"%TARGET%:%SUBID01%"},
  ]
}
*/

u8 block=0;
u8 write[21]={Address, 0x10, 0x00, 0x6A, 0x00, 0x06, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};

V-ID/VENT{

}

V-ID/s:5{
    if(!block){
        u8 read[8]={Address, 0x03, 0x00, 0x6A, 0x00, 0x06, 0xCC, 0x16};
        setStatus(RS485, &read);
    }
}

// Функция вывода ответа
void stat(){
    u8 res[240]="";
    u8 *st = opt;
    u8 i = 0;
    sprintf(res,"%d ",optl);
    for(i = 0; i < optl; ++i){
        sprintf(res+strlen(res), " %x", st[i]);
    }
    sprintf(res+strlen(res), "\10");
    srvError(&res);
}

V-ID/RS485{
    #ifdef DEBUF stat(); #endif
    if(opt(1)==3 && optl==17){
        u8 state[5];
        getStatus(VENT, state);
        state[1]=(((opt(8)<<8)|opt(9))/10)-5;
    }
}