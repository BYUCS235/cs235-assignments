cat << EOF > simple_rebal.txt
Y > X
Y < Z

Z [label=<Z <br/><font point-size="10">(h:<font color="darkgreen">1</font>, b:<font color="darkgreen">0</font>)</font>>]
Y [label=<Y <br/><font point-size="10">(h:2, b:<font color="darkgreen">0</font>)</font>>]
X [label=<X <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 simple_rebal.txt
