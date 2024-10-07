#include<iostream>
using namespace std;
float getMedian(int* arr1,int* arr2, int size1,int size2){
    int totalElem = size1+size2;
    int medianIndex = totalElem/2;
    float median1 = -1;
    float median2 = -1;
    int a=0;
    int b = 0;
    for(int i =0;i<=medianIndex;i++){
        if(a<size1 && b<size2){
            if(arr1[a]<=arr2[b]){
            median1 = median2;
            median2 = arr1[a];
            a++;
        }
        else{
            median1 = median2;
            median2 = arr2[b];
            b++;
            }
        }
        else if(a<size1){
            median1 = median2;
            median2 = arr1[a];
            a++;
        }
        else{
            median1 = median2;
            median2 = arr2[b];
            b++;
        }
        
    }

    if(totalElem %2)
        return median2;
    return (median1 + median2)/2;
}
int main() {
  // Example 1
  int array1[] = {900};
  int array2[] = {1, 5, 8, 10, 20};

  int sizeArray1 = sizeof(array1) / sizeof(array1[0]);
  int sizeArray2 = sizeof(array2) / sizeof(array2[0]);
  
  cout << "The median of the two arrays is: " 
    << getMedian(array1, array2, sizeArray1, sizeArray2);
  
  cout << endl << endl;
   // Example 2
  int array3[] = {900};
  int array4[] = {5, 8, 10, 20};

  int sizeArray3 = sizeof(array3) / sizeof(array3[0]);
  int sizeArray4 = sizeof(array4) / sizeof(array4[0]);
  
  cout << "The median of the two arrays is: " 
    << getMedian(array3, array4, sizeArray3, sizeArray4);

  return 0;
}