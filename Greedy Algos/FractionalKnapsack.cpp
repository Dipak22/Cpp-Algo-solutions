#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
  int value, weight;

  // Constructor 
  Item(int value, int weight): value(value), weight(weight) {}
};

// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b);

bool cmp(struct Item a, struct Item b) {
  double r1 = (double) a.value / a.weight;
  double r2 = (double) b.value / b.weight;
  return r1 > r2;
}

int fractionalKnapsack(int W,Item* items,int n){
    sort(items,items+n,cmp);
    int val =0;
    int wei =0;
    for(int i =0;i<n;i++){
        if(wei+items[i].weight<=W){
            val +=items[i].value;
            wei +=items[i].weight;
        }
        else{
            int remain = W - wei;
            val = val + items[i].value*((double)remain/items[i].weight);
            break;
        }   
    }
    return val;
}

int main() {
  int knapsackWeight = 50;
  Item itemArray[] = {{120, 30}, {100, 20}, {60, 10}};

  int n = sizeof(itemArray) / sizeof(itemArray[0]);

  cout << "Maximum value we can obtain = ";
  cout << fractionalKnapsack(knapsackWeight, itemArray, n);
  return 0;
}