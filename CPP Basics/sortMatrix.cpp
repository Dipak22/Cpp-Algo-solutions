#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#define maxRows 100
#define maxCols 100

void load2DArray(ifstream &rdr, int Array[][maxCols], int &rows, int &cols);
void print2DArray(const char MSG[], int Array[][maxCols], int rows, int cols);

void load2DArray(ifstream &rdr, int Array[][maxCols], int &rows, int &cols){
    rdr>>rows>>cols;
    for(int i=0;i<rows;i++){
        for(int j =0;j<cols;j++)
            rdr>>Array[i][j];
    }
}

void print2DArray(const char MSG[], int Array[][maxCols], int rows, int cols){
    cout << endl << endl;
	cout << MSG;
	cout << endl;
	for (int r = 0; r < rows; r++)
	{
		cout << "\t\t";
		for (int c = 0; c < cols; c++)
		{
			cout << setw(3) << Array[r][c];
		}
		cout << endl;
	}
}
void swapRows(int M[][maxCols], int cols, int ri, int rj)
{
    for(int c=0;c<cols;c++){
        swap(M[ri][c], M[rj][c]);
    }
}
void bubbleSortBasedOnColIndex(int M[][maxCols], int rows, int cols, int ci)
{
    for(int i=0;i<rows;i++){
        for(int r =0;r+1<rows;r++){
            if(M[r][ci]>M[r+1][ci])
                swapRows(M,cols,r,r+1);
        }
    }
}

void radixSort(int M[][maxCols], int rows, int cols)
{
    for(int ci=cols-1; ci>=0; ci--)
        bubbleSortBasedOnColIndex(M, rows, cols, ci);
}

void swapCols(int M[][maxCols], int rows, int ci, int cj)
{
    // Write your code here
	for(int r=0;r<rows;r++){
		swap(M[r][ci],M[r][cj]);
	}
}
void bubbleSortBasedOnRowIndex(int M[][maxCols], int rows, int cols, int ri)
{
    // Write your code here
	for(int c=1;c<=cols;c++){
		for(int i=0;i+1<cols;i++){
			if(M[ri][i]>M[ri][i+1])
				swapCols(M,rows,i,i+1);
		}
	}
}

void matrixSort(int HugeNumbers[maxRows][maxCols], int rows, int cols)
{
    // Write your code here
	for(int i =rows-1;i>=0;i--)
		bubbleSortBasedOnRowIndex(HugeNumbers,rows,cols,i);
}

int main()
{
	/*int HugeNumbers[maxRows][maxCols], 
        sizeOfHugeNums, NoOfDigits;

	ifstream rdr("HugeNumbers.txt");

	// STEP 1: Loading matrix
	load2DArray(rdr, HugeNumbers, sizeOfHugeNums, NoOfDigits);
	
	// STEP 2: Printing matrix
	print2DArray("HugeNumbers (Before sorting):", HugeNumbers, sizeOfHugeNums, NoOfDigits);

	// STEP 3: Sorting matrix
	//radixSort(HugeNumbers, sizeOfHugeNums, NoOfDigits);
	matrixSort(HugeNumbers,sizeOfHugeNums,NoOfDigits);

	// STEP 4: Printing sorted matrix
	print2DArray("HugeNumbers ( After sorting):", HugeNumbers, sizeOfHugeNums, NoOfDigits);*/
	int HugeNumbers[maxRows][maxCols], 
        rows, cols;
	ifstream rdr("HugeNumbers.txt");

	// STEP 1: Loading matrix
	load2DArray(rdr, HugeNumbers, rows, cols);
	cout << "rows:"<<rows<<" cols:"<<cols<<endl;
	// STEP 2: Printing matrix
	print2DArray("HugeNumbers (Before sorting):", HugeNumbers, rows, cols);

	// STEP 3: Sorting matrix
	matrixSort(HugeNumbers, rows, cols);

	// STEP 4: Printing sorted matrix
	print2DArray("HugeNumbers ( After sorting):", HugeNumbers, rows, cols);

	return 0;
}