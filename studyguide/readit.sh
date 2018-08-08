#!/bin/bash

output=$(cat JavaCh10)
n=0

for line in $output
do
	echo -$line
	sleep 2
done
