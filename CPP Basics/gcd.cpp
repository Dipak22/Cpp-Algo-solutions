#include<iostream>
using namespace std;
int smaller(int n1,int n2);
int gcd2(int n1,int n2);
int gcd3(int n1,int n2);
int gcdEuclid(int n1,int n2);

int gcd1(int n1,int n2){
    int gcd = 1;
    for(int i=2;i<=n1;i++){
        if(n1%i == 0 && n2%i==0){
            gcd = i;
        }
    }
    return gcd;
}

int gcd2(int n1,int n2){
    int gcd = 1;
    int s = smaller(n1,n2);
    for(int i=2;i<=s;i++){
        if(n1%i == 0 && n2%i==0){
            gcd = i;
        }
    }
    return gcd;
}
int gcd3(int n1,int n2){
    int s = smaller(n1,n2);
    for(int i=s;i>=1;i--){
        if(n1%i == 0 && n2%i==0){
            return i;
        }
    }
    return 1;
}

int gcdEuclid(int n1,int n2){
    while(n1%n2 !=0){
        int rem = n1%n2;
        n1 = n2;
        n2 = rem;
    }
    return n2;
}

int smaller(int n1,int n2){
    return n1<n2 ? n1:n2;
}

int main(){
    int num1,num2;
    cout<<"Enter numbers to find gcd";
    cin>>num1>>num2;
    cout<<gcdEuclid(num1,num2);

    return 0;
}