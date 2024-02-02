#!/bin/bash
# eric15342335

# for testing purposes
if [ "$1" == "test" ]
then
    touch 1.exe
    touch 2.exe
fi

# -mindepth 1 for searching *.exe files inside Module* folders
# bash -c <command> <$0> <$1>
# The assignment to $0 sets the name of the shell,
# which is used in warning and error messages.

find . -mindepth 1 -name '*.exe' -type f -execdir bash -c '
    for found_files
    do
        echo "Delete $found_files? (answer Y will rm it)"
        read ans
        # for convenience, check for small letters
        if [ "$ans" == "Y" ] || [ "$ans" == "y" ]
        then
            rm "$found_files"
            # check whether file has been removed
            if [ -e $found_files ]
            then
                echo "Failed to remove $found_Files!"
            else
                echo "Removed $found_files"
            fi
        else
            echo "$found_files not removed"
        fi
    done
' exec-bash {} +
