#define maxRows 100
#define maxCols 100
#define max_capacity 1000
#include <iostream>
#include <iomanip>
using namespace std;

bool mapping(int singleDimWorld[], int size, int twoDimWorld[][maxCols], int &rows, int &cols)
{
    if(size <(rows*cols))
        return false;
    int index =0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++)
            twoDimWorld[r][c] = singleDimWorld[index++];
    }
    return true;

}
void print1DWorld(const char Msg[], int projectionMap[max_capacity], int size)
{
    cout << Msg;
    for(int mi=0; mi<size; mi++)
    {
            cout << projectionMap[mi]<<" ";
    }
}

void init(int A[], int size)
{
    int val = 1;
    for(int i=0; i<size; i++)
    {
        A[i] = val++;
    }
}
void print2DMappedWorld(const char Msg[], int TDA[maxRows][maxCols], int rows, int cols)
{
    cout << Msg;
    for(int ri=0; ri<rows; ri++)
    {
        for(int ci=0; ci<cols; ci++)
        {
            cout << setw(3)<<TDA[ri][ci]<<" ";
        }
        cout << endl;
    }
}
int main()
{
    int A[max_capacity]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, size=15;
    int twoDimWorld[maxRows][maxCols], rows=3, cols=4;
    mapping(A, size, twoDimWorld, rows,cols);
       
    print1DWorld("\nOne-dimensional world:\n", A, size);
    if(mapping(A, size, twoDimWorld, rows,cols))
    {
        print2DMappedWorld("\n\nTwo-dimensional mapped world:\n", twoDimWorld, rows, cols);
    }
    else
    {
        cout << "\n\n*** Mapping was not possible...!!! \n";
    }
    
    return 0;
}