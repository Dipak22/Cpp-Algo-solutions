#include<iostream>
using namespace std;
int reverse(int num){
    int result=0;
    while(num !=0){
        result = result*10 + num%10;
        num /=10;
    }
    return result;
}
int main(){
    cout<<"Enter any number";
    int num;
    cin>>num;
    int rev = reverse(num);
    if(rev==num)
        cout<<"It is a palindrome.";
    else
        cout<<"It is not a palindrome";

    return 0;
}