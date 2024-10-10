#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/* int minCost(int* pipes,int size){
    sort(pipes,pipes+size);
    int cost = 0;
    for(int i =0;i+1<size;i++){
        int currCost = pipes[i]+ pipes[i+1];
        cost +=currCost;
        pipes[i+1] = currCost;
    }
    return cost;
} */

int minCost(int* pipes,int size){
    priority_queue<int,vector<int>,greater<int>> myPriorityQueue(pipes,pipes+size);
    int cost = 0;
    while(myPriorityQueue.size()>1){
        int pipe1 = myPriorityQueue.top();
        myPriorityQueue.pop();
        int pipe2 = myPriorityQueue.top();
        myPriorityQueue.pop();
        cost +=pipe1+ pipe2;
        myPriorityQueue.push(pipe1+pipe2);
    }
    return cost;
}

int main() {
  int pipes[] = {4, 3, 2, 6 };
  int size = sizeof(pipes) / sizeof(pipes[0]);
  cout << "Total cost for connecting pipes list 1 is " << minCost(pipes, size);
  cout << endl << endl;
  int pipes1[] = {1, 1, 2, 6};
  int size1 = sizeof(pipes1) / sizeof(pipes1[0]);
  cout << "Total cost for connecting pipes list 2 is " << minCost(pipes1, size1);
  return 0;
}