#include<iostream>
using namespace std;
int reverse(int num);
bool isPalindrome(int num);
int main(){
    //Find largets 3 digit palindrome
    //bool palin= false;
    int largest=0,num1,num2;
    for(int i=999;i>=100;i--){
        for(int j= 999;j>=100;j--){
            if(isPalindrome(i*j)){
                if(largest<i*j){
                    largest = i*j;
                    num1 = i;
                    num2 = j;
                }
                
            }
                
        }
        
    }
    cout<<num1<< " * "<<num2<<" = "<<largest;
    return 0;
    
}

int reverse(int num){
    int rem , result =0;
    while(num !=0){
        rem = num%10;
        num /=10;
        result = result * 10 + rem;
    }
    return result;
}

bool isPalindrome(int num){
    return reverse(num) == num;
}