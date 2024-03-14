cat << EOF > big.txt
10 > 6
6 > 3
3 > 1
3 < 4
4 < 5
1 < 2
1 > 0
    
6 < 8
8 > 7
    
10 < 15
15 > 12
12 < 14
14 > 13

15 < 18
18 > 17
17 > 16
18 < 19
EOF
python3 ~/projects/btrees/btrees.py big.txt
