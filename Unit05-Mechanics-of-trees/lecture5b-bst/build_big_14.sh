rm -f big_14.png
cat big.txt.dot | sed -e 's/}/  n14 -> n15 [color="red"]\n}/' | neato -Tpng > big_14.png
