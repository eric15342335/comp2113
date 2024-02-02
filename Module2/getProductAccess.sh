cat $1 | cut -f 1,4 | sort -n | grep '/products/' | uniq
