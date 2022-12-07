/*
{
        desc:"К Столу",
        name:"К Столу",
        tag:"item",
        selectArea:true,
        vars:[
            {type:"comment",text:"Введите номера скриптов для запуска"},
            {name:"M00",type:"number",required:true,min:0},
            {name:"M01",type:"number",required:true,min:0},
            {name:"M02",type:"number",required:true,min:0},
            {name:"M03",type:"number",required:true,min:0},
            {name:"M04",type:"number",required:true,min:0},
            {name:"M05",type:"number",required:true,min:0},
        ]
}
*/

void OFF()
{
      setStatus(V-ADDR, 0);
}

V-ID/V-ADDR
{
      if((opt(0)&1)==1)
      {
            setStatus(1000:M00, 20);
            setStatus(1000:M01, 20);
            setStatus(1000:M02, 20);
            setStatus(1000:M03, 20);
            setStatus(1000:M04, 20);
            setStatus(1000:M05, 20);
      }
}

