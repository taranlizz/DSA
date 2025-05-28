#include <iostream>
#include <vector>

//Given an array of integers n and a positive number k, find the maximum sum of any contiguous subarray of size k.
int subarray_sum_of_k(const std::vector<int>& n, const int k){
     int window_sum = 0;
     int max_sum = 0;

     for(size_t i = 0; i < k; i++){
       window_sum += n[i];
     }

     max_sum = window_sum;
     for(size_t i = k; i < n.size(); i++){
       window_sum += n[i] - n[i - k];
       max_sum = std::max(window_sum, max_sum);
     }
     return max_sum;
};
