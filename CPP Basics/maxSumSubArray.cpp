#include<iostream>
using namespace std;
void PrintSubArray(char Msg[],int A[],int start,int end){
    cout<<Msg<<": { ";
    for(int i=start;i<=end;i++)
        cout<<A[i]<<" ";
    cout<<"}";
}
int MaximumSumSubArraySlow3Nested(int A[],int size,int& msi,int& mei){
    int Max = A[0];
    msi =0;
    mei = 0;
    for(int i =0;i<size;i++){
        int sum = 0;
        for(int e = i;e<size;e++){
            //for(int s = i; s<=e;s++)
            sum +=A[e];
            if(sum>Max){
                Max = sum;
                msi = i;
                mei = e;
            }
        }
    }
    return Max;
}
int MaximumSumSubArrayFASTKadane_Algo(int A[],int Size,int& msi,int& mei){
    int max = A[0];
    msi =0;
    mei = 0;
    int s = 0;
    int sum =0;
    for(int e =0;e<Size;e++){
        sum +=A[e];
        if(sum>max){
            max=sum; msi = s;mei = e;
        }
        if(sum<0){
            sum =0;
            s= e+1;
        }
    }
    return max;
}
int main(){
    int A[10] = {-100, 4, 2, 7, 13, 0, -4, 6, -10, 5}, Size = 10;
	int msi, mei;
	//int MaxSum = MaximumSumSubArraySlow3Nested(A, Size, msi, mei);
    int MaxSum = MaximumSumSubArrayFASTKadane_Algo(A, Size, msi, mei);
	PrintSubArray("The Original Array", A, 0, Size - 1);
	PrintSubArray("\n\nThe Maximum Sum Subarray", A, msi, mei);
	cout << " with sum of : " << MaxSum << endl;

	return 0;
}