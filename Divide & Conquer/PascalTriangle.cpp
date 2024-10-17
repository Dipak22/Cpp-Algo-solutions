#include<iostream>
using namespace std;

int* pascalTriangleRecursive(int lineNumber){
    int currLineNUmber = lineNumber;
    int prevLineNUmber = currLineNUmber -1;
    if(lineNumber ==1){
        int* currLine =new int[currLineNUmber];
        currLine[0] = 1;
        return currLine;
    }
    int* currLine = new int[currLineNUmber];
    int* previousLine = pascalTriangleRecursive(prevLineNUmber);
    for(int i = 0;i<currLineNUmber;i++){
        int leftCoeff = (i-1)<0? 0: previousLine[i-1];
        int rightCoeff = i<prevLineNUmber ? previousLine[i]:0;
        currLine[i] = leftCoeff + rightCoeff; 
    }
    delete previousLine;
    return currLine;
}

int lineNumber = 6;
int main(){
    int* arr = pascalTriangleRecursive(lineNumber);
    for(int i = 0; i<lineNumber; i++){
        cout << arr[i] << " ";
    }
  	delete arr;
  	return 0;
}