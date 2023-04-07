/*
{
  desc:"Смена ID диммера",
  tag:"item",
  selectArea:true,
  name:"Сменить ID",
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"IDOLD",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"IDNEW",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    ]
}
*/

void REBOOT(){
    u8 writeSetup[8]={IDOLD, 0x06, 0x00, 0x6B, 0x2C, 0x68, 0xCC, 0x16};
    setStatus(RS485, &writeSetup);
    srvError("Смена ID = %d на ID = %d завершена", IDOLD, IDNEW);
}

V-ID/V-ADDR
{
    srvError("Начинаем смену ID = %d на ID = %d", IDOLD, IDNEW);
    u8 writeSetup[8]={IDOLD, 0x06, 0x00, 0x68, 0x00, IDNEW, 0xCC, 0x16};
    setStatus(RS485, &writeSetup);
    delayedCall(REBOOT, 1);
}