#!/bin/bash
# Question 4

# Take file name as input
read -p "Enter file name: " filename
# If file does not exist return error message
test -e $filename || echo "File does not exist"

# If file exists ask for the word to be searched
read -p "Enter word to search for: " word

# Check if word exists in file
count=$( grep -o -w "$word" "$filename" | wc -l )
if [ $count -gt 0 ]
then
    # If found display
    echo "$word found $count times in $filename"
    echo -e "Line number\tCount"
    echo "===================================="
    # Store the count of the word on each line
    countarr=(`grep -o -n $word $filename | cut -d : -f 1 | uniq -c`)
    # Now print 
    for (( i=0; i<${#countarr[@]}; i+=2))
    do
    	echo -e "${countarr[$i+1]}\t\t${countarr[$i]}"
    done
else
    # If not found
    echo "$word not found in $filename"
fi