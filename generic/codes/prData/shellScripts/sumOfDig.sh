#This Shell Script  computes sum of digits
echo -e "\nEnter Any No to find its sum of digits : \c"
read number

temp=$number
sum=0

while [ $temp -gt 0 ]
do
	rem=`expr $temp % 10`
	sum=`expr $sum + $rem`
	temp=`expr $temp / 10`
done

echo -e "Sum of Digits of number " $number " = " $sum

 
