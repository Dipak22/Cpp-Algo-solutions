#include<iostream>
#include<string>
using namespace std;

int* rightRotate(int nums[],int size , int k){
    k = k%size;
    int* result = new int[size];
    for(int i =0; i<size;i++)
        result[(i+k)%size] = nums[i];
    return result;
}

void rightRotateV2(int nums[],int size , int k){
    int newVal =nums[0];
    int index = 0;
    for(int i =0;i<size;i++){
        index = (index+k)%size;
        int temp = nums[index];
        nums[index] = newVal;
        newVal = temp;
        //i = index;

    }
    for(int i =0;i<size;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main() {
    int inputs[][10] = {
        {10, 20, 30, 40, 50},
        {1, -2, 3, 4, 5},
        {-1, 90, -90, 4, 6},
        {3, 6, 9, -12},
        {-100, -200, -300}
    };
    int sizes[] = {5, 5, 5, 4, 3};

    int k[] = {3, 2, 6, 2, 1};

    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        cout << i + 1 << ".\tArray: [";
        for (int j = 0; j < sizes[i]; j++) {
            cout << inputs[i][j];
            if (j != sizes[i] - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        //int* result = rightRotate(inputs[i], sizes[i], k[i]);
        rightRotateV2(inputs[i], sizes[i], k[i]);
        

        // Free memory allocated for the product array
        //delete[] result;
    }

    return 0;
}
