/*
{
  desc:"Тест связи",
  tag:"item",
  target:"RS485",
  selectArea:true,
  vars:[
    {name:"RS485",type:"devices-list",required:true, filter:["com-port"],descWidth:250, desc:"RS485"},
 ]
}
*/

V-ID/V-ADDR{
	u8 data[8]={0x01, 0x03, 0x00, 0x09, 0x00, 0x03, 0xCC, 0x16};
	setStatus(RS485, &data);
}

/*
void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), "%c", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}
*/

void stat(){
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

V-ID/RS485{
	stat();
}