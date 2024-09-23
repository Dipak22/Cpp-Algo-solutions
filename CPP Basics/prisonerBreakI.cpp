#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define maxRows 40
#define maxCols 80

// Follow the guidance provided in the lesson

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

bool isPrisonBreakable(int aPrisonMap[][maxCols], int rectangleStartRow, 
						int rectangleStartCol, int rectangleEndR, int rectangleEndC)
{
    for(int c = rectangleStartCol;c<=rectangleEndC;c++){
        if(aPrisonMap[rectangleEndR][c] == 0 || aPrisonMap[rectangleStartRow][c]==0)
            return true;
    }
    for(int r = rectangleStartRow;r<=rectangleEndR;r++){
        if(aPrisonMap[r][rectangleStartCol]==0 || aPrisonMap[r][rectangleEndC]==0)
            return true;
    }
    return false;
	
}
void findPrisonerLocation(int aPrisonMap[][maxCols], int rows, int cols, 
										int &PrisonerR, int &PrisonerC)
{
	bool found = false;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            if(aPrisonMap[r][c] ==2){
                PrisonerR = r;
                PrisonerC = c;
                found = true;
                break;
            }
        }
        if(found)
            break;
    }
}
bool isPrisonerAlreadyFree(int rectangleStartR, int rectangleStartC, 
			int rectangleEndR, int rectangleEndC, int prisonerR, int prisonerC)
{
	return !((rectangleStartR<prisonerR && prisonerR<rectangleEndR) && 
        (rectangleStartC<prisonerC && prisonerC<rectangleEndC));
}
void findWallBoundary(int aPrisonMap[][maxCols], int rows, int cols, 
		int& rectangleStartR, int& rectangleStartC, int &rectangleEndR, int &rectangleEndC)
{
    bool topCorner = false, bottomCorner = false;
	for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            if(aPrisonMap[r][c]==1){
                rectangleStartR = r;
                rectangleStartC = c;
                //aPrisonMap[r][c] = 25;
                topCorner = true;
                break;
            }
        }
        if(topCorner)
            break;
    }

    for(int r= rows-1;r>=0;r--){
        for(int c= cols-1;c>=0;c--){
            if(aPrisonMap[r][c] ==1){
                rectangleEndR = r;
                rectangleEndC = c;
                //aPrisonMap[r][c] = 25;
                bottomCorner = true;
                break;
            }
        }
        if(bottomCorner)
            break;
    }
}
void prison_BreakSolver(int aPrisonMap[][maxCols], int rows, int cols)
{
	int rectangleStartR,rectangleStartC,rectangleEndR,rectangleEndC,prisonerR,prisonerC;
    bool Free, Breakable;
    findWallBoundary(aPrisonMap,rows,cols,rectangleStartR,rectangleStartC,
        rectangleEndR,rectangleEndC);
    findPrisonerLocation(aPrisonMap,rows,cols,prisonerR,prisonerC);
    Free = isPrisonerAlreadyFree(rectangleStartR,rectangleStartC,rectangleEndR,
        rectangleEndC,prisonerR,prisonerC);
    Breakable = isPrisonBreakable(aPrisonMap, rectangleStartR, rectangleStartC, rectangleEndR, rectangleEndC);
	// STEP 5
	if (Free == 1)
		cout << "The prisoner is already free.";
	else if (!Free && !Breakable)
		cout << "The prisoner is imprisoned for life.";
	else if (!Free && Breakable)
		cout << "The prisoner is inside the prison but can break free.";
    
}
int main()
{
    int aPrisonMap[maxRows][maxCols], rows,cols;
    int noOfMaps;
    ifstream rdr("Maps.txt");
    rdr>>noOfMaps;
    for(int i=1;i<=noOfMaps;i++){
        load2DArray(rdr,aPrisonMap,rows,cols);
        print2DArray(("Prison "+to_string(i)+": ").c_str(),aPrisonMap,rows,cols);
        prison_BreakSolver(aPrisonMap,rows,cols);
                //print2DArray(("Prison "+to_string(i)+": ").c_str(),aPrisonMap,rows,cols);

    }
	
	return 0;
}


