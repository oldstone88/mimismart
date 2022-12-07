/*
{
  desc:"Панель HDL",
  tag:"import-script",
  selectArea:true,

  vars:
  [
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
    {name:"L01",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L02",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L03",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L04",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L05",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L06",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L07",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L08",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L09",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L10",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L11",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"L12",type:"devices-list",required:false,width:600,filter:["lamp","dimer-lamp"],desc:"Лампочка",descWidth:100},
    {name:"O01",type:"devices-list",required:false,width:600,filter:["light-scheme"],desc:"Световая схема",descWidth:100},
    {name:"O02",type:"devices-list",required:false,width:600,filter:["light-scheme"],desc:"Световая схема",descWidth:100},
    {name:"O03",type:"devices-list",required:false,width:600,filter:["light-scheme"],desc:"Световая схема",descWidth:100},
    {name:"O04",type:"devices-list",required:false,width:600,filter:["light-scheme"],desc:"Световая схема",descWidth:100},
    {name:"O05",type:"devices-list",required:false,width:600,filter:["light-scheme"],desc:"Световая схема",descWidth:100},
    {name:"J01",type:"devices-list",required:false,width:600,filter:["jalousie","virtual"],desc:"Световая схема",descWidth:100},
    {name:"J02",type:"devices-list",required:false,width:600,filter:["jalousie","virtual"],desc:"Световая схема",descWidth:100},
    {name:"J03",type:"devices-list",required:false,width:600,filter:["jalousie","virtual"],desc:"Световая схема",descWidth:100},

  ]
}
*/

void stat()
{
u8 res[50]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

u8 i[3]={2, 0, 0};

//Запись - запись в KNX; чтение - чтение из KNX
//нулевой бит = 1-чтение лампы; 2-запись лампы; 3-чтение схемы; 4-запись схемы; 5-чтение шторы; 6-запись штор;
//первый бит = номер элемента;
//Второй бит = состояние элемента

V-ID/L01
{
  i[0]=2;
  i[1]=1;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L02
{
  i[0]=2;
  i[1]=2;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L03
{
  i[0]=2;
  i[1]=3;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L04
{
  i[0]=2;
  i[1]=4;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L05
{
  i[0]=2;
  i[1]=5;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L06
{
  i[0]=2;
  i[1]=6;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L07
{
  i[0]=2;
  i[1]=7;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L08
{
  i[0]=2;
  i[1]=8;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L09
{
  i[0]=2;
  i[1]=9;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L10
{
  i[0]=2;
  i[1]=0x10;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L11
{
  i[0]=2;
  i[1]=0x11;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/L12
{
  i[0]=2;
  i[1]=0x12;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/O01
{
  i[0]=4;
  i[1]=1;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/O02
{
  i[0]=4;
  i[1]=2;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/O03
{
  i[0]=4;
  i[1]=3;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/O04
{
  i[0]=4;
  i[1]=4;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/O05
{
  i[0]=4;
  i[1]=5;
  i[2]=(opt(0)&1);
  setStatus(RS485, &i);
}

V-ID/J01
{
  i[0]=6;
  if((opt(0)&7)!=0 || (opt(0)&7)!=1) {i[1]=4; i[2]=1;} else
  {i[1]=1; i[2]=(opt(0)&1);}
  setStatus(RS485, &i);
}

V-ID/J02
{
  i[0]=6;
  if((opt(0)&7)!=0 || (opt(0)&7)!=1) {i[1]=5; i[2]=1;} else
  {i[1]=2; i[2]=(opt(0)&1);}
  setStatus(RS485, &i);
}

V-ID/J03
{
  i[0]=6;
  if((opt(0)&7)!=0 || (opt(0)&7)!=1) {i[1]=6; i[2]=1;} else
  {i[1]=3; i[2]=(opt(0)&1);}
  setStatus(RS485, &i);
}

V-ID/RS485
{
  //stat();
  if(optl==3)
  {
    if(opt(0)==1)
    {
      if(opt(1)==1) {setStatus(L01, opt(2));} else
      if(opt(1)==2) {setStatus(L02, opt(2));} else
      if(opt(1)==3) {setStatus(L03, opt(2));} else
      if(opt(1)==4) {setStatus(L04, opt(2));} else
      if(opt(1)==5) {setStatus(L05, opt(2));} else
      if(opt(1)==6) {setStatus(L06, opt(2));} else
      if(opt(1)==7) {setStatus(L07, opt(2));} else
      if(opt(1)==8) {setStatus(L08, opt(2));} else
      if(opt(1)==9) {setStatus(L09, opt(2));} else
      if(opt(1)==0x10) {setStatus(L10, opt(2));} else
      if(opt(1)==0x11) {setStatus(L11, opt(2));} else
      if(opt(1)==0x12) {setStatus(L12, opt(2));}
    } else
    if(opt(0)==3)
    {
      if(opt(1)==1 && opt(2)==1) {setStatus(O01, opt(2));} else
      if(opt(1)==2 && opt(2)==1) {setStatus(O02, opt(2));} else
      if(opt(1)==3 && opt(2)==1) {setStatus(O03, opt(2));} else
      if(opt(1)==4 && opt(2)==1) {setStatus(O04, opt(2));} else
      if(opt(1)==5 && opt(2)==1) {setStatus(O05, opt(2));}
    } else
    if(opt(0)==5)
    {
      if(opt(1)==1 && opt(2)!=4) {setStatus(J01, opt(2));} else
      if(opt(1)==2 && opt(2)!=4) {setStatus(J02, opt(2));} else
      if(opt(1)==3 && opt(2)!=4) {setStatus(J03, opt(2));} else
      if(opt(1)==1 && opt(2)==4) {setStatus(J01, 0xFF);} else
      if(opt(1)==2 && opt(2)==4) {setStatus(J02, 0xFF);} else
      if(opt(1)==3 && opt(2)==4) {setStatus(J03, 0xFF);}
    }
  }
}



