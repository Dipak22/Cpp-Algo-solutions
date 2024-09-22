#include <iostream>
using namespace std;

#define MaxR 100
#define MaxC 100
#define Capacity 1000


void diagonalMapping1(int TDA[MaxR][MaxC], int rows, int cols, int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows* cols;
    for(int ri =0;ri<rows;ri++){
        for(int ci=0,d=ri;d>=0;ci++,d--){
            projectionMap[ai++] = TDA[d][ci];
        }
    }
    for(int ci =1;ci<cols;ci++){
        for(int ri = rows-1,d=ci;d<cols;ri--,d++)
            projectionMap[ai++] = TDA[ri][d];
    }

}


void diagonalMapping2(int TDA[MaxR][MaxC], int rows, int cols, int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows*cols;
    for(int ci =0;ci<cols;ci++){
        for(int ri =0,d=ci;d>=0;d--,ri++)
            projectionMap[ai++] = TDA[ri][d];
    }
    for(int ri = 1; ri<rows;ri++){
        for(int ci=cols-1,d = ri; d<rows;d++,ci--)
            projectionMap[ai++] = TDA[d][ci];
    }
}
void diagonalMapping3(int TDA[MaxR][MaxC], int rows, int cols, int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows* cols;
    bool isEven = true;
    for(int r=0;r<rows;r++){
        //cout<<ai<<" ";
        if(isEven){
            for(int ci =0,d=r;d>=0;d--,ci++)
                projectionMap[ai++] = TDA[d][ci];
        }else{
            for(int ci=r,d=0;ci>=0;d++,ci--)
                projectionMap[ai++] = TDA[d][ci];
        }
        isEven = !isEven;

    }
    for(int d=1;d<cols;d++){
        if(isEven){
            for(int r = rows-1,c =d; c<cols;r--,c++)
                projectionMap[ai++] = TDA[r][c];

        }else{
            for(int c=cols-1,r=d; r<rows; c--, r++)
            {
                projectionMap[ai++] = TDA[r][c];
            }
        }
        isEven = !isEven;
    }
    cout<<"\n";
}

void print2DWorld(const char Msg[], int TDA[MaxR][MaxC], int rows, int cols)
{
    cout << Msg;
    for(int ri=0; ri<rows; ri++)
    {
        for(int ci=0; ci<cols; ci++)
        {
            cout << TDA[ri][ci]<<" ";
        }
        cout << endl;
    }
}
void print1DProjection(const char Msg[], int projectionMap[Capacity], int size)
{
    cout << Msg;
    for(int mi=0; mi<size; mi++)
    {
            cout << projectionMap[mi]<<" ";
    }
}
int main()
{
    int TDA[MaxR][MaxC] = {{1,2,3},{4,5,6},{7,8,9}}, rows=3, cols=3;
    int projectionMap[Capacity], size;
    print2DWorld("Two Dimensional World\n", TDA, rows, cols);

   diagonalMapping1(TDA, rows, cols, projectionMap, size);
   print1DProjection("\n\nProjected World\n", projectionMap, size);
    
   diagonalMapping2(TDA, rows, cols, projectionMap, size);
   print1DProjection("\n\nProjected World\n", projectionMap, size);
    
   diagonalMapping3(TDA, rows, cols, projectionMap, size);
   print1DProjection("\n\nProjected World\n", projectionMap, size);
   
   
    return 0;
}











