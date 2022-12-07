/*
{
        desc:"Отслежтвание действий",
        name:"Отслежтвание действий",
        tag:"import-script",
        selectArea:true,
        vars:[
            {name:"U00",type:"devices-list",required:false,filter:["lamp","script","dimer-lamp","rgb-lamp","virtual"],width:888,desc:"Устройство"},
        ]
}
*/

V-ID/U00
{
    u8 buff[100];
    buff[0] = 0;
    sprintf(buff,"%c%d:%d from %d:%d State (size = %d ):",4,senderId(),senderSubId(), exciterId(), exciterSubId(), optl);
    for(u8 i = 0; i < optl; ++i)
        sprintf(buff + strlen(buff)," %02x", opt(i));
    srvError(buff);
    //setStatus(2021:32, &buff);
    //setStatus(2029:32, {4, "Message"});
}
