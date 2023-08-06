#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u] = true;
    for(auto i : adj[u]){
        if(visited[i] == false)
            dfs(i,adj,visited);
    }
}

int main(){
    int t,n,q; cin>>t;
    while(t--){
        cin>>n>>q;
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1, false);
        auto start = std::chrono::steady_clock::now();
        int u,v;
        while(q--){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(visited[i] == false){
                dfs(i, adj, visited);
                ans++;
            }
        }
        auto end = chrono::steady_clock::now();
        chrono::duration<double> time = end - start;
        cout << ans << "\n";
        cout << "spend of time : " << time.count()*1000 << "ms\n";
    }
}