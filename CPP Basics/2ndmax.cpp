#include<iostream>
using namespace std;
int findSecondMax(int k){
    int num;
    cout<<" Enter numbers";
    cin>>num;
    int max = num;
    cin>>num;
    int secondMax = num;
    if(num>max){
        secondMax = max;
        max = num;
    }
    for(int i=3;i<=k;i++){
        cin>>num;
        if(num>max){
            secondMax = max;
            max = num;
        }
        else if(num>secondMax){
            secondMax = num;
        }
    }
    return secondMax;
}
int main(){
    int k , result;
    cout<<" How many numbers would you like to enter";
    cin>>k;
    result = findSecondMax(k);
    cout<<" Second max is : "<<result;
    return 0;
}