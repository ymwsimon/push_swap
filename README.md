# push_swap

repeat 20 {shuf -i 1-5000 -n 100 > input ; ./push_swap `< input` | ./checker `< input`}
