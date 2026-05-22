#!/bin/bash

LIB_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

trim() {
    if [ ! -z "$1" ]; then
        TRIM_STR="$1"
        TRIM_STR="${TRIM_STR#"${TRIM_STR%%[![:space:]]*}"}"
        TRIM_STR="${TRIM_STR%"${TRIM_STR##*[![:space:]]}"}"
        printf "%s" "$TRIM_STR"
    fi
}

find "$LIB_DIR" -mindepth 2 -maxdepth 2 -type f -name "Makefile" ! -path "*/.*" -print0 | while IFS= read -r -d '' file; do
    ROOT_PATH="$(dirname "$(realpath "$file")")";
    ROOT_PATH="${ROOT_PATH%/}"
    FILE_DATA="$(cat $file)"
    LIB_PATH="$ROOT_PATH/$(trim "$(echo "$FILE_DATA" | sed -n 's#NAME[ \t]*=##p')")"
    
    if [[ "$1" == "objs" ]]; then
         find "$ROOT_PATH/srcs" -name '*.c' | sed 's#\.c$#.o#' | sed 's#'"$ROOT_PATH"'\/srcs#'"$ROOT_PATH"'/objs#'
    elif [[ "$1" == "make" ]]; then
        if [[ ! -z "$2" && $(find "$ROOT_PATH/srcs" -name '*.c' | sed 's#\.c$#.o#' | sed 's#'"$ROOT_PATH"'\/srcs#'"$ROOT_PATH"'/objs#' | grep "$2") ]]; then
           cd "$ROOT_PATH" && make;
        fi
    else
        echo "$LIB_PATH"
    fi
done