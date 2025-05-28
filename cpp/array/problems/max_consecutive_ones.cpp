#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int currentMax = 0;
    int generalMax = 0;
    for (int num : nums){
        if (num == 1){
            currentMax++;
            generalMax = std::max(currentMax, generalMax);
        }
        else{
            currentMax = 0;
        }
    };
    return generalMax;
}