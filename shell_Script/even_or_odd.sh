# !/bin/bash
clear
echo "-----EVEN OR ODD IN SHELL SCRIPT -----"
read -p  "Enter a number: " num
echo  "RESULT:"
if [ $((num % 2)) -eq 0 ]; then
    echo "$num is even"
else
    echo "$num is odd"
fi
