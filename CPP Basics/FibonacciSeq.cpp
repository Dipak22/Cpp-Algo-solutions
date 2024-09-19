#include<iostream>
using namespace std;
void fibonacci(int n){
    int prev =0;
    int curr =1;
    int next =0;
    if(n==0)
        cout<<prev<<" .";
    if(n==1)
        cout<<prev<<" ,"<<curr<<" .";
    if(n>=2)
        cout<<prev<<" , "<<curr<<" ,";
    for(int i=2;next<=n;i++){
        next = prev+ curr; 
        if(next>n)
            break;
        prev = curr;
        curr = next;
        if(prev+curr<=n)
            cout<<next<<" ,";
        else
            cout<<next<<" .";
    }
}
int main(){
    cout<<"Print the fibonacci numbers till: ";
    int n;
    cin>>n;
    fibonacci(n);
    return 0;
}