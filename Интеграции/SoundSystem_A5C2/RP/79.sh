#!/bin/sh
# Тут впишите нужный IP адрес точки
IPR='192.168.1.17'
# Команды пульта
hexNum=$3
hexNum="$(echo $(( 16#$hexNum )))"
if [[ $3 -eq 1 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:pause
elif [[ $3 -eq 2 ]]; then 
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:resume
elif [[ $3 -eq 3 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:prev
elif [[ $3 -eq 4 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:next
elif [[ $3 -eq 5 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:stop
elif [[ $3 -eq 6 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:vol--
elif [[ $3 -eq 7 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:vol%2b%2b
elif [[ $3 -eq 8 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:prev
elif [[ $3 -eq 9 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:wifi
elif [[ $3 -eq 10 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:bluetooth
elif [[ $3 -eq 11 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:optical
elif [[ $3 -eq 12 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:line-in
elif [[ $3 -eq 13 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:mute:1
fi
