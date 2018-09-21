#!/bin/bash
# Question 5

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

    # Ask for the second word
    read -p "Enter word to replace with: " word2

    # sed -i 's/\<'"$word1"'\>/'"$word2"'/g' $filename
    sed -i 's/\<'"$word"'\>/'"$word2"'/g' $filename
    echo "Replacement done"
else
    # If not found
    echo "$word not found in $filename"
fi