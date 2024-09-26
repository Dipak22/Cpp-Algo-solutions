#include<iostream>
using namespace std;
int main(){
    int inputs[][10] = {{3,2,41,3,34},
                        {-5,-4,-3,-2,-1},
                        {-1,2,3,-4,-10},
                        {1,2,3,7},
                        {2,4,6,8,10}};
    int sizes[] ={5,5,5,4,5};
    int* result;
    for(int i =0;i<sizeof(sizes)/sizeof(int);i++){
        std::cout << i + 1 << ".\tArray: [";
        for (int j = 0; j < sizes[i]; ++j) {
            if(j==sizes[i]-1)
                std::cout << inputs[i][j];
            else
                std::cout << inputs[i][j] << ", ";
        }
        std::cout <<"]"<< std::endl; 
    } 
}