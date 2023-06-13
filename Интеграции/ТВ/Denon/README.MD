Для работы скрипта:
1) Заходим по ssh
2) Пишем rw
3) Заходим в cron
crontab -e
4) Добавляем строчки
@reboot /path/to/script/Denon_start.sh
0 */4 * * * screen -X -S "Denon" kill; screen -dmS "Denon" /home/sh2/exe/Denon.sh
5) Копируем скрипты Denon.sh, Denon_start.sh,  в /home/sh2/exe/
6) Даем разрешение на исполнение
7) Копируем пульт DENON.txt в /home/sh2/pult_profiles/
8) Заводим пульт