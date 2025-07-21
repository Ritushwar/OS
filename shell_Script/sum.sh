# !/bin/bash
echo "Enter the size (N)"
read N
sum=0
echo "Enter numbers: "
for((i=0;i<N;i++)) do
    read num
    sum=$((sum+num))
done
echo "Sum is $sum"
