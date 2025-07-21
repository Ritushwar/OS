# !/bin/bash
read -p "Enter a Number: " num
i=1
for i in {1..10}
do
    echo "$num x $i = $((num * i))"
done
