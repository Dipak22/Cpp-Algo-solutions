#include <iostream>
using namespace std;
void shapeA(char symbol, int height);
void shapeB(char symbol, int height);
void shapeC(char sym, int H);
void shapeD(char sym, int H);
int main()
{
    int height;
    char symbol;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter symbol: ";
    cin >> symbol;
    cout<<'\n';
    shapeD(symbol,height);
    return 0;
}

void shapeA(char symbol, int height){
    for(int i=1;i<=height;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
void shapeB(char symbol, int height){
    for(int i=1;i<=height;i++){
        for(int j=height;j>=i;j--){
            cout<<"*";
        }
        cout<<"\n";
    }
}

void shapeC(char sym, int height){
    for(int i=1;i<=height;i++){
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=height;j>=i;j--){
            cout<<"*";
        }
        cout<<"\n";
    }
}

void shapeD(char sym, int height){
    for(int i=1;i<=height;i++){
        for(int j=i;j<height;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}