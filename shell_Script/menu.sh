# !/bin/bash
echo "Menu"
echo "Enter Your Choice"
echo "1. Display calender of current month"
echo "2. Display today's date and time"
echo "3. Display username those are currently logged in the system"
echo "4. Display your name at given x, y position"
echo "5. Display your terminal number"
echo "6. Exit"
while [ 1 -le 1 ]
do
   read c
   case $c in
             1) cal;;
             2) date;;
             3) who;;
             4)
                clear
                echo "Enter x, y in position"
                read x
                read y
                tput cup $x$y
                whoami
                ;;
             5)tty;;
             6)exit;;
   esac
done
