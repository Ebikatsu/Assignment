#!/bin/sh
number=${1}
if [ ${#1} -eq 1 ] ; then
	number=0${number}
fi
evince "/media/tasei/USB DISK/taisei/cel-B/${number}.pdf" > /dev/null 2>&1 &

