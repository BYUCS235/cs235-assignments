cat << EOF > lr_noD.txt
B < C
B > A
C < E

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [label=<B <br/><font point-size="10">(h:3, b:1)</font>>]
C [label=<C <br/><font point-size="10">(h:2, b:1)</font>>]
E [label=<E <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 1 lr_noD.txt
