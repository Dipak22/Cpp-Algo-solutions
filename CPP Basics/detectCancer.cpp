#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MaxRows 100
#define MaxCols 100

void loadImageMap(const char fName[], int Map[][MaxCols], int &rows, int &cols)
{
    ifstream Rdr(fName);
    Rdr>>rows>>cols;
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            Rdr>>Map[r][c];
        }
    }
}

void displayMap(int Map[][MaxCols], int rows, int cols)
{
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            cout <<Map[r][c] << " ";
        }
        cout << endl;
    }
}

void displayWindowMap(int Map[][MaxCols], int rows, int cols, int cr, int cc, int cK)
{
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            if (r >= cr && c >= cc && r < cr + cK && c < cc + cK)
                cout <<Map[r][c] << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

bool isCancerousRegion(int K, int zeroCount)
{
    return (zeroCount>(0.7 * K * K))? true:false;
}

int countBlackPixels(int data[][MaxCols], int sr, int sc, int k)
{
    int count =0;
	for(int r=0;r<k;r++){
        for(int c=0;c<k;c++){
            if(data[sr+r][sc+c] ==0)
                count++;
        }   
    }
    return count;
}

void searchCancerRegion(int data[][MaxCols], int rows, int cols, int &cr, int &cc, int &cK)
{
     cK = -1;
     int max = 0;
     for(int k = min(rows,cols);k>=2;k--){
        for(int r = 0; r+k<=rows;r++){
            for(int c=0;c+k<=cols;c++){
                int ZeroCount = countBlackPixels(data,r,c,k);
                if(isCancerousRegion(k,ZeroCount)){
                    if(ZeroCount>max){
                        max = ZeroCount;
                        cr = r;
                        cc = c;
                        cK = k;
                    }
                }
            }
        }
        if(cK !=-1)
            return;
     }
}

int main()
{
	int imageMap[MaxRows][MaxCols], rows, cols;
    int cr, cc, cK;
    loadImageMap("cancer.txt",imageMap, rows, cols);
    displayMap(imageMap, rows, cols);
    searchCancerRegion(imageMap, rows, cols, cr, cc, cK);
    if(cK==-1)
    {
        cout << "\nCancer not found...!\n";
    }
    else
    {
        cout << "\nCancer found....!\n";
        cout << "Size: "<< cK<<"x"<<cK<<"\t at: ("<<cr <<","<< cc << ")" <<endl;
        displayWindowMap(imageMap, rows, cols, cr, cc, cK); // Prints the map with only the window pixels highlighted
    }
	
	return 0;
}