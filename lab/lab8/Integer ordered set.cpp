#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    string command;
    int val;
    set<int> st;
    while(q--){
        cin>>command>>val;
        if(command == "I"){
            if(st.find(val) == st.end())
                st.insert(val);
            cout << st.size() << endl;
        }else if(command == "D"){
            if(st.find(val) != st.end())
                st.erase(val);
            cout << st.size() << endl;
        }else if(command == "S"){
            cout << (st.find(val) == st.end() ? "NO" : "YES") << endl;
        }else if(command == "U"){
            if(st.upper_bound(val) != st.end())
                cout << *st.upper_bound(val) << endl;
            else
                cout << "-1" << endl;
        }else if(command == "L"){
            if(st.lower_bound(val) != st.end())
                cout << *st.lower_bound(val) << endl;
            else
                cout << "-1" << endl;
        }
    }
}
