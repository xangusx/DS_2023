#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin>>q;
    priority_queue<int, vector<int>, greater<int>> tree;
    int command,x;
    while(q--){
        cin>>command;
        if(command == 1){
            cin>>x;
            tree.push(x);
        }
        else if(command == 2 and !tree.empty())
            tree.pop();
        else if(command == 3){
            if(!tree.empty())
                cout << "EMPTY\n";
            else
                cout << tree.top() << "\n";
        }
    }
}