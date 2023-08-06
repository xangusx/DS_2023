#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    list<int> li;
    for(int i=0; i<n; i++){
        li.push_back(i+1);
    }

    list<int>::iterator it;
    it = li.begin();
    it++;
    if(it == li.end())
        it = li.begin();
    for(int i=0; i<n; i++){
        cout << *it << " ";
        it = li.erase(it);
        if(it == li.end())
            it = li.begin();
        it++;
        if(it == li.end())
            it = li.begin();
    }


}