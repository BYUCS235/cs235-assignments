cat << EOF > efc_rebal.txt
C < E
E < F
E > D
C > B
B > A
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 efc_rebal.txt
