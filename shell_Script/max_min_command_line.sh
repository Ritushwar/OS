#!/bin/bash
echo "Finding min and max number from the given dataset passed by command line argument"
if [ "$#" -eq 0 ]; then
   echo "Usage: $0 num1 num2 num3 ..."
   exit 1
fi

min=$1   #$1 is the first argument here not value 1
max=$1

for num in "$@"
do
   if [ "$num" -gt "$max" ]; then
       max=$num
   fi
   if [ "$num" -lt "$min" ]; then
       min=$num
   fi
done

echo "Max : $max"
echo "Min : $min"
