#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sortBySec(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
void maxActivities(int* start,int* finish,int n){
    vector<pair<int,int>> activities;
    for(int i =0;i<n;i++){
        activities.push_back(make_pair(start[i],finish[i]));
    }
    sort(activities.begin(),activities.end(),sortBySec);
    int index,j;
    cout << "Following activities are selected: ";

    // select first activity
    index = 0;
    cout << index << " ";
    for(j =1;j<n;j++){
        if(activities[j].first>=    activities[index].second){
            cout<<j<<" ";
            index = j;
        }
    }
}


int main() {
  int start[] = {0, 3, 3, 2, 4, 3, 8, 10};
  int finish[] = {3, 4, 5, 7, 8, 11, 12, 13};
  int n = sizeof(start) / sizeof(start[0]);
  maxActivities(start, finish, n);
  return 0;
}