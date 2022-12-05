echo "--------Compiling Timer tests--------"

export RUN_TEST=TRUE
export RUN_GPROF=FALSE
make || exit

echo "--------Running Timer Tests--------"

./matrix_theory_test

echo "--------Finnished--------"