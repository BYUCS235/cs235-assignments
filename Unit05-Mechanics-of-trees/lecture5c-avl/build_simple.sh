cat << EOF > simple.txt
Z > Y
Y > X

Z [label=<Z <br/><font point-size="10">(h:3, b:<font color="red">-2</font>)</font>>]
Y [label=<Y <br/><font point-size="10">(h:2, b:-1)</font>>]
X [label=<X <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 simple.txt
