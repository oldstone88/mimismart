/*
{
    desc:"Привязка к СК",
    tag:"import-script",
    selectArea:true,
    
    vars:[
        {name:"H00",type:"devices-list",required:true,width:600,filter:["valve-heating"],desc:"Газовый котёл СК",descWidth:100},
        {name:"B00",type:"devices-list",required:true,width:600,filter:["valve-heating"],desc:"Бойлер",descWidth:100},
        {type:"comment", style:"color:red; font-weight: bold;", text:"Выбирете как управлять газовым катлом: (В приоритете кондиционер)"},
        {name:"KONT",type:"devices-list",required:false,width:600,filter:["lamp"],desc:"Сухой контакт",descWidth:100},
        {name:"K00",type:"devices-list",required:false,width:600,filter:["conditioner"],desc:"Газовый котёл",descWidth:100},
        {name:"TIME",type:"number",min:"0",max:"300",required:true,defaultValue:"30",desc:"Время опроса, с"},
        {name:"TELEGA",type:"devices-list",required:false,width:600,filter:["script"],desc:"Телеграмм",descWidth:100},
    ]
}
*/

u8 kond[5];

V-ID/s:TIME
{
    //srvError("Газ=%d, Бойлер=%d, Контакт=%d", [H00.0]&1, [B00.0]&1, [KONT.0]&1);
    if(
        (([H00.0]&1)==1 || ([B00.0]&1)==1) &&
        (#ifdef KONT ([KONT.0]&1)==0 #endif
        #ifdef KONT #ifdef K00 || #endif #endif
        #ifdef K00 ([K00.0]%2)==0 #endif)
        ) {
    #ifdef KONT setStatus(KONT, 1); #endif //Работа по контакту
    #ifdef K00 getStatus(K00, &kond); kond[0]=kond[0]|0x01; setStatus(K00, &kond); #endif} //Работа по кондиционеру
    else if(
        (([H00.0]&1)==0 && ([B00.0]&1)==0) && 
        (#ifdef KONT ([KONT.0]&1)==1 #endif
        #ifdef KONT #ifdef K00 || #endif #endif
        #ifdef K00 ([K00.0]%2)==1 #endif)
        ) {
    #ifdef KONT setStatus(KONT, 0);  #endif //Работа по контакту
    #ifdef K00 getStatus(K00, &kond); kond[0]=kond[0]&0xFE; setStatus(K00, &kond); #endif} //Работа по кондиционеру
    else if( (([B00.0]&1)==1 || ([H00.0]&1)==1)
    #ifdef KONT && ([KONT.0]&1)==0 #endif // Проверка по СК
    #ifdef K00 && (([K00.0]%2)==0) #endif // Проверка по кондиционеру
        ) {#ifdef TELEGA setStatus(TELEGA, 1); #endif}
}
