# !/bin/bash
echo "Finding Leap Year "
echo "Enter Year In A.D"
read n
if [[( $((n % 4 )) -eq 0 && $((n % 100 )) -ne 0 ) ||  $((n % 400 )) -eq 0 ]]; then
   echo "This is the leap year "
else
   echo "This is not the leap year"
fi
