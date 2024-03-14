cat << EOF > abdcef.txt
B > A
B < D
B [label=<B <br/><font point-size="10">(h:<font color="green">4</font>, b:<font color="red">2</font>)</font>>]
A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
D [label=<D <br/><font point-size="10">(h:<font color="green">3</font>, b:<font color="green">1</font>)</font>>]

D > C
D < E
C [label=<C <br/><font point-size="10">(h:1, b:0)</font>>]
E [label=<E <br/><font point-size="10">(h:<font color="green">2</font>, b:<font color="green">1</font>)</font>>]

E < F
F [label=<F <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 abdcef.txt
