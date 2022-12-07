#!/bin/sh
# by Kamenskiy Sergey
# Тут впишите нужный IP адрес камина
IPR='192.168.1.29'
# Команды пульта

echo $hexNum
if [[ $3 -eq 1 ]]; then
	curl http://$IPR/analog?POWER=1
elif [[ $3 -eq 2 ]]; then 
	curl http://$IPR/analog?POWER=0
elif [[ $3 -eq 3 ]]; then
	curl http://$IPR/SAVE?select_rez=1
elif [[ $3 -eq 4 ]]; then
	curl http://$IPR/SAVE?select_rez=2
elif [[ $3 -eq 5 ]]; then
	curl http://$IPR/SAVE?select_rez=3
elif [[ $3 -eq 6 ]]; then
	curl http://$IPR/SAVE?select_rez=4
elif [[ $3 -eq 7 ]]; then
	curl http://$IPR/SAVE?AUDIO_rej=0
elif [[ $3 -eq 8 ]]; then
	curl http://$IPR/SAVE?AUDIO_rej=1
elif [[ $3 -eq 9 ]]; then
	curl http://$IPR/SAVE?AUDIO_rej=2
fi
