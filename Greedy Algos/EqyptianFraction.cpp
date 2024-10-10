#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void printEgyptianFraction(int numerator,int denominator){
    vector<int> denominators;

    while(numerator !=0){
        int x = ceil((float)denominator/numerator);
        denominators.push_back(x);
        numerator = numerator*x - denominator;
        denominator = denominator*x;
    }
    for(int i =0;i<denominators.size();i++){
        cout<<"1/"<<denominators[i]<<" ";
    }
}

int main() {
  
  //Example 1
  int numerator = 6, denominator = 14;
  cout << "Egyptian Fraction Representation of " << numerator << "/" << denominator << " is\n ";
  printEgyptianFraction(numerator, denominator);
  cout << endl << endl;
  
  //Example 2
  numerator = 2;
  denominator = 3;
  cout << "Egyptian Fraction Representation of " << numerator << "/" << denominator << " is\n ";
  printEgyptianFraction(numerator, denominator);
  return 0;
}