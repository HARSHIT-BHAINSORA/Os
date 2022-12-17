echo "Enter the Number of Rows"
read rows
for (( i=1; i <= rows; i++ ))
do 
	for(( j = 1; j <= i; j++ ))
	do
		echo -n "* "
	done
	echo -e "\n"
done

