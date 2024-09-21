#include<iostream>
#include<cstring>
using namespace std;

void str_reverse_range(char S[], int si, int ei){
    while(si<ei){
        char temp = S[ei];
        S[ei] = S[si];
        S[si] = temp;
        si++;ei--;
    }

}

void reverse_all(char S[]){
    int len = strlen(S);
    str_reverse_range(S,0,len-1);
}

void reverse_word_by_word(char S[ ])
{   
    int si =0;
    int len = strlen(S);
    int i =0;
    while(si<len){
        while(i<len && S[i] != ' '){
            i++;
        }
        if(i != si)
            str_reverse_range(S,si,i-1);
        else
            str_reverse_range(S,si,len-1);
        while(i<len && S[i] == ' ')
            i++;
        si = i;
    }
}
void reverse_sentence_words(char S[ ])
{   
    reverse_all(S);
    reverse_word_by_word(S);
}

int main(){
    char S[ ] = "THIS is A WORLD OF C++";
    cout <<"Before reversing \tS='"<< S <<"'"<< endl;
    reverse_word_by_word(S);
    cout <<" After reversing All\tS='"<< S <<"'"<< endl;
    reverse_word_by_word(S);
    cout <<" After reversing Again\tS='"<< S <<"'"<< endl;

    // Reversing the sentence.
    cout <<"Before sentence reversing \tS='"<< S <<"'"<< endl;
    reverse_sentence_words(S);
    cout <<" After sentence reversing \tS='"<< S <<"'"<< endl;
    reverse_sentence_words(S);
    cout <<" After sentence reversing Again\tS='"<< S <<"'"<< endl;


    return 0;
}