/*
{
    desc:"Привязка к СК",
    tag:"item",
    selectArea:true,
    vars:[
        {name:"K00",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Газовый котёл",descWidth:100},
        {name:"K01",type:"devices-list",required:true,width:600,filter:["conditioner"],desc:"Электрокотёл",descWidth:100},
        {name:"H00",type:"devices-list",required:true,width:600,filter:["valve-heating"],desc:"Газовый котёл",descWidth:100},
        {name:"H01",type:"devices-list",required:true,width:600,filter:["valve-heating"],desc:"Электрокотёл",descWidth:100},
        {name:"B00",type:"devices-list",required:true,width:600,filter:["valve-heating"],desc:"Бойлер",descWidth:100},
        {name:"TIME",type:"number",min:"0",max:"300",required:true,defaultValue:"30",desc:"Время опроса, с"},
    ]
}
*/

u8 cond[5];
u8 i=0;

//Записываем состояние котлов в память
void zapis()
{
    u32 reg = 0;
    reg |= [K00.0];
    reg |= [K00.1] << 8;
    reg |= [K00.3] << 16;
    reg |= [K00.4] << 24;
    u8 result = eeEmulWrite(10, reg);
    if(!result) {
         srvError("Write error K00!");
    }
    reg = 0;
    reg |= [K01.0];
    reg |= [K01.1] << 8;
    reg |= [K01.3] << 16;
    reg |= [K01.4] << 24;
    result = eeEmulWrite(20, reg);
    if(!result) {
         srvError("Write error K01!");
    }
}


//Чтение состояния котлов из памяти
void chtenie()
{
    u32 reg = 0;
    u8 result = eeEmulRead(10, &reg);
    if(!result){
        reg |= [K00.0];
        reg |= [K00.1] << 8;
        reg |= [K00.3] << 16;
        reg |= [K00.4] << 24;
        result = eeEmulWrite(10, reg);
        if(!result) {
            srvError("Write K00 error!");
        }
    } else {
        if(result) {
            setStatus(K00,{reg&0xFF,(reg >> 8)&0xFF,0,(reg >> 16)&0xFF,(reg >> 24)&0xFF});
        }
    }
    reg = 0;
    result = eeEmulRead(20, &reg);
    if(!result){
        
        reg |= [K01.0];
        reg |= [K01.1] << 8;
        reg |= [K01.3] << 16;
        reg |= [K01.4] << 24;
        result = eeEmulWrite(20, reg);
        if(!result) {
            srvError("Write K01 error!");
        }
    } else {
        if(result) {
            setStatus(K01,{reg&0xFF,(reg >> 8)&0xFF,0,(reg >> 16)&0xFF,(reg >> 24)&0xFF});
        }
    }
}

//Действия при перезагрузке
void onInit()
{setStatus(V-ADDR, 1); chtenie();}

V-ID/s:TIME
{
    if( ([B00.0]&1)==1 && ([V-ADDR.0]&1)==1 && i==0) //Бойлер должен греться
    {
        zapis();
        getStatus(K00, &cond); cond[0]=1; cond[1]=70; setStatus(K00, &cond);
        getStatus(K01, &cond); cond[0]=1; cond[1]=80; setStatus(K01, &cond);
        i=1; //Пошел нагрев
        setStatus(1000:102, "H00\0Бойлер");
        setStatus(1000:102, "H01\0Бойлер");
    } else
    if ( ([B00.0]&1)==0 && ([V-ADDR.0]&1)==1 && i==1) // бойлер нагрелся
    {
        chtenie();
        i=0; //Стоп нагрев
        setStatus(1000:102,"H00\0as:-2");
        setStatus(1000:102,"H01\0as:-2");
    }
}