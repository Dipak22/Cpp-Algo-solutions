#include<iostream>
using namespace std;

int min2(int a, int b){
  return a < b ? a : b;
}

int minimumUtil(int l,int r, int h, int* height){
    if(l>=r)
        return 0;
    int m = l;
    //find min height(l to r)
    for(int i =l;i<r;i++){
        if(height[i]<height[m]){
            m = i;
        }
    }
    // take min of 1) all vertical lines(r-l) and 2) alll horizontal lines.
    return min2((r-l),(minimumUtil(l,m,height[m],height) + minimumUtil(m+1,r,height[m],height) + height[m]- h));
}

int minimumSteps(int* height,int N){
    return minimumUtil(0,N,0 ,height);
}


// Testing minimumSteps() method
int main() { 
	int height[] = { 2, 1, 2, 5, 1 }; 
	int N = sizeof(height) / sizeof(int); 

	cout << minimumSteps(height, N) << endl; 
	return 0; 
} 
