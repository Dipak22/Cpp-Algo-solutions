#include<iostream>
using namespace std;

bool isComposite(int num){
    if(num<2)
        return false;
    for(int i=2;i<=num-1;i++){
        if(num%i==0){
            return true;
        }
    }
    return false;
}
int main(){
    cout<<"Enter a number (-1 to end the program)";
    int num;
    cin>>num;
    while(num !=-1){
        if(isComposite(num)){
            cout<<num<<" is a composite.";
        }else{
            cout<<num<<" is a prime";
        }
        cin>>num;

    }
    return 0;
}