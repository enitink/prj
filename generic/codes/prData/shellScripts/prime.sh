#This Programs prints consequtive prime nos. upto given by the user
echo -e "\nEnter Nos of Prime nos. \c "
read nos

num=0

while [ $nos -gt 0 ]
do 
	num=`expr $num + 1`
	count=`expr $num / 2`
	check=1
	while [ $count -gt 1 ]
	do 
		rem=`expr $num % $count`
		if [ $rem -eq 0 ]
		then 
			check=`expr $check \* 0`
		else
			check=`expr $check \* 1`
		fi
		
		count=`expr $count - 1`
		
		if [ $check -eq 0 ]
		then
			check=1
			num=`expr $num + 1`
			count=`expr $num / 2`
		fi
 	done
	#if [ $check -eq 1 ]
	#then
		echo " " $num
		nos=`expr $nos - 1`
	#fi
done 
