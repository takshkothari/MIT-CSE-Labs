echo "enter a number:"
read n
f=1
x=1
while [ $x -le $n ]
do
f=`expr $f \* $x`
x=`expr $x + 1`
done
echo $f