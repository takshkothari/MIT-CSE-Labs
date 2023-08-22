echo the name of this script is $0
echo the first arguement is $1
echo a list of all the arguements is $*
echo this script places the date into a temporary file
echo called $1.$$
date > $1.$$
cat $1.$$
ls $1.$$
rm $1.$$
