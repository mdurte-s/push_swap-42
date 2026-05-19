#/bin/bash
NUMS=$1
shift
make
shuf -i 0-9999 -n $NUMS > args.txt ; ./push_swap --bench $@ $(cat args.txt) | ./checker_linux $(cat args.txt)
