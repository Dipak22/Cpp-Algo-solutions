#include<iostream>
using namespace std;
bool valid6Digit(int number);
int digitsSum(int num);

int main(){
    int num{};
    bool isValidInput = false;
    do{
        cout<<"Please enter a valid 6 digit number";
        cin>>num;
        isValidInput = valid6Digit(num);
        if(!isValidInput)
            cout<<"Incorrect Input, please enter a valid number(6 digits)";
    }while(!isValidInput);

    cout<<"The sum of digits is: "<<digitsSum(num);

    return 0;
}

bool valid6Digit(int number){
    return (number>=100000 && number<=999999);
}

int digitsSum(int num){
    int sum =0;

    while(num>0){
        sum += num%10;
        num /=10;
    }
    return sum;

}