#This is a Shell Script to Print The Factorial of Any Number.
echo -e "\nEnter Any Number to Find its Factorial \c"
read x
f=1
while [ $x -gt 0 ]
do
	f=`expr $f \* $x`
	x=`expr $x - 1`
done
echo -e "\nFactorial = " $f
