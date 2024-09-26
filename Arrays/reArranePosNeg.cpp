#include<iostream>

void Rearrange(int nums[], int size){
    int left = 0;
    for(int i =0;i<size;i++){
        if(nums[i]<0){
            if(i != left){
                std::swap(nums[i],nums[left]);
            }
            left++;
        }
    }
}
int main() {
    int inputs[][5] = {{10, 4, 6, 23, 7},
                       {-3, 20, -1, 8},
                       {2, -5, -4, 43, 2},
                       {-3, -10, -19, 21, -17},
                       {25, 50, 75, -100, 400}};
    int sizes[] = {5, 4, 5, 5, 5};

    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i) {
        std::cout << i + 1 << ".\tArray: [";
        for (int j = 0; j < sizes[i]; j++) {
            std::cout << inputs[i][j] << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << "\tResult: [";
        Rearrange(inputs[i], sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            std::cout << inputs[i][j] << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << "\n";
        std::cout << std::string(100, '-') << std::endl;
    }

}