#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<set<int>> adj(n+1);
    int command,u,v;
    while(m--){
        cin>>command>>u>>v;
        if(command == 1){
            adj[u].insert(v);
            adj[v].insert(u);
        }
        else if(command == 2){
            cout << (adj[u].find(v)!= adj[u].end() ? "yes\n" : "no\n");
        }
    }
}