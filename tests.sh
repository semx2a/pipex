#!/bin/bash

SEP="------------------------------------------------------------"
RESET="\033[0m"

# function to run pipex tests
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

# create file with random data
echo $(head -c 1024 /dev/urandom) > random.txt

# tests
run Makefile cat "grep NAME" userOutput_1.txt
run userOutput_1.txt cat wc userOutput_2.txt
run /dev/null cat wc userOutput_3.txt
run random.txt base64 shasum userOutput_4.txt
run /dev/null cat cat userOutput_5.txt

# bash tests
bash -c < Makefile cat | grep NAME > bashOutput_1.txt
bash -c < bashOutput_1.txt cat | wc > bashOutput_2.txt
bash -c < /dev/null cat | wc > bashOutput_3.txt
bash -c < random.txt base64 | shasum > bashOutput_4.txt
bash -c < /dev/null cat | cat > bashOutput_5.txt

# move files to trace folder
mv *Output*.txt trace
if [ $? -ne 0 ]; then
	echo "Error moving files to trace folder."
	exit 1
else
	echo "Done! Check 'trace' folder for testOutput files."
fi

# compare pipex and bash outputs for each test
for i in {1..5}
do
	echo -e "\n$SEP"
	echo "Comparing userOutput_$i.txt with bashOutput_$i.txt"
	echo $SEP
	diff -sy trace/userOutput_$i.txt trace/bashOutput_$i.txt
done
