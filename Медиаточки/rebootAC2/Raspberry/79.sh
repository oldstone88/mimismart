#!/bin/bash
sshpass -p fedoraarm ssh -o StrictHostKeyChecking=no root@192.168.1.112 reboot
sshpass -p fedoraarm ssh -o StrictHostKeyChecking=no root@192.168.1.108 reboot
sshpass -p fedoraarm ssh -o StrictHostKeyChecking=no root@192.168.1.104 reboot
sshpass -p fedoraarm ssh -o StrictHostKeyChecking=no root@192.168.1.107 reboot
sshpass -p fedoraarm ssh -o StrictHostKeyChecking=no root@192.168.1.113 reboot
