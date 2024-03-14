cat << EOF > big_no6.txt
10 > 5
5 > 3
3 > 1
3 < 4
1 < 2
1 > 0
    
5 < 8
8 > 7
    
10 < 14
14 > 12
12 < 13

14 < 18
18 > 17
17 > 16
18 < 19
EOF
python3 ~/projects/btrees/btrees.py big_no6.txt
