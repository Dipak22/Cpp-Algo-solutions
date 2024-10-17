#include<iostream>
#include<string>
using namespace std;

int minEditDistRec(string s1,string s2, int n1,int n2){
    if(n1==0)
        return n2;
    if(n2 == 0)
        return n1;
    if(s1[n1-1] == s2[n2-1])
        return minEditDistRec(s1,s2,n1-1,n2-1);
    return 1 + min(min(minEditDistRec(s1,s2,n1-1,n2-1) , minEditDistRec(s1,s2,n1-1,n2)), minEditDistRec(s1,s2,n1,n2-1));
}

int minEditDist(string s1,string s2, int n1,int n2){
    return minEditDistRec(s1,s2,n1,n2);
}


int main() {
  // your code goes here 
  string str1 = "sunday";
  string str2 = "saturday";

  cout << minEditDist(str1, str2, str1.length(), str2.length());
  return 0;
}