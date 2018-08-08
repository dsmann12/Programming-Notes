#!/bin/bash

for i in {0..32}
do
	if [ $i -lt 10 ]
	then
		filename=file0$i	
	else
		filename=file$i
	fi	

	touch $filename
	echo "Hi! My name is $filename!" > $filename
done
