
#include<iostream>
using namespace std;
int main(){
    cout<<"Enter a decimal integer";
    int n;
    cin>>n;
    int powerfactor = 1;
    int result = 0;
    while(n !=0){
        int rem = n%2;
        result += rem*powerfactor;
        powerfactor *=10;
        n /=2;
    }
    cout<<"Binary is: "<<result;
}