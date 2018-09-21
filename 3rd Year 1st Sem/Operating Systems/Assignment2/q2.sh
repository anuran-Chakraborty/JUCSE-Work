#!/bin/bash
# Write a shell script to check if a file exists and if it does exist, check the type of the file. 
read -p "Enter name of file to test " filename

if [ ! -e $filename ] 
then
	echo "File does not exist"

else
	echo "File exists"
	# Find type of file
	ftype=$( file -b $filename)
	echo "File type: $ftype"
fi
