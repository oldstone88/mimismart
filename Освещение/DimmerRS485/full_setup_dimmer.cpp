/*
{
  desc:"Диммер MimiSmart",
  tag:"item",
  selectArea:true,
  name:"Установить",
  addItems:[
    {tag:"item", id:"%TARGET%", name:"Ток 1", "sub-id":"%SUBID93%", type:"virtual", "sub-type":"sensor", length:"2", dim:"мА"},
    {tag:"item", id:"%TARGET%", name:"Ток 2", "sub-id":"%SUBID99%", type:"virtual", "sub-type":"sensor", length:"2", dim:"мА"},
    {tag:"item", id:"%TARGET%", name:"Ток 3", "sub-id":"%SUBID97%", type:"virtual", "sub-type":"sensor", length:"2", dim:"мА"},
    {tag:"item", id:"%TARGET%", name:"Ток 4", "sub-id":"%SUBID95%", type:"virtual", "sub-type":"sensor", length:"2", dim:"мА"},
    {tag:"item", id:"%TARGET%", name:"Проц", "sub-id":"%SUBID91%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 1", "sub-id":"%SUBID89%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 2", "sub-id":"%SUBID87%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 3", "sub-id":"%SUBID85%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 4", "sub-id":"%SUBID83%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 5", "sub-id":"%SUBID82%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 6", "sub-id":"%SUBID79%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 7", "sub-id":"%SUBID77%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
    {tag:"item", id:"%TARGET%", name:"Температура 8", "sub-id":"%SUBID75%", type:"virtual", "sub-type":"sensor", length:"2", dim:"ºС"},
  ],
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {type:"comment", style:"color:red", text:"Настройки первого канала:"},
    {name:"LOW01",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 1",descWidth:350},
    {name:"MAX01",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 1",descWidth:350},
    {name:"DEF01",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 1",descWidth:350},
    {name:"LINE01",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT01",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки второго канала:"},
    {name:"LOW02",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 2",descWidth:350},
    {name:"MAX02",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 2",descWidth:350},
    {name:"DEF02",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 2",descWidth:350},
    {name:"LINE02",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT02",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки третьего канала:"},
    {name:"LOW03",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 3",descWidth:350},
    {name:"MAX03",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 3",descWidth:350},
    {name:"DEF03",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 3",descWidth:350},
    {name:"LINE03",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT03",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки четвертого канала:"},
    {name:"LOW04",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 4",descWidth:350},
    {name:"MAX04",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 4",descWidth:350},
    {name:"DEF04",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 4",descWidth:350},
    {name:"LINE04",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT04",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {name:"AD01",type:"hidden",value:"%TARGET%:%SUBID93%"},
    {name:"AD02",type:"hidden",value:"%TARGET%:%SUBID99%"},
    {name:"AD03",type:"hidden",value:"%TARGET%:%SUBID97%"},
    {name:"AD04",type:"hidden",value:"%TARGET%:%SUBID95%"},
    {name:"CPU",type:"hidden",value:"%TARGET%:%SUBID91%"},
    {name:"TD01",type:"hidden",value:"%TARGET%:%SUBID89%"},
    {name:"TD02",type:"hidden",value:"%TARGET%:%SUBID87%"},
    {name:"TD03",type:"hidden",value:"%TARGET%:%SUBID85%"},
    {name:"TD04",type:"hidden",value:"%TARGET%:%SUBID83%"},
    {name:"TD05",type:"hidden",value:"%TARGET%:%SUBID81%"},
    {name:"TD06",type:"hidden",value:"%TARGET%:%SUBID79%"},
    {name:"TD07",type:"hidden",value:"%TARGET%:%SUBID77%"},
    {name:"TD08",type:"hidden",value:"%TARGET%:%SUBID75%"},
  ]
}
*/

//Настройка
V-ID/V-ADDR
{
    u16 j1 = PROTECT01;
    u16 j2 = PROTECT02;
    u16 j3 = PROTECT03;
    u16 j4 = PROTECT04;
    u8 writeSetup[49]={
        ID1, 0x10, 0x00, 0x35, 0x00, 0x14, 0x28,//общие данные
        0x00, LOW01, 0x00, MAX01, 0x00, DEF01, 0x00, LINE01, //Диммер 1
        0x00, LOW02, 0x00, MAX02, 0x00, DEF02, 0x00, LINE02, //Диммер 2
        0x00, LOW03, 0x00, MAX03, 0x00, DEF03, 0x00, LINE03, //Диммер 3
        0x00, LOW04, 0x00, MAX04, 0x00, DEF04, 0x00, LINE04, //Диммер 4
        j1>>8, j1, j2>>8, j2, j3>>8, j3, j4>>8, j4, //Защита по току
        0xCC, 0x16 //CRC
    };
    setStatus(RS485, &writeSetup);
}


//Управление
u8 numberidset=0;

V-ID/ms:150
{
    //Подсчет яркости
    if(numberidset==0)
    {
    //Уставка диммеров
        u8 data[33]={ID1, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
        0x00, [DIMMER01.0]&1, 0x00, [DIMMER01.1], 0x00, 0x01, //12
        0x00, [DIMMER02.0]&1, 0x00, [DIMMER02.1], 0x00, 0x01, //18
        0x00, [DIMMER03.0]&1, 0x00, [DIMMER03.1], 0x00, 0x01, //24
        0x00, [DIMMER04.0]&1, 0x00, [DIMMER04.1], 0x00, 0x01, //30
        0xCC, 0x16}; //32
        setStatus(RS485, &data);
        numberidset=1;
        return;
    } else if(numberidset==1){
        u8 data[8]={ID1, 0x03, 0x00, 0x49, 0x00, 0x04, 0xCC, 0x16};
        setStatus(RS485, &data);
        numberidset=2;
        return;
    } else if(numberidset==2){
        u8 data[8]={ID1, 0x03, 0x00, 0x53, 0x00, 0x01, 0xCC, 0x16};
        setStatus(RS485, &data);
        numberidset=3;
        return;
    } else if(numberidset==3){
        u8 data[8]={ID1, 0x03, 0x00, 0x10, 0x00, 0x08, 0xCC, 0x16};
        setStatus(RS485, &data);
        numberidset=0;
        return;
    }
}

//Вывода в лог
void stat()
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

V-ID/RS485
{
    stat();
    if(opt(0)==ID1 && opt(1)==0x03 && optl==13){
        u16 zhach=(opt(3)<<8)|opt(4);
        u8 full=zhach/1000;
        u8 drob=(((zhach%1000)/100)*250)/10;
        setStatus(AD01, {drob, full});
        zhach=(opt(5)<<8)|opt(6);
        full=zhach/1000;
        drob=(((zhach%1000)/100)*250)/10;
        setStatus(AD02, {drob, full});
        zhach=(opt(7)<<8)|opt(8);
        full=zhach/1000;
        drob=(((zhach%1000)/100)*250)/10;
        setStatus(AD03, {drob, full});
        zhach=(opt(9)<<8)|opt(10);
        full=zhach/1000;
        drob=(((zhach%1000)/100)*250)/10;
        setStatus(AD04, {drob, full});
    }
    else if(opt(0)==ID1 && opt(1)==0x03 && optl==7){
        u16 zhach=opt(3)<<8|opt(4);
        u8 full= zhach/10;
        setStatus(CPU, {0, full});
    }
    else if(opt(0)==ID1 && opt(1)==0x03 && optl==21){
        u16 zhach=opt(3)<<8|opt(4);
        u8 full= zhach/10;
        setStatus(TD01, {0, full});
        zhach=opt(5)<<8|opt(6);
        full= zhach/10;
        setStatus(TD02, {0, full});
        zhach=opt(7)<<8|opt(7);
        full= zhach/10;
        setStatus(TD03, {0, full});
        zhach=opt(9)<<8|opt(10);
        full= zhach/10;
        setStatus(TD04, {0, full});
        zhach=opt(11)<<8|opt(12);
        full= zhach/10;
        setStatus(TD05, {0, full});
        zhach=opt(13)<<8|opt(14);
        full= zhach/10;
        setStatus(TD06, {0, full});
        zhach=opt(15)<<8|opt(16);
        full= zhach/10;
        setStatus(TD07, {0, full});
        zhach=opt(17)<<8|opt(18);
        full= zhach/10;
        setStatus(TD08, {0, full});
    }
}