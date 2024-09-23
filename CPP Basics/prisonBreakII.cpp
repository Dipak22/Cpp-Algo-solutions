#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define maxRows 100
#define maxCols 100

void load2DArray(ifstream &rdr, int aPrisonMap[][maxCols], int &rows, int &cols)
{
	rdr>>rows>>cols;
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            rdr>>aPrisonMap[r][c];

}
void print2DArray(const char MSG[], int aPrisonMap[][maxCols], int rows, int cols)
{
	cout<<endl<<endl<<MSG<<" \n";
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++)
            cout<<aPrisonMap[r][c]<<" ";
        cout<<endl;}

}
void one_Stride_Forward(int ri, int ci, int aPrisonMap[][maxCols], int rows, int cols, bool &changeHappen)
{
    for(int r=ri-1;r<=ri+1;r++){
        for(int c= ci-1;c<=ci+1;c++){
            if((r<0 || r>=rows) || (c<0 || c>=cols) ||(r==ri && c==ci))
                continue;
            else if(aPrisonMap[r][c] ==0){
                aPrisonMap[r][c] = 3;
                changeHappen = true;
            }
        }
    }
}
void calculate_Prisoner_s_Approachable_Strides(int aPrisonMap[][maxCols], int rows, int cols)
{
	bool changeHappen = false;
    bool prisonerFound = false;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            if(aPrisonMap[r][c] ==2){
                one_Stride_Forward(r,c,aPrisonMap,rows,cols,changeHappen);
                prisonerFound = true;
                break;
            }
        }
        if(prisonerFound)
            break;
    }
    do{
        changeHappen = false;
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    if(aPrisonMap[r][c] ==3){
                        one_Stride_Forward(r,c,aPrisonMap,rows,cols,changeHappen);
                    }
                }
            }

    }while(changeHappen);

}
bool hasPrisoner_ReachBoundary(int aPrisonMap[ ][maxCols], int rows, int cols)
{
	for(int c=0;c<cols;c++){
        if(aPrisonMap[0][c]==2 || aPrisonMap[0][c] ==3)
            return true;
        if(aPrisonMap[rows-1][c]==2 || aPrisonMap[rows-1][c] ==3)
            return true;
    }
    for(int r=0;r<rows;r++){
        if(aPrisonMap[r][0]==2 || aPrisonMap[r][0] ==3)
            return true;
        if(aPrisonMap[r][cols-1]==2 || aPrisonMap[r][cols-1] ==3)
            return true;
    }
    return false;
		
}
bool isPrisonBreakable(int aPrisonMap[][maxCols], int rows, int cols)
{
	calculate_Prisoner_s_Approachable_Strides(aPrisonMap,rows,cols);
    return hasPrisoner_ReachBoundary(aPrisonMap,rows,cols);

}
void prison_BreakSolver(int aPrisonMap[][maxCols], int rows, int cols)
{
	if(isPrisonBreakable(aPrisonMap,rows,cols))
        cout<<"Free";
    else
        cout<<"Prisoned for life...";

}

int main()
{
	int aPrisonMap[maxRows][maxCols], rows, cols;
    ifstream rdr("map2.txt");
    int noMps;
    rdr>>noMps;
    for(int ci=1; ci<=noMps; ci++)
    {
        load2DArray(rdr, aPrisonMap, rows, cols);
        print2DArray(("Prison "+to_string(ci)+": ").c_str(), aPrisonMap, rows, cols);
        prison_BreakSolver(aPrisonMap, rows, cols);
        print2DArray(("After All Strides "), aPrisonMap, rows, cols);
        
        cout <<endl;
    }

	return 0;
}