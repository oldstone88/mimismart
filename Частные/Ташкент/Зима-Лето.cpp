/*
{
  desc:"Зима-Лето",
  tag:"item",
  selectArea:true,
  name:"Лето",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Зима", sub-id:"%SUBID01%", type:"script"},
  ],
  vars:
  [
    {name:"ZIMA",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"COND00",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 1",descWidth:100},
    {name:"COND01",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 2",descWidth:100},
    {name:"COND02",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 3",descWidth:100},
    {name:"COND03",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 4",descWidth:100},
    {name:"COND04",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 5",descWidth:100},
    {name:"COND05",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 6",descWidth:100},
    {name:"COND06",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 7",descWidth:100},
    {name:"COND07",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 8",descWidth:100},
    {name:"COND08",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 9",descWidth:100},
    {name:"COND09",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 10",descWidth:100},
    {name:"COND10",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 11",descWidth:100},
    {name:"COND11",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 12",descWidth:100},
    {name:"COND12",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 13",descWidth:100},
    {name:"COND13",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 14",descWidth:100},
    {name:"COND14",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 15",descWidth:100},
    {name:"COND15",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 16",descWidth:100},
    {name:"COND16",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 17",descWidth:100},
    {name:"COND17",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 18",descWidth:100},
    {name:"COND18",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 19",descWidth:100},
    {name:"COND19",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 20",descWidth:100},
    {name:"COND20",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 21",descWidth:100},
    {name:"COND21",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 22",descWidth:100},
    {name:"COND22",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Кондиционер 23",descWidth:100},
  ]
}
*/

const u16 ID[]={
    #ifdef COND00 ADDR2ID(COND00) #else ,0 #endif
    #ifdef COND01, ADDR2ID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2ID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2ID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2ID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2ID(COND05) #else ,0 #endif
    #ifdef COND06, ADDR2ID(COND06) #else ,0 #endif
    #ifdef COND07, ADDR2ID(COND07) #else ,0 #endif
    #ifdef COND08, ADDR2ID(COND08) #else ,0 #endif
    #ifdef COND09, ADDR2ID(COND09) #else ,0 #endif
    #ifdef COND10, ADDR2ID(COND10) #else ,0 #endif
    #ifdef COND11, ADDR2ID(COND11) #else ,0 #endif
    #ifdef COND12, ADDR2ID(COND12) #else ,0 #endif
    #ifdef COND13, ADDR2ID(COND13) #else ,0 #endif
    #ifdef COND14, ADDR2ID(COND14) #else ,0 #endif
    #ifdef COND15, ADDR2ID(COND15) #else ,0 #endif
    #ifdef COND16, ADDR2ID(COND16) #else ,0 #endif
    #ifdef COND17, ADDR2ID(COND17) #else ,0 #endif
    #ifdef COND18, ADDR2ID(COND18) #else ,0 #endif
    #ifdef COND19, ADDR2ID(COND19) #else ,0 #endif
    #ifdef COND20, ADDR2ID(COND20) #else ,0 #endif
    #ifdef COND21, ADDR2ID(COND21) #else ,0 #endif
    #ifdef COND22, ADDR2ID(COND22) #else ,0 #endif
};

const u8 SID [] = {
    #ifdef COND00 ADDR2SID(COND00) #else ,0 #endif
    #ifdef COND01, ADDR2SID(COND01) #else ,0 #endif
    #ifdef COND02, ADDR2SID(COND02) #else ,0 #endif
    #ifdef COND03, ADDR2SID(COND03) #else ,0 #endif
    #ifdef COND04, ADDR2SID(COND04) #else ,0 #endif
    #ifdef COND05, ADDR2SID(COND05) #else ,0 #endif
    #ifdef COND06, ADDR2SID(COND06) #else ,0 #endif
    #ifdef COND07, ADDR2SID(COND07) #else ,0 #endif
    #ifdef COND08, ADDR2SID(COND08) #else ,0 #endif
    #ifdef COND09, ADDR2SID(COND09) #else ,0 #endif
    #ifdef COND10, ADDR2SID(COND10) #else ,0 #endif
    #ifdef COND11, ADDR2SID(COND11) #else ,0 #endif
    #ifdef COND12, ADDR2SID(COND12) #else ,0 #endif
    #ifdef COND13, ADDR2SID(COND13) #else ,0 #endif
    #ifdef COND14, ADDR2SID(COND14) #else ,0 #endif
    #ifdef COND15, ADDR2SID(COND15) #else ,0 #endif
    #ifdef COND16, ADDR2SID(COND16) #else ,0 #endif
    #ifdef COND17, ADDR2SID(COND17) #else ,0 #endif
    #ifdef COND18, ADDR2SID(COND18) #else ,0 #endif
    #ifdef COND19, ADDR2SID(COND19) #else ,0 #endif
    #ifdef COND20, ADDR2SID(COND20) #else ,0 #endif
    #ifdef COND21, ADDR2SID(COND21) #else ,0 #endif
    #ifdef COND22, ADDR2SID(COND22) #else ,0 #endif
};

V-ID/V-ADDR{
  if((opt(0)&1)==1 && (senderId()!=exciterId())){
    for(u8 i=0; i<23; ++i){
      if(ID[i]!=0){
        u8 statecond[5]={0, 0, 0, 0, 0};
        #ifdef COND00 if(i==0) getStatus(COND00, &statecond); #endif
        #ifdef COND01 if(i==1) getStatus(COND01, &statecond); #endif
        #ifdef COND02 if(i==2) getStatus(COND02, &statecond); #endif
        #ifdef COND03 if(i==3) getStatus(COND03, &statecond); #endif
        #ifdef COND04 if(i==4) getStatus(COND04, &statecond); #endif
        #ifdef COND05 if(i==5) getStatus(COND05, &statecond); #endif
        #ifdef COND06 if(i==6) getStatus(COND06, &statecond); #endif
        #ifdef COND07 if(i==7) getStatus(COND07, &statecond); #endif
        #ifdef COND08 if(i==8) getStatus(COND08, &statecond); #endif
        #ifdef COND09 if(i==9) getStatus(COND09, &statecond); #endif
        #ifdef COND10 if(i==10) getStatus(COND10, &statecond); #endif
        #ifdef COND11 if(i==11) getStatus(COND11, &statecond); #endif
        #ifdef COND12 if(i==12) getStatus(COND12, &statecond); #endif
        #ifdef COND13 if(i==13) getStatus(COND13, &statecond); #endif
        #ifdef COND14 if(i==14) getStatus(COND14, &statecond); #endif
        #ifdef COND15 if(i==15) getStatus(COND15, &statecond); #endif
        #ifdef COND16 if(i==16) getStatus(COND16, &statecond); #endif
        #ifdef COND17 if(i==17) getStatus(COND17, &statecond); #endif
        #ifdef COND18 if(i==18) getStatus(COND18, &statecond); #endif
        #ifdef COND19 if(i==19) getStatus(COND19, &statecond); #endif
        #ifdef COND20 if(i==20) getStatus(COND20, &statecond); #endif
        #ifdef COND21 if(i==21) getStatus(COND21, &statecond); #endif
        #ifdef COND22 if(i==22) getStatus(COND22, &statecond); #endif
        statecond[0]=(statecond[0]&0x0F)|16;
        setStatus(@ID[i]:@SID[i], &statecond);
      }
    }
  }
}

V-ID/ZIMA{
  if((opt(0)&1)==1 && (senderId()!=exciterId())){
    for(u8 i=0; i<23; ++i){
      if(ID[i]!=0){
        u8 statecond[5]={0, 0, 0, 0, 0};
        #ifdef COND00 if(i==0) getStatus(COND00, &statecond); #endif
        #ifdef COND01 if(i==1) getStatus(COND01, &statecond); #endif
        #ifdef COND02 if(i==2) getStatus(COND02, &statecond); #endif
        #ifdef COND03 if(i==3) getStatus(COND03, &statecond); #endif
        #ifdef COND04 if(i==4) getStatus(COND04, &statecond); #endif
        #ifdef COND05 if(i==5) getStatus(COND05, &statecond); #endif
        #ifdef COND06 if(i==6) getStatus(COND06, &statecond); #endif
        #ifdef COND07 if(i==7) getStatus(COND07, &statecond); #endif
        #ifdef COND08 if(i==8) getStatus(COND08, &statecond); #endif
        #ifdef COND09 if(i==9) getStatus(COND09, &statecond); #endif
        #ifdef COND10 if(i==10) getStatus(COND10, &statecond); #endif
        #ifdef COND11 if(i==11) getStatus(COND11, &statecond); #endif
        #ifdef COND12 if(i==12) getStatus(COND12, &statecond); #endif
        #ifdef COND13 if(i==13) getStatus(COND13, &statecond); #endif
        #ifdef COND14 if(i==14) getStatus(COND14, &statecond); #endif
        #ifdef COND15 if(i==15) getStatus(COND15, &statecond); #endif
        #ifdef COND16 if(i==16) getStatus(COND16, &statecond); #endif
        #ifdef COND17 if(i==17) getStatus(COND17, &statecond); #endif
        #ifdef COND18 if(i==18) getStatus(COND18, &statecond); #endif
        #ifdef COND19 if(i==19) getStatus(COND19, &statecond); #endif
        #ifdef COND20 if(i==20) getStatus(COND20, &statecond); #endif
        #ifdef COND21 if(i==21) getStatus(COND21, &statecond); #endif
        #ifdef COND22 if(i==22) getStatus(COND22, &statecond); #endif
        statecond[0]=(statecond[0]&0x0F)|48;
        setStatus(@ID[i]:@SID[i], &statecond);
      }
    }
  }
}

V-ID/s:5{
  if(
    #ifdef COND00 ((([COND00.0]&0xF0)==16) || (([COND00.0]&0xF0)==0) || (([COND00.0]&0xF0)==32)) #endif
    #ifdef COND01 && ((([COND01.0]&0xF0)==16) || (([COND01.0]&0xF0)==0) || (([COND01.0]&0xF0)==32)) #endif
    #ifdef COND02 && ((([COND02.0]&0xF0)==16) || (([COND02.0]&0xF0)==0) || (([COND02.0]&0xF0)==32)) #endif
    #ifdef COND03 && ((([COND03.0]&0xF0)==16) || (([COND03.0]&0xF0)==0) || (([COND03.0]&0xF0)==32)) #endif
    #ifdef COND04 && ((([COND04.0]&0xF0)==16) || (([COND04.0]&0xF0)==0) || (([COND04.0]&0xF0)==32)) #endif
    #ifdef COND05 && ((([COND05.0]&0xF0)==16) || (([COND05.0]&0xF0)==0) || (([COND05.0]&0xF0)==32)) #endif
    #ifdef COND06 && ((([COND06.0]&0xF0)==16) || (([COND06.0]&0xF0)==0) || (([COND06.0]&0xF0)==32)) #endif
    #ifdef COND07 && ((([COND07.0]&0xF0)==16) || (([COND07.0]&0xF0)==0) || (([COND07.0]&0xF0)==32)) #endif
    #ifdef COND08 && ((([COND08.0]&0xF0)==16) || (([COND08.0]&0xF0)==0) || (([COND08.0]&0xF0)==32)) #endif
    #ifdef COND09 && ((([COND09.0]&0xF0)==16) || (([COND09.0]&0xF0)==0) || (([COND09.0]&0xF0)==32)) #endif
    #ifdef COND10 && ((([COND10.0]&0xF0)==16) || (([COND10.0]&0xF0)==0) || (([COND10.0]&0xF0)==32)) #endif
    #ifdef COND11 && ((([COND11.0]&0xF0)==16) || (([COND11.0]&0xF0)==0) || (([COND11.0]&0xF0)==32)) #endif
    #ifdef COND12 && ((([COND12.0]&0xF0)==16) || (([COND12.0]&0xF0)==0) || (([COND12.0]&0xF0)==32)) #endif
    #ifdef COND13 && ((([COND13.0]&0xF0)==16) || (([COND13.0]&0xF0)==0) || (([COND13.0]&0xF0)==32)) #endif
    #ifdef COND14 && ((([COND14.0]&0xF0)==16) || (([COND14.0]&0xF0)==0) || (([COND14.0]&0xF0)==32)) #endif
    #ifdef COND15 && ((([COND15.0]&0xF0)==16) || (([COND15.0]&0xF0)==0) || (([COND15.0]&0xF0)==32)) #endif
    #ifdef COND16 && ((([COND16.0]&0xF0)==16) || (([COND16.0]&0xF0)==0) || (([COND16.0]&0xF0)==32)) #endif
    #ifdef COND17 && ((([COND17.0]&0xF0)==16) || (([COND17.0]&0xF0)==0) || (([COND17.0]&0xF0)==32)) #endif
    #ifdef COND18 && ((([COND18.0]&0xF0)==16) || (([COND18.0]&0xF0)==0) || (([COND18.0]&0xF0)==32)) #endif
    #ifdef COND19 && ((([COND19.0]&0xF0)==16) || (([COND19.0]&0xF0)==0) || (([COND19.0]&0xF0)==32)) #endif
    #ifdef COND20 && ((([COND20.0]&0xF0)==16) || (([COND20.0]&0xF0)==0) || (([COND20.0]&0xF0)==32)) #endif
    #ifdef COND21 && ((([COND21.0]&0xF0)==16) || (([COND21.0]&0xF0)==0) || (([COND21.0]&0xF0)==32)) #endif
    #ifdef COND22 && ((([COND22.0]&0xF0)==16) || (([COND22.0]&0xF0)==0) || (([COND22.0]&0xF0)==32)) #endif
    && ((([V-ADDR.0]&1)!=1) || ([ZIMA.0]==1))
    ) {setStatus(V-ADDR, 1); setStatus(ZIMA, 0);}
    else
    if(
    #ifdef COND00 ((([COND00.0]&0xF0)==48) || (([COND00.0]&0xF0)==0)) #endif
    #ifdef COND01 && ((([COND01.0]&0xF0)==48) || (([COND01.0]&0xF0)==0)) #endif
    #ifdef COND02 && ((([COND02.0]&0xF0)==48) || (([COND02.0]&0xF0)==0)) #endif
    #ifdef COND03 && ((([COND03.0]&0xF0)==48) || (([COND03.0]&0xF0)==0)) #endif
    #ifdef COND04 && ((([COND04.0]&0xF0)==48) || (([COND04.0]&0xF0)==0)) #endif
    #ifdef COND05 && ((([COND05.0]&0xF0)==48) || (([COND05.0]&0xF0)==0)) #endif
    #ifdef COND06 && ((([COND06.0]&0xF0)==48) || (([COND06.0]&0xF0)==0)) #endif
    #ifdef COND07 && ((([COND07.0]&0xF0)==48) || (([COND07.0]&0xF0)==0)) #endif
    #ifdef COND08 && ((([COND08.0]&0xF0)==48) || (([COND08.0]&0xF0)==0)) #endif
    #ifdef COND09 && ((([COND09.0]&0xF0)==48) || (([COND09.0]&0xF0)==0)) #endif
    #ifdef COND10 && ((([COND10.0]&0xF0)==48) || (([COND10.0]&0xF0)==0)) #endif
    #ifdef COND11 && ((([COND11.0]&0xF0)==48) || (([COND11.0]&0xF0)==0)) #endif
    #ifdef COND12 && ((([COND12.0]&0xF0)==48) || (([COND12.0]&0xF0)==0)) #endif
    #ifdef COND13 && ((([COND13.0]&0xF0)==48) || (([COND13.0]&0xF0)==0)) #endif
    #ifdef COND14 && ((([COND14.0]&0xF0)==48) || (([COND14.0]&0xF0)==0)) #endif
    #ifdef COND15 && ((([COND15.0]&0xF0)==48) || (([COND15.0]&0xF0)==0)) #endif
    #ifdef COND16 && ((([COND16.0]&0xF0)==48) || (([COND16.0]&0xF0)==0)) #endif
    #ifdef COND17 && ((([COND17.0]&0xF0)==48) || (([COND17.0]&0xF0)==0)) #endif
    #ifdef COND18 && ((([COND18.0]&0xF0)==48) || (([COND18.0]&0xF0)==0)) #endif
    #ifdef COND19 && ((([COND19.0]&0xF0)==48) || (([COND19.0]&0xF0)==0)) #endif
    #ifdef COND20 && ((([COND20.0]&0xF0)==48) || (([COND20.0]&0xF0)==0)) #endif
    #ifdef COND21 && ((([COND21.0]&0xF0)==48) || (([COND21.0]&0xF0)==0)) #endif
    #ifdef COND22 && ((([COND22.0]&0xF0)==48) || (([COND22.0]&0xF0)==0)) #endif
    && ((([ZIMA.0]&1)!=1) || ([V-ADDR.0]&1)==1)
    ) {setStatus(ZIMA, 1); setStatus(V-ADDR, 0);}
}