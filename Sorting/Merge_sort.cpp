#include<iostream>

void merge(int* arr, int left, int mid, int right){
    int leftSize = mid-left+1;
    int rightSize = right-mid;
    int tempLeft[leftSize];
    int tempRight[rightSize];
    for(int i=0;i<leftSize;i++)
        tempLeft[i] = arr[left+i];
    for(int i=0;i<rightSize;i++)
        tempRight[i] = arr[mid+1+i];
    
    int c=0,a=0,b=0;
    while(a<leftSize && b<rightSize){
        if(tempLeft[a]<tempRight[b]){
            arr[left+c] = tempLeft[a];
            a++;
            c++;
        }else{
            arr[left+c] = tempRight[b];
            b++;
            c++;
        }
    }
    while(a<leftSize){
        arr[left+c] = tempLeft[a];
        a++;
        c++;
    }
    while(b<rightSize){
        arr[left+c] = tempRight[b];
        c++;
        b++;
    }

}

void mergeSort(int* arr,int left, int right){
    if(left>=right)
        return;
    int mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left, mid,right);
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
  mergeSort(arr, 0, arrSize-1);
  printArray(arr, arrSize);
}