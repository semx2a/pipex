#!/bin/bash

SEP="------------------------------------------------------------"
RESET="\033[0m"

function run {
	echo "Running $1 $2 $3 $4"
	echo $SEP
	./pipex $1 "$2" "$3" $4
	echo -e "\n"
}

function clean {
	rm -rf trace
	rm -f random.txt
}

if [ "$1" == "clean" ]; then
    clean
	make fclean
    echo "Cleaning complete."
    exit 0
elif [ "$1" == "bonus" ]; then
	make fclean
	make bonus
else 
	make
fi

echo -e "$RESET"

mkdir -p trace

echo $(head -c 1024 /dev/urandom) > random.txt

run Makefile cat "grep NAME" testOutput1.txt
run testOutput1.txt cat wc testOutput2.txt
run testOutput1.txt cat wc testOutput2bis.txt
run /dev/null cat wc testOutput2bis.txt
run random.txt base64 shasum testOutput3.txt
run /dev/null cat cat testOutput4.txt

mv testOutput*.txt trace

echo "Done! Check 'trace' folder for output files."