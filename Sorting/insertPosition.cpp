#include<iostream>
using namespace std;

int insertPosition(int* arr, int size, int k){
    int start =0;
    int end = size -1;
    int pos = -1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid]> k){
            end = mid -1;
            pos  = mid;
        }
        else{
            pos = mid;
            start = mid+1;
        }
    }
    return pos;
}

int main() {
  int arr[] = {1,3,5,6};
  int s = 5;
  int arrSize = 4;
  cout << insertPosition(arr, arrSize, s) << endl;
  s = 2;
  cout << insertPosition(arr, arrSize, s) << endl;
}