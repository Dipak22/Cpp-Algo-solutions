#include<iostream>
#include<fstream>
using namespace std;
void init(char fname[],int A[], int &size);

void init(char fname[],int A[], int &size){
    ifstream rdr(fname);
    rdr>>size;
    for(int i=0;i<size;i++)
        rdr>>A[i];
    
}

void print_array(int A[],int size_of_array)
{
	for(int i=0;i<size_of_array;i++)
	{
    	cout <<A[i]<<" ";
	}
}

void bubble_sort(int A[], int& size){
    bool swapped = false;
    for(int i=1;i<size;i++){
        for(int j=0;j+1<(size - (i-1));j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

void selection_sort(int A[], int size){
    for(int i=0;i<size-1;i++){
        int min = A[i];
        int index = i;
        for(int j=i+1;j<size;j++){
            if(A[j]<min){
                min = A[j];
                index = j;
            }
        }
        swap(A[index],A[i]);
    }
}

void insertion_sort(int A[], int size){
    for(int i =1;i<size;i++){
        int j = i;
        while(j-1>=0 && A[j-1]>A[j]){
            swap(A[j],A[j-1]);
            j--;
        }
    }
}

int main(){
    const int capacity = 20;
    int A[capacity],size;
    init("data.txt",A,size);
    cout <<"before sort : ";
	print_array(A,size);
    //bubble_sort(A,size);
    //selection_sort(A,size);
    insertion_sort(A,size);
    cout <<"\nafter sort : ";
	print_array(A,size);
	return 0;
}