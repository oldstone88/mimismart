/*
{
  desc:"Групповое управление шторами по Мастер шторе",
  tag:"import-script",
target:"MASTER",
name:"jalousie master-slave",
  vars:[
{type:"comment",text:"Выберите Мастер штору",width:600, "style":"color:red; font-weight:bold"},
{name:"MASTER",type:"devices-list",required:true, filter:["jalousie","virtual"],desc:"Мастер"},
{name:"SLAVE01",type:"devices-list",required:true, filter:["jalousie"],desc:"Слейв 1"},
{name:"SLAVE02",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 2"},
{name:"SLAVE03",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 3"},
{name:"SLAVE04",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 4"},
{name:"SLAVE05",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 5"},
{name:"SLAVE06",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 6"},
{name:"SLAVE07",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 7"},
{name:"SLAVE08",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 8"},
{name:"SLAVE09",type:"devices-list",required:false, filter:["jalousie"],desc:"Слейв 9"},
  ]                       
}
*/

void chekOpen()
{
if (([SLAVE01.0]&7)==3 || ([SLAVE01.0]&7)==1) {} else {setStatus(SLAVE01,1); srvError("chekOpen1");}
#ifdef SLAVE02 if (([SLAVE02.0]&7)==3 || ([SLAVE02.0]&7)==1) {} else {setStatus(SLAVE02,1); srvError("chekOpen2");} #endif
#ifdef SLAVE03 if (([SLAVE03.0]&7)==3 || ([SLAVE03.0]&7)==1) {} else {setStatus(SLAVE03,1); srvError("chekOpen3");} #endif
#ifdef SLAVE04 if (([SLAVE04.0]&7)==3 || ([SLAVE04.0]&7)==1) {} else {setStatus(SLAVE04,1); srvError("chekOpen4");} #endif
#ifdef SLAVE05 if (([SLAVE05.0]&7)==3 || ([SLAVE05.0]&7)==1) {} else {setStatus(SLAVE05,1); srvError("chekOpen5");} #endif
#ifdef SLAVE06 if (([SLAVE06.0]&7)==3 || ([SLAVE06.0]&7)==1) {} else {setStatus(SLAVE06,1); srvError("chekOpen6");} #endif
#ifdef SLAVE07 if (([SLAVE07.0]&7)==3 || ([SLAVE07.0]&7)==1) {} else {setStatus(SLAVE07,1); srvError("chekOpen7");} #endif
#ifdef SLAVE08 if (([SLAVE08.0]&7)==3 || ([SLAVE08.0]&7)==1) {} else {setStatus(SLAVE08,1); srvError("chekOpen8");} #endif
#ifdef SLAVE09 if (([SLAVE09.0]&7)==3 || ([SLAVE09.0]&7)==1) {} else {setStatus(SLAVE09,1); srvError("chekOpen9");} #endif

}

void chekClose()
{
if (([SLAVE01.0]&7)==2  || ([SLAVE01.0]&7)==0) {} else {setStatus(SLAVE01,0); srvError("chekC1");}
#ifdef SLAVE02 if (([SLAVE02.0]&7)==2 || ([SLAVE02.0]&7)==0) {} else {setStatus(SLAVE02,0); srvError("chekO2");} #endif
#ifdef SLAVE03 if (([SLAVE03.0]&7)==2 || ([SLAVE03.0]&7)==0) {} else {setStatus(SLAVE03,0); srvError("chekO3");} #endif
#ifdef SLAVE04 if (([SLAVE04.0]&7)==2 || ([SLAVE04.0]&7)==0) {} else {setStatus(SLAVE04,0); srvError("chekO4");} #endif
#ifdef SLAVE05 if (([SLAVE05.0]&7)==2 || ([SLAVE05.0]&7)==0) {} else {setStatus(SLAVE05,0); srvError("chekO5");} #endif
#ifdef SLAVE06 if (([SLAVE06.0]&7)==2 || ([SLAVE06.0]&7)==0) {} else {setStatus(SLAVE06,0); srvError("chekO6");} #endif
#ifdef SLAVE07 if (([SLAVE07.0]&7)==2 || ([SLAVE07.0]&7)==0) {} else {setStatus(SLAVE07,0); srvError("chekO7");} #endif
#ifdef SLAVE08 if (([SLAVE08.0]&7)==2 || ([SLAVE08.0]&7)==0) {} else {setStatus(SLAVE08,0); srvError("chekO8");} #endif
#ifdef SLAVE09 if (([SLAVE09.0]&7)==2 || ([SLAVE09.0]&7)==0) {} else {setStatus(SLAVE09,0); srvError("chekO9");} #endif
}

void chekStop()
{
if (([SLAVE01.0]&7)==4) {} else {setStatus(SLAVE01,0); srvError("chekS1");}
#ifdef SLAVE02 if (([SLAVE02.0]&7)==4) {} else {setStatus(SLAVE02,0); srvError("chekS2");} #endif
#ifdef SLAVE03 if (([SLAVE03.0]&7)==4) {} else {setStatus(SLAVE03,0); srvError("chekS3");} #endif
#ifdef SLAVE04 if (([SLAVE04.0]&7)==4) {} else {setStatus(SLAVE04,0); srvError("chekS4");} #endif
#ifdef SLAVE05 if (([SLAVE05.0]&7)==4) {} else {setStatus(SLAVE05,0); srvError("chekS5");} #endif
#ifdef SLAVE06 if (([SLAVE06.0]&7)==4) {} else {setStatus(SLAVE06,0); srvError("chekS6");} #endif
#ifdef SLAVE07 if (([SLAVE07.0]&7)==4) {} else {setStatus(SLAVE07,0); srvError("chekS7");} #endif
#ifdef SLAVE08 if (([SLAVE08.0]&7)==4) {} else {setStatus(SLAVE08,0); srvError("chekS8");} #endif
#ifdef SLAVE09 if (([SLAVE09.0]&7)==4) {} else {setStatus(SLAVE09,0); srvError("chekS9");} #endif
}

//секция подъема
void UP1()
{setStatus(SLAVE01,1);}
#ifdef SLAVE02 void UP2()
{setStatus(SLAVE02,1);} #endif
#ifdef SLAVE03 void UP3()
{setStatus(SLAVE03,1);} #endif
#ifdef SLAVE04 void UP4()
{setStatus(SLAVE04,1);} #endif
#ifdef SLAVE05 void UP5()
{setStatus(SLAVE05,1);} #endif
#ifdef SLAVE06 void UP6()
{setStatus(SLAVE06,1);} #endif
#ifdef SLAVE07 void UP7()
{setStatus(SLAVE07,1);} #endif
#ifdef SLAVE08 void UP8()
{setStatus(SLAVE08,1);} #endif
#ifdef SLAVE09 void UP9()
{setStatus(SLAVE09,1);} #endif

// Секция опуска
void DOWN1()
{setStatus(SLAVE01,0);}
#ifdef SLAVE02 void DOWN2()
{setStatus(SLAVE02,0);} #endif
#ifdef SLAVE03 void DOWN3()
{setStatus(SLAVE03,0);} #endif
#ifdef SLAVE04 void DOWN4()
{setStatus(SLAVE04,0);} #endif
#ifdef SLAVE05 void DOWN5()
{setStatus(SLAVE05,0);} #endif
#ifdef SLAVE06 void DOWN6()
{setStatus(SLAVE06,0);} #endif
#ifdef SLAVE07 void DOWN7()
{setStatus(SLAVE07,0);} #endif
#ifdef SLAVE08 void DOWN8()
{setStatus(SLAVE08,0);} #endif
#ifdef SLAVE09 void DOWN9()
{setStatus(SLAVE09,0);} #endif



V-ID/MASTER
{
if ([MASTER.0]==3)
{
cancelDelayedCall(chekClose);
cancelDelayedCall(chekStop);
srvError("openShades");
                          if(([SLAVE01.0]&7)==0 || ([SLAVE01.0]&7)==4) delayedCallMs(UP1, 100); else if(([SLAVE01.0]&7)==2) {delayedCallMs(UP1, 100); delayedCall(UP1,1);}
#ifdef SLAVE02 if(([SLAVE02.0]&7)==0 || ([SLAVE02.0]&7)==4) delayedCallMs(UP2, 200); else if(([SLAVE02.0]&7)==2) {delayedCallMs(UP2, 200); delayedCall(UP2,1);} #endif
#ifdef SLAVE03 if(([SLAVE03.0]&7)==0 || ([SLAVE03.0]&7)==4) delayedCallMs(UP3, 300); else if(([SLAVE03.0]&7)==2) {delayedCallMs(UP3, 300); delayedCall(UP3,1);} #endif
#ifdef SLAVE04 if(([SLAVE04.0]&7)==0 || ([SLAVE04.0]&7)==4) delayedCallMs(UP4, 400); else if(([SLAVE04.0]&7)==2) {delayedCallMs(UP4, 400); delayedCall(UP4,1);} #endif
#ifdef SLAVE05 if(([SLAVE05.0]&7)==0 || ([SLAVE05.0]&7)==4) delayedCallMs(UP5, 500); else if(([SLAVE05.0]&7)==2) {delayedCallMs(UP5, 500); delayedCall(UP5,1);} #endif
#ifdef SLAVE06 if(([SLAVE06.0]&7)==0 || ([SLAVE06.0]&7)==4) delayedCallMs(UP6, 600); else if(([SLAVE06.0]&7)==2) {delayedCallMs(UP6, 600); delayedCall(UP6,1);} #endif
#ifdef SLAVE07 if(([SLAVE07.0]&7)==0 || ([SLAVE07.0]&7)==4) delayedCallMs(UP7, 700); else if(([SLAVE07.0]&7)==2) {delayedCallMs(UP7, 700); delayedCall(UP7,1);} #endif
#ifdef SLAVE08 if(([SLAVE08.0]&7)==0 || ([SLAVE08.0]&7)==4) delayedCallMs(UP8, 800); else if(([SLAVE08.0]&7)==2) {delayedCallMs(UP8, 800); delayedCall(UP8,1);} #endif
#ifdef SLAVE09 if(([SLAVE09.0]&7)==0 || ([SLAVE09.0]&7)==4) delayedCallMs(UP9, 900); else if(([SLAVE09.0]&7)==2) {delayedCallMs(UP9, 900); delayedCall(UP9,1);} #endif
delayedCall(chekOpen,2);
}



if ([MASTER.0]==2)
{
cancelDelayedCall(chekOpen);
cancelDelayedCall(chekStop);
srvError("closeShades");
                          if(([SLAVE01.0]&7)==1 || ([SLAVE01.0]&7)==4) delayedCallMs(DOWN1, 100); else if(([SLAVE01.0]&7)==3) {delayedCallMs(DOWN1, 100); delayedCall(DOWN1,1);}
#ifdef SLAVE02 if(([SLAVE02.0]&7)==1 || ([SLAVE02.0]&7)==4) delayedCallMs(DOWN2, 200); else if(([SLAVE02.0]&7)==3) {delayedCallMs(DOWN2, 200); delayedCall(DOWN2,1);} #endif
#ifdef SLAVE03 if(([SLAVE03.0]&7)==1 || ([SLAVE03.0]&7)==4) delayedCallMs(DOWN3, 300); else if(([SLAVE03.0]&7)==3) {delayedCallMs(DOWN3, 300); delayedCall(DOWN3,1);} #endif
#ifdef SLAVE04 if(([SLAVE04.0]&7)==1 || ([SLAVE04.0]&7)==4) delayedCallMs(DOWN4, 400); else if(([SLAVE04.0]&7)==3) {delayedCallMs(DOWN4, 400); delayedCall(DOWN4,1);} #endif
#ifdef SLAVE05 if(([SLAVE05.0]&7)==1 || ([SLAVE05.0]&7)==4) delayedCallMs(DOWN5, 500); else if(([SLAVE05.0]&7)==3) {delayedCallMs(DOWN5, 500); delayedCall(DOWN5,1);} #endif
#ifdef SLAVE06 if(([SLAVE06.0]&7)==1 || ([SLAVE06.0]&7)==4) delayedCallMs(DOWN6, 600); else if(([SLAVE06.0]&7)==3) {delayedCallMs(DOWN6, 600); delayedCall(DOWN6,1);} #endif
#ifdef SLAVE07 if(([SLAVE07.0]&7)==1 || ([SLAVE07.0]&7)==4) delayedCallMs(DOWN7, 700); else if(([SLAVE07.0]&7)==3) {delayedCallMs(DOWN7, 700); delayedCall(DOWN7,1);} #endif
#ifdef SLAVE08 if(([SLAVE08.0]&7)==1 || ([SLAVE08.0]&7)==4) delayedCallMs(DOWN8, 800); else if(([SLAVE08.0]&7)==3) {delayedCallMs(DOWN8, 800); delayedCall(DOWN8,1);} #endif
#ifdef SLAVE09 if(([SLAVE09.0]&7)==1 || ([SLAVE09.0]&7)==4) delayedCallMs(DOWN9, 900); else if(([SLAVE09.0]&7)==3) {delayedCallMs(DOWN9, 900); delayedCall(DOWN9,1);} #endif
delayedCall(chekClose,2);
}

if  ([MASTER.0]==4)
{
cancelDelayedCall(chekOpen);
cancelDelayedCall(chekClose);
srvError("stopShades");
                          if ((([SLAVE01.0]&7) == 2) || (([SLAVE01.0]&7) == 3)) delayedCallMs(DOWN1, 100);
#ifdef SLAVE02 if ((([SLAVE02.0]&7) == 2) || (([SLAVE02.0]&7) == 3)) delayedCallMs(DOWN2, 200); #endif
#ifdef SLAVE03 if ((([SLAVE03.0]&7) == 2) || (([SLAVE03.0]&7) == 3)) delayedCallMs(DOWN3, 300); #endif
#ifdef SLAVE04 if ((([SLAVE04.0]&7) == 2) || (([SLAVE04.0]&7) == 3)) delayedCallMs(DOWN4, 400); #endif
#ifdef SLAVE05 if ((([SLAVE05.0]&7) == 2) || (([SLAVE05.0]&7) == 3)) delayedCallMs(DOWN5, 500); #endif
#ifdef SLAVE06 if ((([SLAVE06.0]&7) == 2) || (([SLAVE06.0]&7) == 3)) delayedCallMs(DOWN6, 600); #endif
#ifdef SLAVE07 if ((([SLAVE07.0]&7) == 2) || (([SLAVE07.0]&7) == 3)) delayedCallMs(DOWN7, 700); #endif
#ifdef SLAVE08 if ((([SLAVE08.0]&7) == 2) || (([SLAVE08.0]&7) == 3)) delayedCallMs(DOWN8, 800); #endif
#ifdef SLAVE09 if ((([SLAVE09.0]&7) == 2) || (([SLAVE09.0]&7) == 3)) delayedCallMs(DOWN9, 900);; #endif
delayedCall(chekStop,2);
}
}

