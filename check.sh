#!/usr/bin/sh
problem_file=$1
if [[ ! -f $problem_file ]]; then
    echo "${problem_file} does not exist"
    exit 0
fi

result=$(head -n 1 $problem_file | grep -E -o '[0-9.-]+')
ext="${problem_file##*.}"

if [[ $ext -ne 'c' || $ext -ne "cc" ]]; then # non-c/c++ solutions are not allowed!
    echo "File extension not recognized"
    exit 0
fi

cc=""
if [[ $ext -eq "c" ]]; then
    cc="gcc"
fi
if [[ $ext -eq "cc" ]]; then
    cc="g++"
fi

$cc $problem_file -lm -lgmp -o out
output=$(./out)
rm out

if [[ $output -eq $result ]]; then
    echo "${output} is correct."
else
    echo "${output} is incorrect. Expected: ${result}"
fi
