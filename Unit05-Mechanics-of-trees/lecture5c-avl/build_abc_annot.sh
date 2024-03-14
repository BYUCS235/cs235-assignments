cat << EOF > abc_annot.txt
A < B
B < C

A [label=<A <br/><font point-size="10">(h:3, b:2)</font>>]
B [label=<B <br/><font point-size="10">(h:2, b:1)</font>>]
C [label=<C <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 abc_annot.txt
