#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/* int findPlatform(int* arrival, int* departure, int n){
    int result = 0;
    for(int i =0;i<n;i++){
        int count = 0;
        for(int j= 0;j<n;j++){
            if(arrival[j]>= arrival[i] && arrival[j]<departure[i] )
                count++;
        }
        if(result<count)
            result = count;
    }
    return result;
} */

bool sortBySec(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

/* int findPlatform(int* arrival,int* departure,int n){
    vector<pair<int,int>> zipped;
    for(int i=0;i<n;i++){
        zipped.push_back(make_pair(arrival[i],departure[i]));
    }
    sort(zipped.begin(),zipped.end(), sortBySec);
    int result = 1;
    int count = 1;
    int index = 0;
    int j = 1;
    while(j<n && index<n){
        if(zipped[j].first<= zipped[index].second){
            count++;
            j++;
            if(count>result)
                result = count;
        }
        else{
            count--;
            index++;
        }
    }
    return result;
}
 */
int findPlatform(int* arrival, int* departure, int n){
    multimap<int,char> myMultiMap;
    for(int i =0;i<n;i++){
        myMultiMap.insert(make_pair(arrival[i],'a'));
        myMultiMap.insert(make_pair(departure[i],'d'));
    }
    int result = 0;
    int count = 0;
    multimap<int,char>::iterator i;
    for(i = myMultiMap.begin();i!=myMultiMap.end();i++){
        if((*i).second =='a')
            count++;
        else
            count --;
        if(count>result)
            result = count;
    }
    return result;
}

int main() {
  
  int arrival[] = {900, 940, 950, 1100, 1500, 1800};
  int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arrival) / sizeof(arrival[0]);

 cout << "Minimum Number of Platforms Required for Plan1 = " <<
   findPlatform(arrival, departure, n);

  cout << endl << endl;

  // Example 2
  int arrival1[] = {200, 210, 300, 320, 350, 500};
  int departure1[] = {230, 240, 320, 430, 400, 520};
  int n1 = sizeof(arrival1) / sizeof(arrival1[0]);

  cout << "Minimum Number of Platforms Required for Plan2 = " <<
    findPlatform(arrival1, departure1, n1);
  
  return 0;
}