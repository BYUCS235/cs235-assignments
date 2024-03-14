cat << EOF > lr_second.txt
B < D
B > A
D > C
D < E

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [label=<B <br/><font point-size="10">(h:<font color="darkgreen">3</font>, b:<font color="darkgreen">1</font>)</font>>]
C [color="darkgreen" label=<C <br/><font point-size="10">(h:<font color="darkgreen">1</font>, b:<font color="darkgreen">0</font>)</font>>]
D [color="darkgreen" label=<D <br/><font point-size="10">(h:<font color="darkgreen">2</font>, b:<font color="darkgreen">0</font>)</font>>]
E [color="darkgreen" label=<E <br/><font point-size="10">(h:<font color="darkgreen">1</font>, b:<font color="darkgreen">0</font>)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 1 lr_second.txt
