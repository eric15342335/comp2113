#!/bin/bash
# eric15342335
read user
user_len=${#user}
result="`cat /usr/share/dict/words | grep -E "^$user[[:alpha:]]*" -o -i`"
for found in $result
do
  let "temp=${#found}-$user_len"
  echo *${found:0:$user_len}*${found:$user_len:$temp}
done
