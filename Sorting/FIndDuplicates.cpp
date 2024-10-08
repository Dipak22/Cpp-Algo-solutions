#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> findDuplicates(int* arr, int size){
    vector<int> result;
    unordered_map<int,int> umap;
    for(int i =0;i<size;i++)
        umap[arr[i]]++;
    for(auto itr : umap){
        if(itr.second>1)
            result.push_back(itr.first);
    }
    return result;
}
int main() {
  vector <int> output;
  int arr[] = {1, 3, 4, 3, 5, 4, 100, 100};
  int arrSize = 8;
  output = findDuplicates(arr, arrSize);
  if(!output.empty()) {
    for(std::vector<int>::iterator it = output.begin(); it != output.end()-1; ++it)
      cout << *it << ",";
    cout << *(output.end()-1);
  } else {
    cout << "No duplicates exist!" << endl;
  }
  
  cout << endl;
  int arr2[] = {1, 3, 3, 4, 3, 4, 100, 100};
  int arrSize2 = 8;
  output = findDuplicates(arr2, arrSize2);
  if(!output.empty()) {
    for(std::vector<int>::iterator it = output.begin(); it != output.end()-1; ++it)
      cout << *it << ",";
    cout << *(output.end()-1);
  } else {
    cout << "No duplicates exist!" << endl;
  }
  
  cout << endl;
  int arr3[] = {1, 3, 4, 5, 100};
  int arrSize3 = 5;
  output = findDuplicates(arr3, arrSize3);
  if(!output.empty()) {
    for(std::vector<int>::iterator it = output.begin(); it != output.end()-1; ++it)
      cout << *it << ",";
    cout << *(output.end()-1);
  } else {
    cout << "No duplicates exist!" << endl;
  }
}