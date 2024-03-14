cat << EOF > big_no17.txt
10 > 6
6 > 3
3 > 1
3 < 4
4 < 5
1 < 2
1 > 0
    
6 < 8
8 > 7
    
10 < 14
14 > 12
12 < 13

14 < 18
18 > 16
18 < 19
EOF
python3 ~/projects/btrees/btrees.py big_no17.txt
