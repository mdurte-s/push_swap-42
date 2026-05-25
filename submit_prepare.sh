#!/bin/bash

DEST_PATH=$1

trim() {
    if [ ! -z "$1" ]; then
        TRIM_STR="$1"
        TRIM_STR="${TRIM_STR#"${TRIM_STR%%[![:space:]]*}"}"
        TRIM_STR="${TRIM_STR%"${TRIM_STR##*[![:space:]]}"}"
        printf "%s" "$TRIM_STR"
    fi
}

DEST_PATH="$(trim "$DEST_PATH")"
DEST_PATH="${DEST_PATH%/}"

if [ -z "$DEST_PATH" ] || [ ! -d $DEST_PATH ]; then
    echo "Destination folder not found."
    exit 1
fi


make fclean > /dev/null 2>&1

find "$DEST_PATH" -mindepth 1 -not -path '*/.git*' -delete
find . -mindepth 1 -maxdepth 1 -not -name "$(basename "$DEST_PATH")" -not -name ".git" -exec cp -r {} "$DEST_PATH/" \;

rm "$DEST_PATH/"*.py > /dev/null 2>&1
rm "$DEST_PATH/"*.sh > /dev/null 2>&1
rm "$DEST_PATH/"*.bin > /dev/null 2>&1
rm "$DEST_PATH/"autoheaders* > /dev/null 2>&1
rm "$DEST_PATH/"checker* > /dev/null 2>&1
rm "$DEST_PATH/".gitignore > /dev/null 2>&1

find "$DEST_PATH" -type f -name "*.h" -print0 | while IFS= read -r -d '' file; do
    echo "$(cat $file | sed -z 's#/\*[ \t]*autoheaders[ \t]*\*/##')" > $file
done

find "$DEST_PATH" -type f -name "Makefile" -print0 | while IFS= read -r -d '' file; do
    ROOT_PATH="$(dirname "$(realpath "$file")")";
    ROOT_PATH="${ROOT_PATH%/}"
    FILE_DATA="$(cat $file)"
    SRC_DIR="$(echo "$FILE_DATA" | sed -n 's#.*$(shell find $(\([A-Za-z0-9\-_]*\)) -name '"'"'\*\.c'"'"').*#\1#p')"
    SRC_PATH="$(trim "$(echo "$FILE_DATA" | sed -n 's#'"$SRC_DIR"'[ \t]*=##p')")"
    $(cd "$ROOT_PATH" && cd "$SRC_PATH" && find . -name "*.c" -type f -exec bash -c 'NAME="${1#./}"; mv "$1" "$2/${NAME//\//_}"' _ {} "$ROOT_PATH" \;)
    $(cd "$ROOT_PATH" && cd "includes" && find . -name "*.h" -type f -exec bash -c 'NAME="${1#./}"; mv "$1" "$2/${NAME//\//_}"' _ {} "$ROOT_PATH" \;)
    $(cd "$ROOT_PATH" && rm -rf "$SRC_PATH")
    $(cd "$ROOT_PATH" && rm -rf "includes")
    NEW_SRCS="$(cd "$ROOT_PATH" && find . -maxdepth 1 -name "*.c" -type f | tr '\n' ' ')"
    echo "$FILE_DATA" | sed 's#\(=[ \t]*\)includes#\1./#' | sed -z 's#\n[ \t]*SRCDIR[ \t]*=[ \t]*[A-Za-z0-9\-_]*##' | sed -z 's#\n[ \t]*OBJDIR[ \t]*=[ \t]*[A-Za-z0-9\-_]*##' | sed 's#\($(RM) -r \)$(OBJDIR)#\1*.o#' | sed 's#$(OBJDIR)/%\.o: $(SRCDIR)/%\.c#%.o: %.c#' | sed 's#$(SRCS:$(SRCDIR)/%\.c=$(OBJDIR)/%\.o)#$(SRCS:.c=.o)#' | sed 's#$(shell find $(\([A-Za-z0-9\-_]*\)) -name '"'"'\*\.c'"'"')#'"$NEW_SRCS"'#' > $file
done

find "$DEST_PATH" -type f \( -name "*.h" -o -name "*.c" \) -print0 | while IFS= read -r -d '' file; do
    echo "$(cat $file | sed 's@\(#[ \t]*include[ \t]*"\)[\.\/]*includes/\([^"]*\)"@\1./\2"@' | sed 's@\(#[ \t]*include[ \t]*"\)[\.\/]*\([A-Za-z0-9\-_]*\)/includes/\([^"]*\)"@\1./\2/\3"@')" > $file
done

echo "Done!"