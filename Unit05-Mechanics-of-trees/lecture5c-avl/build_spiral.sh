cat << EOF > spiral.txt
1 < 7
7 > 2
2 < 6
6 > 3
3 < 5
5 > 4
EOF
python3 ~/projects/btrees/btrees.py spiral.txt
