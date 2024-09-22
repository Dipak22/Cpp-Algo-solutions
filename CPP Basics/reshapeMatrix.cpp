#include <iostream>
#include <iomanip>
using namespace std;

#define maxRows 100
#define maxCols 100

void init(int World[maxRows][maxCols], int rows, int cols)
{
    int val=1;
    for(int r = 0;r<rows;r++)
        for(int c=0;c<cols;c++)
            World[r][c] = val++;
}

bool matrixReshape(int World[][maxCols], int rows, int cols, int mappedWorld[][maxCols], int &mRows, int &mCols) 
{
    int oldWorld = rows * cols;
    int newWorld = mRows * mCols;
    if(oldWorld != newWorld)
        return false;
    int ri=0,ci=0;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++){
            if(ci == mCols){
                ri++;ci =0;
            }
            mappedWorld[ri][ci++] = World[r][c];
        }
    return true;
}

// This function will be called for both the original World
// and also for the mappedWorld.

void print2DWorld(const char Msg[], int TDA[maxRows][maxCols], int rows, int cols)
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
    int World[maxRows][maxCols], rows=10, cols = 10;
    init(World, rows, cols);
    
    print2DWorld("Original World:\n\n", World, rows, cols);
    
    int mappedWorld[maxRows][maxCols], mapRows = 5, mapCols=20;

    if(!matrixReshape(World, rows, cols, mappedWorld, mapRows, mapCols))
    {
        cout << "\n\nReshaping was not possible...!"<<endl;
    }
    else
    {
        print2DWorld("\n\nReshaped World:\n\n", mappedWorld, mapRows, mapCols);    
    }
    
    return 0;
}


