/*
{
    desc:"Режимы",
    tag:"import-script",
    name: "Режимы",
    selectArea:true,
    addItems:[
    {tag:"item", id:"%TARGET%", name:"Режим", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", length:"2"},
    ],
    vars:[
        {name:"Address",type:"number",min:"0",max:"127",required:true,defaultValue:"1",desc:"Номер ячейки в памяти СМ"},
        {name:"MODES",type:"hidden",value:"%TARGET%:%SUBID97%"},
    ]
}
*/

u8 stopWrite = 1;

void blockWrite(){
    stopWrite = 0;
}

void onInit(){
    u32 stateOfScript = 0;
    u8 result = eeEmulRead(Address, &stateOfScript);
    if(result==0) {
        setStatus(MODES, {0, stateOfScript});
        srvError("Ошибка чтения из памяти");
    }
    else{
        setStatus(MODES, {0, stateOfScript});
        srvError("Считали значение режима и оно равно = %d", stateOfScript);
    }
    delayedCall(blockWrite, 3);
}

V-ID/MODES{
    if(stopWrite==0){
        setStatus(MODES, {0, opt(1)});
        u32 stateOfScript = opt(1);
        u8 result = eeEmulWrite(Address, stateOfScript);
        if(result==0) {srvError("Ошибка записи!");}
    } else srvError("Запись заблокирована");
}