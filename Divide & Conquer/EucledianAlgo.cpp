#include<iostream>
using namespace std;

int euclideanAlgorithm(int x, int y){
    if(y==0)
        return x;
    return euclideanAlgorithm(y,x%y);
}


int main() {
  int x = 252, y = 105;
  cout << "The GCD of " << x << " and " << y << " is equal to "<< euclideanAlgorithm(x, y) << endl;
  
  x = 10, y = 15;
  cout << "The GCD of " << x << " and " << y << " is equal to "<< euclideanAlgorithm(x, y) << endl;
  
  x = 77, y = 2;
  cout << "The GCD of " << x << " and " << y << " is equal to "<< euclideanAlgorithm(x, y) << endl;
}