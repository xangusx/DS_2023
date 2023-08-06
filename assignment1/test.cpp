#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    list<int> li;
    vector<list<int>::iterator> loc;

    auto it = li.begin();
    for(int i=1; i<=n; i++){
        loc.push_back(it);
        li.push_back(i);
        it++;
    }
    for(auto i: loc){
        cout << *i << " ";
    }
    cout << endl;
    for(auto i: li){
        cout << i << " ";
    }
}