/*
{
  desc:"Термостат RS",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
 addItems:[
		{tag:"item", id:"%TARGET%", name:"Термостат", "sub-id":"%SUBID%", type:"virtual", "sub-type":"sensor", "length":"0", "dim":"°C"},
	],
  vars:[
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
    {name:"COND",type:"devices-list",required:true, filter:["conditioner"],descWidth:250, desc:"Кондиционер"},
    {name:"SENSOR",type:"hidden",value:"%TARGET%:%SUBID%"},
 ]
}
*/

u8 a=0;
u8 on=0;
u8 m=0;
u32 k1=0;
u8 k0=0;
u32 t1=0;
u8 t0=0;
u8 kond[6];
u8 i[8]={0x01, 0x06, 0x00, 0x04, 0x00, 0xFA, 0xCC, 0x16};

V-ID/
{
	if ([~COND.4]==0 && a==1) {i[5]=0; i[3]=0x02; setStatus(RS485, &i); return;}
	if ([~COND.4]==1 && a==0) {i[5]=1; i[3]=0x02; setStatus(RS485, &i); return;}
}

V-ID/COND
{
    {
    m=1;
	if ([COND.0]%2!=0 && on==0) {i[5]=1; i[3]=0x00; setStatus(RS485, &i); return;}
	if ([COND.0]==0 && on==1) {i[5]=0; i[3]=0x00; setStatus(RS485, &i); return;}

	i[3]=0x04;	
	if (([COND.1]+5)<26) {i[4]=0; i[5]=([COND.1]+5)*10;}
	else {i[4]=1; i[5]=(([COND.1]+5)*10)-256;}
	setStatus(RS485, &i);
    }
}
 
V-ID/s:5
{
    setStatus(RS485, {0x01, 0x03, 0x00, 0x00, 0x00, 0x05, 0xCC, 0x16});
}

void check()
{
//Датчик температуры
if (t0==1) t1=(t1+256)/10; else t1=t1/10;
	u8 t3=0;
	if (t1%2!=0) t3=128; else t3=0;
	setStatus(SENSOR, {t3, t1});

//Синхронизация температуры
if (m==0)
{
    if (k0==1) k1=k1+256;
	if (k1!=([COND.1]+5)*10)
	{
	getStatus(COND, &kond);
	kond[1]=(k1/10)-5;
	setStatus(COND, &kond);
	}

//Синхронизация ВКЛ-ВЫКЛ
    if (on==1 && [COND.0]%2==0) {getStatus(COND, &kond); kond[0]=1; setStatus(COND, &kond);}
    if (on==0 && [COND.0]%2!=0) {getStatus(COND, &kond); kond[0]=0; setStatus(COND, &kond);}

//Синхронизачия режима
    if ([COND.4]==1 && a==0) {getStatus(COND, &kond); kond[4]=0; setStatus(COND, &kond);}
	if ([COND.4]==0 && a==1) {getStatus(COND, &kond); kond[4]=1; setStatus(COND, &kond);}
} else m=0;
}

void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %d", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

V-ID/RS485
{
if (optl==15)
{
on=opt(4);
a=opt(8);
t1=opt(6);
t0=opt(5);
k1=opt(12);
k0=opt(11);
check();
//stat();
}
}
