#!/bin/sh
for i in `ls fruits` ; do echo 線形探索 ; ./7_program31 < fruits/${i} ; echo 二分探索 ; ./7_program31 < fruits/${i} ; done
