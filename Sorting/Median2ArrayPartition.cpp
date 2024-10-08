#include<iostream>
using namespace std;
float getMedian(int* arr1, int* arr2, int size1, int size2){
    int totalElem = size1+ size2;
    int med_Element = totalElem/2;
    int* a, *b;
    int n,m;
    if(size1>size2){
        a = arr1;
        b = arr2;
        m = size2;
        n = size1;
    }
    else{
        a = arr2;
        b = arr1;
        n = size2;
        m = size1;
    }

    int left = 0;
    int right = n -1;
    while(true){
        int mid1 = (left+ right)/2;
        int mid2 = med_Element - mid1-2;
        int aLeft = mid1>=0? a[mid1] : INT_MIN;
        int aRight = mid1+1<n? a[mid1+1]: INT_MAX;
        int bLeft = mid2>=0? b[mid2]: INT_MIN;
        int bRight = mid2+1<m? b[mid2+1]: INT_MAX;

        if(aLeft<bRight && bLeft<aRight){
            if(totalElem%2)
                return min(bRight,aRight);
            else
                return (float)(max(aLeft,bLeft) + min(bRight,aRight))/2.0;
        } 
        else if(aLeft>bRight)
            right = mid1-1;
        else
            left = mid1+1;
    }

    return 0.0f;

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
  int array3[] = {900,1000};
  int array4[] = {5, 8, 10, 20};

  int sizeArray3 = sizeof(array3) / sizeof(array3[0]);
  int sizeArray4 = sizeof(array4) / sizeof(array4[0]);
  
  cout << "The median of the two arrays is: " 
    << getMedian(array3, array4, sizeArray3, sizeArray4);

  return 0;
}