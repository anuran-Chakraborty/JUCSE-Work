#!/bin/bash
# Question 4

# Take file name as input
read -p "Enter file name: " filename
# If file does not exist return error message
test -e $filename || echo "File does not exist"

# If file exists ask for the word to be searched
read -p "Enter word to search for: " word

# Check if word exists in file
count=$( grep -c -w "$word" "$filename" )
if [ $count -gt 0 ]
then
    # If found display
    echo "$word found $count times in $filename"
else
    # If not found
    echo "$word not found in $filename"
fi