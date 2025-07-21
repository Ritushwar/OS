#!/bin/bash
echo "Reversed of the number"
echo "Enter Number"
read num
reversed=0
while [ "$num" -ne 0 ]
do
   digit=$((num%10))
   reversed=$((reversed * 10 + digit))
   num=$((num/10))
done
echo "Reversed is $reversed"
