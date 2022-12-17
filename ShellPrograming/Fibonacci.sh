echo "Enter the any number ="
read n
num1=0
num2=1

echo "The Fibonacci series is : "

for(( i=0; i<n; i++ ))
do 
	echo -n "$num1 "
	next=$((num1 + num2))
	num1=$num2
	num2=$next
done	
