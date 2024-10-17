#include<iostream>
#include<string>
#include<map>
using namespace std;

int findSIRec(string s1,string s2,string s3,int i1,int i2,int i3,map<string,int> lookup){
    if(i1==s1.length() && i2 ==s2.length() && i3 ==s3.length())
        return true;
    if(i3==s3.length())
        return false;
    string key = to_string(i1)+"-"+to_string(i2)+"-"+to_string(i3);
    if(lookup.count(key)==0){
        bool b0,b1;
    if(s1[i1] == s3[i3])
        b1 = findSIRec(s1,s2,s3,i1+1,i2,i3+1,lookup);
    if(s2[i2]==s3[i3])
        b0 = findSIRec(s1,s2,s3,i1,i2+1,i3+1,lookup);
    lookup.insert(pair<string,bool> (key, b0 || b1));
    }
    return lookup.find(key)->second;
    
}
int findSI(string s1,string s2,string s3){
    map<string,int> lookup;
    return findSIRec(s1,s2,s3,0,0,0,lookup);

}


int main() {
  cout << findSI("abd", "cef", "adcbef") << endl;
  cout << findSI("abc", "def", "abdccf") << endl;
  cout << findSI("abcdef", "mnop", "mnaobcdepf") << endl;
  cout << findSI("abc", "acd", "acdabc") << endl;
}