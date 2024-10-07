#include<iostream>
#include<vector>
using namespace std;

void printVector(std::vector<int> nums){
    for(size_t i =0;i<nums.size();i++)
        std::cout<<nums[i]<<" ";
}

std::vector<int> RearrangeArray(std::vector<int> nums){
    int size = nums.size();
    int mid = nums.size()/2;
    std::vector<int> result;
    for(size_t i =0;i<mid;i++){
        result.push_back(nums[size-(i+1)]);
        result.push_back(nums[i]);
    }
    if(nums.size()%2==1)
        result.push_back(nums[mid]);
    return result;
}

int main() {
    std::vector<std::vector<int>> inputArray = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {11, 22, 33, 44, 55, 66, 77, 88},
        {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024},
        {3, 3, 5, 5, 7, 7, 9, 9, 11, 11, 13, 13},
        {100, 233, 544, 753, 864, 935, 1933, 2342}
    };

    for (size_t i = 0; i < inputArray.size(); ++i) {
        std::cout << i + 1 << ".\tOriginal array: ";
        printVector(inputArray[i]);
        std::cout << "\n\tRearranged array: ";
        std::vector<int> rearranged = RearrangeArray(inputArray[i]);
        printVector(rearranged);
        std::cout << "\n" << std::string(100, '-') << std::endl;
    }

    return 0;
}