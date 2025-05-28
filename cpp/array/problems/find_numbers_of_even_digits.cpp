#include <vector>

using namespace std;

int findNumbers(vector<int>& nums) {

    int maxNumber = 0;
    int currentNumber = 0;

    for (int num : nums){

        currentNumber = 0;

        while(num > 0){
            num /= 10;
            currentNumber++;
        };

        if(currentNumber % 2 == 0){
            maxNumber++;
        };
    }
    return maxNumber;
}