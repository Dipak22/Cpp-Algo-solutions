#include<iostream>
using namespace std;

void sortAscendingOnlyEvenValues(int A[],int size);
void sortDescendingOnlyEvenValues(int A[],int size);
int nextEven(int A[], int start,int end);

void printSpecial(const char msg[ ], int D[ ], int size)
{
    cout << msg << " = { ";
    for(int i=0; i<size; i++)
    {
        cout << D[i] << " ";
    }
    cout << " }"<<endl;
}
int nextEven(int A[], int start,int end){
    for(int i = start;i<=end;i++){
        if(A[i]%2 == 0)
            return i;
    }
    return -1;
}
void sortAscendingOnlyEvenValues(int A[],int size){
    for(int i=1;i<size;i++){
        for(int j = nextEven(A,0,size-1); j!=-1; j = nextEven(A,j+1,size-1)){
            int ni = nextEven(A,j+1,size-1);
            if(ni !=-1 && A[j]>A[ni])
                swap(A[j],A[ni]);
        }
    }
}

void sortDescendingOnlyEvenValues(int A[],int size){
    for(int i=1;i<size;i++){
        for(int j = nextEven(A,0,size-1); j!=-1; j = nextEven(A,j+1,size-1)){
            int ni = nextEven(A,j+1,size-1);
            if(ni !=-1 && A[j]<A[ni])
                swap(A[j],A[ni]);
        }
    }
}

int main(){
    int A[ ] = {7, 9, 6, 5, 8, 0, -1, 8, 9, 4, 6, 7, 8, 9, 7, 6, 4, 3, 2, 1};
    int size = sizeof(A)/sizeof(int);
    
    cout << "Array Before Ascending Sorting...\n";
    printSpecial("A", A, size); cout << endl;
    sortAscendingOnlyEvenValues(A,size);  
    cout << "Array After Ascending Sorting...\n";
    printSpecial("A", A, size); cout << endl;
    cout << "Array Before Descending Sorting...\n";
    printSpecial("A", A, size); cout << endl;
    sortDescendingOnlyEvenValues(A,size);  
    cout << "Array After Descending Sorting...\n";
    printSpecial("A", A, size); cout << endl;
    return 0;
}