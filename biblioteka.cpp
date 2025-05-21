#include "biblioteka.h"
#include <vector>
#include <random>
#include <chrono>
#include <omp.h>
#include <algorithm>
#include <thread>
#include <climits>

static std::vector<int> data;
static int num_threads = 1;
static double last_duration = 0.0;
static int max_sum_result = 0;

extern "C" {

void biblioteka_set_cpu_usage(int percent) {
    int hw_threads = std::thread::hardware_concurrency();
    num_threads = std::max(1, hw_threads * percent / 100);
    omp_set_num_threads(num_threads);
}

void biblioteka_init_data(int n, int seed) {
    data.resize(n);
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(-1000, 1000);
    for (int &x : data) x = dist(rng);
}

int parallel_max_subarray_sum() {
    int n = data.size();
    int chunk = (n + num_threads - 1) / num_threads;
    std::vector<int> local_max(num_threads, INT_MIN);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int start = tid * chunk;
        int end = std::min(start + chunk, n);

        int max_sum = INT_MIN, curr_sum = 0;
        for (int i = start; i < end; ++i) {
            curr_sum = std::max(data[i], curr_sum + data[i]);
            max_sum = std::max(max_sum, curr_sum);
        }
        local_max[tid] = max_sum;
    }
    return *std::max_element(local_max.begin(), local_max.end());
}

void biblioteka_compute() {
    auto t1 = std::chrono::high_resolution_clock::now();
    max_sum_result = parallel_max_subarray_sum();
    auto t2 = std::chrono::high_resolution_clock::now();
    last_duration = std::chrono::duration<double>(t2 - t1).count();
}

double biblioteka_get_last_duration() { return last_duration; }
int biblioteka_get_max_sum_result() { return max_sum_result; }
int biblioteka_get_num_threads() { return num_threads; }

} // extern "C"