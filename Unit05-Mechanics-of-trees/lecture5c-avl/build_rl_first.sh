cat << EOF > rl_first.txt
D < E
D > C
C > B
B > A

A [color="darkgreen" label=<A <br/><font point-size="10">(h:<font color="darkgreen">1</font>, b:<font color="darkgreen">0</font>)</font>>]
B [color="darkgreen" label=<B <br/><font point-size="10">(h:<font color="darkgreen">2</font>, b:<font color="darkgreen">-1</font>)</font>>]
C [label=<C <br/><font point-size="10">(h:3, b:<font color="red">-2</font>)</font>>]
D [label=<D <br/><font point-size="10">(h:4, b:<font color="red">-2</font>)</font>>]
E [label=<E <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 rl_first.txt
