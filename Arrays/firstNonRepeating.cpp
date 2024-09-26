#include <iostream>
#include <string>
#include<algorithm>

int findFirstUnique(int nums[], int size) {
    for(int i=0;i<size;i++){
        int j =0;
        for(;j<size;j++){
            if(i !=j && nums[i] == nums[j])
                break;
        }
        if(j==size)
            return nums[i];
    }
}

int main() {
    int inputs[][6] = {
        {9, 2, 3, 2, 6, 6},
        {-5, -4, -4, 6, -1, 0},
        {-1, 2, -1, -4, -10, 2},
        {1, 1, 2, 9, 5, 5},
        {-2, 2, -2, 2, 5, -3}
    };

    int rows = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < rows; ++i) {
        int cols = sizeof(inputs[i]) / sizeof(inputs[i][0]);
        
        std::cout << i + 1 << ".\tInput list: ";
        for (int j = 0; j < cols; ++j) {
            std::cout << inputs[i][j] << " ";
        }
        std::cout << std::endl;

        std::cout << "\tFirst unique number: " << findFirstUnique(inputs[i], cols) << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }

    return 0;
}