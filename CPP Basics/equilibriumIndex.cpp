#include <iomanip>
#include <iostream>
using namespace std;

int equilibriumIndex(int nums[], int numsSize)
{
    //write your code here
    int sum = 0;
    for(int i =0;i<numsSize;i++)
        sum +=nums[i];
    int curr_sum = 0;
    for(int i =0;i<numsSize;i++){
        if(curr_sum == (sum-curr_sum-nums[i]))
            return i;
        curr_sum += nums[i];
    }
    -1;
    
}
void print(const char msg[], int nums[], int size)
{
    cout << setw(22) << msg << " : {";
    for(int i=0; i<size; i++)
        cout << nums[i] << " ";
    cout << "}";
}
int main()
{
    int nums[] = {7,-1,-5,2,4,-3,0}, size = 7;

    print("Before Removal nums[]", nums, size);
    
    size = equilibriumIndex(nums, size);

    print("After Removal nums[]", nums, size);
}

