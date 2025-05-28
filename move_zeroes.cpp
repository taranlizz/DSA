#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        // Iterate through the array using two pointers:
        // 'right' - scans every element of the array
        // 'left' - points to the position where next non-zero element should be
        // placed
        for (int right = 0, left = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                // Only swap if the current non-zero element is not already in the correct position
                if (left != right) {
                    swap(nums[left], nums[right]);
                }
                // Move left to the next position where non-zero element should be placed
                left++;
            }
        }
    }