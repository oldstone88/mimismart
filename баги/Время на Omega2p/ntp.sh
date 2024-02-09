#!/bin/sh

/bin/ash -c 'sleep 10; killall ntpd' &

echo "MSK-3" > /tmp/TZ
/usr/sbin/ntpd -d -n -q  -p pool.ntp.org

if [ $? -eq 0 ]; then
    echo "data set successful"
	date
    else
        return -1
fi

/mimismart/time/hwclock.sh -w
