#!/bin/bash
echo "Half Pyramid"
echo "Enter the number of rows "
read rows
number=1
for i in $(seq 1 $rows)
do
     for j in $(seq 1 $i)
     do
         echo -n " $number"
         number=$((number+1))
     done
     number=1
     echo
done
echo
