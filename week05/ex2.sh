#!/bin/bash

lockfile=fileLock

if [ ! -f "numbers.txt" ]
then
    touch numbers.txt
fi

while true
do
if ( set -o noclobber; echo "$$" > "$lockfile") 2> /dev/null; then

        trap 'rm -f "$lockfile"; exit $?' INT TERM EXIT

	VAR1="$(tail -n1 numbers.txt)"
	echo "$((${VAR1}+1))" >> numbers.txt
	rm -f {$LockFile}

        rm -f "$lockfile"
        trap - INT TERM EXIT
fi
	
done

