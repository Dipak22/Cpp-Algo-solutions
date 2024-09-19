#include<iostream>
using namespace std;
bool isPerfectSquare(int num){
    int i=1;
    for(i=1; i*i<=num;i++){

    }
    return (i-1)*(i-1) == num;
}
int main(){
    int num=0;
    cout<<"Enter numbers to check for perfect squares";
    while(num !=-1){
        cin>>num;
        if(isPerfectSquare(num)){
            cout<<num<<" is a perfect square";
        }else{
            cout<<num<<" is not a perfect square";
        }
    }

    return 0;
}