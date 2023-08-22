#!/bin/bash
X=0
while [ $X -le 20 ]
do
    echo $X
    X=$((X+1))
done
while test $# != 0
do
    echo $1
done