#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* int longestCommonSubstrLengthRecurse(string s1,string s2,int index1,int index2,int count,vector<vector<vector<int>>>& lookup){
    if(s1.length()==index1 || s2.length()==index2)
        return count;
    if(lookup[index1][index2][count]==-10){
        int c1 = count;
        if(s1[index1]==s2[index2])
            c1 = longestCommonSubstrLengthRecurse(s1,s2,index1+1,index2+1,count+1,lookup);
        int c2 = longestCommonSubstrLengthRecurse(s1,s2,index1+1,index2,0,lookup);
        int c3 = longestCommonSubstrLengthRecurse(s1,s2,index1,index2+1,0,lookup);
        lookup[index1][index2][count] =  max(c1, max(c2,c3));
    }
    return lookup[index1][index2][count];
}

int longestCommonSubstrLength(string s1,string s2){
    int maxlenhgth = max(s1.size(),s2.size());
    vector<vector<vector<int>>> lookup(s1.size(),
                                vector<vector<int>> (s2.size(),
                                vector<int> (maxlenhgth,-10)));
    return longestCommonSubstrLengthRecurse(s1,s2,0,0,0,lookup);
}  */

int longestCommonSubstrLength(string s1,string s2){
    vector<vector<int>> lookup(s1.length()+1, vector<int>(s2.length()+1,0));
    int maxLength =0;
    for(int i=1;i<=s1.length();i++){
        for(int j =1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]){
                lookup[i][j] = 1 + lookup[i-1][j-1];
                maxLength = max(maxLength,lookup[i][j]);
            }
        }

    }
    return maxLength;
}


int main() {
  string S1 = "www.educative.io/explore";
  string S2 = "educative.io/edpresso";
  string s1 = "0abc321";
  string s2 = "123abcdef";
  cout << longestCommonSubstrLength(s1, s2) << endl;
  cout << longestCommonSubstrLength(S1, S2) << endl;
}