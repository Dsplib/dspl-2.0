#!/bin/bash
rm -f verification.log
make clean
make
cd verif/bin/
for file in *.exe
do
    "./$file"
done

cd octave/

for file in *.m
do
    octave "$file"
done

cd ../../../

