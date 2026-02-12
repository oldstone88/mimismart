#Работа с can-dali MMSMART:
---
##Предварительно шина DALI требует отдельной настройки и деления освещения на группы
---
1. Сделать hw="ow-clean", удалить через 10 секунд
2. Сделать hw="br 115200 virtual:24-DDDDDDDD virtual:32-DDDDDDDD virtual:40-DDD"
3. Загрузить скрипт с названием MMDALI на сервер (Название именно MMDALI, иначе придется менять название и в скрипте)
4. Вставить этот франмент с заменой id на id модуля DALI <import-script RS485="508:20" ID1="1" DIMMER01="508:25" DIMMER02="508:26" DIMMER03="508:27" DIMMER04="508:28" DIMMER05="508:29" DIMMER06="508:30" DIMMER07="508:31" DIMMER08="508:33" DIMMER09="508:34" DIMMER10="508:35" DIMMER11="508:36" DIMMER12="508:37" DIMMER13="508:38" DIMMER14="508:39" DIMMER15="508:41" DIMMER16="508:42" id="508" path="scripts/MMDALI.txt" name="DALI"/>
---
