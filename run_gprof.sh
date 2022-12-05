echo "--------Compiling Profiling run--------"

export RUN_GPROF=TRUE
make || exit

echo "--------Running Profiling run--------"

valgrind --tool=callgrind ./matrix_theory_gprof

echo "--------Finnished--------"