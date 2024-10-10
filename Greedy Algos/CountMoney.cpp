#include<iostream>

int coinsAvailable[] = {1, 5, 10, 25};

int n = sizeof(coinsAvailable) / sizeof(coinsAvailable[0]);

void findMinCoins(int V){
    for(int i = n-1;i>=0;i--){
        while(V>=coinsAvailable[i]){
            V -=coinsAvailable[i];
            std::cout<<coinsAvailable[i]<<" ";
        }
    }
}

// Driver program 
int main() {
  int n = 19;
  findMinCoins(n);
  return 0;
}