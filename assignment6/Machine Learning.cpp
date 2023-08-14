#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& l, pair<int,int>& r){
        if (l.second == r.second){
            return l.first < r.first;
        }
        return l.second < r.second;
}

int main(){
    int n,k; cin>>n>>k;
    vector<int> start(n);
    vector<pair<int,int>> course(n);
    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n; i++){
        cin>>course[i].second;
        course[i].first = start[i];
    }
    sort(course.begin(), course.end(),cmp);

    multiset<int> end_time;
    int count = 0;
    for(auto i : course){
        // cout << i.first << " " << i.second << "\n";
        if(!end_time.empty()){
            auto iter = end_time.lower_bound(i.first);
            if(iter != end_time.begin()){
                end_time.erase(--iter);
                end_time.emplace(i.second);
                count++;
            }
        }
        if(end_time.size() < k){
            end_time.emplace(i.second);
            count++;
        }
        
    }
    cout << count << "\n";
}