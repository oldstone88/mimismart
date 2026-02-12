/*
{
  desc:"Диммер MimiSmart",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {name:"DIMMER09",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 9",width:500},
    {name:"DIMMER10",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 10",width:500},
    {name:"DIMMER11",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 11",width:500},
    {name:"DIMMER12",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 12",width:500},
    {name:"DIMMER13",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 13",width:500},
    {name:"DIMMER14",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 14",width:500},
    {name:"DIMMER15",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 15",width:500},
    {name:"DIMMER16",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 16",width:500},
  ]
}
*/

u32 numberidset=0;
u8 data[41] = {ID1, 0x10, 0x10, 0x68, 0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0x16};
// u8 data[8] = {ID1, 0x06, 3000>>8, 3000, 0x00, 0x00, 0xCC, 0x16};

V-ID/ms:850{
    //Уставка диммеров
	data[8] = ([DIMMER01.0]&1) == 0 ? 0 : [DIMMER01.1];
    data[10] = ([DIMMER02.0]&1) == 0 ? 0 : [DIMMER02.1];
    data[12] = ([DIMMER03.0]&1) == 0 ? 0 : [DIMMER03.1];
    data[14] = ([DIMMER04.0]&1) == 0 ? 0 : [DIMMER04.1];
    data[16] = ([DIMMER05.0]&1) == 0 ? 0 : [DIMMER05.1];
    data[18] = ([DIMMER06.0]&1) == 0 ? 0 : [DIMMER06.1];
    data[20] = ([DIMMER07.0]&1) == 0 ? 0 : [DIMMER07.1];
    data[22] = ([DIMMER08.0]&1) == 0 ? 0 : [DIMMER08.1];
    data[24] = ([DIMMER09.0]&1) == 0 ? 0 : [DIMMER09.1];
    data[26] = ([DIMMER10.0]&1) == 0 ? 0 : [DIMMER10.1];
    data[28] = ([DIMMER11.0]&1) == 0 ? 0 : [DIMMER11.1];
    data[30] = ([DIMMER12.0]&1) == 0 ? 0 : [DIMMER12.1];
    data[32] = ([DIMMER13.0]&1) == 0 ? 0 : [DIMMER13.1];
    data[34] = ([DIMMER14.0]&1) == 0 ? 0 : [DIMMER14.1];
    data[36] = ([DIMMER15.0]&1) == 0 ? 0 : [DIMMER15.1];
    data[38] = ([DIMMER16.0]&1) == 0 ? 0 : [DIMMER16.1];
    setStatus(RS485, &data);
}

//Вывода в лог
void stat(){
	++numberidset;
	srvError("Было ответов = %d", numberidset);
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

V-ID/RS485{
    #ifdef DEBUG stat(); #endif
    
}
