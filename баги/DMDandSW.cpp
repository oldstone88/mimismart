//В логику добавить <import-script btn="530:28" dimmer="511:8" id="530" path="scripts/DMDandSW.txt"/> - привязка скрипта в логике к диммеру,
//где btn - то что срипт поймёт как константу, id - адрес скрипта(sid не нужен - т. к. скрипт вызывается другим элементом), path - путь к скрипту
u8 OldState [2] ={0,0}; //Переменная где будет храниться прошлое состояние
u8 State [2] = {0,0}; //Переменная где хранится нынешнее состояние
u8 OnOff = 0; //Включение-Выключение
V-ID/btn{ //V-ID - Всегда идёт вначале скрипта, btn - что он выполнится при изменении состояния кнопки
	State[0]=opt(0); //Считываем 0й байт - Что с кнопкой? Нажата, отжата или удерживается (Если указано opt, то это байт именно того элемента который указан после V-ID)
	State[1]=opt(1); //Считываем 1й бит - время удерживания
	if(opt(0)==0xfc) { //Если нажали кнопку

		if(OnOff == 0) //Если было выключенно - включить
			OnOff = 1;
		else 
			OnOff = 0; //Иначе выключить
		setStatus(dimmer, {OnOff}); //Установка статуса ВКЛ или ВЫКЛ
	}

}
u8 temp =0;

V-ID/ms:150{ //Цикл который исполняется каждые 150 мс
	u8 breakpoint=0;
	if(State[0]==0xfd){ //Если клавиша удерживается
		for(u8 i=0;i<2;++i){ //Цикл сравнения текущего статуса и прошлого
			if(OldState[i]!=State[i] || (OldState[1]==0xff && State[1]==0xff)){ //Если состояние кнопки изменилось(как время удержания или вкл-выкл) или удержание максимальное.
				OldState[i]=State[i]; //Записываем текущее состояние
				if(!breakpoint){
					u8 bright = [dimmer.1]; //Записываем яркость в переменную
					if(bright>245) temp = 1; //Если ярость более 245, начинаем уменьшать яркость (Ставим флаг на 1)
					else if(bright<5) temp = 0; //Если яркость меньше 5 будем увеличивать яркость (ставим флаг на 0)
					if(temp) setStatus(dimmer,{1,bright-3,0}); //Уменьшаем яркость на 3 если флаг 1
					else setStatus(dimmer,{1,bright+3,0}); //Увеличиваем яркость на 3 если флаг 0
					breakpoint=1; //Блок до следующего цикла
				}
			}
		}
	}
}
