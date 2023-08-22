echo "enter a number:"
read n
x=`expr $n % 2`
if [ $x -eq 0 ]
then
echo "even"
else
echo "odd"
fi
