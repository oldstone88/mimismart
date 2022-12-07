/*
{
    desc:"Управление с термостата",
    tag:"item",
    selectArea:true,
    vars:[
    {name:"K00",type:"devices-list",required:false,filter:["conditioner"],width:888,desc:"Кондиционер"},
    {name:"YLITSA", type:"devices-list", required:true, filter:["temperature-sensor", "virtual"], desc:"Датчик температуры улицы", descWidth:370},
    {name:"DELTA",type:"number",min:"0",max:"20",required:true,defaultValue:"3",desc:"Прибавка к отоплению относительно кондиционера"},
    {name:"H00",type:"devices-list",required:false,filter:["valve-heating"],width:888,desc:"Тёплый пол"},
    {name:"H01",type:"devices-list",required:false,filter:["valve-heating"],width:888,desc:"Отопление"},    
    ]
}
*/

void onInit()
{
    setStatus(V-ADDR, 1);
}

void transform(u8 j) //Преобразование температуры для сравнения
{
  if((j&0x80)==0x80)
  {
    j=256-j;
    i16 k=0-j;
    return(k);
  } else return(j);
}

u8 cond[5];

V-ID/s:5
{
    if([V-ADDR.0]&1==1 && ([K00.0]%2!=0))
    {
        getStatus(K00, &cond);
        i16 test=-1;
        if( transform([YLITSA.1])>=test ) {cond[0]=65; cond[4]=0; setStatus(K00, &cond);} else //Температура до 0 - включаем кондиционер в авто режим
        {cond[0]=1; cond[4]=1; setStatus(K00, &cond);} //Температура ниже 0 - включаем режим вентиляции минимальная скорость
        u8 temp=[K00.1]+16+DELTA;
        if(([K00.1]+16+DELTA)!=[H00.2])
        {
            setStatus(1000:102, {"H00\0t:"A, temp,0});
        }
        if((transform([YLITSA.1]))<test) //На улице меньше 0, включаем отопление
        {
            if(([K00.1]+16+DELTA)!=[H01.2]) setStatus(1000:102, {"H01\0t:"A, temp,0});
        } else
        if(([H01.0]&1)==1) setStatus(1000:102,"H01\0as:-1"); // На улице больше 0, выключаем отопление
    } else
    {
        if((([V-ADDR.0]&1)==1) && ([K00.0]%2==0)) //Выключили пульт - выключаем всё
        {
            if([H00.5]!=254) setStatus(1000:102,"H00\0as:-1");
            if([H00.5]!=254) setStatus(1000:102,"H01\0as:-1");
        }
    }
}
