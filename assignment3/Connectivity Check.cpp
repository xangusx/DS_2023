#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& visited){
    visited[u] = true;
    for(auto i : adj[u]){
        if(visited[i] == false)
            dfs(i, adj, visited);
    }
}

bool is_connectivity(ll u, vector<vector<ll>>& adj, ll n){
    vector<bool> visited(n+1, false);
    visited[0] = true;
    dfs(u, adj, visited);
    bool flag = true;
    for(auto i : visited){
        if(i == false){
            flag = false;
            break;
        }
    }
    return (flag ? true : false);
}

int main(){
    ll n,q; cin>>n>>q;
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> reverse_adj(n+1);

    ll u,v;
    while(q--){
        cin>>u>>v;
        adj[u].emplace_back(v);
        reverse_adj[v].emplace_back(u);
    }
    if(is_connectivity(1, adj, n) && is_connectivity(1, reverse_adj, n))
        cout << "YES";
    else
        cout << "NO";
}