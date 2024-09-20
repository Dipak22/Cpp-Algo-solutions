#include<iostream>
#include<fstream>
using namespace std;
void loadSet(const char Msg[], int S[], int &size, ifstream &rdr);
void sort(int S[ ], int size);
void setPrint(const char Msg[], int S[], int size);
bool isPresent(int S[], int size, int t);
bool isSubset(int subSet[ ], int sizeSubSet, int supSet[ ], int sizeSupSet);
void subsetTest(int A[ ], int sizeA, int B[ ], int sizeB);
void UNION(int A[ ], int sizeA, int B[ ], int sizeB, int UnionSet[ ], int &sizeU);
void intersection(int A[ ], int sizeA,int B[ ], int sizeB,
                                                    int IntersectionSet[ ],int& iSize);
void crossProduct(const char Msg[],int A1[],int sizeA1,int A2[],int sizeA2);
void setMinus(int A1[ ], int sizeA1,int A2[ ], int sizeA2,int R[ ], int &sizeR);

void loadSet(const char Msg[], int S[ ], int &size, ifstream &rdr){
    rdr>>size;
    cout<<"Size of "<<Msg<<" : "<<size<<endl;
    int input, repeatedElement= false;
    for(int i =0;i<size;i++){
        rdr>>input;
        for(int j=0;j<i;j++){
            if(input == S[j]){
                repeatedElement = true;
                cout << "\n"<<input<<" was repeated!";
				cout << "\nMust have unique elements in the set!\n";
                i--;
                break;
            }
            
        }
        if(!repeatedElement){
                S[i] = input;
        }
        repeatedElement = false;
    }

     cout <<Msg <<" is loaded...!"<<endl;

}
void setPrint(const char Msg[], int S[], int size){
    cout << Msg<<" = {";
	for (int ai = 0; ai <= size - 1; ai++)
	{
		cout << S[ai];
		if (ai != size - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}
void sort(int S[ ], int size){
    for(int i=0;i<size;i++){
        for(int j =0;j+1<size;j++){
            if(S[j]>S[j+1])
                swap(S[j],S[j+1]);
        }
    }
}
bool isPresent(int S[ ], int size, int t)
{
  for(int si=0; si<size; si++)
  {
     if(S[si]==t)
        return true;
     else if(t<S[si])
        return false;
  }
  return false;
}
bool isSubset(int subSet[ ], int sizeSubSet, int supSet[ ], int sizeSupSet){
    for(int i =0;i<sizeSubSet;i++){
        if(!isPresent(supSet,sizeSupSet,subSet[i]))
            return false;
    }
    return true;
}
void subsetTest(int A[ ], int sizeA, int B[ ], int sizeB){
    if(sizeA<= sizeB){
        if(isSubset(A,sizeA,B,sizeB))
            cout<<"\nA is subset of B.\n";
        else
            cout<<"\nNeither is a subset.\n";
    }else{
        if(isSubset(B,sizeB,A,sizeA))
            cout<<"\nB is subset of A.\n";
        else
            cout<<"\nNeither is a subset.\n";
    }
}
void UNION(int A[ ], int sizeA, int B[ ], int sizeB, int UnionSet[ ], int &uSize){
    for(int i=0;i<sizeA;i++)
        UnionSet[i] = A[i];
    uSize = sizeA;
    for(int i =0;i<sizeB;i++){
            if(!isPresent(A,sizeA,B[i])){
                UnionSet[uSize] = B[i];
                uSize++;
            }
    }
    sort(UnionSet,uSize);
}
void intersection(int A[ ], int sizeA,int B[ ], int sizeB,
                                                    int IntersectionSet[ ],int& iSize){

    for(int i =0;i<sizeB;i++){
            if(isPresent(A,sizeA,B[i])){
                IntersectionSet[iSize] = B[i];
                iSize++;
            }
    }

}
void crossProduct(const char Msg[],int A1[],int sizeA1,int A2[],int sizeA2){
    cout << Msg<<": = {\n";
    
    for(int i=0;i<sizeA1;i++){
        cout << "\t";
        for(int j =0;j<sizeA2;j++){
            cout<<"("<<A1[i]<<", "<<A2[j]<<")";
            if(j!=(sizeA2-1) || i!= (sizeA1-1))
                cout<<", ";
        }
    }
    cout << "}";
}
void setMinus(int A1[ ], int sizeA1,int A2[ ], int sizeA2,int R[ ], int &sizeR){
    int ri=0;
    for(int i=0;i<sizeA1;i++){
        if(!isPresent(A2,sizeA2,A1[i])){
            R[ri++] = A1[i];
        }
    }
    sizeR = ri;
}

int main(){
    const int capacity = 100;
    int A[capacity] = {0},sizeA;
    int B[capacity] = {0},sizeB;

    ifstream rdr("sets.txt");
    loadSet("A",A,sizeA,rdr);
    loadSet("B",B,sizeB,rdr);
    
    cout << "\n========\n";
	cout << "Tast 2 - Sorting the two sets" << endl;
    sort(A,sizeA);
    sort(B,sizeB);

    setPrint("A",A,sizeA);
    setPrint("B",B,sizeB);
    subsetTest(A, sizeA, B, sizeB);

    int UnionSet[capacity] = { 0 }, uSize;
    UNION(A,sizeA,B,sizeB,UnionSet,uSize);
    setPrint("UnionSet",UnionSet,uSize);

    int IntersectionSet[capacity] = { 0 };
    int iSize=0;
    intersection(A,sizeA,B,sizeB,IntersectionSet,iSize);
    setPrint("Intersection Set",IntersectionSet,iSize);

    crossProduct("AxB",A,sizeA,B,sizeB);
    cout<<"\n";
    crossProduct("BxA",B,sizeB,A,sizeA);
    int AminusB[capacity],BMinusA[capacity],minusSize; 
    setMinus(A,sizeA,B,sizeB,AminusB,minusSize);
    setPrint("A-B",AminusB,minusSize);
    setMinus(B,sizeB,A,sizeA,BMinusA,minusSize);
    setPrint("B-A",BMinusA,minusSize);

    return 0;

}