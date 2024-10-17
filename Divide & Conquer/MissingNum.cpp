#include<iostream>
using namespace std;

int missingNumber(int N,int* arr){
    int l = 0;
    int r = N-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] !=mid+1 && arr[mid-1] == mid)
            return mid+1;
        else if(arr[mid] !=mid+1)
            r = mid-1;
        else
            l = mid+1;
    }
}

// Driver code 
int main() { 
	int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
	int N = sizeof(arr)/sizeof(arr[0]); 
	cout << missingNumber(N, arr);
	return 0; 
} 