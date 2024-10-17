#include<iostream>
using namespace std;

int closer(int target,int a,int b){
   return (target-a)>=(b - target) ? b:a;
}

int closestNumber(int n,int target, int* arr){
    if(target<=arr[0])
        return arr[0];
    else if(target>=arr[n-1])
        return arr[n-1];
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]== target)
            return arr[mid];
        else if(target<arr[mid]){
            if(mid>0 && target>=arr[mid-1])
                return closer(target,arr[mid-1],arr[mid]);
            r = mid-1;
        }
        else{
            if((mid+1)<n && target<=arr[mid+1])
                return closer(target,arr[mid],arr[mid+1]);
            l = mid+1;
        }     
    }
}

int main() { 
	int arr[] = {-9, -4, -2, 0, 1, 3, 4, 10}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int target = -5; 
	cout << (closestNumber(n, target, arr)); 
} 