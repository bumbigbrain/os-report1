#!/bin/bash


#loop summation print
#and check time

start=`date +%s%N`

for n in {1..10}
do
	x+=n
	echo $x
	
done

end=`date +%s%N`
echo Execution time was `expr $end - $start` nanoseconds.

