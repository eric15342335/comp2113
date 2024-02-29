# question 1
p1_num="1 2 3 4 5 6"
if [ "$OSTYPE" == "linux-gnu"* ]
then
    exe_prefix=""
else
    # only will test in windows(mingw) and linux so no problem doing this
    exe_prefix=".exe"
fi

g++ -pedantic-errors -std=c++11 -o 1"$exe_prefix" 1.cpp
if [ -e 1"$exe_prefix" ]
then
    for case in $p1_num
    do
        echo question1-----"$case"
        ./1"$exe_prefix" < P1/input1_"$case".txt > myoutput1_"$case".txt
        diff -Bw myoutput1_"$case".txt P1/output1_"$case".txt
    done
fi

# more testing
p1_num_ext="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"
if [ -e 1"$exe_prefix" ]
then
    for case in $p1_num_ext
    do
        # test case explaination:
        # a --[encryption]--> b --[decryption]--> c
        # we want to see whether a and c are the same
        # if same, the program works flawlessly
        echo question1-----ext"$case"
        # generate input encryption
        # use python3 because python defaults to python2 in academy
        echo "`python3 moretest.py`" > myinput1_ext_e"$case".txt
        # get the encrypted output
        ./1"$exe_prefix" < myinput1_ext_e"$case".txt > myoutput1_ext_e"$case".txt
        # generate input for decryption
        echo "d `cut -d ' ' -f 2,3 myinput1_ext_e"$case".txt` `cat myoutput1_ext_e"$case".txt`" > myinput_1_ext_d"$case".txt
        # get the decrypted output
        ./1"$exe_prefix" < myinput_1_ext_d"$case".txt > myoutput1_ext_d"$case".txt
        # reassembles the output to be compared with the original input
        echo "e `cut -d ' ' -f 2,3 myinput1_ext_e"$case".txt` `cat myoutput1_ext_d"$case".txt`" > myoutput1_ext_r"$case".txt
        # compare the original input with the reassembled output (should be the same)
        diff -Bw myinput1_ext_e"$case".txt myoutput1_ext_r"$case".txt
    done
fi

# question 2
p2_num="1 2 3 4"

for case in $p2_num
do
    echo question2-----"$case"
    g++ -pedantic-errors -std=c++11 -o 2"$exe_prefix" P2/2.cpp P2/main2_"$case".cpp
    ./2"$exe_prefix" > myoutput2_"$case".txt
    diff -Bw myoutput2_"$case".txt P2/output2_"$case".txt
done

g++ -pedantic-errors -std=c++11 -o 2_test"$exe_prefix" P2/2.cpp P2/2_testcase.cpp
./2_test"$exe_prefix"

# cleanup
rm myoutput*.txt
rm 1"$exe_prefix"
rm 2"$exe_prefix"
rm myinput*.txt
rm 2_test"$exe_prefix"
