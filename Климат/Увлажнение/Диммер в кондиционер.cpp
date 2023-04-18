/*
{
  desc:"Диммер в кондиционер",
  tag:"import-script",

  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME1", "sub-id":"%SUBID01%", "type":"conditioner", "t-min":"30", "t-delta":"50", "vane-ver":"0x00", "vane-hor":"0x00", "funs":"0x00", "modes":"0x00"},
  ],
  vars:[
        {name:"NAME1",type:"string",required:true,min:3,max:40,desc:"Увлажнитель",defaultValue:"Увлажнитель"},
        {name:"HUMIDITIFIRE",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"D00",type:"devices-list",required:false,filter:["dimer-lamp"],desc:"Диммер 0"},
  ]
}
*/

u8 write=0;

void setHum(){
  u8 cond[5]={0, 0, 0, 0, 0};
  getStatus(HUMIDITIFIRE, &cond);
}

V-ID/HUMIDITIFIRE{
  write=1;
  u8 cond[5]={0, 0, 0, 0, 0};
  getStatus(HUMIDITIFIRE, &cond);
  if(opt(0)==0){
    cond[0]=1; setStatus(HUMIDITIFIRE, &cond);
  }
  else if(opt(0)%2!=0){
    setStatus(D00, {1, cond[1]*5, 0});
  }
}

V-ID/s:5{
  if( !write && [D00.1]!=([HUMIDITIFIRE.1]/5) ){
    u8 cond[5]={0, 0, 0, 0, 0};
    getStatus(HUMIDITIFIRE, &cond);
    cond[1]=[D00.1]/5;
    setStatus(HUMIDITIFIRE, &cond);
  }
}