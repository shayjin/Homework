#!/bin/bash

runner=$1

if test -f Main.py
then
	runner="python3.7 Main.py"
elif test -f Main.java
then
	echo "Attempting to compile java code..."
	javac *.java
	runner="java Main"
fi

score=0
error=0

for value in {1..13}
do
	echo ""
	echo "Running ${value}.code"
	${runner} Correct/${value}.code > Correct/${value}.student
	echo ""
	echo "Comparing with ${value}.expected"
	
	#Check for correct print
	tr -d '[:space:]' < Correct/${value}.student > temp1
	tr -d '[:space:]' < Correct/${value}.expected > temp2
	echo "Comparing input and output"
	if cmp -s "temp1" "temp2"; then
		echo "Print looks good"
		score=$(($score + 1))
	else
		echo "Student output and expected output are different"
	fi
done

echo ""
echo ""

echo "Running error cases:"
echo ""
echo "Running 1.error:"

printf "Your error message -> " 
${runner} Error/1.code | tail -n1 

read -n 1 -p "Error is ':' in file. Error message related to that? (y/n)" mainmenuinput
if [ $mainmenuinput = "y" ]; then
	error=$(($error + 1))
fi

echo ""

echo "Running error cases:"
echo ""
echo "Running 2.error:"

printf "Your error message -> " 
${runner} Error/2.code | tail -n1 

read -n 1 -p "Error is '?' in file. Error message related to that? (y/n)" mainmenuinput
if [ $mainmenuinput = "y" ]; then
	error=$(($error + 1))
fi

echo ""

echo "Running error cases:"
echo ""
echo "Running 3.error:"

printf "Your error message -> " 
${runner} Error/3.code | tail -n1 

read -n 1 -p "Error is '$' in file. Error message related to that? (y/n)" mainmenuinput
if [ $mainmenuinput = "y" ]; then
	error=$(($error + 1))
fi

echo ""

echo "Running error cases:"
echo ""
echo "Running 4.error:"

printf "Your error message -> " 
${runner} Error/4.code | tail -n1 

read -n 1 -p "Error is constant too large in file. Error message related to that? (y/n)" mainmenuinput
if [ $mainmenuinput = "y" ]; then
	error=$(($error + 1))
fi

echo ""

echo "Correct cases score out of 13:"
echo $score
echo "Error cases score out of 4:"
echo $error


echo Done!