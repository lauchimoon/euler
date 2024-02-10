#!/usr/bin/sh
problem_file=$1
if [[ ! -f $problem_file ]]; then
    echo "${problem_file} does not exist"
    exit 0
fi

result=$(head -n 1 $problem_file | grep -E -o '[0-9.-]+')
ext="${problem_file##*.}"

if [[ $ext != 'c' ]]; then # non-c solutions are not allowed!
    echo "File extension not recognized"
    exit 0
fi

gcc $problem_file -lm -lgmp -o out
output=$(./out)
rm out

if [[ $output -eq $result ]]; then
    echo "${output} is correct."
else
    echo "${output} is incorrect. Expected: ${result}"
fi
