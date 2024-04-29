cat << EOF > rl_annot.txt
D < E
D > C
C > A
A < B

A [label=<A <br/><font point-size="10">(h:<font color="darkgreen">2</font>, b:<font color="darkgreen">1</font>)</font>>]
B [label=<B <br/><font point-size="10">(h:1, b:0)</font>>]
C [label=<C <br/><font point-size="10">(h:<font color="darkgreen">3</font>, b:<font color="red">-2</font>)</font>>]
D [label=<D <br/><font point-size="10">(h:<font color="darkgreen">4</font>, b:<font color="red">-2</font>)</font>>]
E [label=<E <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 rl_annot.txt
