#include <iostream>
using namespace std;
void mergeSorted_Arrays(int C[], int &CSize, int A[], int ASize, int B[], int BSize)
{
    CSize= ASize+BSize;
    int a=0,b=0;
    int i =0;
    for(i=0;i<CSize;i++){
        if(a==ASize || b == BSize)
            break;
        if(A[a]<B[b]){
            C[i] = A[a];
            a++;
        }else{
            C[i] = B[b];
            b++;
        }
    }

    while(a<ASize)
        C[i++] = A[a++];
    while (b<BSize)
    {
        C[i++] = B[b++];
    }
    
}
void print(const char Name[], int A[], int Size)
{
    cout << Name << " = { ";
    for(int i=0; i<Size; i++)
        cout << A[i] << " ";
    cout << "}"<<endl;
}
int main()
{    
    const int Capacity = 100;
    int A[ ] = {1,4,6,7,7,8,9,10}, ASize = sizeof(A)/4;
    int B[ ] = {-1,2,3,7,7,8,9,10,100,200,399}, BSize = sizeof(B)/4;
    int C[Capacity], CSize;
    mergeSorted_Arrays(C, CSize, A, ASize, B, BSize);
    print("A", A,ASize);
    print("B", B,BSize);
    print("Merged Array \nC", C,CSize);
    return 0;
}








