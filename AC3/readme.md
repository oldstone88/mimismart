Для управления AC3 закинуть скрипт в /home/sh2/exe/
Примеры работы:
setStatus(1000:96, {"addr=192.168.1.126|command=httpapi.asp?command=playPromptUrl:http://192.168.1.125/sirena.mp3|"}); - Будет проигран файл sirena.mp3
setStatus(1000:96, {"addr=192.168.1.126|command=httpapi.asp?command=setPlayerCmd:stop|"}); - остановить воспроизведение
setStatus(1000:96, {"addr=192.168.1.126|command=httpapi.asp?command=setPlayerCmd:play:<url>|"}); - проииграется <url> (вместо него нужно вставить ссылку)
