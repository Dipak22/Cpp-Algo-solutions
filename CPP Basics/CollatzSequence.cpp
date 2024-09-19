#include<iostream>
using namespace std;

int CollatzLen(int num){
    int count = 0;
    cout<<"The Collatz's sequence of "<<num<<" : "<<num<< " ";
    while(num !=1){
        num = num%2 ? 3*num+1 : num/2;
        cout<<num<<" ";
        count++;
    }
    cout<<'\n';
    cout<<"The Collatz's sequence length of "<<num<<" is:"<<count<<endl;
    return count;
}

int CollatzSequenceGenerator(){
    int max = 0;
    int num;
    int returnVal;
    cout<<"A number stream (ending with -1):";
    //cout<<"-----------------------------------------";
    while(true){
        cin>>num;
        if(num==-1)
            break;
        int count = CollatzLen(num);
        if(count>max){
            max = count;
            returnVal = num;
        }
    }
    return returnVal;
}

int main(){

    int maxSeq = CollatzSequenceGenerator();
    cout<<"Maximun sequence is by :"<<maxSeq;

    return 0;
}