#!/bin/bash
echo "Find the argument are valid or not"
echo $1 $2 $3 $4 $5
if [ "$#" -eq 5 ]; then
   echo "Valid argument"
else
   echo "Invalid argument"
fi

