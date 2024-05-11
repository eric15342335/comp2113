# question 1
p1_num="1 2 3"
if [ "$OSTYPE" == "linux-gnu"* ]
then
    exe_prefix=""
else
    # only will test in windows(mingw) and linux so no problem doing this
    exe_prefix=".exe"
fi

g++ -Wall -Wextra -g -O0 -pedantic-errors -std=c++11 -o 1"$exe_prefix" 1.cpp
if [ -e 1"$exe_prefix" ]
then
    for case in $p1_num
    do
        echo question1-----"$case"
        ./1"$exe_prefix" < P1/input1_"$case".txt > myoutput1_"$case".txt
        diff -Bw myoutput1_"$case".txt P1/output1_"$case".txt
    done
fi

# question 2
p2_num="1 2 3"

gcc -Wall -Wextra -g -O0 -pedantic-errors -std=c11 -o 2"$exe_prefix" 2.c
for case in $p2_num
do
    echo question2-----"$case"
    ./2"$exe_prefix" < P2/input2_"$case".txt > myoutput2_"$case".txt
    diff -Bw myoutput2_"$case".txt P2/output2_"$case".txt
done

cd P3
# question 3
p3_num="1 2 3 4"

for case in $p3_num
do
    echo question3-----"$case"
    gcc -pedantic-errors -std=c11 -o main3_"$case""$exe_prefix" 3.c main3_"$case".c
    ./main3_"$case""$exe_prefix" > myoutput3_"$case".txt
    diff -Bw myoutput3_"$case".txt output3_"$case".txt
done
cd ..

# cleanup
rm myoutput*.txt
rm 1"$exe_prefix"
rm 2"$exe_prefix"
rm P3/main3_*.exe
rm P3/myoutput3_*.txt