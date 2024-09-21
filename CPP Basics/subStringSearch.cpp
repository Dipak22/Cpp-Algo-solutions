#include<iostream>
#include<cstring>
using namespace std;

int substring_index(char S[],char sub[]){
    int window_size = strlen(sub);
    int str_len = strlen(S);
    for(int i =0;i+window_size<str_len;i++){
        for(int j = 0;j<window_size;j++){
            if(S[i+j] != sub[j])
                break;
            else if(j==window_size-1)
                return i;
        }
    }
    return -1;
}

void printSpecial(int times, char S[], char sub[], int Is[])
{
    if(times!=0)
    {
        cout << S<<endl;
        int ti=0;
        for(int i=0;ti!=times; i++)   // Printing location where exactly found.
        {
            if(Is[ti]!=i)
                cout << ' ';
            else
                cout << '^', ti++;
                
        }
        cout<< endl << sub <<" found " << times << " times!" <<endl;
    }
    else
    {
        cout<< endl << sub <<" was not found "<<endl;
    }
}
int substring_index_all(char S[],char sub[], int Is[]){
    int str_len = strlen(S);
    int window_size = strlen(sub)-1;
    int index =0;
    int count =0;
    for(int i=0;i+window_size<str_len;i++){
        for(int j =0;j<= window_size;j++){
            if(S[i+j] != sub[j])
                break;
            else if(j == window_size){
                Is[index++] = i;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    const int capacity = 100;
    char S[ ] = "helloaaabbcabbc";
    char sub[] = "abbc";
    
    int Is[capacity] = {};
    int times = substring_index_all(S, sub,Is);
    printSpecial(times, S, sub, Is);

    return 0;    
}
