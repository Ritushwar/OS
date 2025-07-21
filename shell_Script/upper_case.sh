#!/bin/bash
echo "Change text to upper case"
echo "Enter text"
read text
echo "$text" | tr 'a-z' 'A-z'
echo
