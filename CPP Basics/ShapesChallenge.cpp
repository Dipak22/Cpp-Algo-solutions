#include <iostream>
using namespace std;
void printT1(int h)
{
   for(int i =1;i<=h;i++){
    for(int j =1;j<=i;j++){
        cout<<j<<" ";
    }
    cout<<"\n";
   }
}

void printT2(int h)
{
   for(int i =h;i>=1;i--){
    for(int j =1;j<=i;j++){
        cout<<j<<" ";
    }
    cout<<"\n";
   }
}

void printT3(int h)
{
    int k =1;
  for(int i =1;i<=h;i++){
    for(int j =1;j<=i;j++){
        cout<<k++<<" ";
    }
    cout<<"\n";
   }
}

void printT4(int h)
{
	for(int i=1;i<=h;i++){
        for(int j=h;j>i;j--)
            cout<<" ";
        int k = i;
        while(k<(2*i)){
            cout<<k<<" ";
            k++;
        }
        k -=2;
        while(k>=i){
            cout<<k<<" ";
            k--;
        }
        
        cout<<endl;
    }
}

void printT5(int h)
{
    char ch = 'A';
	for(int i =1;i<=h;i++){
    for(int j =1;j<=i;j++){
        cout<<ch<<" ";
    }
    ch++;
    cout<<"\n";
   }
}

void printT6(int h)
{
	for(int i =1;i<=h;i++){
    char ch = 'A';
    for(int j =1;j<=i;j++){
        cout<<ch++<<" ";
    }
    cout<<"\n";
   }
}

int main()
{
    cout<<"Enter height";
    int h;
    cin>>h;
    printT6(h);
}