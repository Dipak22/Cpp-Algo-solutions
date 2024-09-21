#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
void init(char fstream[], int D[], int& size){
    ifstream rdr(fstream);
    rdr>>size;
    for(int i=0;i<size;i++)
        rdr>>D[i];
}
void segregateEvensOdds_ExtremeShrinking(int D[], const int size){
   int start = 0;
   int end = size-1;
   while(start<end){
        while(D[start]%2 ==0 && start<end)
            start++;
        while(D[end]%2 ==1 && start<end)
            end--;
        if(start<end)
            swap(D[start],D[end]);
   } 
}
void specialDisplay(const char Msg[ ], int A[ ], int size)
{
    cout << left << setw(25) << Msg<< " = { ";
    for(int ai=0; ai<size; ai++)
    {
        cout << right <<setw(5)<<A[ai] << " ";
    }
    cout << "  }"<<endl;
}

int main(){
    const int capacity = 25;
    int D[capacity]={},size;
    init("segregation.txt",D,size);
    specialDisplay("Read from file Data Ds: ", D, size);
    segregateEvensOdds_ExtremeShrinking(D, size);
    specialDisplay("Replaced Array - New Ds: ", D, size);

    return 0;
}