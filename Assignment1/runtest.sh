#!/bin/bash
# eric15342335
# cannot write: for case in "1 2 3 4"
p1_num="1 2 3 4"
# four test cases with different user inputs
p1_words=("tale" "time" "jerry" "pokemon")
# loop for 4 test cases
for case in $p1_num
do
    # distinguish 4 test case's output
    echo question1-----"$case"
    # ${} curly brace is required for accessing an array
    # $(()) converts string into number
    # array is zero-indexed :) so case-1
    ./1.sh ${p1_words[$((case-1))]} ebook.txt > myoutput1_"$case".txt
    diff -Bw myoutput1_"$case".txt SampleOutputs/P1/output1_"$case".txt
done

# question 2
p2_num="1 2 3 4"
for case in $p2_num
do
    echo question2-----"$case"
    ./2.sh < SampleOutputs/P2/input2_"$case".txt > myoutput2_"$case".txt
    diff -Bw myoutput2_"$case".txt SampleOutputs/P2/output2_"$case".txt
done

# question 3
p3_num="1 2 3 4"
if [ "$OSTYPE" == "linux-gnu"* ]
then
    exe_prefix=""
else
    # only will test in windows(mingw) and linux so no problem doing this
    exe_prefix=".exe"
fi

g++ -pedantic-errors -std=c++11 -o 3"$exe_prefix" 3.cpp
if [ -e 3"$exe_prefix" ]
then
    for case in $p3_num
    do
        echo question3-----"$case"
        ./3"$exe_prefix" < SampleOutputs/P3/input3_"$case".txt > myoutput3_"$case".txt
        diff -Bw myoutput3_"$case".txt SampleOutputs/P3/output3_"$case".txt
    done
fi

# cleanup
rm myoutput*.txt
rm 3"$exe_prefix"
