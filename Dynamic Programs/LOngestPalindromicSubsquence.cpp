#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* int LPSLengthRec(vector<vector<int>> lookup, string s, int start ,int end){
    if(start>end)
        return 0;
    if(start == end)
        return 1;
    if(lookup[start][end]==-1){
            if(s[start] == s[end])
                lookup[start][end] = 2 + LPSLengthRec(lookup, s,start+1,end-1);
            else{
                int c1 = LPSLengthRec(lookup, s,start+1,end);
                int c2 =LPSLengthRec(lookup, s,start,end-1);
                lookup[start][end] =  max(c1,c2);
            }
    
    }
    return lookup[start][end];
    
}

int LPSLength(string s){
    vector<vector<int>> lookup(s.length(),vector<int>(s.length(),-1));
    return LPSLengthRec(lookup,s,0,s.length()-1);
} */

int LPSLength(string s){
    vector<vector<int>> lookup(s.length(),vector<int>(s.length(),0));
    for(int i =0;i<s.length();i++)
        lookup[i][i] = 1;

    for(int i = s.length()-1;i>=0;i--){
        for(int j = i+1;j<s.length();j++){
            if(s[i]==s[j])
                lookup[i][j] = 2 + lookup[i+1][j-1];
            else
                lookup[i][j] = max(lookup[i+1][j], lookup[i][j-1]);
        }
    }
    return lookup[0][s.length()-1];
}


int main() {
  cout << LPSLength("cddpd") << endl;
  cout << LPSLength("abdbca") << endl;
  cout << LPSLength("cddpd") << endl;
  cout << LPSLength("pqr") << endl;
}