#include<iostream>
#define n 4
using namespace std;

void sortAndMerge(int left,int right,int* result){
    int leftIndex = left*n;
    int rightIndex = ((left+right)/2 +1)*n;

    int leftSize = ((left+right)/2 -left +1)*n;
    int rightSize = (right - (left+right)/2)*n;
    int leftArr[leftSize];
    int rightArr[rightSize];
    for(int i =0;i<leftSize;i++)
        leftArr[i] = result[leftIndex+i];
    for(int i=0;i<rightSize;i++)
        rightArr[i] = result[rightIndex+i];
    int leftCurr = 0;
    int rightCurr = 0;
    int currIndex = leftIndex;
    while(leftCurr + rightCurr < leftSize + rightSize){
        if(rightCurr == rightSize || (leftCurr != leftSize && leftArr[leftCurr]<rightArr[rightCurr]))
        {
            result[currIndex] = leftArr[leftCurr]; leftCurr++; currIndex++;
        }
        else{
            result[currIndex] = rightArr[rightCurr]; rightCurr++; currIndex++;
        }
            
    }
}

void mergeSortedRecursive(int arr[][n], int left, int right,int* result){
    if(left>right)
        return;
    if(left == right){
        for(int i =0;i<n;i++)
            result[left*n+i] = arr[left][i];
        return;
    }
    mergeSortedRecursive(arr,left,(left+right)/2,result);
    mergeSortedRecursive(arr,(left+right)/2+1,right,result);
    sortAndMerge(left,right,result);
}

void mergeSortedArrays(int arr[][n], int k,int *result){
    mergeSortedRecursive(arr,0,k-1,result);
}


int main() { 
	// 2D input array 
	int arr[][n] = {{ 16, 25, 36, 79 }, 
					        { 2, 9, 15, 38 }, 
					        { 22, 55, 67, 98 }}; 

	// Number of arrays 
	int k = sizeof(arr) / sizeof(arr[0]); 

	// Output array 
	int* result = new int[n * k]; 
  
	mergeSortedArrays(arr, k, result); 

	// Print merged array 
	for (int i = 0; i < n * k; i++) 
		cout << result[i] << " "; 

	return 0; 
} 