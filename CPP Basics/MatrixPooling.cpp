#include<iostream>
#include<fstream>
using namespace std;
#define MaxRows 100
#define MaxCols 100

void initLoad(char fname[],int M[][MaxCols],int& rows,int& cols,int& wr,int& wc,int& strideR,int& strideC){
    ifstream rdr(fname);
    rdr>>rows>>cols>>wr>>wc>>strideR>>strideC;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            rdr>>M[r][c];
}

void displayGrid(char Msg[],int M[][MaxCols],int rows,int cols){
    cout<<Msg<<endl;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++)
            cout<<M[r][c]<<" ";
        cout<<"\n";
    }
}
int findMax(int M[][MaxCols],int wr,int wc,int sr, int sc){
    int max = M[sr][sc];
    for(int r=0;r<wr;r++){
        for(int c=0;c<wc;c++){
            if(M[sr+r][sc+c]>max)
                max = M[sr+r][sc+c];
        }
    }
    return max;
}
void maxPooling(int M[][MaxCols],int rows,int cols,int MMax[][MaxCols], int& mRows,
                        int& mCols,int wr,int wc,int strideR,int strideC){

    mRows = (rows - wr)/strideR + 1;
    mCols = (cols - wc)/strideC +1;
    for(int r =0;r+wr<=rows;r+=strideR){
        for(int c=0; c+wc<=cols;c+=strideC){
            int windowMax = findMax(M,wr,wc,r,c);
            MMax[r][c] = windowMax;
        }
    }

}

int main(){
    int M[MaxRows][MaxCols], rows,cols,wr,wc,strideR,strideC;
    initLoad("poolMatrix.txt",M,rows,cols,wr,wc,strideR,strideC);
    displayGrid("\nThe Matrix is:", M,rows,cols);
    int MMax[MaxRows][MaxCols], mRows,mCols;
    maxPooling(M,rows,cols,MMax,mRows,mCols,wr,wc,strideR,strideC);
    displayGrid("\nThe Max Pooling Matrix is:", MMax,mRows,mCols);

    return 0;
}