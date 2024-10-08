#include<iostream>
using namespace std;
int calcFreq(int* arr,int size, int k){
    int start = 0;
    int end = size-1;
    int result1 = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == k){
            result1 = mid;
            end = mid-1;
        }
        else if(arr[mid]>k)
            end = mid -1;
        else
            start = mid+1;
    }
    start = 0;
    end = size-1;
    int result2 = -1;
    if(result1 ==-1)
        return 0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == k){
            result2 = mid;
            start = mid+1;
        }
        else if(arr[mid]>k)
            end = mid -1;
        else
            start = mid+1;
    }
    return result2 - result1 + 1;
}
int main() {
  int arr[] = {-5,-3,0,1,3,4,5};
  cout << calcFreq(arr, 7, 19) << endl;
}