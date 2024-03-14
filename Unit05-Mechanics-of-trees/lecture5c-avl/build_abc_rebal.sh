cat << EOF > abc_rebal.txt
B > A
B < C

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [label=<B <br/><font point-size="10">(h:2, b:0)</font>>]
C [label=<C <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 abc_rebal.txt
