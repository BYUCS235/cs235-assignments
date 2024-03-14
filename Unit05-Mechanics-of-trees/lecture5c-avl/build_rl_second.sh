cat << EOF > rl_second.txt
D < E
D > B
B > A
B < C

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [color="darkgreen" label=<B <br/><font point-size="10">(h:2, b:<font color="darkgreen">0</font>)</font>>]
C [color="darkgreen" label=<C <br/><font point-size="10">(h:<font color="darkgreen">1</font>, b:<font color="darkgreen">0</font>)</font>>]
D [label=<D <br/><font point-size="10">(h:<font color="darkgreen">3</font>, b:<font color="darkgreen">-1</font>)</font>>]
E [label=<E <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 1 rl_second.txt
