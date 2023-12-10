# push_swap

repeat 20 {shuf -i 1-5000 -n 500 > input ; ./push_swap `< input` | ./checker `< input`}
