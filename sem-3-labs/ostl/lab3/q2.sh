echo "enter a number:"
read n
x=0
while [ $x -lt $n ]
do
k=`expr 2 \* $x + 1`
echo $k
x=`expr $x + 1`
done