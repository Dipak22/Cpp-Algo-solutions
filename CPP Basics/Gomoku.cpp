#include <iostream>
#include<time.h>
#define CAPACITY 100
using namespace std;

void init(char Board[][CAPACITY], int& dim, char pName[2][30], char pSym[], int&NOP, int& turn, int& winCount);
void printBoard(char Board[][CAPACITY], int  dim);
void askForMove(int& ri, int& ci, char pName[], char pSym);
bool isValidMove(int ri, int ci, char Board[][CAPACITY], int dim);
void updateBoard(char Board[][CAPACITY], int  dim, int ri, int ci, char pSym);
void turnChange(int& turn, int NOP);

int main()
{
    cout <<"\n\n\t\t\tThe Game of Gomoku...!!!\n\n";
    cout <<"\n\n\t\t\t    Let us play...!\n\n"<<endl;
	srand(time(0));
	char choice;
	char Board[CAPACITY][CAPACITY];
	char pName[2][30];
	char pSym[2];
	int NOP, winCount, dim;
	int turn, ri, ci;
	
	cout <<"Initializing..."<<endl;
	// passing the function arguments in the same 
	  // order as the function expects them
	init(Board, dim, pName, pSym, NOP, turn, winCount);
	// steps to repeat for each player's turn 
	do
	{
		printBoard(Board, dim);
		// do while loop to ensure the input entered is valid 
		do 
		{
		    askForMove(ri, ci, pName[turn], pSym[turn]);
		    if(!isValidMove(ri, ci, Board, dim))
            {		    			
					cout << "Invalid Input" << endl;

			}
		}
        while(!isValidMove(ri, ci, Board, dim));

		updateBoard(Board, dim, ri, ci, pSym[turn]);
		turnChange(turn, NOP);
	}
	while(true);
}


void init(char Board[][CAPACITY], int& dim, char pName[2][30], char pSym[], int&NOP, int& turn, int& winCount)
{
	cout << "Dimension: ";
	cin >> dim;
	cout << "Win Count: ";
	cin >> winCount;
	cout << "# of Players: ";
	cin >> NOP;
	for (int i = 0; i < NOP; i++)
	{
		cout << "Enter player " << i + 1 << "'s name: ";
		cin >> pName[i]; // or cin.getline(Pname[i], 100) for full name
	}
	for (int i = 0; i < NOP; i++)
	{
		cout << "Enter player " << i + 1 << "'s symbol: ";
		cin >> pSym[i];  
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Board[ri][ci] = '-';
		}
	}
	turn = rand() % 2;
}
void printBoard(char Board[][CAPACITY], int  Dim)
{
	system("clear");   
	cout << endl;
	cout << setw(4) << " ";
	for( int ci = 0; ci < Dim; ci++)
	{
      cout << left << setw(5) << ci+1; 
	}
	cout << endl;
	for (int ri = 0; ri < Dim; ri++)
	{
		cout << setw(4) << ri+1;  
		for (int ci = 0; ci < Dim; ci++)
		{
			cout << Board[ri][ci] << "    ";
		}
		cout << endl;
	}
}
void askForMove(int& ri, int& ci, char pName[], char pSym)
{
	cout << pName << "'s turn to place '" << pSym << "' (ri, ci): " ;
	cin >> ri;
	cin >> ci;
        // subtracting 1 from ri and ci because our row and column indices start from (0,0)
	ri--;
	ci--;
}
bool isValidMove(int ri, int ci, char Board[][CAPACITY], int dim)
{
	return ((ri >= 0 && ci >= 0) && (ri <= dim && ci <= dim) && Board[ri][ci] == '-');
}
void updateBoard(char Board[][CAPACITY], int  dim, int ri, int ci, char pSym)
{
	Board[ri][ci] = pSym;
}
void turnChange(int& turn, int NOP)
{
	turn = (turn + 1) % NOP;
}






