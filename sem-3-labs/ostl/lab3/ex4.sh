echo "menu test program"
stop=0
while test $stop -eq 0
do
cat << ENDOFMENU
1: print the date
2,3: print the current working directory
4: exit
ENDOFMENU
echo
echo "your choice?"
read reply
echo
case $reply in
"1")
    date
    ;;
"2" | "3")
    pwd
    ;;
"4")
    stop=1
    ;;
*)
    echo "illegal choice"
    ;;
esac
done