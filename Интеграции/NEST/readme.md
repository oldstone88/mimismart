1. Лимиты и ограничения: https://developers.google.com/nest/device-access/project/limits
2. Требует 5$ для аккаунта


Установка
cp -r nest /home/sh2/exe/
cp 99.sh /home/sh2/exe/
cp nest-script /home/sh2/scripts/

logic.xml пример:
<area name="nest">
		<item addr="114:101" funs="0" modes="0x1A" name="NEST" t-min="16" type="conditioner" vane-hor="0" vane-ver="0"/>
		<item addr="114:102" funs="0" modes="0x1A" name="NEST" t-min="16" type="conditioner" vane-hor="0" vane-ver="0"/>
		<item addr="114:103" funs="0" modes="0x1A" name="NEST" t-min="16" type="conditioner" vane-hor="0" vane-ver="0"/>
		<import-script Cond="114:101" addr="114:231" path="scripts/nest-script.txt" tmin="16" ID="0"/>
		<import-script Cond="114:102" addr="114:232" path="scripts/nest-script.txt" tmin="16" ID="1"/>
		<import-script Cond="114:103" addr="114:233" path="scripts/nest-script.txt" tmin="16" ID="2"/>
</area>

заполняем конфиг config.json своими данными, данные по токенам получать по инструкции: https://developers.google.com/nest/device-access/api/authorization#oauth_flow
https://developers.google.com/nest/device-access/authorize?hl=ru

идентификаторы термостатов можно увидеть отправив запрос (укажите свои access token и project-id)
curl --location 'https://smartdevicemanagement.googleapis.com/v1/enterprises/<project-id>/devices' \
--header 'Authorization: Bearer <access_token>'

вписываем в конфиг

скопировать файл сервиса nest-subscribe.service в /etc/systemd/system (команда 
	rw; cd /home/sh2/exe/nest; cp nest-subscribe.service /etc/systemd/system; chmod +x /etc/systemd/system/nest-subscribe.service; chmod +x subscribe.php; systemctl daemon-reload; sync;ro; 
	)
проверить что сервис работает с помощью команды systemctl start nest-subscribe.service; systemctl status nest-subscribe.service
если все ок, поставить сервис на автозапуск с помощью команды systemctl enable nest-subscribe.service