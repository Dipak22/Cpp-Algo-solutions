#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* int knapSackRecurive(int* profits,int* weights,int size,int capacity,int index,vector<vector<int>> lookupTable){
    if(index>=size || index<0 || capacity<=0)
        return 0;
    if(lookupTable[index][capacity] !=0)
        return lookupTable[index][capacity];
    int profit1=0,profit2=0;
    if(weights[index]<=capacity){
        profit1 = profits[index] + knapSackRecurive(profits,weights,size,capacity-weights[index],index+1,lookupTable);
    }
    profit2 = knapSackRecurive(profits,weights,size,capacity,index+1,lookupTable);
    lookupTable[index][capacity] = max(profit1,profit2);
    return lookupTable[index][capacity];
}
int knapSack(int profits[],int size,int weights[],int capacity){
    vector<vector<int>> lookupTable(size,vector<int>(capacity+1,0));
    return knapSackRecurive(profits,weights,size,capacity,0,lookupTable);
}  */

//bottom up and tabulation

/* int knapSack(int profits[], int profitsLength, int weights[], int capacity) {
    if(capacity<=0 || profitsLength<=0)
        return 0;
    int lookupTable[profitsLength+1][capacity+1];
    for(int i=0;i<=profitsLength;i++){
        for(int w=0;w<=capacity;w++){
            if(i==0 || w==0)
                lookupTable[i][w] =0;
            else if(weights[i-1]<=w)
                lookupTable[i][w] = max(lookupTable[i-1][w], lookupTable[i-1][w-weights[i-1]] + profits[i-1]);
            else
                lookupTable[i][w] = lookupTable[i-1][w];
            }
        }
    return lookupTable[profitsLength][capacity];
} */

//space optimized
int knapSack(int profits[], int profitsLength, int weights[], int capacity){
    if(capacity<=0 || profitsLength<=0)
        return 0;
    int lookupTable[capacity+1] ={0};
    for(int c=0;c<=capacity;c++){
        if(weights[0]<=c)
            lookupTable[c]= profits[0];
    }

    for(int i=1;i<profitsLength;i++){
        for(int c= capacity;c>=0;c--){
            int profit1 =0;int profit2 = 0;
            if(weights[i]<=c){
                profit1 = lookupTable[c-weights[i]]+ profits[i];
            }else
                profit2 = lookupTable[c];
            lookupTable[c] = max(profit1,profit2);

        }
    }
    return lookupTable[capacity];
}

int main() {
  int profits[] = {1, 6, 10, 16}; // The values of the jewelry
  int weights[] = {1, 2, 3, 5}; // The weight of each
  cout << "Total knapsack profit = " << knapSack(profits, 4, weights, 7) << endl;
  cout << "Total knapsack profit = " << knapSack(profits, 4, weights, 6) << endl;
  return 0;
}