#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n);
int noOfDigits(int n);
bool circularPrime(int number);

int main(){
    int k;
    cout<<"Circular primes below the number: "<<endl;
    cin>>k;
    int count =0;
    for(int i=2;i<k;i++){
        if(isPrime(i)){
            if(noOfDigits(i)==1){
                cout<<i<<" ";
                count++;
            }
            else{
                if(circularPrime(i)){
                    cout<<i<<" ";
                    count++;
                }
            }
        }
    }
    cout<<" The total no of circular primes are: "<<count;

    return 0;
}
bool circularPrime(int n){
    int digits = noOfDigits(n);
    //bool isPrime = true;
    int counter = 1;
    while(counter<digits){
        int rem = n%10;
        int num = pow(10,digits-1)*rem + n/10;
        if(!isPrime(num))
            return false;
        n = num;
        counter++;
    }
    return true;
}
bool isPrime(int n){
    if(n==1)
        return false;
    if(n!=2 && n%2==0)
        return false;
    int limit = sqrt(n);
    for(int i=2;i<= limit;i++){
        if(n%i ==0)
            return false;
    }
    return true;
}

int noOfDigits(int n){
    int count = 0;
    while(n){
        count++;
        n /=10;
    }
    return count;
}