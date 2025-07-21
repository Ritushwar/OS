#!/bin/bash
echo "Sum of floating number"
echo "Enter first number"
read num1
echo "Enter second number"
read num2
echo "The sum of the these number is"
echo $num1+$num2|bc

