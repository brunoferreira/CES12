
#include <mysortfunctions.h>

void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int min = 0;
    int n = v.size();
    std::vector<int> aux;
    aux.resize(n);
    mymergesort_recursive_aux(v, stats, min, n - 1, 0, aux);
}

void mymergesort_recursive_aux(std::vector<int> &v, SortStats &stats, int min, int max, int depth, std::vector<int> &aux) {
    stats.recursive_calls++;
    if(++depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth; 
    if(min < max) {
        int m = (min + max) / 2;
        mymergesort_recursive_aux(v, stats, min, m, depth, aux);
        mymergesort_recursive_aux(v, stats, m + 1, max, depth, aux);
        merge(v, min, m, max, aux);
    }
}

void merge(std::vector<int> &v, int min, int m, int max, std::vector<int> &aux) {
    int i1 = min;
    int i2 = min;
    int i3 = m + 1;
    while(i2 <= m && i3 <= max) {
        if (v[i2] < v[i3]) {
            aux[i1++] = v[i2++];
        }
        else {
            aux[i1++] = v[i3++];
        }
    }
    while(i2 <= m) {
        aux[i1++] = v[i2++];
    }
    while(i3 <= max) {
        aux[i1++] = v[i3++];
    }
    for(int j = min; j <= max; j++) {
        v[j] = aux[j];
    }
}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    
    int min = 0;
    int n = v.size();
    int max = n - 1;
    std::vector<int> aux;
    aux.resize(n);
    int b = 1;
    while(b < max) {
        int p = min;
        while(p + b <= max) {
            int r = std::min(max, p - 1 + 2 * b);
            int m = p + b - 1;
            merge(v, p, m, r, aux);
            p += 2*b;
        }
        b *= 2;
    }
}
    
