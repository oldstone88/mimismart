/*
{
  desc:"Диммер WB-MDM3",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Диммер 1", "sub-id":"%SUBID01%", type:"virtual", sub-type:"dimer-lamp", length:"0"},
    {tag:"item", id:"%TARGET%", name:"Диммер 2", "sub-id":"%SUBID02%", type:"virtual", sub-type:"dimer-lamp", length:"0"},
    {tag:"item", id:"%TARGET%", name:"Диммер 3", "sub-id":"%SUBID03%", type:"virtual", sub-type:"dimer-lamp", length:"0"},
  ],
  vars:[
    {name:"DIMMER1",type:"hidden",value:"%TARGET%:%SUBID01%"},
    {name:"DIMMER2",type:"hidden",value:"%TARGET%:%SUBID02%"},
    {name:"DIMMER3",type:"hidden",value:"%TARGET%:%SUBID03%"},
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:1,max:255,desc:"ID диммера",descWidth:350},
  ]
}
*/

u8 state1 [] = {0,0};
u8 state2 [] = {0,0};
u8 state3 [] = {0,0};
u8 i[8]={ID1, 0x01, 0x00, 0x00, 0x00, 0x03, 0xCC, 0x16};

void bright()
{
  setStatus(RS485, &i);
}

V-ID/DIMMER1
{
    if (opt(0)==0xff)
    {
        state1[0] = state1[0] ? 0:1;
        setStatus(DIMMER1,state1);
        i[1]=0x05; i[2]=0x00; i[3]=0x00; if(state1[0]==1) {i[4]=0xFF; i[5]=0x00;} else {i[4]=0x00; i[5]=0x00;}
        setStatus(RS485, &i);

    }
    else if (opt(0)==0xfe)
    {
        state1[1] = opt(1);
        setStatus(DIMMER1,state1);
    }
    else
    {
      state1[0]=opt(0);
      state1[1]=opt(1);
      i[1]=0x06; i[2]=0x00; i[3]=0x00; i[4]=0x00; i[5]=state1[1]*100/250; if(i[5]==0) i[5]=1;
      cancelDelayedCall(bright);
      delayedCallMs(bright, &i);
    }
}

V-ID/DIMMER2
{
    if (opt(0)==0xff)
    {
        state2[0] = state2[0] ? 0:1;
        setStatus(DIMMER2,state2);
        i[1]=0x05; i[2]=0x00; i[3]=0x01; if(state2[0]==1) {i[4]=0xFF; i[5]=0x00;} else {i[4]=0x00; i[5]=0x00;}
        setStatus(RS485, &i);
    }
    else if (opt(0)==0xfe)
    {
        state2[1] = opt(1);
        setStatus(DIMMER2,state2);
    }
    else
    {
      state2[0]=opt(0);
      state2[1]=opt(1);
      i[1]=0x06; i[2]=0x00; i[3]=0x01; i[4]=0x00; i[5]=state2[1]*100/250; if(i[5]==0) i[5]=1;
      cancelDelayedCall(bright);
      delayedCallMs(bright, &i);
    }
}

V-ID/DIMMER3
{
    if (opt(0)==0xff)
    {
        state3[0] = state3[0] ? 0:1;
        setStatus(DIMMER3,state3);
        i[1]=0x05; i[2]=0x00; i[3]=0x02; if(state3[0]==1) {i[4]=0xFF; i[5]=0x00;} else {i[4]=0x00; i[5]=0x00;}
        setStatus(RS485, &i);
    }
    else if (opt(0)==0xfe)
    {
        state3[1] = opt(1);
        setStatus(DIMMER3,state3);
    }
    else
    {
      state3[0]=opt(0);
      state3[1]=opt(1);
      i[1]=0x06; i[2]=0x00; i[3]=0x02; i[4]=0x00; i[5]=state3[1]*100/250; if(i[5]==0) i[5]=1;
      cancelDelayedCall(bright);
      delayedCallMs(bright, &i);
    }
}

void rsreading()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

V-ID/s:10
{
  //u8 test[8]={ID1, 0x03, 0x00, 0x00, 0x00, 0x03, 0xCC, 0x16};
  //setStatus(RS485, &test);
}

V-ID/RS485
{
  //rsreading();
}