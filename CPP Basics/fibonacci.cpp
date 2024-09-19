#include<iostream>
using namespace std;
void fibonacciPrinting(int k);
int fibonacci(int k);
int main(){
    cout<<"No of queries needed";
    int k;
    cin>>k;
    fibonacciPrinting(k);
    return 0;
}

void fibonacciPrinting(int k){
    for(int i=0;i<k;i++){
        cout<<"Nth fibonacci u want? :";
        int n;
        cin>>n;
        cout<<"\n F"<<n<<" = " <<fibonacci(n);
    }
}

int fibonacci(int n){
    int prev =0;
    int curr = 1;
    if(n<2)
        return n;
    int next = 0;
    for(int i=2;i<=n;i++){
        next = curr+prev;
        prev = curr;
        curr = next;
    }
    return curr;
}