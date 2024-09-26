#include<iostream>
#include<vector>
using namespace std;

vector<int> MergeArrays(vector<int> nums1, vector<int> nums2){
    vector<int> result(nums1.size()+ nums2.size());
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    while(p1<nums1.size() && p2<nums2.size()){
        if(nums1[p1]<=nums2[p2])
            result[p3++] = nums1[p1++];
        else
            result[p3++] = nums2[p2++];
        
    }
    while(p1<nums1.size())
        result[p3++] = nums1[p1++];
    while(p2<nums2.size())
        result[p3++] = nums2[p2++];
    return result;
}

int main(){
    vector<vector<int>> nums1 = {
        {23,33,35,41,44,47,56,91,105},
        {1,2},
        {1,1,1},
        {6},
        {12,34,45,56,67,78,89,99}
    };

    vector<vector<int>> nums2 = {
        {32, 49, 50, 51, 61, 99},
        {7},
        {1, 2, 3, 4},
        {-99, -45},
        {100}
    };

    vector<int> size1 = {9, 2, 3, 1, 8};
    vector<int> size2 = {6, 1, 4, 2, 1};

    for(size_t i =0;i<nums1.size();++i){
        cout<<i+1<<" .\1First Array: [ ";
        for(size_t j=0;j<size1[i];++j){
            cout<<nums1[i][j]<<" ";
        }
        cout<<"]"<<endl;
        cout<<"\tSecond Array: [ ";
        for(size_t j=0;j<size2[i];++j){
            cout<<nums2[i][j]<<" ";
        }
        cout<<"]"<<endl;

        vector<int> merged = MergeArrays(nums1[i], nums2[i]);
        cout << "\tMerged array: [ ";
        for (int num : merged) {
            cout << num << " ";
        }
        cout <<"]"<< endl;

        string line(100, '-');
        cout << line << endl;
    }

    return 0;
}