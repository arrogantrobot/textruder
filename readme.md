Textruder
===========

Textruder is a tool for extruding text through patterns. The patterns currently baked into this project are produced by a [one-dimensional cellular automaton](http://archetyp.al/cellular-automata-rule-explorer "cellular automaton"). Any input text may be used, either from a file or from stdin.

Build it
==========

git clone git@github.com:arrogantrobot/textruder.git
cd textruder
cmake .
make

done!

Use it
=========

./textruder -i subcellular_automaton.txt

or from stdin

yes | ./textruder

The default width matches the terminal. This may be overridden:

yes | ./textruder -w 20
