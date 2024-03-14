cat << EOF > abc.txt
A < B
B < C
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 abc.txt
