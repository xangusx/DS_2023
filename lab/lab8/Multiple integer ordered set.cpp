#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    string command;
    int val;
    map<int, int> mp;
    while(q--){
        cin>>command>>val;
        if(command == "I"){
            mp[val]++;
            cout << mp.size() << endl;
        }else if(command == "D"){
            if(mp.find(val) != mp.end()){
                mp[val]--;
                if(mp[val] == 0)
                    mp.erase(val);
            }
            cout << mp.size() << endl;
        }else if(command == "C"){
            mp.find(val) == mp.end() ?  cout << "0" << endl : cout << mp[val] << endl;
        }else if(command == "U"){
            if(mp.upper_bound(val) != mp.end())
                cout << (*mp.upper_bound(val)).first << endl;
            else
                cout << "-1" << endl;
        }else if(command == "L"){
            if(mp.lower_bound(val) != mp.end())
                cout << (*mp.lower_bound(val)).first << endl;
            else
                cout << "-1" << endl;
        }
    }
}
