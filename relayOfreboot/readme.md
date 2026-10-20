# Как настроить скрипт
1) Скачиваем оба файла в /home/sh2/exe/relay/
2) Выдаем права файлу main.sh 777(chmod 777 /home/sh2/exe/relay/main.sh)
3) Открываем main.sh и вносим IP шлюза. Сохраняем.
4) В cron добавляем запись * * * * * /usr/bin/php /home/sh2/exe/relay/main.sh
5) Производим тестовый запуск /home/sh2/exe/relay/main.sh. Смотрим что ошибок нет.
