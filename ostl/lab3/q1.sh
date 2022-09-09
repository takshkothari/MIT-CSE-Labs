echo "enter a number:"
read number
x=`expr $number % 2`
if [ $x -eq 0 ]
then
echo "even"
else
echo "odd"
fi
