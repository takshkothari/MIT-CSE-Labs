(sleep 10; echo done 1) &
(sleep 10; echo done 2) &
echo done 3; wait; echo done 4
