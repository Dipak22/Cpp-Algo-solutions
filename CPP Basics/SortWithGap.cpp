#include<iostream>
using namespace std;

void printWithGap(char msg[],int D[], const int size, const int gap){
    cout<< msg ;
    cout <<" = { ";

    for(int i=0; i<size; i+=gap)
    {
        cout << D[i] << " ";
        for(int s=1; s<gap; s++)
             cout <<"  "; // one space for value and one actual space
    }
    cout << "}"<<endl;
}

void sortAscendingWithGap(int A[], int size, int gap){
    int iterations = size/gap+1;
    for(int i=1;i<=iterations;i++){
        for(int j=0;j+gap<size;j+=gap){
            if(A[j]>A[j+gap])
                swap(A[j],A[j+gap]);
        }
    }
}

void sortDescendingWithGap(int A[], int size, int gap){
    int iterations = size/gap+1;
    for(int i=1;i<=iterations;i++){
        for(int j=0;j+gap<size;j+=gap){
            if(A[j]<A[j+gap])
                swap(A[j],A[j+gap]);
        }
    }
}

int main()
{
    int A[ ] = {7, 9, 6, 5, 8, 0, -1, 8, 9, 4, 6, 7, 8, 9, 7, 6, 4, 3, 2, 1};// {1,2,3,4,5,6,1,2,3,4,5,6,10,-20,30,-40,50,60,-11,-2,-33,-34,-35,-6};
    int size = sizeof(A)/sizeof(int);
    
    cout << "Complete Array Before Sorting...\n";
    printWithGap("A", A, size,1); 
    //cout << endl;
    cout << "\n----------------------------------------------------\n";

    sortAscendingWithGap(A, size, 3);
    printWithGap("Complete Array After Ascending Sort with Gap=3: \nA", 
                            A, size,1); 
    cout << "\nArray values which are changed after Ascending Sort...\n";
    printWithGap("A", A, size,3); 
    cout << "----------------------------------------------------\n";

    sortDescendingWithGap(A, size, 3);
    printWithGap("Complete Array After Descending Sort with Gap=3: \nA", 
                            A, size,1); 
    cout << "\nArray values which are changed after Descending Sort...\n";
    printWithGap("A", A, size,3); 
    cout << "----------------------------------------------------\n";
    
    return 0;
}