#/bin/bash
make && shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $@ $(cat args.txt) | ./checker_linux $(cat args.txt)
