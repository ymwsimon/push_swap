# push_swap

repeat 20 {shuf -i 1-5000 -n 500 > input ; ./push_swap `< input` | ./checker `< input`}
python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

for i in (seq 1 20); set ARGS (shuf -i 1-5000 -n 500); ./push_swap $ARGS | wc -l; end;
for i in (seq 1 20); set ARGS (shuf -i 1-5000 -n 500); ./push_swap $ARGS | ./checker_linux $ARGS; end;

for i in (seq 1 20); set ARGS (seq -5000 5000 | shuf -n 500); ./push_swap $ARGS | ./checker_linux $ARGS; end;

for i in (seq 1 5); set ARGS (seq -5000 5000 | shuf -n 3); ./push_swap $ARGS | wc -l; ./push_swap $ARGS | ./checker_linux $ARGS; echo "------"; end;