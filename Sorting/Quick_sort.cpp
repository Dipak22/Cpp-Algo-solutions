#include<iostream>
using namespace std;

int partition(int arr[],int left,int right){
    int pivot_index = left;
    int pivot = arr[left];
    swap(arr[pivot_index],arr[right]);
    for(int i = left;i<right;i++){
        if(arr[i]<pivot){
            swap(arr[pivot_index], arr[i]);
            pivot_index++;
        }
    }
    swap(arr[pivot_index],arr[right]);
    return pivot_index;
}
void quickSort(int arr[], int left, int right){
    if(left>=right)
        return;

    int p = partition(arr,left,right);
    quickSort(arr,left,p-1);
    quickSort(arr,p+1,right);
}

void printArray(int* arr,int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main() { 
  int arr[] = {5,4,1,0,5,95,4,-100,200,0};
	int arrSize = 10; 
	quickSort(arr, 0, arrSize-1); 
	cout << "Sorted array: ";
	printArray(arr, arrSize); 
}