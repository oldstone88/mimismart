/*
{
	desc:"Я ушел - пришел",
	tag:"item",
	selectArea:true,
	vars:[
		{name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Группа 1",descWidth:100},
		{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Группа 2",descWidth:100},
		{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Группа 3",descWidth:100},
		{name:"L03",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Группа 4",descWidth:100},
		{name:"L04",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Группа 5",descWidth:100},
		{name:"A00",type:"devices-list",required:false,width:800,filter:["script"],desc:"Сценарий на фрамугу 1",descWidth:100},
		{name:"A01",type:"devices-list",required:false,width:800,filter:["script"],desc:"Сценарий на фрамугу 2",descWidth:100},
		{name:"F00",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Фрамуга 1",descWidth:100},
		{name:"F01",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Фрамуга 2",descWidth:100},
		{name:"C00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер 1",descWidth:100},
		{name:"C01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер 2",descWidth:100},
		{name:"A02",type:"devices-list",required:false,width:800,filter:["script"],desc:"Выкл. весь свет",descWidth:100},
	]
}
*/


V-ID/V-ADDR{
	if((opt(0)&1)==1){
		u8 cond[5];
		// Кондиционеры
		#ifdef C00 getStatus(C00, cond); cond[0]=cond[0]&0xFE; setStatus(C00, &cond);#endif
		#ifdef C01 getStatus(C01, cond); cond[0]=cond[0]&0xFE; setStatus(C01, &cond);#endif
		// Скрипты фрамуг
		#ifdef A00 setStatus(A00, 0); #endif
		#ifdef A01 setStatus(A01, 0); #endif
		// Фрамуги
		#ifdef F00 if(([F00.0]&7)==1 || ([F00.0]&7)==4 || ([F00.0]&7)==5){setStatus(F00, 0);} #endif
		#ifdef F01 if(([F01.0]&7)==1 || ([F01.0]&7)==4 || ([F01.0]&7)==5){setStatus(F01, 0);} #endif
		// Управляемые группы
		#ifdef L00 setStatus(L00, 0); #endif
		#ifdef L01 setStatus(L01, 0); #endif
		#ifdef L02 setStatus(L02, 0); #endif
		#ifdef L03 setStatus(L03, 0); #endif
		#ifdef L04 setStatus(L04, 0); #endif
		#ifdef A03 setStatus(A02, 1); #endif
	} else if((opt(0)&1)==0){
		#ifdef L00 setStatus(L00, 1); #endif
		#ifdef L01 setStatus(L01, 1); #endif
		#ifdef L02 setStatus(L02, 1); #endif
		#ifdef L03 setStatus(L03, 1); #endif
		#ifdef L04 setStatus(L04, 1); #endif
	}
}