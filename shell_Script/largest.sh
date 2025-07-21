# !/bin/bash
echo "Find greatest among 3"
echo "Enter num1"
read num1
echo "Enter num2"
read num2
echo "Enter num3"
read num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
    echo "Greatest number is $num1"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
    echo "Greatest number is $num2"
else
    echo "Greatest number is $num3"
fi
