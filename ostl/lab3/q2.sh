echo "enter a number:"
read number
x=0
while [ $x -lt $number ]
do
k=`expr 2 \* $x + 1`
echo $k
x=`expr $x + 1`
done