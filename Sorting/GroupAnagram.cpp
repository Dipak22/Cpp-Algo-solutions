#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int partition(string& arr, int left, int right){
    int pivot_index = left;
    int pivot = arr[left];
    swap(arr[pivot_index], arr[right]);
    for(int i = left; i<right;i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[pivot_index]);
            pivot_index++;
        }
    }
    swap(arr[pivot_index], arr[right]);
    return pivot_index;
}

void quickSort(string& arr,int left,int right){
    if(left>=right)
        return;
    int pivot = partition(arr,left,right);
    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1, right);
}

vector<string> groupAnagrams(string* arr,const int size){
    string dup[size];
    for(int i =0;i<size;i++)
        dup[i] = arr[i];
    for(int i=0;i<size;i++)
        quickSort(arr[i],0,arr[i].length()-1);
    unordered_map<string,vector<int>> map;
    for(int i =0;i<size;i++){
        map[arr[i]].push_back(i);
    }
    vector<string> result;
    for(auto itr: map){
        for(int i : itr.second)
            result.push_back(dup[i]);
    }
    return result;   

}

// Group anagrams together from given list of words
int main() {
  string arr[] = {
    "tom marvolo riddle ",
    "abc",
    "def",
    "cab",
    "fed",
    "clint eastwood ",
    "i am lord voldemort",
    "elvis",
    "old west action",
    "lives"
  };
  int arrSize = 10;
  vector<string> vec;
  vec = groupAnagrams(arr, arrSize);
  for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    std::cout << *i << ' ';
}