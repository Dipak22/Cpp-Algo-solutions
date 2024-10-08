#include<iostream>
#include<string>
using namespace std;
int modifiedBinarySearch(string arr[], int left, int right, string k){
    if(left>right)
        return -1;
    int mid = left + (right - left)/2;
    int i ,j;
    if(arr[mid] ==""){
        i = mid-1;
        j = mid+1;
    while(true){
        if(i<left && j>right)
            return -1;
        if(i>=left && arr[i] != ""){
            mid = i;
            break;
        }
        if(j<=right && arr[j] !=""){
            mid = j;
            break;
        }
        i--;
        j++;
    }
    }

    if(arr[mid] == k)
        return mid;
    else if(arr[mid]>k)
        return modifiedBinarySearch(arr,left,mid-1,k);
    else
        return modifiedBinarySearch(arr,mid+1, right, k);
}
int searchForString(string array[], int size, string k){
    return modifiedBinarySearch(array,0,size-1,k);
}
int main() {
  int size = 12;
  string array[size] = {"", "educative", "", "", 
                        "",  "hello", "", "learning", 
                        "world", "", "", ""};
  
  string targetArray[2] = {"educative", "learning"};
  
  for(int i = 0; i < 2; i++) {
    cout << targetArray[i] << ": " << searchForString(array, size, targetArray[i]) << endl;
  }
  return 0;
}