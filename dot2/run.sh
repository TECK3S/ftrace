#!/bin/sh

rm -rf graph.dot;
make re;
make clean;
./graph;
chmod +x graph.dot;
dot -Tpng graph.dot -o graph.png;
cat graph.dot;