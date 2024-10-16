#include<iostream>
#include<vector>
using namespace std;

/* bool canPartitionRecurse(int* set, int size, int sum,int index,vector<vector<int>> lookupTable){
    if(sum ==0)
        return true;
    if(size<=0 || index>=size)
        return false;
    if(lookupTable[index][sum]==-1){
        if(set[index]<=sum){
        if(canPartitionRecurse(set,size,sum - set[index],index+1,lookupTable))
            return true;
        }
    }
    
    lookupTable[index][sum] =  canPartitionRecurse(set,size,sum,index+1,lookupTable);
    return lookupTable[index][sum];
}

bool canPartition(int* set, int size){
    int sum = 0;
    for(int i = 0;i<size;i++)
        sum +=set[i];
    if(sum%2 !=0)
        return false;
    vector<vector<int>> lookupTable(size,vector<int>(sum/2+1,-1));
    return canPartitionRecurse(set,size, sum/2,0,lookupTable);
} */

bool canPartition(int* set,int size){
    int sum = 0;
    for(int i=0;i<size;i++)
        sum +=set[i];
    if(sum%2)
        return false;
    sum /=2;
    vector<vector<int>> lookup(size,vector<int>(sum+1,0));
    for(int s=0;s<=sum;s++)
        if(set[0]==s)
            lookup[0][s] = 1;
    for(int i =1;i<size;i++){
        for(int s=1;s<=sum;s++){
            if(lookup[i-1][s])
                lookup[i][s] = lookup[i-1][s];
            else if(set[i]<=s)
                lookup[i][s] = lookup[i-1][s-set[i]];
        }
    }
    return lookup[size-1][sum];
}

int main() {
    int set1[] = {1, 2, 3, 4};
    cout << canPartition(set1, 4) << endl;
    int set2[] = {1, 1, 3, 4, 7};
    cout << canPartition(set2, 5) << endl;
    int set3[] = {2, 3, 4, 6};
    cout << canPartition(set3, 4) << endl;
}