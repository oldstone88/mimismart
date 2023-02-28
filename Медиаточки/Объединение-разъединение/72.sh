#!/bin/bash
MAIN='192.168.1.22'
SLAVE1='192.168.1.23'
SLAVE2='192.168.1.25'
SLAVE3='192.168.1.37'
if [[ $3 -eq 1 ]]; then
	curl http://$SLAVE1/httpapi.asp?command=ConnectMasterAp:JoinGroupMaster:eth$MAIN:wifi0.0.0.0
	curl http://$SLAVE2/httpapi.asp?command=ConnectMasterAp:JoinGroupMaster:eth$MAIN:wifi0.0.0.0
	curl http://$SLAVE3/httpapi.asp?command=ConnectMasterAp:JoinGroupMaster:eth$MAIN:wifi0.0.0.0
elif [[ $3 -eq 2 ]]; then 
	curl http://$MAIN/httpapi.asp?command=multiroom:Ungroup
fi

# Скрипт для объединения-разъединения медиаточек