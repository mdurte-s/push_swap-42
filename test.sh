#/bin/bash
make
shuf -i 0-9999 -n $1 > args.txt ; ./push_swap --bench ${@:2} $(cat args.txt) | ./checker_linux $(cat args.txt)