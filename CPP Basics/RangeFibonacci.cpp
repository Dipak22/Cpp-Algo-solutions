#include<iostream>
using namespace std;
void getFibRange(int start, int end){
    int prev =0;
    int curr = 1;
    while(curr<start){
        int next = prev+curr;
        prev = curr;
        curr = next;
    }
    while(curr<end){
        //cout<<curr<<",";
        int next = prev+curr;
        if(next+prev>end)
            cout<<curr;
        else
            cout<<curr<<",";
        prev = curr;
        curr = next;
    }
}
int main(){
    cout<<"Start: ";
    int start;
    cin>>start;
    cout<<"End: ";
    int end;
    cin>>end;
    getFibRange(start,end);
    return 0;
}