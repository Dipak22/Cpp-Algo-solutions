#include<iostream>
#include<algorithm>
int* FindSumV1(int nums[],int k ,int size){
    int* result = new int[2];
    for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if(nums[i]+nums[j] == k){
                result[0] = nums[i];
                result[1] = nums[j];
                return result;
            }
        }
    }
    delete[] result;
    return nullptr; 
}

int* FindSumV2(int nums[],int k ,int size){
    int* result = new int[2];
    std::sort(nums,nums+size);
    int left = 0;
    int right = size-1;
    while(left<right){
        if(nums[left]+ nums[right] == k){
            result[0] = nums[left];
            result[1] = nums[right];
            return result;
        }else if(nums[left]+ nums[right]>k)
            right --;
        else
            left++;
    }

    delete[] result;
    return nullptr; 
}


int main(){
    int inputs[][10] = {
        {1, 2, 3, 4},
        {1, 2},
        {2, 2},
        {-4, -1, -9, 1, -7},
        {25, 50, 75, 100, 400}
    };

    int sizes[5] = {4, 2, 2, 5, 5};
    int k[5] = {5, 3, 4, -3, 425};

    for (int i = 0; i < 5; i++) {
        std::cout << (i + 1) << "\tArray: [";
        for (int j = 0; j < sizes[i]; j++) {
            std::cout << inputs[i][j];
            if (j < sizes[i] - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        //int* nums2 = FindSumV1(inputs[i], k[i], sizes[i]); 
        int* nums2 = FindSumV2(inputs[i], k[i], sizes[i]); 
        if(nums2 == nullptr){
            std::cout<<"\nNo such elements\n";
        }else{
            int num1 = nums2[0];
            int num2 = nums2[1];
            std::cout << "\n\tk: " << k[i] << std::endl;
            std::cout << "\n\tResult: [" << num1 <<", " << num2 << "]" <<std::endl;
            
            std::cout << std::string(100, '-') << std::endl;
            delete[] nums2; // Free memory after use
        }
        
        
    }

    return 0;
}