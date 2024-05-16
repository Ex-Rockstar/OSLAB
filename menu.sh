choice = 0
while [ $choice -ne 4];
do
	echo "****MENU****"
	echo "1. Display list of files"
	echo "2. Delete a file"
	echo "3. Append a file"
	echo "4. Exit"
	read choice 

	case $choice in 
		1)
			ls -l;;
		2)
			echo "enter file name"
			read file
			rm $file;;
		3)
			echo "enter file name"
			read file
			echo "Enter data to append CTRLD when done"
			cat>>$file;;
		4)
			echo "Thank you foor using me "
		esac
	done
