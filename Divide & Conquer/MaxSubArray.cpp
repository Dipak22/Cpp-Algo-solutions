#include<iostream>
using namespace std;
int maxSumArr(int* arr, int n){
    int max =INT_MIN;
    int currMax = 0;
    for(int i =0;i<n;i++){
        currMax +=arr[i];
        if(arr[i]>currMax){
            currMax = arr[i];
        }
        if(currMax>max)
            max = currMax;
    }
    return max;
}


int main() { 
   int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int arrSize = sizeof(arr)/sizeof(arr[0]); 
   int maxSum = maxSumArr(arr, arrSize); 
   cout << "Maximum contiguous sum is " << maxSum; 
   return 0; 
} 