/*
{
  desc:"Диммер WB-MDM3",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"DIMMER1",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1"},
    {name:"DIMMER2",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2"},
    {name:"DIMMER3",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3"},
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"ID диммера",descWidth:350},
  ]
}
*/

u8 i1[8]={ID1, 0x01, 0x00, 0x00, 0x00, 0x03, 0xCC, 0x16};
u8 i2[8]={ID1, 0x01, 0x00, 0x01, 0x00, 0x03, 0xCC, 0x16};
u8 i3[8]={ID1, 0x01, 0x00, 0x02, 0x00, 0x03, 0xCC, 0x16};
u8 k[3]={0, 0, 0};

void bright1()
{
  setStatus(RS485, &i1);
}

void bright2()
{
  setStatus(RS485, &i2);
}

void bright3()
{
  setStatus(RS485, &i3);
}

V-ID/DIMMER1
{
    if((opt(0)&1)==1)
        {
            i1[1]=0x05; i1[4]=0xFF; i1[5]=0x00; //ВКЛ-ВЫКЛ
            if(k[1]==0) setStatus(RS485, &i1);
            i1[1]=0x06; i1[4]=0x00; i1[5]=[DIMMER1.1]*100/250; if(i1[5]==0) i1[5]=1;
            cancelDelayedCall(bright1);
            delayedCallMs(bright1, 500);
            k[0]=1;
        } else
    if((opt(0)&1)==0 && k[0]==1)
        {
            i1[5]=0x05; i1[4]=0x00; i1[5]=0x00; // ВКЛ-ВЫКЛ
            setStatus(RS485, &i1);
            k[0]=0;
        }
}

V-ID/DIMMER2
{
    if((opt(0)&1)==1)
        {
            i2[1]=0x05; i2[4]=0xFF; i2[5]=0x00; //ВКЛ-ВЫКЛ
            if(k[1]==0) {setStatus(RS485, &i2);}
            i2[1]=0x06; i2[4]=0x00; i2[5]=[DIMMER2.1]*100/250; if(i2[5]==0) i2[5]=1;
            cancelDelayedCall(bright2);
            delayedCallMs(bright2, 500);
            k[1]=1;
        } else
    if((opt(0)&1)==0 && k[1]==1)
        {
            i2[5]=0x05; i2[4]=0x00; i2[5]=0x00; // ВКЛ-ВЫКЛ
            setStatus(RS485, &i2);
            k[1]=0;
        }
}

V-ID/DIMMER3
{
    if((opt(0)&1)==1)
        {
            i3[1]=0x05; i3[4]=0xFF; i3[5]=0x00; //ВКЛ-ВЫКЛ
            if(k[2]==0) {setStatus(RS485, &i3);}
            i3[1]=0x06; i3[4]=0x00; i3[5]=[DIMMER3.1]*100/250; if(i3[5]==0) i3[5]=1;
            cancelDelayedCall(bright3);
            delayedCallMs(bright3, 500);
            k[2]=1;
        } else
    if((opt(0)&1)==0 && k[2]==1)
        {
            i3[5]=0x05; i3[4]=0x00; i3[5]=0x00; // ВКЛ-ВЫКЛ
            setStatus(RS485, &i3);
            k[2]=0;
        }
}

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

V-ID/RS485
{
    //stat();
}