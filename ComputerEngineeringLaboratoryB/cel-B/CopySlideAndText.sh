#!/bin/sh
cp ~/cel-B/texts/lec${1}.pdf /media/s153012/PUBLIC/taisei/cel-B
number=${1}
test ${#1} -eq 1 ; number=0${number}
cp ~/cel-B/slides/${number}.pdf /media/s153012/PUBLIC/taisei/cel-B

