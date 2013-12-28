#This is a Shell Script to print 50 even nos.
echo -e "\nThe following are the first 50 even nos."
counter=1
number=1

while [ $counter -lt 50 ]
do
	rem=`expr $number % 2`
	if [ $rem -eq 0 ]
	then
		echo " " $number
		counter=`expr $counter + 1`
	fi 
	number=`expr $number + 1`	
done 
