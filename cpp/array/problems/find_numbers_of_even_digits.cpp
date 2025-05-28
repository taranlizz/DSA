#include <vector>

using namespace std;

int findNumbers(vector<int>& nums) {
    //Initialise variables to track
    int totalWithEvenDigits = 0;
    int currentNumberOfDigits = 0;

    for (int num : nums){

        currentNumberOfDigits = 0;

        while(num > 0){
            num /= 10;
            currentNumberOfDigits++;
        };

        if(currentNumberOfDigits % 2 == 0){
            totalWithEvenDigits++;
        };
    }
    return totalWithEvenDigits;
}