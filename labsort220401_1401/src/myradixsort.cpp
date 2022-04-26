
#include <mysortfunctions.h>
#include <cmath>
#include <queue>

void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int n = v.size();
    int n_bits = std::ceil(std::log(n))/4;
    int base = 16;
    int bits_base = 4;
    std::queue<int> q[base];
    for(int i = 0, factor = 1; i < n_bits; factor *= base, i++) {
        for(int j = 0; j < n; j++) {
            int index = (v[j] & (base - 1)*factor) >> (bits_base * i);
            q[index].push(v[j]);
        }
        for(int j = 0, k = 0; j < base; j++) {
            while(!q[j].empty()) {
                v[k++] = q[j].front();
                q[j].pop();
            }
        }
    }
}
