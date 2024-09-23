#include <iostream>
using namespace std;

#define MaxRows 100
#define MaxCols 100
#define Capacity 1000

void allPossibleWindows(int R[][MaxCols], int Rows, int Cols)
{
	// for each starting row index 
	for (int sri = 0; sri < Rows; sri++)
	{
		// for each starting column index
		for (int sci = 0; sci < Cols; sci++)
		{
			// for each ending row index
			cout << "Anchored at[" << sri << "," << sci << "]: " << endl << endl;
			for (int eri = sri; eri < Rows; eri++)
			{
				// for each ending column index
				for (int eci = sci; eci < Cols; eci++)
				{
					cout << "[" << sri << "," << sci << "]" <<
						"[" << eri << "," << eci << "]  ";
				}
			}

			cout << endl << endl;
		}
	}
}

int MaximumSumSubRectangleSlow6NestedLoops(int M[][MaxCols], int Rows, int Cols,
	int &msri, int &msci, int &meri, int &meci){
    
    int MaxSumWindow = M[0][0];
    msri = 0;msci = 0; meri= 0;meci=0;
    for(int sri = 0;sri<Rows;sri++){
        for(int sci = 0; sci<Cols;sci++){
            int WinSum = 0;
            int PrevSum[MaxCols]{};
            for(int eri = sri;eri<Rows;eri++){
                int LinearSum =0;
                for(int eci=sci;eci<Cols;eci++){
                    LinearSum +=M[eri][eci];
                    WinSum = PrevSum[eci] + LinearSum;
                    PrevSum[eci] = WinSum;
                    if(WinSum>MaxSumWindow){
                        MaxSumWindow = WinSum;
                        msri = sri;
                        meri = eri;
                        msci = sci;
                        meci = eci;
                    }
                }
            }
        }
    }
    return MaxSumWindow;

}

int MaximumSumSubRectangleSlow3NestedLoopsKadane(int M[][MaxCols], int Rows, int Cols,
	int &msri, int &msci, int &meri, int &meci){

    int MaxSumWindow = M[0][0];
    msri = 0;msci = 0; meri= 0;meci=0;
    for(int sri =0;sri<Rows;sri++){
        int PrevRowSum[MaxCols] ={};
        for(int eri =sri;eri<Rows;eri++){
            int sum =0;
            for(int s=0,e=0;e<Cols;e++){
                PrevRowSum[e] +=M[eri][e];
                sum += PrevRowSum[e];
                if(MaxSumWindow<sum){
                    MaxSumWindow = sum;
                    msri = sri;
                    meri = eri;
                    msci = s;
                    meci = e;
                }
                if(sum<0){
                    sum =0;
                    s= e+1;
                }
            }

        }
    }
    return MaxSumWindow;
    
}

int main()
{
	int R[MaxRows][MaxCols] = { { 10, 10, -40 },
								{-80, 40, 10  },
								{ 30, 80, 100 }
							   };

	int Rows = 3, Cols = 3,msri, msci,
		meri, meci;

	//allPossibleWindows(R, Rows, Cols);
    //cout << "Maximum sum rectangle with N^6 is: " <<
	//MaximumSumSubRectangleSlow6NestedLoops(R, Rows, Cols, msri, msci, meri, meci) << endl;
    cout << "Maximum Sum rectangle with N^3 is: " << MaximumSumSubRectangleSlow3NestedLoopsKadane(R, Rows, Cols, msri, msci, meri, meci) << endl;
	cout << "Anchored at: (" << msri << "," << msci << ")" << endl;
	cout << "    Ends at: (" << meri << "," << meci << ")" << endl;

	return 0;
}