#!/bin/sh
cp ~/cel-B/texts/lec${1}.pdf /media/s153012/PUBLIC/taisei/cel-B
number=${1}
if [ ${#1} -eq 1 ] ; then
	number=0${number}
fi
cp ~/cel-B/slides/${number}.pdf /media/s153012/PUBLIC/taisei/cel-B

