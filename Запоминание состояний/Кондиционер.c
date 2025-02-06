/*
{
    desc:"Сохранение состояния кондиционкра",
    tag:"import-script",
    selectArea:true,
    name:"Сохранение состояния кондиционкра",
    vars:[
        
        {name:"COND",type:"devices-list",required:false, filter:["conditioner"],desc:"Элемент кондиционера"},
        {type:"comment",text:"Один кондиционер занимает 5 ячеек памяти!!! Будьте внимательны задавая стартовую ячейку. Рекомендую задавать кратно 8!!!",width:200, style:"color:red;"},
        {name:"MEMMORY",type:"number",required:true,min:1,max:128,defaultValue:21,descWidth:150,desc:"Номер стартовой ячейки памяти"},
    ]
}
*/

u8 state[5]={0, 0, 0, 0, 0};
u8 res = 0;
u8 buff = 0;
u8 goChamp = 0;

void reset(){
    for(u8 i; i<5; ++i){
        res =  eeEmulRead(MEMMORY+i, &buff);
        if(!res) srvError("Ошибка = %d", i);
        else state[i]=buff;
    }
    if(res) setStatus(COND, &state);
    goChamp = 1;
}

void onInit(){
    delayedCall(reset, 3);
}

void remember(){
	getStatus(COND, state);
    for(u8 i; i<5; ++i){
        u8 res = eeEmulWrite(MEMMORY+i, state[i]);
    }
}

V-ID/COND{
    if(goChamp){
        cancelDelayedCall(remember);
        delayedCall(remember, 3);
    }
}