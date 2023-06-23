#Smart48.ru Telegram bot v2.0

Для установки программной части на сервер нужно зайти по ssh и запустить команду:
```

if [ "`cat /proc/cpuinfo | grep -c Omega`" -ne "0" ] ;then wget -O /tmp/install.sh http://tg.smart48.ru/distr/install.sh && ash /tmp/install.sh omega ; else wget -O /tmp/install.sh http://tg.smart48.ru/distr/install.sh && bash /tmp/install.sh raspberry;fi && rm /tmp/install.sh
```
Везде где надо нажать "Y" для установки нужных компонентов.

##Работа с ботом
scripts/notifications/telegramm.txt - пример работы с ботом