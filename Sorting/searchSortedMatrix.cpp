#include<iostream>
#include<vector>
using namespace std;

bool search(vector<vector<int>> matrix,int rows,int cols,int k){
    int start = 0;
    int end = rows*cols-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int r = mid/rows;
        int c = mid%cols;
        if(matrix[r][c] == k)
            return true;
        if(matrix[r][c]>k){
            end = mid -1;
        }else
            start = mid+1;
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = { {10, 11, 12, 13}, {14, 15, 16, 17}, {27, 29, 30, 31}, {32, 33, 39, 80} };
  
  // Example 1
 if (search(matrix, 4, 4, 80))
    cout << "80 is Found" << endl;
  else
    cout << "80 is Not Found" << endl;
  
  // Example 2
   if (search(matrix, 4, 4, 37))
    cout << "37 is Found" << endl;
  else
    cout << "37 is Not Found" << endl;
  
  return 0;
}