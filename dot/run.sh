#!/bin/sh

rm -rf graph.dot;
make re;
make clean;
./graph;
chmod +x graph.dot;
cat graph.dot;
rm -rf graph.dot;