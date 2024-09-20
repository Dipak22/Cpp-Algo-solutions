#include<iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

     int A[8]={1,2,-93,-4,75,6,8,23}; 
     int length = sizeof(A)/sizeof(int);
     int min = A[0];
     int secmin = A[1];
     if(A[0]>A[1])
        swap(A[0],A[1]);
    for(int i=2;i<length;i++){
        if(A[i]<min){
            secmin = min;
            min = A[i];
        }
        else if(A[i]<secmin){
            secmin = A[i];
        }
    }
    cout << "\nMin: "<< min << endl; 
    cout << "Second Min: "<< secmin << endl;   
    return 0;
}