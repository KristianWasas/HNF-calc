echo "--------Compiling Sandbox--------"

export RUN_TEST=FALSE
export RUN_GPROF=FALSE
make || exit

echo "--------Running Sandbox--------"

./matrix_theory_sandbox

echo "--------Finnished--------"