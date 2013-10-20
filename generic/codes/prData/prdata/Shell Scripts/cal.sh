#This is a program to print Cal of Any Year given by the user
echo -e "\n Enter The year for which you want to view the Calender : \c" 
read year
echo -e "\n Enter The Month Also : \c"
read month

count=30
echo "PROCESSING PLEASE WAIT"

while [ $count -gt 0 ]
do
	echo -e ".\c"
	sleep 1
	count=`expr $count - 1`
done
echo " "
cal $month $year
