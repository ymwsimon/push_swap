# push_swap

repeat 20 {shuf -i 1-5000 -n 500 > input ; ./push_swap `< input` | ./checker `< input`}
python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`