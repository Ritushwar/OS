#!/bin/bash
echo "Choose any option"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Exit"
while [ 1 -le 1 ]
do
   read option
   echo "Enter first number"
   read num1
   echo "Enter 2nd number"
   read num2
   case $option in
                 1) echo $num1+$num2|bc;;
                 2) echo $num1-$num2|bc;;
                 3) echo $num1*$num2|bc;;
                 4) echo $num1/$num2|bc;;
                 5) exit;;
   esac
done

