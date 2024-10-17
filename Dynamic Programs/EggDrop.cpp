#include<iostream>
#include<vector>
using namespace std;

int eggDropRec(int eggs,int floors,vector<vector<int>> lookup){
    if(lookup[eggs][floors]== INT_MAX){
            if(eggs<=0)
        return 0;
    if(floors<=1)
        return floors;
    if(eggs ==1)
        return floors;
    int min = INT_MAX;
    int x,res;
    for(x=1;x<=floors;x++){
        res = 1 + max(eggDropRec(eggs-1,x-1,lookup), eggDropRec(eggs,floors - x,lookup));
        if(res<lookup[eggs][floors])
            lookup[eggs][floors] = res;
    }
    }
    return lookup[eggs][floors];
}

int eggDrop(int eggs,int floors){
    vector<vector<int>> lookup(eggs+1,vector<int>(floors+1,INT_MAX));
    return eggDropRec(eggs,floors, lookup);
    
}



int main() {
  int n = 2, k = 13;
  cout << "Minimum number of trials in worst case with " <<
    n << " eggs and " << k << " floors is " <<
    eggDrop(n, k) << endl;
  return 0;
}