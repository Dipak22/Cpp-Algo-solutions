#include<iostream>
#include<vector>
using namespace std;
int partition(int* arr, int left, int right){
    int pivot_index = left;
    int pivot = arr[pivot_index];
    swap(arr[pivot_index],arr[right]);
    for(int i = left;i<right;i++){
        if(arr[i]<pivot){
            swap(arr[pivot_index],arr[i]);
            pivot_index++;
        }
    }
    swap(arr[pivot_index],arr[right]);
    return pivot_index;
}
void quickSort(int* arr, int left,int right){
    if(left>=right)
        return;
    int pivot = partition(arr,left,right);
    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1,right);
}
vector<int> findSum(int* arr,int size, int k){
    quickSort(arr,0,size-1);
    int left = 0;
    int right = size-1;
    vector<int> result;
    while(left<right){
        int sum = arr[left]+ arr[right];
        if(sum==k){
            result.push_back(arr[left]);
            result.push_back(arr[right]);
            break;
        }
        else if(sum>k)
            right--;
        else
            left++;

    }
    return result;
}

int main() {
  int arr[] = {8,4,1,6,5,9};
  int sum = 10;
  vector<int> result = findSum(arr, 6, sum);
  if(!result.empty())
    cout << "Sum of " << sum << " found: " << result[0] << " " << result[1];
  else
    cout << "Results not found" << endl;
}