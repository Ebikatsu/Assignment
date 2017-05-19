#!/bin/sh
number=${1}
test ${#1} -eq 1 ; number=0${number}
evince ~/cel-B/slides/${number}.pdf > /dev/null 2>&1 &

