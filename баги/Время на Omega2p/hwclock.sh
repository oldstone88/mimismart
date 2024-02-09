#!/bin/sh

dir=`dirname $0`
if [ "$1" == "-s" ]; then
    echo "set date from i2c"
    echo "date from i2c:"
    hw_date=$($dir/hwclock.sh -d)
    echo $hw_date
    date -s "$hw_date"
    if [ $? -eq 0 ]; then
	echo "data set successful"
	date
    else
	return -1
    fi
elif [ "$1" == "-w" ]; then
    echo "write date to i2c"
    dt=`date '+0x%d 0x%m 0x%y 0x%u 0x%H 0x%M 0x%S'`
    echo "date: $(date '+%d-%m-%y %u %H:%M:%S') "
    i2cset -y 0 0x68 0x00 $(echo $dt | awk '{print $7}')
    i2cset -y 0 0x68 0x01 $(echo $dt | awk '{print $6}')
    i2cset -y 0 0x68 0x02 $(echo $dt | awk '{print $5}')
    i2cset -y 0 0x68 0x03 $(echo $dt | awk '{print $4}')
    i2cset -y 0 0x68 0x04 $(echo $dt | awk '{print $1}')
    i2cset -y 0 0x68 0x05 $(echo $dt | awk '{print $2}')
    i2cset -y 0 0x68 0x06 $(echo $dt | awk '{print $3}')
    echo $($dir/hwclock.sh -r)    
elif [ "$1" == "-h" ]; then
    echo "Using: ./hwclock.sh -r - read date from i2c\n./hwclock.sh -w - write date to i2c\n./hwclock.sh -s - set date from i2c\n"
elif [ "$1" == "-d" ]; then
    echo "20$(i2cget -y 0 0x68 0x06|cut -d x -f 2)-$(i2cget -y 0 0x68 0x05|cut -d x -f 2)-$(i2cget -y 0 0x68 0x04|cut -d x -f 2) $(i2cget -y 0 0x68 0x02|cut -d x -f 2):$(i2cget -y 0 0x68 0x01|cut -d x -f 2):$(i2cget -y 0 0x68 0x00|cut -d x -f 2)"
else
    echo "read date from i2c:"
    echo "20$(i2cget -y 0 0x68 0x06|cut -d x -f 2)-$(i2cget -y 0 0x68 0x05|cut -d x -f 2)-$(i2cget -y 0 0x68 0x04|cut -d x -f 2) $(i2cget -y 0 0x68 0x03|cut -d x -f 2) $(i2cget -y 0 0x68 0x02|cut -d x -f 2):$(i2cget -y 0 0x68 0x01|cut -d x -f 2):$(i2cget -y 0 0x68 0x00|cut -d x -f 2)"
fi
