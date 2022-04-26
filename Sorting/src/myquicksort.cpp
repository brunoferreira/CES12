
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int min = 0;
    int max = v.size() - 1;
    myquicksort_2recursion_medianOf3_aux(v, min, max, stats, 0);

}// function myquicksort_2recursion_medianOf3

void myquicksort_2recursion_medianOf3_aux(std::vector<int> &v, int min, int max, SortStats &stats, int depth) {
    stats.recursive_calls++;
    if(++depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth; 
    if(min < max) {
        int pivot_index = partition(v, min, max);
        myquicksort_2recursion_medianOf3_aux(v, min, pivot_index - 1, stats, depth);
        myquicksort_2recursion_medianOf3_aux(v, pivot_index + 1, max, stats, depth);
    }
}

int partition(std::vector<int> &v, int left, int right) {
    int pivot = medianOf3(v, left, right);
    int l = left + 1;
    int r = right;
    while(true) {
        while (l < right && v[l] < pivot) l++;
        while (r > left && v[r] > pivot) r--;
        if (l >= r) break;
        swap(v[l], v[r]);
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}

int medianOf3(std::vector<int> &v, int left, int right) {
    int a = v[left];
    int b = v[right];
    int c = v[(right+left)/2];
    int median = std::max(std::min(a, b), std::min(std::max(a,b), c));
    if(b == median) {
        v[left] = b;
        v[right] = a;
    }
    else if (c == median) {
        v[left] = c;
        v[(right+left)/2] = a;
    }
    return median;
}

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int min = 0;
    int max = v.size() - 1;
    myquicksort_1recursion_medianOf3_aux(v, stats, min, max, 0);
} // function myquicksort_1recursion_medianOf3

void myquicksort_1recursion_medianOf3_aux(std::vector<int> &v, SortStats &stats, int min, int max, int depth) {
    stats.recursive_calls++;
    if(++depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth;
    while(min < max) {
        int p = partition(v, min, max);
        if(p - min < max - p) {
            myquicksort_1recursion_medianOf3_aux(v, stats, min, p - 1, depth);
            min = p + 1;
        }
        else {
            myquicksort_1recursion_medianOf3_aux(v, stats, p + 1, max, depth);
            max = p - 1;
        }
    }
}

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int min = 0;
    int max = v.size() - 1;
    myquicksort_fixedPivot_aux(v, min, max, stats, 0);
} // myquicksort_fixedPivot

void myquicksort_fixedPivot_aux(std::vector<int> &v, int min, int max, SortStats &stats, int depth) {
    stats.recursive_calls++;
    if(++depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth; 
    if(min < max) {
        int pivot_index = partition_fixed_pivot(v, min, max);
        myquicksort_fixedPivot_aux(v, min, pivot_index - 1, stats, depth);
        myquicksort_fixedPivot_aux(v, pivot_index + 1, max, stats, depth);
    }
}

int partition_fixed_pivot(std::vector<int> &v, int left, int right) {
    int pivot = v[left];
    int l = left + 1;
    int r = right;
    while(true) {
        while (l < right && v[l] < pivot) l++;
        while (r > left && v[r] > pivot) r--;
        if (l >= r) break;
        swap(v[l], v[r]);
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}
