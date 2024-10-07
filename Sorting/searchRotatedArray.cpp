#include<iostream>
using namespace std;

int searchRotatedArray(int* arr, int left, int right, int k){
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[left]<= arr[mid]){
            if(k>=arr[left] && k<arr[mid])
                right = mid-1;
            else
                left = mid+1;
       }
       else{
        if(k>arr[mid] && k<=arr[right])
            left = mid+1;
        else
            right = mid -1;
       }
    }
    return -1;
}
int main() {
  int arr[] = {40,100,-100,-40,0,24,40};
  cout << searchRotatedArray(arr, 0, 6, -40) << endl;
}