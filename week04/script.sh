#!/bin/bash

x=1
while [ $x -le 10 ]
do
  ./a.out
  x=$(( $x + 1 ))
done
