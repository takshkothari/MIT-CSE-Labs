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
    echo "roots are imaginary"
    r=$((-b/2*a))
    d=`expr -1 \* $d`
    i=$(echo "sqrt($d)" | bc)
    i=`expr $i \/ \( 2 \* $a \)`
    echo "real part is $r and imaginary part is $i"
    ;;
0)
    echo "roots are real and equal"
    r=$((-b/2*a))
    echo "root is $r"
    ;;
1)
    echo "roots are real and distinct"
    x=$(echo "sqrt($d)" | bc)
    p=$((-b+x))
    q=$((-b-x))
    x1=$((p/2*a))
    x2=$((q/2*a))
    echo "roots are $x1 and $x2"
    ;;
esac
