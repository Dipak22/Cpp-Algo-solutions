#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MaxRows 100
#define MaxCols 100

void displayAWindow(int M[][MaxCols], int wsr, int wsc, int wr, int wc);

void load(const char fileName[], int M[][MaxCols], int &Rows, int &Cols, int &wr, int &wc, int &strideR, int &strideC)
{
	ifstream Rdr(fileName);
	Rdr >> Rows >> Cols >> wr >> wc >> strideR >> strideC;
	for (int r = 0; r < Rows; r++)
		for (int c = 0; c < Cols; c++)
			Rdr >> M[r][c];
}

void displayGrid(const char Name[], int M[][MaxCols], int Rows, int Cols)
{
	cout << Name << ": {\n\n";
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
			cout << setw(4) << M[r][c];

		cout << endl;
	}

	cout << "}\n\n";
}

int calcSum(int M[][MaxCols],int wr,int wc,int wsr,int wsc){
    int sum = 0;
    for(int r=0;r<wc;r++){
        for(int c=0;c<wc;c++){
            sum += M[wsr+r][wsc+c];
        }
    }
    return sum;
}

int findMaxWindow(int M[][MaxCols], int Rows, int Cols, 
           int wr, int wc, 
              int &mwr, int &mwc,   // this function should store the max window indices
                int strideR=1, int strideC=1)
{
    int max = calcSum(M,wr,wc,0,0);
    for(int r=0;r+wr<=Rows;r+=strideR){
        for(int c=0;c+wc<=Cols;c+=strideC){
            int sum = calcSum(M,wr,wc,r,c);
            if(sum>max){
                max = sum;
                mwr = r;mwc = c;
            }
        }
    }
    cout<<endl;
    cout<<"Max Window of "<<wr<<"x"<<wc<<" is:\n{";
    displayAWindow(M,mwr,mwc,wr,wc);
    cout<<"}\n";
    cout << "Anchored At:[" << mwr << "," << mwc << "] and has teh sum of "<<max;
    return 0;

}

void displayAWindow(int M[][MaxCols], int wsr, int wsc, int wr, int wc)
{
	// Displaying a window anchored at (wsr, wsc) of the size of wrxwc

	cout << "{\n";
	for (int r = 0; r < wr; r++)	// the window is of wr-rows
	{
		cout << "   ";
		for (int c = 0; c < wc; c++)	// the window is of wc-columns
			cout << setw(3) << M[wsr + r][wsc + c] << " ";
		// anchored at (wsc, wsc) hence shifted 
		cout << endl;
	}

	cout << "}";
}

void displayAllWindows(int M[][MaxCols], int Rows, int Cols, int wr, int wc, int strideR = 1, int strideC = 1)
{
	cout << "All the windows of: \t" << wr << " x " << wc << "\nAnd stride of: \t\t" << strideR << " x " << strideC << endl << endl;
	for (int r = 0; 
        r + wr <= Rows;	// one window is of wr size, hence no further stride
		    r += strideR)	// r should be incremented by strideR size
	{
		for (int c = 0; 
            c + wc <= Cols;	// one window is of wc size, hence no further stride
			    c += strideC)	// c should be incremented by strideC size
		{
			cout << "Anchored At:[" << r << "," << c << "]: \n";
			displayAWindow(M, r, c, wr, wc);
			// anchored at[r, c] and of the size wr x wc
			cout << endl << endl;
		}
	}
}
void displayAllWindowsMutuallyExclusively(int M[][MaxCols], int Rows, int Cols, int wr, int wc)
{   // Exercise 1
	cout << "All the mutually exclusive windows of: \t" << wr << " x " << wc  << endl << endl;
	// Write your code here
    for(int r=0;r+wr<=Rows;r+=wr){
        for(int c=0;c+wc<=Cols; c+=wc){
            cout << "Anchored At:[" << r << "," << c << "]: \n";
			displayAWindow(M, r, c, wr, wc);
			// anchored at[r, c] and of the size wr x wc
			cout << endl << endl;
        }
    }


}
int main()
{
	int M[MaxRows][MaxCols], Rows, Cols, wr, wc, strideR, strideC;

	load("SW.txt", M, Rows, Cols, wr, wc, strideR, strideC);
	displayGrid("\n\nThe Matrix M[][] ", M, Rows, Cols);
	//displayAllWindows(M, Rows, Cols, wr, wc, strideR, strideC);
	 //displayAllWindowsMutuallyExclusively(M, Rows, Cols, wr, wc);
	// Exercise 1: uncomment above line of displayAllWindowsMutuallyExclusively() call
	// and comment line with displayAllWindows() function call.
    int mwr=0,mwc =0;
    findMaxWindow(M,Rows,Cols,wr,wc,mwr,mwc,strideR,strideC);
	return 0;
}