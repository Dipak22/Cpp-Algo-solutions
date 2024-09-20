#include <iostream>
#include<cmath>
using namespace std;

void allZeros(int A[], int size);
void wholeNum(int A[], int size);
void naturalNum(int A[], int size);
void evenNum(int A[], int size);
void multipleOfFive(int A[], int size);
void multipleOfNum(int A[], int size,int num);
bool isPrime(int N);
void primeNum(int A[], int size);
void randomNum(int A[], int size);
void randomEven(int A[], int size);
void randomRange(int A[], int size,int start,int end);
void printArray(const char Name[], int A[], int size);

int main()
{
    const int capacity = 100;
    int arrayT[capacity], // A has all garbage values
        size, num;
    cout << "Size(Maximum of 100): ";
    cin>>size;

	// cout <<"allZeros:     {0, 0, 0, 0, 0,	...}" << endl;
     allZeros(arrayT, size);  

	// cout << "wholeNum:     {0, 1, 2, 3, 4,	...}" << endl;
	 wholeNum(arrayT, size);
	
	// cout << "naturalNum:     {1, 2, 3, 4, 5,	...}" << endl;
	 naturalNum(arrayT, size);

	// cout << "evenNum:     {2, 4, 6, 8, 10,	...}" << endl;
	 evenNum(arrayT, size);

	// cout << "multipleOfFive:     {10, 15, 20, 25,	...}" << endl;
	 multipleOfFive(arrayT, size);

	// cout << "multipleOfNum:     {T*0, T*1, T*2, T*3,...} where T is entered by the user" << endl;
	 //cout << "Multiple of (starting from 0):";
	 //cin >> num;
	 //multipleOfNum(arrayT, size,num);
	
	// cout << "primeNum:     {2, 3, 5, 7, 11,	...} Save all the prime numbers" << endl;
	 //primeNum(arrayT, size);

	// cout << "randomNum:     {Assigning random values}" << endl;
	 randomNum(arrayT, size);

	// cout << "randomEven:    {Assigning random Even numbers}" << endl;
	 randomEven(arrayT, size);
	
	// cout << "randomRange:    {Assigning random numbers within a range}" << endl;
	 int start, end;
	 cout << "start: "; 
	 cin>>start;
	 cout << "end: ";
	 cin>>end;
	 randomRange(arrayT, size,start,end);

	printArray("A:", arrayT, size);

    return 0;
}

void allZeros(int A[], int size){
    for(int i=0;i<size;i++)
        A[i] =0;
}

void wholeNum(int A[], int size)
{
    for(int i=0;i<size;i++)
        A[i] =i;
}
void naturalNum(int A[], int size)
{
	for(int i=0;i<size;i++)
        A[i] =i+1;
}
void evenNum(int A[], int size)
{
    int num =2;
	for(int i=0;i<size;i++){
        A[i] = num;
        num +=2;
    }
}
void multipleOfFive(int A[], int size)
{
	for(int i=0;i<size;i++)
        A[i] =(i+1)*5;
}
void multipleOfNum(int A[], int size, int num)
{
	for(int i=0;i<size;i++)
        A[i] =i*num;
}
bool isPrime(int N)
{
    if(N==1)
        return false;
    if(N !=2 && N%2 == 0)
        return false;
    int limit = sqrt(N);
    for(int i =2;i<=limit;i++){
        if(N%i ==0)
            return false;
    }
	return true;
}
void primeNum(int A[], int size)
{
    int k =2;
	for(int i =0;i<size;i++){
        while(!isPrime(k))
            k++;
        A[i] = k;
        k++;
    }
}
void randomNum(int A[], int size)
{
	for(int i=0;i<size;i++){
        A[i] = rand();
    }
}
void randomEven(int A[], int size)
{
	for(int i=0;i<size;i++)
        A[i] = rand()/2 * 2;
}
void randomRange(int A[], int size, int start, int end)
{
	for(int i=0;i<size;i++){
        A[i] = rand()%end + start;
    }
}

void printArray(const char Name[], int A[], int size){
    cout<<Name<<" {";
    for(int i=0;i<size;i++){
        cout<<A[i];
        if(i !=(size-1))
            cout<<", ";
    }
    cout<<"}";
}






