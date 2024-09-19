#include<iostream>
using namespace std;
void printPrimeFactors(int n){
    cout << n << " = ";
    int d = 2;
    
    for(int d = 2; n!=1; d++)
    {
        while(n%d == 0)  // keep dividing until no factor of d is left
        {
            n /= d;    // shrinking n by d    
            cout << d; // displaying the factor
            if(n != 1)
                cout<< " x ";  
        }
    }
}

int main(){

    cout<<"Enter the numbers(-1 to end the program)";
    int num;
    cin>>num;
    while(num!=-1){
        //cout<<"Prime factors of "<<num<<" : ";
        printPrimeFactors(num);
        cin>>num;
    }
    return 0;
}