#include <benchmark/benchmark.h>

#include "src/matrix.cpp"
#include "src/hermite.cpp"

void BM_MatrixHNF(benchmark::State& state){
    
    for(auto _ : state){
        state.PauseTiming();
        Matrix test(state.range(0), state.range(0));
        state.ResumeTiming();
        test.hermite();
    } 
}

BENCHMARK(BM_MatrixHNF)->DenseRange(1, 64, 1)
                        ->Unit(benchmark::kNanosecond);

BENCHMARK_MAIN();