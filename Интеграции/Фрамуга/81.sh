#!/bin/bash
function hex2string () {
I=0
while [ $I -lt ${#1} ];
do
get_str=$get_str`echo -en "\x"${1:$I:2}`
let "I += 2"
done 
}
hexNum=$3
hexNum="$(echo $(( 16#$hexNum )))"

echo "http://192.168.1.109/?TargetProcent=${hexNum}"
curl "http://192.168.1.109/?TargetProcent=${hexNum}"
