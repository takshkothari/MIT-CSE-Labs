echo "enter co-eff of x^2"
read a
echo "enter co-eff of x"
read b
echo "enter constant term"
read c
d=`expr $b \* $b - 4 \* $a \* $c`
#echo $d
if [ $d -lt 0 ]
then
    k=-1
elif [ $d -eq 0 ]
then
    k=0
else
    k=1
fi
#echo $k
case $k in
-1)
    echo "imaginary"
    ;;
0)
    echo "real and equal"
    ;;
1)
    echo "real and distinct"
    ;;
esac