#include <iostream>
#include <iomanip>
#include<Windows.h>
using namespace std;

#define MaxRows 100
#define MaxCols 100
#define Capacity 10000

// initializing the grid
void squareInit(int Grid[MaxRows][MaxCols], int Rows, int Cols, int val=1)
{
     int rank = min(Rows, Cols);

     int v = val; 
    
    for(int sqri =0;sqri<rank/2;sqri++){
        for(int ci =sqri;ci<Cols-1-sqri;ci++)
            Grid[sqri][ci] = v++;

        for(int ri = sqri; ri<=Rows-1-(sqri+1); ri++)  
        {
            Grid[ri][Cols-1-sqri] = v++;
        } 
            
        for(int ci = Cols-1-sqri;ci>sqri;ci--)
            Grid[Rows-1-sqri][ci] = v++; 
            
        // for loop for bottom to top pattern
        for(int ri = Rows-1-sqri;ri>sqri;ri--)
            Grid[ri][sqri] = v++;

    }   
     Grid[rank/2][Cols/2] = v;   
     
}

// displaying the grid
void printR2_Grid(const char Msg[], int Grid[MaxRows][MaxCols], int Rows, int Cols)
{
    cout << Msg;
    for(int ri=0; ri<Rows; ri++)
    {
        for(int ci=0; ci<Cols; ci++ )
           cout << setw(4)<<Grid[ri][ci] ;
        cout << endl;
    }
}

void PrintR2_World(const char Msg[], int World[MaxRows][MaxCols], int Rows, int Cols) {
    system("clear");
    cout << Msg;
    for(int ri=0; ri<Rows; ri++)
    {
        for(int ci=0; ci<Cols; ci++ )
           cout << setw(4)<<World[ri][ci] ;
        cout << endl;
    }
}

void CWRotatingRectangles(int World[MaxRows][MaxCols], int Rows, int Cols) {
    int rank = min(Rows,Cols);
    int prev;
    for(int sqri= 0;sqri<rank/2;sqri++){
        prev = World[sqri][sqri];
        for(int ci = sqri;ci<Cols-1-sqri;ci++){
            swap(prev,World[sqri][ci]);
        }
        for(int ri = sqri;ri<Rows-1-sqri;ri++)
            swap(prev,World[ri][Cols-1-sqri]);
        for(int ci = Cols-1-sqri;ci>sqri;ci--)
            swap(prev,World[Rows-1-sqri][ci]);
        for(int ri = Rows-1-sqri;ri>sqri;ri--)
            swap(prev,World[ri][sqri]);
        World[sqri][sqri]=prev;
    }
    
}

int main()
{
    int val;
    cout << "The initializing value: " << endl;
    cin >> val;
    int Grid[MaxRows][MaxCols]={{}}; 
    int Rows=7, Cols=7;

     squareInit(Grid, Rows, Cols, val);
     printR2_Grid("Grid:\n\n", Grid, Rows, Cols);
    
    while(true)
    {
        CWRotatingRectangles(Grid, Rows, Cols);
        PrintR2_World("R^2 World:\n\n", Grid, Rows, Cols);
        cout << flush;
        Sleep(1);
    }    
    return 0;
}

