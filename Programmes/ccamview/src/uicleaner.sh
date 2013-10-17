#!/bin/bash
#
#Version : 0.9
#
#Auteur : Mathieu Faivre
#
#
#

declare -a listfiles

for i in $(ls)
do
	if [ -f $i ] 
	then
		if test ${i##*.} = "ui";
		then
			listfiles[${#listfiles[*]}]=$(echo $i|sed -e "s/.ui$//g")
		fi
	fi
done

for i in ${!listfiles[*]}
do
	echo "${listfiles[$i]}.ui found"
	
	if [ -f "${listfiles[$i]}.h" ]
	then
		rm "${listfiles[$i]}.h"
		echo "${listfiles[$i]}.h removed"
	fi
	
	if [ -f "${listfiles[$i]}.cpp" ]
	then
		rm "${listfiles[$i]}.cpp"
		echo "${listfiles[$i]}.cpp removed"
	fi
	
	if [ -f "${listfiles[$i]}.ui.h" ]
	then
		rm "${listfiles[$i]}.ui.h"
		echo "${listfiles[$i]}.ui.h removed"
	fi
	
	if [ -f "ui_${listfiles[$i]}.h" ]
	then
		rm "ui_${listfiles[$i]}.h"
		echo "ui_${listfiles[$i]}.h removed"
	fi
	

done

