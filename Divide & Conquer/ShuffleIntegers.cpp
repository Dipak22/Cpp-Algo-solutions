#include<iostream>
using namespace std;

void shufflerRec(int* a,int l, int r){
    if(r-l == 1)
        return;
    int mid = (l+r)/2;
    int mfirst = (l+mid)/2;
    int mSec = mid+1;
    for(int i = mfirst+1;i<=mid;i++){
        swap(a[i],a[mSec]);
        mSec++;
    }
    shufflerRec(a,l,mid);
    shufflerRec(a,mid+1,r);
}

void shuffler(int* a,int n){
    shufflerRec(a,0,n-1);
}

int main() { 
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	shuffler(a, n); 
  
	for (int i = 0; i < n; i++) 
		cout << a[i] << " "; 
  
	return 0; 
}