#include<iostream>
using namespace std;

int* DutchNationalFlag(int* arr, int size){
    int i = 0;
    int left = 0;
    int right = size-1;
    while(i<=right){
        if(arr[i] ==2){
            swap(arr[i],arr[right]);
            right--;
        }
        else if(arr[i]==0){
            swap(arr[i], arr[left]);
            left++;
            i++;
        }
        else
            i++;
    }
    return arr;
}

int main() {
  int size = 6;
  int arr[size] = {2, 0, 0, 1, 2, 1};
  int * sortedArray = DutchNationalFlag(arr, size);

  for (int i = 0; i < size; i++) {
    cout << sortedArray[i] << " ";
  }
  return 0;
}