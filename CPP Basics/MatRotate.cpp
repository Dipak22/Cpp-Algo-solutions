#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

#define maxRows 100
#define maxCols 100

void load2DArray(ifstream &Rdr, int matrix[][maxCols], int &rows, int &cols)
{
	Rdr >> rows >> cols;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			Rdr >> matrix[r][c];
		}
	}
}
void print2DArray(const char MSG[], int matrix[][maxCols], int rows, int cols)
{
	cout << endl << endl;
	cout << MSG;
	cout << endl;
	for (int r = 0; r < rows; r++)
	{
		cout << "\t\t";
		for (int c = 0; c < cols; c++)
		{
			cout << setw(3) << matrix[r][c];
		}
		cout << endl;
	}
}

void load2DArray(ifstream &Rdr, int matrix[][maxCols], int &rows, int &cols);
void print2DArray(const char MSG[], int matrix[][maxCols], int rows, int cols);
// Assume we have the above implementations

void swapCols(int Array[][maxCols], int c1, int c2, int rows)
{
	for (int ri = 0; ri < rows; ri++)
	{
		int t = Array[ri][c1];
		Array[ri][c1] = Array[ri][c2];
		Array[ri][c2] = t;
	}
}
void rotateRight2DArrayByCols(int Matrix[][maxCols], int rows, int cols)
{
	for (int c = cols - 1; c > 0; c--)
	{
		swapCols(Matrix, c, c - 1, rows);
	}
}
void rotateLeft2DArrayByCols(int Array[][maxCols], int rows, int cols)
{   
    for(int c= 0;c+1<cols;c++){
        swapCols(Array,c,c+1,rows);
    }
}
void swapRows(int Array[][maxCols], int r1, int r2, int cols)
{   
    for(int c =0;c<cols;c++){
        int temp = Array[r1][c];
        Array[r1][c] = Array[r2][c];
        Array[r2][c] = temp;
    }
}
void rotateDown2DArrayByRows(int Array[][maxCols], int rows, int cols)
{
	for(int i=0;i+1<rows;i++){
        swapRows(Array,i,i+1,cols);
    }
}
void rotateUp2DArrayByRows(int Array[][maxCols], int rows, int cols)
{
	for(int r = rows-1;r-1>=0;r--){
        swapRows(Array,r,r-1,cols);
    }
}
int main()
{
	int Matrix[maxRows][maxCols], rows, cols;
	ifstream Rdr("Matrix.txt");
	
	// STEP 1: Load Matrix
	load2DArray(Rdr, Matrix, rows, cols);

	// STEP 2: Print the Matrix
	print2DArray("Matrix:", Matrix, rows, cols);

	// STEP 3: Rotate the Matrix
    //rotateRight2DArrayByCols(Matrix, rows, cols);
        //rotateLeft2DArrayByCols(Matrix, rows, cols);
    //rotateUp2DArrayByRows(Matrix, rows, cols);
    rotateDown2DArrayByRows(Matrix, rows, cols);
	// STEP 4: Print the Rotated Matrix
	print2DArray("Rotate Matrix by Column:", Matrix, rows, cols);

	// Add the calls to the respective function calls (of exercises)
	
	return 0;
}
