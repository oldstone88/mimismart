/*
{
desc:"Световая схема",
tag:"item",
selectArea:true,

vars:[
{type:"comment", style:"color:red; font-weight: bold;", text:"Реле:"},
{name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON00",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU00",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON01",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU01",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON02",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU02",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L03",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON03",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU03",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L04",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON04",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU04",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L05",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON05",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU05",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L06",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON06",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU06",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L07",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON07",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU07",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L08",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON08",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU08",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"L09",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Свет",descWidth:100},
{name:"ON09",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"AU09",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{type:"comment", style:"color:red; font-weight: bold;", text:"Диммер:"},
{name:"D00",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD00",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR00",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD00",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D01",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD01",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR01",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD01",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D02",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD02",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR02",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD02",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D03",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD03",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR03",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD04",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D04",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD04",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR04",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"D05",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD05",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR05",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD05",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D06",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD06",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR06",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD06",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D07",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD07",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR07",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD07",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D08",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD08",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR08",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD08",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"D09",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Свет",descWidth:100},
{name:"OD09",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Включить - галочка, Выключить - пусто"},
{name:"BR09",type:"number",min:"0",max:"250",required:false,defaultValue:"250",desc:"Яркость"},
{name:"AD09",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{type:"comment", style:"color:red; font-weight: bold;", text:"Шторы:"},
{name:"B00",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB00",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB00",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B01",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB01",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB01",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B02",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB02",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB02",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B03",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB03",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB03",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B04",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB04",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB04",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B05",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB05",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB05",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B06",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB06",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB06",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B07",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB07",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB07",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B08",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB08",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB08",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
{name:"B09",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Шторы",descWidth:100},
{name:"OB09",  type:"checkbox", descWidth:250, checked:true, checkValue:1, uncheckValue:0, desc:"Открыть - галочка, Закрыть - пусто"},
{name:"AB09",  type:"checkbox", descWidth:250, checked:true,desc:"Убрать автопериод?"},
]
}
*/

//При включении выполняются действия в скрипте.
//При выключении - включаются автоматизации.
//На движущиеся шторы скрипт не реагиркет.
//Если штора остановилась не в том положении - скрипт отключится.

V-ID/V-ADDR
{
    if((opt(0)&1)==1)
    {
        //Реле
        #ifdef L00 #ifdef AU00 setAutoState(L00, 0xfffe); #endif setStatus(L00, ON00); #endif
        #ifdef L01 #ifdef AU01 setAutoState(L01, 0xfffe); #endif setStatus(L01, ON01); #endif
        #ifdef L02 #ifdef AU02 setAutoState(L02, 0xfffe); #endif setStatus(L02, ON02); #endif
        #ifdef L03 #ifdef AU03 setAutoState(L03, 0xfffe); #endif setStatus(L03, ON03); #endif
        #ifdef L04 #ifdef AU04 setAutoState(L04, 0xfffe); #endif setStatus(L04, ON04); #endif
        #ifdef L05 #ifdef AU05 setAutoState(L05, 0xfffe); #endif setStatus(L05, ON05); #endif
        #ifdef L06 #ifdef AU06 setAutoState(L06, 0xfffe); #endif setStatus(L06, ON06); #endif
        #ifdef L07 #ifdef AU07 setAutoState(L07, 0xfffe); #endif setStatus(L07, ON07); #endif
        #ifdef L08 #ifdef AU08 setAutoState(L08, 0xfffe); #endif setStatus(L08, ON08); #endif
        #ifdef L09 #ifdef AU09 setAutoState(L09, 0xfffe); #endif setStatus(L09, ON09); #endif
        //Диммеры
        #ifdef D00 #ifdef AD00 setAutoState(D00, 0xfffe); #endif setStatus(D00, {OD00, BR00, 1}); #endif
        #ifdef D01 #ifdef AD01 setAutoState(D01, 0xfffe); #endif setStatus(D01, {OD01, BR01, 1}); #endif
        #ifdef D02 #ifdef AD02 setAutoState(D02, 0xfffe); #endif setStatus(D02, {OD02, BR02, 1}); #endif
        #ifdef D03 #ifdef AD03 setAutoState(D03, 0xfffe); #endif setStatus(D03, {OD03, BR03, 1}); #endif
        #ifdef D04 #ifdef AD04 setAutoState(D04, 0xfffe); #endif setStatus(D04, {OD04, BR04, 1}); #endif
        #ifdef D05 #ifdef AD05 setAutoState(D05, 0xfffe); #endif setStatus(D05, {OD05, BR05, 1}); #endif
        #ifdef D06 #ifdef AD06 setAutoState(D06, 0xfffe); #endif setStatus(D06, {OD06, BR06, 1}); #endif
        #ifdef D07 #ifdef AD07 setAutoState(D07, 0xfffe); #endif setStatus(D07, {OD07, BR07, 1}); #endif
        #ifdef D08 #ifdef AD08 setAutoState(D08, 0xfffe); #endif setStatus(D08, {OD08, BR08, 1}); #endif
        #ifdef D09 #ifdef AD09 setAutoState(D09, 0xfffe); #endif setStatus(D09, {OD09, BR09, 1}); #endif
        //Шторы
        #ifdef B00 #ifdef AB00 setAutoState(B00, 0xfffe); #endif setStatus(B00, OB00); #endif
        #ifdef B01 #ifdef AB01 setAutoState(B01, 0xfffe); #endif setStatus(B01, OB01); #endif
        #ifdef B02 #ifdef AB02 setAutoState(B02, 0xfffe); #endif setStatus(B02, OB02); #endif
        #ifdef B03 #ifdef AB03 setAutoState(B03, 0xfffe); #endif setStatus(B03, OB03); #endif
        #ifdef B04 #ifdef AB04 setAutoState(B04, 0xfffe); #endif setStatus(B04, OB04); #endif
        #ifdef B05 #ifdef AB05 setAutoState(B05, 0xfffe); #endif setStatus(B05, OB05); #endif
        #ifdef B06 #ifdef AB06 setAutoState(B06, 0xfffe); #endif setStatus(B06, OB06); #endif
        #ifdef B07 #ifdef AB07 setAutoState(B07, 0xfffe); #endif setStatus(B07, OB07); #endif
        #ifdef B08 #ifdef AB08 setAutoState(B08, 0xfffe); #endif setStatus(B08, OB08); #endif
        #ifdef B09 #ifdef AB09 setAutoState(B09, 0xfffe); #endif setStatus(B09, OB09); #endif
    } else if((opt(0)&1)==0)
    {
        #ifdef L00 #ifdef AU00 setAutoState(L00, 0x00); #endif #endif
        #ifdef L01 #ifdef AU01 setAutoState(L01, 0x00); #endif #endif
        #ifdef L02 #ifdef AU02 setAutoState(L02, 0x00); #endif #endif
        #ifdef L03 #ifdef AU03 setAutoState(L03, 0x00); #endif #endif
        #ifdef L04 #ifdef AU04 setAutoState(L04, 0x00); #endif #endif
        #ifdef L05 #ifdef AU05 setAutoState(L05, 0x00); #endif #endif
        #ifdef L06 #ifdef AU06 setAutoState(L06, 0x00); #endif #endif
        #ifdef L07 #ifdef AU07 setAutoState(L07, 0x00); #endif #endif
        #ifdef L08 #ifdef AU08 setAutoState(L08, 0x00); #endif #endif
        #ifdef L09 #ifdef AU09 setAutoState(L09, 0x00); #endif #endif
        //Диммеры
        #ifdef D00 #ifdef AD00 setAutoState(D00, 0x00); #endif #endif
        #ifdef D01 #ifdef AD01 setAutoState(D01, 0x00); #endif #endif
        #ifdef D02 #ifdef AD02 setAutoState(D02, 0x00); #endif #endif
        #ifdef D03 #ifdef AD03 setAutoState(D03, 0x00); #endif #endif
        #ifdef D04 #ifdef AD04 setAutoState(D04, 0x00); #endif #endif
        #ifdef D05 #ifdef AD05 setAutoState(D05, 0x00); #endif #endif
        #ifdef D06 #ifdef AD06 setAutoState(D06, 0x00); #endif #endif
        #ifdef D07 #ifdef AD07 setAutoState(D07, 0x00); #endif #endif
        #ifdef D08 #ifdef AD08 setAutoState(D08, 0x00); #endif #endif
        #ifdef D09 #ifdef AD09 setAutoState(D09, 0x00); #endif #endif
        //Шторы
        #ifdef B00 #ifdef AB00 setAutoState(B00, 0x00); #endif #endif
        #ifdef B01 #ifdef AB01 setAutoState(B01, 0x00); #endif #endif
        #ifdef B02 #ifdef AB02 setAutoState(B02, 0x00); #endif #endif
        #ifdef B03 #ifdef AB03 setAutoState(B03, 0x00); #endif #endif
        #ifdef B04 #ifdef AB04 setAutoState(B04, 0x00); #endif #endif
        #ifdef B05 #ifdef AB05 setAutoState(B05, 0x00); #endif #endif
        #ifdef B06 #ifdef AB06 setAutoState(B06, 0x00); #endif #endif
        #ifdef B07 #ifdef AB07 setAutoState(B07, 0x00); #endif #endif
        #ifdef B08 #ifdef AB08 setAutoState(B08, 0x00); #endif #endif
        #ifdef B09 #ifdef AB09 setAutoState(B09, 0x00); #endif #endif
    }
}

V-ID/s:1
{
        //Реле
        #ifdef L00  if(([L00.0]&1)!=ON00) setStatus(V-ADDR, 0); #endif
        #ifdef L01  if(([L01.0]&1)!=ON01) setStatus(V-ADDR, 0); #endif
        #ifdef L02  if(([L02.0]&1)!=ON02) setStatus(V-ADDR, 0); #endif
        #ifdef L03  if(([L03.0]&1)!=ON03) setStatus(V-ADDR, 0); #endif
        #ifdef L04  if(([L04.0]&1)!=ON04) setStatus(V-ADDR, 0); #endif
        #ifdef L05  if(([L05.0]&1)!=ON05) setStatus(V-ADDR, 0); #endif
        #ifdef L06  if(([L06.0]&1)!=ON06) setStatus(V-ADDR, 0); #endif
        #ifdef L07  if(([L07.0]&1)!=ON07) setStatus(V-ADDR, 0); #endif
        #ifdef L08  if(([L08.0]&1)!=ON08) setStatus(V-ADDR, 0); #endif
        #ifdef L09  if(([L09.0]&1)!=ON09) setStatus(V-ADDR, 0); #endif
        //Диммеры
        #ifdef D00 if(([D00.0]&1)!=OB00 || [D00.1]!=BR00) setStatus(V-ADDR, 0); #endif
        #ifdef D01 if(([D01.0]&1)!=OB01 || [D01.1]!=BR01) setStatus(V-ADDR, 0); #endif
        #ifdef D02 if(([D02.0]&1)!=OB02 || [D02.1]!=BR02) setStatus(V-ADDR, 0); #endif
        #ifdef D03 if(([D03.0]&1)!=OB03 || [D03.1]!=BR03) setStatus(V-ADDR, 0); #endif
        #ifdef D04 if(([D04.0]&1)!=OB04 || [D04.1]!=BR04) setStatus(V-ADDR, 0); #endif
        #ifdef D05 if(([D05.0]&1)!=OB05 || [D05.1]!=BR05) setStatus(V-ADDR, 0); #endif
        #ifdef D06 if(([D06.0]&1)!=OB06 || [D06.1]!=BR06) setStatus(V-ADDR, 0); #endif
        #ifdef D07 if(([D07.0]&1)!=OB07 || [D07.1]!=BR07) setStatus(V-ADDR, 0); #endif
        #ifdef D08 if(([D08.0]&1)!=OB08 || [D08.1]!=BR08) setStatus(V-ADDR, 0); #endif
        #ifdef D09 if(([D09.0]&1)!=OB09 || [D09.1]!=BR09) setStatus(V-ADDR, 0); #endif
        //Шторы
        #ifdef B00 if(([B00.0]&7)!=OB00 && ([B00.0]&7)!=2 && ([B00.0]&7)!=3 && ([B00.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B01 if(([B01.0]&7)!=OB01 && ([B01.0]&7)!=2 && ([B01.0]&7)!=3 && ([B01.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B02 if(([B02.0]&7)!=OB02 && ([B02.0]&7)!=2 && ([B02.0]&7)!=3 && ([B02.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B03 if(([B03.0]&7)!=OB03 && ([B03.0]&7)!=2 && ([B03.0]&7)!=3 && ([B03.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B04 if(([B04.0]&7)!=OB04 && ([B04.0]&7)!=2 && ([B04.0]&7)!=3 && ([B04.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B05 if(([B05.0]&7)!=OB05 && ([B05.0]&7)!=2 && ([B05.0]&7)!=3 && ([B05.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B06 if(([B06.0]&7)!=OB06 && ([B06.0]&7)!=2 && ([B06.0]&7)!=3 && ([B06.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B07 if(([B07.0]&7)!=OB07 && ([B07.0]&7)!=2 && ([B07.0]&7)!=3 && ([B07.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B08 if(([B08.0]&7)!=OB08 && ([B08.0]&7)!=2 && ([B08.0]&7)!=3 && ([B08.0]&7)!=5) setStatus(V-ADDR, 0); #endif
        #ifdef B09 if(([B09.0]&7)!=OB09 && ([B09.0]&7)!=2 && ([B09.0]&7)!=3 && ([B09.0]&7)!=5) setStatus(V-ADDR, 0); #endif
}