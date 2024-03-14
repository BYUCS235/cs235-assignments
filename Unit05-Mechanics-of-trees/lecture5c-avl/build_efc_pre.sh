cat << EOF > efc_pre.txt
E < F
E > C
C < D
C > B
B > A
EOF 
python3 ~/projects/btrees/btrees.py --w-scale 0.2 efc_pre.txt
