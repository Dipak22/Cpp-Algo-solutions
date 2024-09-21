#include <iostream>
#include <iomanip> // a C++ library that includes a collection of tools for 
           // input output manipulation, includes setw() 
using namespace std;

void print(const char msg[], int nums[], int size)
{
    cout << setw(22) << msg << " : {";
    for(int i=0; i<size; i++)
        cout << nums[i] << " ";
    cout << "}";
}

int removeAllOccurences(int nums[], int numsSize, int val)
{
    int k =0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != val){
            nums[k++] = nums[i];
        }
    }
    return k;
}
int main()
{
    int nums[] = {0,1,2,2,3,0,4,2}, val = 2, size = 8;

    print("Before Removal nums[]", nums, size);
    // Call your function here

    int k = removeAllOccurences(nums,size,val);
    size = k;
    // --------------------------------------
    print("After Removal nums[]", nums, size);
    return 0;
}










