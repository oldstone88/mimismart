/*
{
  desc:"Счетчик импульсов",
  tag:"import-script",
  name:"Очистить показания",
  target:"COUNTER",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"%NAME%", sub-id:"%SUBID%", type:"virtual", length:"0", sub-type:"long-text"}
  ],
  vars:[
    {name:"NAME",type:"string",required:true,min:3,max:40,desc:"Имя счетчика",defaultValue:"Счетчик Воды",descWidth:350},
    {name:"COUNTER",type:"devices-list",required:true,filter:["door-sensor"],desc:"геркон",descWidth:350},
    {name:"STVALUE1",type:"number",required:true,defaultValue:0,min:0,max:10000,filter:"0123456789",desc:"Начальное значение T1",descWidth:350},
    {name:"STVALUE2",type:"number",required:true,defaultValue:0,min:0,max:10000,filter:"0123456789",desc:"Начальное значение T2",descWidth:350},
    {name:"STVALUE3",type:"number",required:true,defaultValue:0,min:0,max:10000,filter:"0123456789",desc:"Начальное значение T3",descWidth:350},
    {name:"PERIOD",type:"number",required:true,defaultValue:1,min:1,max:1440,desc:"Период сохранения данных в минутах",descWidth:350},
    {name:"VIRT",type:"hidden",value:"%TARGET%:%SUBID%"}
  ]
}
*/

u8 data[128];

u32 I1=0;
u32 I2=0;
u32 I3=0;

u16 schet1=0;
u16 schet2=0;
u16 schet3=0;

void update_virt()
{
sprintf(data, " Показания Т1: %06d.%03d\10 Показания Т2: %06d.%03d\10 Показания Т3: %06d.%03d", I1, schet1, I2, schet2, I3, schet3);
setStatus(VIRT, data);
}

void onInit()
{
    // Load variables
    u8 resultOfRead=eeEmulRead(1, &I1);
    if(I1==0 || resultOfRead==0) I1=STVALUE1;
    resultOfRead=eeEmulRead(9, &I2);
    if(I2==0 || resultOfRead==0) I2=STVALUE2;
    resultOfRead=eeEmulRead(17, &I3);
    if(I3==0 || resultOfRead==0) I3=STVALUE3;
    update_virt();
}

V-ID/COUNTER
{
    u8 res1 = timeInRange(7:00-10:00);
    u8 res2 = timeInRange(17:00-21:00);
    if( ((opt(0)&1)==1) && (res1!=0 || res2!=0)) {++schet1; if(schet1>=1000) {++I1; schet1=0;  eeEmulWrite(1, I1);} update_virt();}
    res1 = timeInRange(23:00-7:00);
    if( ((opt(0)&1)==1) && (res1!=0)) {++schet2; if(schet2>=1000) {++I2; schet2=0; eeEmulWrite(9, I2);} update_virt();}
    res1 = timeInRange(10:00-17:00);
    res2 = timeInRange(21:00-23:00);
    if( ((opt(0)&1)==1) && (res1!=0 || res2!=0)) {++schet3; if(schet3>=1000) {++I3; schet3=0; eeEmulWrite(17, I2);} update_virt();}
}

