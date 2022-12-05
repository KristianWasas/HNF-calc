Program for calculating hermite form of integer matricies

NOTE, no integer overflow guard, so results are wrong/undefined for too large matrices or too large elements.

For elements -10 < x < 10 5x5 matrix is still fine* most of the time

For elements -2 < x < 2 20x20 matrix is fine*. 

*Tested couple of times, no guarantees

Three programs, test, profiling and sandbox

Test runs timers for int matricies

Grpof runs profiling over hermite calculations on 64x64 matrices.

Run "./gprof2dot.py -f callgrind callgrind.out.<pid> | dot -Tsvg -o output.svg" after running gprof script, as 
to produce a picture of the profiling. Note that eventhough named gprof, runs callgrind not gprof

Sandbox allows user to generate random integer matricies of desired size with elements between desired range, and calculate the hermite form

Sandbox has commands
    
    -"q"  which quits the program
    
    -"r <rows> <columns>" were rows and colums are > 0 integers. Generates random integer matrix of size rowsxcolums and prints it to std out
    
    -"s <range>" were range is > 1. And then the elements are from range -range to +range. 
    
    -"h" calculates and displays hermite form of most recent matrix.
    
    -"f <format>" changes matrix print format. Options are "r" for human readable, "m" for matlab format, "w" for wolfram alpha format
    
    -ALL commands are whitespace and case sensitive

./run_sandbox.sh
    
./run_test.sh
    
./run_grpof.sh

Respectfully to run programs. Requires g++, valgrind, graphivz, python3 and make in path. Linux OS.

Tested on "g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0" and "GNU Make 4.2.1" and "valgrind-3.15.0"
