
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n);

int main(){
    int n =1;
    while(true){
        int answer = n*n + n + 41;
        if(!isPrime(answer)){
            cout<<n <<"\t"<<answer;
            break;
        }
        ++n;
    }

    return 0;
}

bool isPrime(int n){
    if(n==1)
        return false;
    if(n!=2 && n%2==0)
        return false;
    int limit = sqrt(n);
    for(int i =2;i<=limit;i++){
        if(n%i ==0)
            return false;
    }
    return true;
}