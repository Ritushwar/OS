# !/bin/bash
echo "Enter a number"
read n
if [ "$n" -le 1 ]; then
    echo "$n is not a prime number"
    exit
fi
for ((i=2;i<n;i++))
do
    if [ $((n%i)) -eq 0 ]; then
        echo "$n is not prime number."
        exit
    fi
done
echo "$n is a prime number."
