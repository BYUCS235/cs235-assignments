cat << EOF > imbalanced.txt
H > E
H < T
T < W
T > S
W < X
X < Y
Y < Z
W > M
M > L
M < P
P < Q

E > C
C > B
C < D
B > A
EOF
python3 ~/projects/btrees/btrees.py imbalanced.txt
