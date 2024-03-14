rm -f big_6.png
cat big.txt.dot | sed -e 's/}/  n5 -> n6 [color="red"]\n}/' | neato -Tpng > big_6.png
