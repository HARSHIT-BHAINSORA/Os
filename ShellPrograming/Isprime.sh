echo "Enter any Number = "
read nums
for(( i=2; i<=$nums/2; i++ ))
do
	ans=$(( nums%i ))
	if [ $ans -eq 0 ]
	then 
		echo "$nums is Not a Prime number"
		exit 0
	fi
done
echo "$nums is a Prime Number"

