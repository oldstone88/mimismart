/*
{
desc:"Протечка",
tag:"item",
selectArea:true,

vars:[
{name:"TG",type:"string",required:true,desc:"Укажите id получателя в телеграмм-боте",width:880},
{type:"comment",text:"Время уборки:",width:200, style:"color:red;"},
{name:"TIME", type:"number", required:true, defaultValue:7200, min:1800, max:21600, desc:"Задержка, сек", descWidth:370},
{type:"comment",text:"Кран к датчикам:",width:200, style:"color:red;"},
{name:"V00",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{name:"V01",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{name:"V02",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{name:"V03",type:"devices-list",required:false,width:800,filter:["valve"],desc:"Кран",descWidth:100},
{type:"comment",text:"Датчики протечки:",width:200, style:"color:red;"},
{name:"H00",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T00",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H01",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T01",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H02",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T02",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H03",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T03",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H04",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T04",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H05",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T05",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H06",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T06",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H07",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T07",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H08",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T08",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H09",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T09",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H10",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T10",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H11",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T11",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H12",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T12",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H13",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T13",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H14",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T14",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H15",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T15",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H16",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T16",type:"string",required:false,desc:"Текст оповещения",width:300},
{name:"H17",type:"devices-list",required:false,width:800,filter:["door-sensor"],desc:"Датчик-геркон",descWidth:100},
{name:"T17",type:"string",required:false,desc:"Текст оповещения",width:300},
]
}
*/

u8 i[18];
u32 timer=0;
u8 antispam=0;

V-ID/s:1
{
	u8 alarm=0;
	//Уборка
    if(([V-ADDR.0]&1)==1){
    	++timer; if(timer>=TIME) setStatus(V-ADDR, 0);}
    else if(timer!=0) {timer=0;		
    }
    #ifdef H00 if([H00.0]==0 && ([V-ADDR.0]&1)==0) { if(i[0]<=12) i[0]=i[0]+1; else {if(antispam==0) setStatus(2047:32, {8, "T00"}); #ifdef TG setStatus(1000:90, "TG||T00||||"); #endif  alarm=1;}    } else i[0]=0; #endif
    #ifdef H01 if([H01.0]==0 && ([V-ADDR.0]&1)==0) { if(i[1]<=12) i[1]=i[1]+1; else {if(antispam==0) setStatus(2047:32, {8, "T01"}); #ifdef TG setStatus(1000:90, "TG||T01||||"); #endif  alarm=1;}    } else i[1]=0; #endif
    #ifdef H02 if([H02.0]==0 && ([V-ADDR.0]&1)==0) { if(i[2]<=12) i[2]=i[2]+1; else {if(antispam==0) setStatus(2047:32, {8, "T02"}); #ifdef TG setStatus(1000:90, "TG||T02||||"); #endif  alarm=1;}    } else i[2]=0; #endif
    #ifdef H03 if([H03.0]==0 && ([V-ADDR.0]&1)==0) { if(i[3]<=12) i[3]=i[3]+1; else {if(antispam==0) setStatus(2047:32, {8, "T03"}); #ifdef TG setStatus(1000:90, "TG||T03||||"); #endif  alarm=1;}    } else i[3]=0; #endif
    #ifdef H04 if([H04.0]==0 && ([V-ADDR.0]&1)==0) { if(i[4]<=12) i[4]=i[4]+1; else {if(antispam==0) setStatus(2047:32, {8, "T04"}); #ifdef TG setStatus(1000:90, "TG||T04||||"); #endif  alarm=1;}    } else i[4]=0; #endif
    #ifdef H05 if([H05.0]==0 && ([V-ADDR.0]&1)==0) { if(i[5]<=12) i[5]=i[5]+1; else {if(antispam==0) setStatus(2047:32, {8, "T05"}); #ifdef TG setStatus(1000:90, "TG||T05||||"); #endif  alarm=1;}    } else i[5]=0; #endif
    #ifdef H06 if([H06.0]==0 && ([V-ADDR.0]&1)==0) { if(i[6]<=12) i[6]=i[6]+1; else {if(antispam==0) setStatus(2047:32, {8, "T06"}); #ifdef TG setStatus(1000:90, "TG||T06||||"); #endif  alarm=1;}    } else i[6]=0; #endif
    #ifdef H07 if([H07.0]==0 && ([V-ADDR.0]&1)==0) { if(i[7]<=12) i[7]=i[7]+1; else {if(antispam==0) setStatus(2047:32, {8, "T07"}); #ifdef TG setStatus(1000:90, "TG||T07||||"); #endif  alarm=1;}    } else i[7]=0; #endif
    #ifdef H08 if([H08.0]==0 && ([V-ADDR.0]&1)==0) { if(i[8]<=12) i[8]=i[8]+1; else {if(antispam==0) setStatus(2047:32, {8, "T08"}); #ifdef TG setStatus(1000:90, "TG||T08||||"); #endif  alarm=1;}    } else i[8]=0; #endif
    #ifdef H09 if([H09.0]==0 && ([V-ADDR.0]&1)==0) { if(i[9]<=12) i[9]=i[9]+1; else {if(antispam==0) setStatus(2047:32, {8, "T09"}); #ifdef TG setStatus(1000:90, "TG||T09||||"); #endif  alarm=1;}    } else i[9]=0; #endif
    #ifdef H10 if([H10.0]==0 && ([V-ADDR.0]&1)==0) { if(i[10]<=12) i[10]=i[10]+1; else {if(antispam==0) setStatus(2047:32, {8, "T10"}); #ifdef TG setStatus(1000:90, "TG||T10||||"); #endif alarm=1;} } else i[10]=0; #endif
    #ifdef H11 if([H11.0]==0 && ([V-ADDR.0]&1)==0) { if(i[11]<=12) i[11]=i[11]+1; else {if(antispam==0) setStatus(2047:32, {8, "T11"}); #ifdef TG setStatus(1000:90, "TG||T11||||"); #endif alarm=1;} } else i[11]=0; #endif
    #ifdef H12 if([H12.0]==0 && ([V-ADDR.0]&1)==0) { if(i[12]<=12) i[12]=i[12]+1; else {if(antispam==0) setStatus(2047:32, {8, "T12"}); #ifdef TG setStatus(1000:90, "TG||T12||||"); #endif alarm=1;} } else i[12]=0; #endif
    #ifdef H13 if([H13.0]==0 && ([V-ADDR.0]&1)==0) { if(i[13]<=12) i[13]=i[13]+1; else {if(antispam==0) setStatus(2047:32, {8, "T13"}); #ifdef TG setStatus(1000:90, "TG||T13||||"); #endif alarm=1;} } else i[13]=0; #endif
    #ifdef H14 if([H14.0]==0 && ([V-ADDR.0]&1)==0) { if(i[14]<=12) i[14]=i[14]+1; else {if(antispam==0) setStatus(2047:32, {8, "T14"}); #ifdef TG setStatus(1000:90, "TG||T14||||"); #endif alarm=1;} } else i[14]=0; #endif
    #ifdef H15 if([H15.0]==0 && ([V-ADDR.0]&1)==0) { if(i[15]<=12) i[15]=i[15]+1; else {if(antispam==0) setStatus(2047:32, {8, "T15"}); #ifdef TG setStatus(1000:90, "TG||T15||||"); #endif alarm=1;} } else i[15]=0; #endif
    #ifdef H16 if([H16.0]==0 && ([V-ADDR.0]&1)==0) { if(i[16]<=12) i[14]=i[16]+1; else {if(antispam==0) setStatus(2047:32, {8, "T16"}); #ifdef TG setStatus(1000:90, "TG||T16||||"); #endif alarm=1;} } else i[16]=0; #endif
    #ifdef H17 if([H17.0]==0 && ([V-ADDR.0]&1)==0) { if(i[17]<=12) i[15]=i[17]+1; else {if(antispam==0) setStatus(2047:32, {8, "T17"}); #ifdef TG setStatus(1000:90, "TG||T17||||"); #endif alarm=1;} } else i[17]=0; #endif
    //Где то протечка!!!
    if(alarm!=0){
    	++antispam;
    	if(antispam>60) antispam=0;
    	setStatus(V00, 1); #ifdef V01 setStatus(V01, 1); #endif #ifdef V02 setStatus(V02, 1); #endif #ifdef V03 setStatus(V03, 1); #endif
    } else{
    	if(antispam!=0) antispam=0;
    }
}
