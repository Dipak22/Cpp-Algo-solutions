#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* int findSCSLengthRec(string s1,string s2,int index1,int index2,vector<vector<int>> lookup){
    if(s1.length() == index1)
        return s2.length() - index2;
    else if(s2.length() == index2)
        return s1.length() - index1;
    if(lookup[index1][index2] == -1){
        if(s1[index1] == s2[index2])
            lookup[index1][index2] =  1 + findSCSLengthRec(s1,s2,index1+1,index2+1,lookup);
        else{
                int c1 = 1 + findSCSLengthRec(s1,s2,index1+1,index2,lookup);
                int c2 = 1 + findSCSLengthRec(s1,s2,index1,index2+1,lookup);
                lookup[index1][index2] = min(c1,c2);
        }
    
    return lookup[index1][index2];
    }
    
}

int findSCSLength(string s1,string s2){
    vector<vector<int>> lookup(s1.length(),vector<int>(s2.length(),-1));
    return findSCSLengthRec(s1,s2,0,0,lookup);
} */

int findSCSLength(string s1,string s2){
    vector<vector<int>> lookup(s1.length()+1, vector<int>(s2.length()+1,0));
    for(int i=0;i<=s1.length();i++)
        lookup[i][0] = i;
    for(int j = 0;j<=s2.length();j++)
        lookup[0][j] = j;
    for(int i = 1;i<=s1.length();i++){
        for(int j =1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1])
                lookup[i][j] = 1 + lookup[i-1][j-1];
            else{
                lookup[i][j] = 1 + min(lookup[i-1][j],lookup[i][j-1]);
            }
        }
    }
    return lookup[s1.length()][s2.length()];
}



int main() {
  cout << findSCSLength("abcdz", "bdcf") << endl;
  cout << findSCSLength("educative", "educative.io") << endl;
}