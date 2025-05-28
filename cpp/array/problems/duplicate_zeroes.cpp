#include <vector>

using namespace std;

void insert(vector<int>& arr, const int& i, const int& j) {
    if(j < arr.size()){
        arr[j] = arr[i];
    }
}

void duplicateZeros(vector<int>& arr) {
    int zeroes = 0;
    for (int i: arr){
        if(i == 0){
            zeroes++;
        }
    }

    int i = arr.size() - 1, j = arr.size() + zeroes - 1;
    while(i != j){
        insert(arr, i, j--);
        if(arr[i] == 0){
            insert(arr, i, j--);
        }
        i--;
    };
};


