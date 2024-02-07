#!/bin/bash
# eric15342335
# usage: ./1.sh substring file

# Should not output anything if too few arguments or file does not exist
# $# returns the number of arguments when user execute the script

if [ -e $2 ] && [ $# -ge 2 ]
    # grep -o -i means grep --only-matching --ignore-case
    # sort -n means --numeric-sort (string ASCII values)
    # uniq -c means --count (output format <no. of occurrence> <word>)
    # sort -r means --reverse (since highest no. of count should appear first)
    # sort -k<start-column>,<end-column><sorting-method>
   then
    cat $2 | grep -E "[[:alpha:]]*$1[[:alpha:]]*" -o -i | sort | uniq -c | sort -k1,1r -k2,2n
fi
