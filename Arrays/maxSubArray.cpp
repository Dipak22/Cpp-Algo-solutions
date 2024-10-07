#include<iostream>
using namespace std;

int maxSumArr(int num[],int size){
    int globalMax = INT_MIN;
    int currMax = INT_MIN;
    for(int i =0;i<size;i++){ 
        if(currMax<0)
            currMax = num[i];
        else
            currMax +=num[i];
        if(globalMax<currMax)
            globalMax = currMax;
    }
    return globalMax;
}

int main() {
    int inputs[][10] = {
        {1, 2, 2, 3, 3, 1, 4},
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {-4, -1, -2, -1, -2},
        {-4, 2, -5, 1, 2, 3, 6, -5, 1}, 
        {25}
    };
    int sizes[] = {7, 3, 5, 5, 9, 1};

    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        cout << i + 1 << ".\tArray: [";
        for (int j = 0; j < sizes[i]; j++) {
            cout << inputs[i][j];
            if (j != sizes[i] - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        cout << "\tMaximum Sum: " << maxSumArr(inputs[i], sizes[i]) << endl;
        cout << "-" << string(75, '-') << endl;
    }

    return 0;
}