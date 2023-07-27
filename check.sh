#!/usr/bin/sh
problem_file=$1
if [[ -f $problem_file ]]; then
    result=$(head -n 1 $problem_file | grep -E -o '[0-9.]+') # result is at first line
    ext="${problem_file##*.}"
    output=""
    if [[ $ext = 'c' ]]; then
        gcc $problem_file -lm -o out
        output=$(./out)
        rm out
    elif [[ $ext = 'py' ]]; then
        output=$(python $problem_file)
    else
        echo "File extension not recognized"
    fi

    if [[ $output -eq $result ]]; then
        echo "${output} is correct."
    else
        echo "${output} is incorrect. Expected: ${result}"
    fi
else
    echo $problem_file 'does not exist'
fi
