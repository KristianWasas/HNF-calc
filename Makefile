CC = g++
CC_FLAGS = -O3 -Werror -Wall -pedantic -std=c++17 -march=native -fopenmp

BENCHMARK_INSTALL_PATH = "/home/kristian/koulu/MatrixTheoryProject/benchmark"
BENCHMARK_INCLUDE_PATH = $(BENCHMARK_INSTALL_PATH)/include
BENCHMARK_LIBRARY_PATH = $(BENCHMARK_INSTALL_PATH)/build/src
BENCHMARK_LIBRARY_PATH1 = $(BENCHMARK_INSTALL_PATH)/build/lib

ifeq ($(RUN_GPROF), TRUE)
all: matrix_theory_gprof

matrix_theory_gprof: matrix_theory_gprof.cpp
	$(CC) $(CC_FLAGS) -g -fno-inline-functions -fno-inline-functions-called-once -fno-default-inline -fno-inline \
	-I$(BENCHMARK_INCLUDE_PATH) \
	-L$(BENCHMARK_LIBRARY_PATH) \
	-L$(BENCHMARK_LIBRARY_PATH1) \
	-o matrix_theory_gprof matrix_theory_gprof.cpp \
	-lbenchmark
	
clean:
	rm -vf matrix_theory_gprof

.PHONEY: clean
else
ifeq ($(RUN_TEST), FALSE)
all: matrix_theory_sandbox

matrix_theory_sandbox: matrix_theory_sandbox.cpp
	$(CC) $(CC_FLAGS) \
	-I$(BENCHMARK_INCLUDE_PATH) \
	-L$(BENCHMARK_LIBRARY_PATH) \
	-L$(BENCHMARK_LIBRARY_PATH1) \
	-o matrix_theory_sandbox matrix_theory_sandbox.cpp \
	-lbenchmark
	
clean:
	rm -vf matrix_theory_sandbox

.PHONEY: clean
else
all: matrix_theory_test

matrix_theory_test: matrix_theory_test.cpp
	$(CC) $(CC_FLAGS) \
	-I$(BENCHMARK_INCLUDE_PATH) \
	-L$(BENCHMARK_LIBRARY_PATH) \
	-o matrix_theory_test matrix_theory_test.cpp \
	-lbenchmark
	
clean:
	rm -vf matrix_theory_test

.PHONEY: clean
endif
endif