#include <iostream>
#include<cmath>
using namespace std;
int sieveOfEratosthenes(int A[], int n)
{
    // Write your code here
    A[0] = -1;
    A[1] = -1;
    int count = 0;
    for(int i =2;i<=n;i++){
        if(A[i] ==-1)
            continue;
        count++;
        for(int p = i+i;p<=n;p +=i){
            A[p] =-1;
        }
        
    }
    return count;
}

void allPrimesBetween1_N(int N)   // N <=100000
{
    const int Capacity =100000;   
    int A[Capacity]={};
    int primesCount = sieveOfEratosthenes(A, N);
    cout << "Found "<<primesCount << " primes between 1 to "<<N<<endl;
    cout << "The Primes are: {";
    for(int i=0; i<=N; i++)
    {
        if(A[i]!=-1)
        {
            cout << i << " ";
        }
    }
}
int main()
{    
    allPrimesBetween1_N(1000);
    return 0;
}






