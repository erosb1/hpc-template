#include <benchmark/benchmark.h>
#include <Eigen/Dense>

static void BM_EigenMatrixMultiplication(benchmark::State& state) {
    const int size = state.range(0);
    
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);
    Eigen::MatrixXd C(size, size);

    for (auto _ : state) {
        C.noalias() = A * B;
        
        benchmark::DoNotOptimize(C.data());
        benchmark::ClobberMemory();
    }
}

BENCHMARK(BM_EigenMatrixMultiplication)->Range(64, 512);

BENCHMARK_MAIN();
