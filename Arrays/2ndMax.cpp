#include<iostream>
using namespace std;
int FindSecondMaximum(int nums[],int size){
    int max = INT_MIN;
    int secondMax = INT_MIN;
    for(int i=0;i<size;i++){
        if(nums[i]>max){
            secondMax = max;
            max = nums[i];
        }else if(nums[i] != max && nums[i]>secondMax)
            secondMax = nums[i];
    }
    return secondMax;
}
int main() {
    int inputs[][10] = {
        {9, 2, 3, 6},
        {1, 2},
        {-2, 2},
        {-4, -1, -9, 1, -7},
        {25, 50, 75, 100, 100},
    };
    int sizes[] = {4, 2, 2, 5, 5};

    for (int i = 0; i < sizeof(inputs)/sizeof(inputs[0]); i++) {
        cout << i+1 << "\tArray: [";
        for (int j = 0; j < sizes[i]; j++)
            cout << inputs[i][j] << (j == sizes[i] - 1 ? "" : ", "); // Print comma except for the last element
        cout << "]" << endl;

        int secMax = FindSecondMaximum(inputs[i], sizes[i]);
        cout << "\tSecond maximum value: " << secMax << endl;
        cout << string(100, '-') << endl; // Print a line of dashes
    }

    return 0;
}