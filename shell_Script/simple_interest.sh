# !/bin/bash
echo "Enter principle value: "
read p
echo "Enter time: "
read t
echo "Enter interest rate: "
read r
s=$(((p * t * r) / 100 ))
echo "Simple interest is $s "
