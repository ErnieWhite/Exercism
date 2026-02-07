#!/usr/bin/env bash

main () {
    if [ "$#" -gt 0 ]; then
        for arg in "$@"; do 
            reversed_string=""
            len=${#arg}
            for (( i=len-1; i>=0; i--)); do
                reversed_string="$reversed_string${arg:i:1}"
            done
            echo "$reversed_string"
        done
    fi
}

main "$@"
