cat << EOF > test.txt
5 > 3
3 > 2
3 < 4
2 > 1
5 < 7
7 > 6
7 < 9
9 > 8
EOF
python3 ~/projects/btrees/btrees.py test.txt
