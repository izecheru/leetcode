#include "problems.hpp"
#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <vector>

static void BM_Atoi110000( benchmark::State& state )
{
  for ( auto _ : state )
    benchmark::DoNotOptimize( myNamespace::atoi( "110000" ) );
}

static void BM_AtoiNegative( benchmark::State& state )
{
  for ( auto _ : state )
    benchmark::DoNotOptimize( myNamespace::atoi( "-1233444" ) );
}

static void BM_OriginalAtoi110000( benchmark::State& state )
{
  for ( auto _ : state )
    benchmark::DoNotOptimize( atoi( "110000" ) );
}

static void BM_OriginalAtoiNegative( benchmark::State& state )
{
  for ( auto _ : state )
    benchmark::DoNotOptimize( atoi( "-1233444" ) );
}

BENCHMARK( BM_Atoi110000 )->Unit( benchmark::kNanosecond );
BENCHMARK( BM_AtoiNegative )->Unit( benchmark::kNanosecond );
BENCHMARK( BM_OriginalAtoi110000 )->Unit( benchmark::kNanosecond );
BENCHMARK( BM_OriginalAtoiNegative )->Unit( benchmark::kNanosecond );

BENCHMARK_MAIN();
