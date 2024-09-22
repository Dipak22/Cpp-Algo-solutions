#include <iostream>
using namespace std;

void rightShift(int A[], int size)
{              
  for(int i=size-1; i-1>=0; i--)
  {
    swap(A[i-1],A[i]); 
  } 
}
void leftShift(int A[], int size)
{  
 for(int i=0; i+1<size; i++)
  {
    swap(A[i+1],A[i]); 
  } 
}
void print1D(const char MSG[], int A[], int size)
{   
    cout << MSG<<": {";
    for(int i=0; i<size; i++)
    {
        cout<<A[i];
        if(i!=size-1)
            cout<<",";
    }                  
    cout<< "}";  
}
int main()
{
    const int capacity=100;
    int size=7;
    int Array[capacity]={1,2,3,4,5,6,7};

    print1D("Before right shift A[]", Array, size);
    leftShift(Array, size);
    print1D("\n After right shift A[]", Array, size);
    
    return 0;
}