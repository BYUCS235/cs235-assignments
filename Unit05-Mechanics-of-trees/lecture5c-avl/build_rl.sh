cat << EOF > rl.txt
D < E
D > C
C > A

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
C [label=<C <br/><font point-size="10">(h:2, b:-1)</font>>]
D [label=<D <br/><font point-size="10">(h:3, b:-1)</font>>]
E [label=<E <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 rl.txt
