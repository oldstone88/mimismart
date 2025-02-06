/*
{
    desc:"Сохранение состояния диммера",
    tag:"import-script",
    selectArea:true,
    name:"Сохранение состояния диммера",
    vars:[
        
        {name:"DIMM",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер"},
        {type:"comment",text:"Один диммер занимает 2 ячейки памяти!!! Будьте внимательны задавая стартовую ячейку. Рекомендую задавать кратно 3!!!",width:200, style:"color:red;"},
        {name:"MEMMORY",type:"number",required:true,min:1,max:128,defaultValue:3,descWidth:150,desc:"Номер стартовой ячейки памяти"},
    ]
}
*/

u8 state[5]={0, 0};
u8 res = 0;
u8 buff = 0;
u8 goChamp = 0;

void reset(){
    for(u8 i; i<2; ++i){
        res =  eeEmulRead(MEMMORY+i, &buff);
        if(!res) srvError("Ошибка = %d", i);
        else state[i]=buff;
    }
    if(res) setStatus(DIMM, {state[0], state[1], 0});
    goChamp = 1;
}

void onInit(){
    delayedCall(reset, 3);
}

void remember(){
    getStatus(DIMM, state);
    for(u8 i; i<2; ++i){
        u8 res = eeEmulWrite(MEMMORY+i, state[i]);
    }
}

V-ID/DIMM{
    if(goChamp){
        cancelDelayedCall(remember);
        delayedCall(remember, 3);
    }
}