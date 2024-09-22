#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define MaxRows 100
#define MaxCols 100
#define Capacity 100

int binarySize(int aNumber)
{
	int count =0;
    if(aNumber ==0)
        return 1;
    while(aNumber>0){
        aNumber /=2;
        count++;
    }
    return count;
}

void convertToBinary(int binaryMap[][MaxCols], int Numbers[], int size)
{
	for(int i =0;i<size;i++){
        int num = Numbers[i];
        int binSize = binarySize(num);
        binaryMap[i][0] = binSize;
        for(int c=binSize;c>=1;c--){
            binaryMap[i][c] = num%2;
            num /=2;
        }
    }
}
void displayBinary(int binaryMap[][MaxCols], int Numbers[], int size)
{
	int counter = 0;

    for (int i = 0; i < size; i++)
    {
        cout << setw(3)<<right<<Numbers[i] << " : \t";
        counter = binaryMap[i][0];

        for (int j = 1; j <= counter; j++)
            cout<<binaryMap[i][j] << " ";

        cout << endl << endl;
    }
}

int main()
{
	ifstream Rdr("Numbers.txt");
	int size;
	Rdr >> size;
	int binaryMap[MaxRows][MaxCols];
	int Numbers[Capacity];
	for (int i = 0; i < size; i++)
	{
		Rdr >> Numbers[i];
	}
	convertToBinary(binaryMap, Numbers, size);
    displayBinary(binaryMap, Numbers, size);
	return 0;
}






