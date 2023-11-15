logic.xml
```
...
	<area name="Ecobee">
		<item addr="575:101" modes="0x1a" name="3 floor" t-delta="26" t-min="7" type="conditioner" vane-hor="0x00" vane-ver="0x00"/>
		<item addr="575:102" modes="0x1a" name="2 floor child" t-delta="26" t-min="7" type="conditioner" vane-hor="0x00" vane-ver="0x00"/>
		<item addr="575:103" modes="0x1a" name="1 floor left" t-delta="26" t-min="7" type="conditioner" vane-hor="0x00" vane-ver="0x00"/>
	
		<import-script COND="575:101" ID_ECOBEE="521721004301" id="575" path="scripts/ecobee.txt"/> 
		<import-script COND="575:102" ID_ECOBEE="521743881377" id="575" path="scripts/ecobee.txt"/>
		<import-script COND="575:103" ID_ECOBEE="521767827038" id="575" path="scripts/ecobee.txt"/>
	</area>
...
```
**ID_ECOBEE** указываем свой, для каждого девайса разный, получить список доступных девайсов в доме можно так: 

```
curl --location --globoff 'https://api.ecobee.com/1/thermostat?format=json&body={%22selection%22%3A{%22selectionType%22%3A%22registered%22%2C%22selectionMatch%22%3A%22%22%2C%22includeRuntime%22%3Atrue%2C%22includeSettings%22%3Atrue}}' \
--header 'Authorization: Bearer <access_token>' \
--header 'Cookie: did=s%3Av0%3Acd83f260-77d5-11ee-b925-a13f7919550c.SissSP4wdJcKUT2Hl8VEuQmFGo%2F3oY2rxPX9M%2F%2B2XXM; did_compat=s%3Av0%3Acd83f260-77d5-11ee-b925-a13f7919550c.SissSP4wdJcKUT2Hl8VEuQmFGo%2F3oY2rxPX9M%2F%2B2XXM'
```


Access token добывать по инструкции: https://www.ecobee.com/home/developer/api/documentation/v1/auth/authz-code-authorization.shtml
```
#editing the settings exe/ecobee/settings.php 
cp -r ecobee /home/sh2/exe;
cp 92.sh /home/sh2/exe;
cp ecobee.txt /home/sh2/scripts/
```
Также редактируем файл _/home/sh2/exe/ecobee/settings.php_ под свой сервер


Также редактируем файл _/home/sh2/exe/ecobee/config.json_, даем права на запись для php , timestamp_update_accesToken произвольно, остальные данные меняем из панели, thermostats заполняем по принципу ID_ECOBEE <-> адрес виртуального кондиционера 

В кроны добавляем 
```
59 * * * * php /home/sh2/exe/ecobee/ecobee.php
* * * * * php /home/sh2/exe/ecobee/ecobee.php feedback
```

Возможно у вас другая версия ShClient, приложил свой в папке api
