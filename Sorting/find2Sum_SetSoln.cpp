#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findSum(int* arr, int size, int k){
    vector<int> result;
    unordered_set<int> us;
    for(int i =0;i<size;i++){
        int cmp = k - arr[i];
        if(us.find(cmp) != us.end()){
            result.push_back(cmp);
            result.push_back(arr[i]);
            break;
        }
        us.insert(arr[i]);
    }
    return result;
}

int main() {
  int arr[] = {8,4,1,6,5,9};
  int sum = 9;
  vector<int> result = findSum(arr, 6, sum);
  if(!result.empty())
    cout << "Sum of " << sum << " found: " << result[0] << " " << result[1];
  else
    cout << "Results not found" << endl;
}