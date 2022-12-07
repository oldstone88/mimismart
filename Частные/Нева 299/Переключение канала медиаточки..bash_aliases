#!/bin/sh
# IP tochki
IPR='192.168.1.148'
# Komandi
if [[ $3 -eq 1 ]]; then
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:wifi
elif [[ $3 -eq 2 ]]; then 
	curl http://$IPR/httpapi.asp?command=setPlayerCmd:switchmode:line-in
fi
