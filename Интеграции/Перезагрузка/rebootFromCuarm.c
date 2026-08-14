/*
{
  desc:"Перезагрузка реле",
  name:"1е Реле",
  tag:"item",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"2е Реле", "sub-id":"%SUBID97%", type:"script"},
  ],
  vars:[
    {name:"EXE",type:"string",required:true,filter:"1234567890.",min:0,max:100,desc:"ID скрипта",width:200},
    {name:"CHANEL00",type:"string",required:true,filter:"1234567890.",min:1,max:2,desc:"Номер канала 1",width:200},
    {name:"CHANEL01",type:"string",required:true,filter:"1234567890.",min:1,max:2,desc:"Номер канала 2",width:200},
    {name:"REBOOT",type:"string",required:true,filter:"1234567890.",min:5,max:500,desc:"IP реле",width:500},
    {name:"SECOND",type:"hidden",value:"%TARGET%:%SUBID97%"},
  ]                       
}
*/

void OFF(){
	setStatus(V-ADDR, 0);
	setStatus(SECOND, 0);
}

V-ID/V-ADDR{
	if((opt(0)&1) == 1){
		cancelDelayedCall(OFF);
		setStatus(1000:EXE, "IP=REBOOT|RELAY=CHANEL00|");
		delayedCall(OFF, 1);
	}
}

V-ID/SECOND{
	if((opt(0)&1) == 1){
		cancelDelayedCall(OFF);
		setStatus(1000:EXE, "IP=REBOOT|RELAY=CHANEL01|");
		delayedCall(OFF, 1);
	}
}
