��� ������ �������:
1) ������� �� ssh
2) ����� rw
3) ������� � cron
crontab -e
4) ��������� �������
@reboot /path/to/script/Denon_start.sh
0 */4 * * * screen -X -S "Denon" kill; screen -dmS "Denon" /home/sh2/exe/Denon.sh
5) �������� ������� Denon.sh, Denon_start.sh,  � /home/sh2/exe/
6) ���� ���������� �� ����������
7) �������� ����� DENON.txt � /home/sh2/pult_profiles/
8) ������� �����