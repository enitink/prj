#This is the Shell Script to find whether a string is palindrome or not
clear
echo -e "Enter any String : \c"
read str

echo $str > ttx
l=`wc -c ttx`
l1=`expr $l`
div=`expr $l / 2`

while [ $l -gt $div ]
do
	check=1
	a=`cut -c $l,$l ttx`
	l2=`expr $l1 - $l`
	b=`cut -c $l2,$l2 ttx`

	if [ $a -ne $b ]
	then
		check=0
		break;
	fi
	l=`expr $l - 1`
done

echo "Original String : " $str
if [ $check -eq 1 ]
then
	echo "String is palindrome"
else
	echo "String is not palindrome"
fi
