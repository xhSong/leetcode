#!/bin/bash

IFS=$(echo -en "\n\b")

for fullname in `ls code/`; do
    # echo $fullname
    filename=${fullname%.*}
    # echo $filename
    fileurl="https://oj.leetcode.com/problems/"${filename//\ /-}
    echo $fileurl
    wget $fileurl -O problems/${filename}.html
done
