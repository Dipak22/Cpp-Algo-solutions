#include<iostream>
using namespace std;

//Brute force
/* int findPeak(int* arr,int n){
    if(n<1)
        return -1;
    int peak = -1;

    for(int i =1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            return i;
    }

    if(arr[0]>arr[1])
        return 0;
    if(arr[n-1]>arr[n-2]);
        return n-1;
} */

//Divide & Conquer
int findPeakRec(int* arr,int left,int right, int n){
    int mid = left + (right-left)/2;
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
        return mid;
    else if(arr[mid]>0 && arr[mid-1]>=arr[mid])
        return findPeakRec(arr,left,mid-1,n);
    else
        return findPeakRec(arr,mid+1,right,n);
}
int findPeak(int *arr, int n){
    return findPeakRec(arr,0, n-1,n);
}


int main() {
  int arr[] = {7,11,22,13,4,0};
  int x = sizeof(arr);
  int y = sizeof(arr[0]);
  int arrSize = x / y;
  cout << "One peak point index is: " << findPeak(arr, arrSize) << endl;
}