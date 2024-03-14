cat << EOF > abd.txt
B > A
B < D
B [label=<B <br/><font point-size="10">(h:2, b:0)</font>>]
A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
D [label=<D <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 abd.txt
