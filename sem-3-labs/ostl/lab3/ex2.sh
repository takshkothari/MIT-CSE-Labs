x=1
x=`expr $x + 1`
echo $x
x=`expr 2 + 3 \* 5`
echo $x
echo `expr \( 4 \> 5 \)`
echo `expr length "cat"`
echo `expr substr "donkey" 4 3`