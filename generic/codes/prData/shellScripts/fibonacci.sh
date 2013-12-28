# Program to Print the Fibonacci Series upto given number of terms.
echo -e "\nEnter Number of Terms of Fibonacci Series to Print \c"
read n
f=0;f1=1;f2=0

echo -e "\nThe Series is As Below :  \n"
while [ $n -gt 0 ]
do
	echo -e " " $f
	f=`expr $f1 + $f2`
	f1=$f2
	f2=$f
	n=`expr $n - 1`
done


 
