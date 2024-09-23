#include<iostream>
using namespace std;
int findingMaxInEachWindow(int M[], int size, int wSize, int stride, 
                                int Maxes[], int &maxSize)
{
    // Write code here. 
}
int main(){
    int A[] = {5,-20,15,16,-3,5,1};
    int windowSize =3, stride = 1,size = 7;
    int max =A[0];
    for(int i=0;i+windowSize<=size;i+=stride){
        max= A[i];
        for(int j = 1;j<windowSize;j++){
            if(A[i+j]>max)
                max = A[i+j];
        }
        cout<<max<<" ";
    }
    return 0;

}