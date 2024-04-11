/*
{
  desc:"Диммер по кнопке v2",
  name: "Диммер по кнопке v2",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"SW",type:"devices-list",required:true,filter:["switch"],desc:"Кнопка"},
    {name:"DB0",type:"number",required:true,defaultValue:250,min:0,max:250,desc:"Яркость на двойной клик",descWidth:350},
    {name:"D0",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер",width:500},
  ]
}
*/

u8 press = 0;
u8 range = 0;
u8 hold = 0;
u8 brs;

void onoff() {
    setStatus(D0, {0xFF, 0xFE});
    //srvMessage("onoff");
}

void brightness() {
    brs = [D0.1];
    if (![D0.0]) {
        brs = 0;
        setStatus(D0, {1, brs});
    }
    if (!range){
        brs -= 1;
        setStatus(D0, {0xFE, brs});
        if (brs <= 1) {
            range = 1;
        }
    } else {
        brs += 1;
        setStatus(D0, {0xFE, brs});
        if (brs >= 249) {
            range = 0;
        }
    }
}

void max_bright() {
    setStatus(D0, {0xFE, DB0});
    //srvMessage("Called Max_bright");
}

void pressoff() {
    press = 0;
}

V-ID/SW
{
    if (opt(0)==252) {
        press += 1;
        cancelDelayedCall(onoff);
        delayedCallMs(onoff, 900);
        //srvMessage("Click detected: %d", press);
        if (press == 2) {
            cancelDelayedCall(onoff);
            delayedCallMs(max_bright, 900);
        }
    } else if (opt(0)==253 && !hold) {
        hold = 1;
        cancelDelayedCall(onoff);
        cancelDelayedCall(max_bright);
        if (press == 1) {
            range = 1;
            delayedCallMsR(brightness, 50);
        }
        if (press == 2) {
            range = 0;
            delayedCallMsR(brightness, 50);
        }
        //srvMessage("Called brightness, press = %d", press);
    } else if (opt(0)==255) {
        cancelDelayedCall(brightness);
        delayedCallMs(pressoff, 900);
        hold = 0;
        //srvMessage("Button realised");
    }
}
