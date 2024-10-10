#include<iostream>
#include<vector>
using namespace std;
int policeThief(char* policeTheifArray, int n, int k){
    int result =0;
    vector<bool> caught(n,false);
    for(int i =0;i<n;i++){
        if(policeTheifArray[i]=='P' && !caught[i]){
            for(int j = i;j<=(i+k) && j<n; j++){
                if(policeTheifArray[j] =='T'){
                    result++;
                    caught[i] = true;
                    break;
                }
            }
        }

        if(policeTheifArray[i]=='P' && !caught[i]){
            for(int j = i; j>=0 && j>=(i-k);j--){
                if(policeTheifArray[j] =='T' ){
                    result++;
                    caught[i] = true;
                    break;
                }
            }
        }
    }
    return result;
}

int main() {
  int k, n;

    char policeTheifArray[] = {'P', 'T', 'T', 'P', 'T'};
  k = 2;
  n = sizeof(policeTheifArray) / sizeof(policeTheifArray[0]);
  cout << "Maximum thieves caught for {P, T, T, P, T}: " << policeThief(policeTheifArray, n, k) << endl;
  

  char policeTheifArray1[] = {'T', 'T', 'P', 'P', 'T', 'P'};
  k = 2;
  n = sizeof(policeTheifArray1) / sizeof(policeTheifArray1[0]);
  cout << "Maximum thieves caught for {T, T, P, P, T,P}: " << policeThief(policeTheifArray1, n, k) << endl;

  return 0;
}