/*
{
  desc:"Скрипт изменения короткого адреса драйверу на шине DALI",
  tag:"item",
  selectArea:true,
  target:"PORT",
  vars:[
    {name:"PORT",type:"devices-list",required:true,filter:["com-port"],desc:"Comport DALI шлюза"},
    {name:"ADDR",type:"number",required:true, min:1, max:63, defaultValue:1, desc:"Новый адрес"},
    {name:"OLD_ADDR00",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR01",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR02",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR03",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR04",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR05",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR06",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR07",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR08",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR09",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR10",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR11",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR12",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR13",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR14",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR15",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR16",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR17",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR18",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    {name:"OLD_ADDR19",type:"number",required:false, min:0, max:63, defaultValue:1, desc:"Старый адрес"},
    
  ]
}
*/

void FROM_DTR1()
{
        #ifdef OLD_ADDR00
        setStatus(PORT,{(OLD_ADDR00<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR00<<1)|1,128});
        #endif
        #ifdef OLD_ADDR01
        setStatus(PORT,{(OLD_ADDR01<<1)|1,128});
	    setStatus(PORT,{(OLD_ADDR01<<1)|1,128});
        #endif
        #ifdef OLD_ADDR02
        setStatus(PORT,{(OLD_ADDR02<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR02<<1)|1,128});
        #endif
        #ifdef OLD_ADDR03
        setStatus(PORT,{(OLD_ADDR03<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR03<<1)|1,128});
        #endif
        #ifdef OLD_ADDR04
        setStatus(PORT,{(OLD_ADDR04<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR04<<1)|1,128});
        #endif
        #ifdef OLD_ADDR05
        setStatus(PORT,{(OLD_ADDR05<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR05<<1)|1,128});
        #endif
        #ifdef OLD_ADDR06
        setStatus(PORT,{(OLD_ADDR06<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR06<<1)|1,128});
        #endif
        #ifdef OLD_ADDR07
        setStatus(PORT,{(OLD_ADDR07<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR07<<1)|1,128});
        #endif
        #ifdef OLD_ADDR08
        setStatus(PORT,{(OLD_ADDR08<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR08<<1)|1,128});
        #endif
        #ifdef OLD_ADDR09
        setStatus(PORT,{(OLD_ADDR09<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR09<<1)|1,128});
        #endif
        #ifdef OLD_ADDR10
        setStatus(PORT,{(OLD_ADDR10<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR10<<1)|1,128});
        #endif
        #ifdef OLD_ADDR11
        setStatus(PORT,{(OLD_ADDR11<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR11<<1)|1,128});
        #endif
        #ifdef OLD_ADDR12
        setStatus(PORT,{(OLD_ADDR12<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR12<<1)|1,128});
        #endif
        #ifdef OLD_ADDR13
        setStatus(PORT,{(OLD_ADDR13<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR13<<1)|1,128});
        #endif
        #ifdef OLD_ADDR14
        setStatus(PORT,{(OLD_ADDR14<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR14<<1)|1,128});
        #endif
        #ifdef OLD_ADDR15
        setStatus(PORT,{(OLD_ADDR15<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR15<<1)|1,128});
        #endif
        #ifdef OLD_ADDR16
        setStatus(PORT,{(OLD_ADDR16<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR16<<1)|1,128});
        #endif
        #ifdef OLD_ADDR17
        setStatus(PORT,{(OLD_ADDR17<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR17<<1)|1,128});
        #endif
        #ifdef OLD_ADDR18
        setStatus(PORT,{(OLD_ADDR18<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR18<<1)|1,128});
        #endif
        #ifdef OLD_ADDR19
        setStatus(PORT,{(OLD_ADDR19<<1)|1,128});
        setStatus(PORT,{(OLD_ADDR19<<1)|1,128});
        #endif
    	setStatus(V-ADDR, 0);
}


V-ID/V-ADDR
{
    if (opt0())
    {
        setStatus(PORT,{0xA3, (ADDR<<1)|1}); 
	cancelDelayedCall(FROM_DTR1);
	delayedCall(FROM_DTR1, 1);
    }
}




