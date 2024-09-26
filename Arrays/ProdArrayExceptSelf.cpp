#include<iostream>
using namespace std;

int* findProductV1(int nums[], int size){
    int* result = new int[size];
    int left = 1;
    for(int i=0;i<size;i++){
        int currProduct = 1;
        for(int j = i+1;j<size;j++){
            currProduct *= nums[j];

        }
        currProduct *=left;
        left *=nums[i];
        result[i] = currProduct;
    }
    return result;
}

int* findProductv2(int nums[], int size){
    int* result = new int[size];
    int left = 1;
    for(int i=0;i<size;i++){
        result[i] = left;
        left *=nums[i];
    }
    int right = 1;
    for(int i=size-1;i>=0;i--){
        result[i] *=right;
        right *=nums[i];
    }

    return result;
}

int main() {
    int inputs[][10] = {
        {1, 2, 3, 4},
        {5, -3, 1, 2},
        {2, 2, 2, 0},
        {0, 0, 0, 0},
        {-1, -2, -4}
    };
    int sizes[] = {4, 4, 4, 4, 3};

    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        cout << i + 1 << ".\tArray: [";
        for (int j = 0; j < sizes[i]; j++) {
            cout << inputs[i][j];
            if (j != sizes[i] - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        //int* result = findProductV1(inputs[i], sizes[i]);
        int* result = findProductv2(inputs[i], sizes[i]);
        cout << "\n\tList of products: [";
        for (int k = 0; k < sizes[i]; k++) {
            
            cout << result[k];
            if (k != sizes[i] - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        cout << "-" << string(70, '-') << endl;

        // Free memory allocated for the product array
        delete[] result; 
    }

    return 0;

}