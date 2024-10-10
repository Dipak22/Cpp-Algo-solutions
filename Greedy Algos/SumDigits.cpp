#include<iostream>
using namespace std;
void findLargestNumber(int nDigits,int sumDigits){
    if(sumDigits ==0){
        if(nDigits ==1)
            cout<<1;
        else
            cout<<"not possible";
    }
    else if(sumDigits>(9*nDigits))
        cout<<"not possible";
    else{
        for(int i=0;i<nDigits;i++){
            if(sumDigits>9){
                sumDigits -=9;
                cout<<9;
            }else{
                cout<<sumDigits;
            }
        }
    }

}
int main() {
  int sumOfDigits = 20;
  int numberOfDigits = 3;
  
  cout << "If sum of digits is 20 and number of digits is 3 then ";
  findLargestNumber(numberOfDigits, sumOfDigits);
  cout << endl << endl;
  
  //Example 2
  sumOfDigits = 100;
  numberOfDigits = 2;
  
  cout << "If sum of digits is 100 and number of digits is 2 then ";
  findLargestNumber(numberOfDigits, sumOfDigits);
  
  return 0;
}