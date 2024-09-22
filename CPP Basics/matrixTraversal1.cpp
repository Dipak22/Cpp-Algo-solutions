#include <iostream>
using namespace std;

#define MaxR 100
#define MaxC 100
#define Capacity 10000

void MappingCase1(int TDA[MaxR][MaxC], int rows, int cols, 
                      int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows*cols;
    for(int ri =0;ri<rows;ri++){
        for(int ci = 0;ci<cols;ci++){
            projectionMap[ai++] = TDA[ri][ci];
        }
    }

}
void MappingCase2(int TDA[MaxR][MaxC], int rows, int cols, 
                      int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows*cols;
    for(int ri =0;ri<rows;ri++){
        if(ri%2 ==0){
            for(int ci = 0;ci<cols;ci++){
            
                projectionMap[ai++] = TDA[ri][ci];
            }
        }
        else{
            for(int ci = cols-1;ci>=0;ci--){
                projectionMap[ai++] = TDA[ri][ci];
            }
        }
        
    }

}

// Exercise
void MappingCase3(int TDA[MaxR][MaxC], int rows, int cols, 
                      int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows*cols;
    for(int ci =0;ci<cols;ci++){
        for(int ri =0;ri<rows;ri++){
            projectionMap[ai++] = TDA[ri][ci];
        }
    }

}

void MappingCase4(int TDA[MaxR][MaxC], int rows, int cols, 
                      int projectionMap[Capacity], int &size)
{
    int ai =0;
    size= rows*cols;
    for(int ci = 0;ci<cols;ci++){
        if(ci%2==0){
            for(int ri =0;ri<rows;ri++){
                projectionMap[ai++] = TDA[ri][ci];
            }
        }
        else{
            for(int ri =rows-1;ri>=0;ri--)
                projectionMap[ai++] = TDA[ri][ci];
        }
    }

}

// Exercise
void MappingCase5(int TDA[MaxR][MaxC], int rows, int cols, 
                      int projectionMap[Capacity], int &size)
{
    int ai =0;
    size = rows*cols;
    for(int ri = rows-1;ri>=0;ri--){
        for(int ci =0;ci<cols;ci++)
            projectionMap[ai++] = TDA[ri][ci];
    }

}

void print2DWorld(const char msg[], int TDA[MaxR][MaxC], int rows, int cols)
{
    cout << msg;
    for(int ri=0; ri<rows; ri++)
    {
        for(int ci=0; ci<cols; ci++)
        {
            cout << TDA[ri][ci]<<" ";
        }
        cout << endl;
    }
}
void print1DProjection(const char msg[], int projectionMap[Capacity], int size)
{
    cout << msg;
    for(int mi=0; mi<size; mi++)
    {
            cout << projectionMap[mi]<<" ";
    }
}
int main()
{
    int TDA[][MaxC] = {{1,2,3},{4,5,6},{7,8,9}}, rows=3, cols=3;
    int projectionMap[Capacity], size;
    print2DWorld("Two Dimensional World:\n", TDA, rows, cols);
    MappingCase1(TDA, rows, cols, projectionMap, size);
    print1DProjection("Projected World 1:\n", projectionMap, size);
    
    MappingCase2(TDA, rows, cols, projectionMap, size);
    print1DProjection("\n\nProjected World 2:\n", projectionMap, size);
    
    MappingCase3(TDA, rows, cols, projectionMap, size);
    print1DProjection("\n\nProjected World 3:\n", projectionMap, size);
    
    MappingCase4(TDA, rows, cols, projectionMap, size);
    print1DProjection("\n\nProjected World 4:\n", projectionMap, size);
    
    MappingCase5(TDA, rows, cols, projectionMap, size);
    print1DProjection("\n\nProjected World 5:\n", projectionMap, size);
    
   
    return 0;
}