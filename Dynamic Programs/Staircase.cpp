#include<iostream>
#include<vector>
using namespace std;

/* int countWaysRec(int n,vector<int> lookupTable){
   if (n < 0) // negative staircases i.e., invalid input
    return 0;
  else if (n == 0) // if 0 staircases
    return 1;
  else if (lookupTable[n] > -1) // if already present in the table
    return lookupTable[n];
  else
    lookupTable[n] = countWaysRec(n - 1, lookupTable)+ countWaysRec(n - 2, lookupTable)+countWaysRec(n - 3, lookupTable);
  return lookupTable[n];
}
int countWays(int n){
    vector<int> lookupTable(n + 1, -1);
    return countWaysRec(n,lookupTable);

} */

//bottomup with tabularization

/*int countWays(int n){
    if(n<0)
        return 0;
    vector<int> lookup(n+1,0);
    lookup[0] = 1;
    lookup[1] = 1;
    lookup[2] = 2;
    for(int s =3;s<=n;s++){
        lookup[s] = lookup[s-3]+ lookup[s-2] + lookup[s-1];
    }
    return lookup[n];
} */

//bottom up , optimized for space

int countWays(int n){
    if(n<0)
        return 0;
    int first = 1;
    int second = 1;
    int third = 2;
    int result = 0;
    for(int s=3;s<=n;s++){
        result = first+ second + third;
        first = second;
        second = third;
        third = result;
    }
    return result;
}

int main() {
  cout << countWays(3) << endl;
}