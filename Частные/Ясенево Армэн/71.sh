#!/bin/bash
IP='192.168.1.131'
if [[ $3 -eq 1 ]]; then
	curl http://$IP/httpapi.asp?command=setPlayerCmd:play:https://pub0201.101.ru:8000/stream/air/aac/64/200
elif [[ $3 -eq 2 ]]; then 
	curl http://$IP/httpapi.asp?command=setPlayerCmd:stop
fi