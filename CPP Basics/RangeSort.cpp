#include<iostream>
using namespace std;

void printSpecial(const char msg[ ], int D[ ], int size)
{
    cout << msg << " = { ";
    for(int i=0; i<size; i++)
    {
        cout << D[i] << " ";
    }
    cout << " }"<<endl;
}

void rangeSort(int A[], int start, int end){
    for(int i=1;i<(end-start+1);i++){
        for(int j = start; j+1<=end;j++){
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
        }
    }
}

int main(){
    int A[] = { 1, 2 ,3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 10, -20, 30, -40, 50, 60, -11, -2 ,-33, -34 ,-35, -6  };
    int size = sizeof(A)/sizeof(int);
    cout << "Before sorting:\n";
    printSpecial("A", A, size); cout << endl;
    rangeSort(A,0,12);
    cout << "After sorting:\n";
    printSpecial("A", A, size); cout << endl;
    return 0;
}