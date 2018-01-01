#!/bin/bash
rm -f verification.log
make clean
make
cd doc/ru/html
rm -f !("*.gitignore")
cd ../../../
doxygen doxyfile_ru



