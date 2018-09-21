#!/bin/bash

# Function to create a new directory
function newdir()
{
	# if no arguments are passed show error
	if [ $# -eq 0 ] || [ -z "$1" ]
	then 
		echo "jubcseIII: error newdir requires one argument"
	# case for more arguments
	elif [ $# -gt 1 ] 
	then
		echo "jubcseIII: error newdir requires one exactly argument"
	else
		mkdir "$1"
		echo "directory $1 was created"
	fi 
}

# Function to edit a file
function editfile()
{
	# if no arguments are passed open vi for new file
	if [ $# -eq 0 ] || [ -z "$1" ]
	then
		vi
	# case for more arguments
	elif [ $# -gt 1 ] 
	then
		echo "jubcseIII: error editfile requires one exactly argument" 
	else
		vi "$1"
	fi
}

# Function to print contents of a file
function content()
{
	# if no arguments are passed show error
	if [ $# -eq 0 ] || [ -z "$1" ]
	then 
		echo "jubcseIII: error content requires exactly one argument"
	elif [ ! -e "$1" ]
	then
		echo "jubcseIII: file does not exist"
	# case for more arguments
	elif [ $# -gt 1 ] 
	then
		echo "jubcseIII: error content requires one exactly argument"
	else
		cat "$1"
	fi 
}

# Function to print info of file
function info()
{
	pathFile=$( realpath "$1" )
	sizeFile=$( stat --printf="%s" "$1" )
	modfile=$( stat -c %y "$1" )
	creator=$( stat -c '%U' "$1" )

	echo "Path of file: $pathFile"
	echo "Size of file: $sizeFile bytes"
	echo "Last modified date of file: $modfile"
	echo "Creator of file: $creator"
}

# Utility info function
function info_util()
{
	# if no arguments are passed show error
	if [ $# -eq 0 ] || [ -z "$1" ]
	then 
		echo "jubcseIII: error info requires exactly one argument"
	elif [ ! -e "$1" ]
	then
		echo "jubcseIII: file does not exist"
	# case for more arguments
	elif [ $# -gt 1 ] 
	then
		echo "jubcseIII: error info requires one exactly argument"
	else
		info "$1"
	fi 
}

# Function to exit
function exitbcse()
{
	echo "jubcseIII: exiting..."
	exit 1
}

# Function to display message with time of day
function messageWithTimeOfDay()
{
	#check the time of day and assign appropriate string to timestring
	currenttime=$( date +%H:%M )

	#For morning
   	if [[ "$currenttime" > "00:00" ]] && [[ "$currenttime" < "12:00" ]]
   		then
   		timestring="Morning"

   	#For afternoon
   	elif [[ "$currenttime" > "12:01" ]] && [[ "$currenttime" < "18:00" ]]
   		then
   		timestring="Afternoon"

   	#For evening
   	elif [[ "$currenttime" > "18:01" ]] && [[ "$currenttime" < "23:59" ]]
   		then
   		timestring="Evening"
   	fi
   	echo "$currenttime"
	echo "Good $timestring"
}


# Function to start the shell
function start()
{
	clear

	echo "======== Welcome to jucseIII shell ==============="
	messageWithTimeOfDay
	echo "newdir <directory>  : Create a new directory"
	echo "editfile [filename] : Edit a file"
	echo "content <filename>  : See contents of a file"
	echo "info <filename>     : Display info about file"
	echo "exitbcse            : Exit form the shell"
	echo "=================================================="

	username=$( whoami )

	while true
	do
		read -p "jubcseIII@$username: " command file

		if [ "$command" == "newdir" ]
		then 
			newdir "$file"
		elif [ "$command" == "editfile" ]
		then 
			editfile "$file"
		elif [ "$command" == "content" ]
		then 
			content "$file"
		elif [ "$command" == "info" ]
		then 
			info_util "$file"
		elif [ "$command" == "exitbcse" ]
		then 
			exitbcse
		else
			echo "$command: command not found"
		fi
	done

}


start